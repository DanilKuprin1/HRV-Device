#include "AppState.hpp"

#include <QtGlobal>
#include <cstdlib>
#include <utility>

AppState::AppState() : state{AppStates::IDLE}, current_session(EmptySession{}) {}

AppState::~AppState() {}

AppStates AppState::get_state() const {
  return state;
}

void AppState::start_session() {
  if (state == AppStates::RECORDING) {
    qWarning("Can't start recording when already recording");
    std::abort();
  }

  state = AppStates::RECORDING;
  current_session = RecordingSession{
    Session(history.next_session_id()),
    std::vector<double>(),
    0.0,
    std::chrono::milliseconds{0},
    std::chrono::milliseconds{0}};

  qInfo(
    "Started recording session %zu",
    std::get<RecordingSession>(current_session).session.get_id().id);
}

std::optional<double> AppState::record_sample(Sample sample) {
  if (state != AppStates::RECORDING) {
    qWarning("Can only record pulse when in AppStates::RECORDING state");
    std::abort();
  }

  auto& session = std::get<RecordingSession>(current_session);
  session.session.add_reading(sample);
  session.since_last_coherence_update += sample.time_since_last_sample;
  session.duration = sample.time_since_sensor_start;

  if (session.since_last_coherence_update >= std::chrono::milliseconds{5000}) {
    session.since_last_coherence_update -= std::chrono::milliseconds{5000};

    // FOR SIMULATION ONLY
    double coherence_score = (double(std::rand()) / RAND_MAX) * 16.0;
    session.coherence_scores.push_back(coherence_score);

    session.achievement_score += coherence_score;

    return coherence_score;
  } else {
    return std::nullopt;
  }
}

SessionId AppState::stop_session() {
  if (state != AppStates::RECORDING) {
    qWarning("Can only stop recording when in AppStates::RECORDING state");
    std::abort();
  }

  auto& recording = std::get<RecordingSession>(current_session);

  Summary summary(recording);

  auto id = recording.session.get_id();

  qInfo("Session %zu stopped.", id.id);

  history.add_session(recording.session, std::move(summary));

  qInfo("There are now %zu sessions in the session history", history.get_sessions().size());

  state = AppStates::REVIEWING;

  return id;
}

const HistoricalSession& AppState::review_session(SessionId session_id) {
  if (state != AppStates::IDLE && state != AppStates::REVIEWING) {
    qWarning(
      "Can only review previous sessions when in the AppStates::IDLE or AppStates::REVIEWING states");
    std::abort();
  }

  // No state change
  for (const auto& session : history.get_sessions()) {
    if (session.session.get_id().id == session_id.id) {
      return session;
    }
  }

  qWarning("Could not find session {id: %lu}", session_id.id);
  std::abort();
}

void AppState::delete_session(SessionId session_id) {
  if (state != AppStates::IDLE && state != AppStates::REVIEWING) {
    qWarning(
      "Can only delete previous sessions when in the AppStates::IDLE or AppStates::REVIEWING states");
    std::abort();
  }

  qInfo("Removing session {id: %zu}", session_id.id);

  auto found = history.remove_session(session_id);

  if (!found) {
    qWarning("Could not find session {id: %zu}", session_id.id);
    std::abort();
  }
}

void AppState::clear_session_history() {
  if (state != AppStates::IDLE && state != AppStates::REVIEWING) {
    qWarning(
      "Can only clear session history when in the AppStates::IDLE or AppStates::REVIEWING states");
    std::abort();
    return;
  }

  history.clear();
}

auto AppState::get_recording_session() const -> const RecordingSession& {
  if (state != AppStates::RECORDING) {
    qWarning("Can only get recording session when in AppStates::RECORDING state");
    std::abort();
  }

  return std::get<RecordingSession>(current_session);
}

auto AppState::get_session_history() -> const std::vector<HistoricalSession>& {
  return history.get_sessions();
}
