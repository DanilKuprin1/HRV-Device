#include "Session.hpp"

#include <QDebug>
#include <QtGlobal>

Summary::Summary(const RecordingSession& session) {
  this->achievement_score = session.achievement_score;
  this->session_length = session.duration;

  size_t num_high = 0, num_mid = 0, num_low = 0;
  for (auto score : session.coherence_scores) {
    if (score <= 0.5) {
      num_low++;
    } else if (score <= 0.9) {
      num_mid++;
    } else {
      num_high++;
    }
  }

  qInfo() << "num_high" << num_high << "num_mid" << num_mid << "num_low" << num_low;

  this->percent_at_high_coherence = (double)num_high / session.coherence_scores.size();
  this->percent_at_medium_coherence = (double)num_mid / session.coherence_scores.size();
  this->percent_at_low_coherence = (double)num_low / session.coherence_scores.size();

  this->average_coherence_score =
    (double)session.achievement_score / session.coherence_scores.size();
}

Summary::Summary(std::istream& in) {
  in.read(reinterpret_cast<char*>(&percent_at_high_coherence), sizeof(double));
  in.read(reinterpret_cast<char*>(&percent_at_medium_coherence), sizeof(double));
  in.read(reinterpret_cast<char*>(&percent_at_low_coherence), sizeof(double));
  in.read(reinterpret_cast<char*>(&average_coherence_score), sizeof(double));
  in.read(reinterpret_cast<char*>(&achievement_score), sizeof(double));

  uint64_t time64 = 0;
  in.read(reinterpret_cast<char*>(&time64), sizeof(uint64_t));

  session_length = std::chrono::milliseconds(time64);
}

void Summary::serialize(std::ostream& out) const {
  out.write(reinterpret_cast<const char*>(&percent_at_high_coherence), sizeof(double));
  out.write(reinterpret_cast<const char*>(&percent_at_medium_coherence), sizeof(double));
  out.write(reinterpret_cast<const char*>(&percent_at_low_coherence), sizeof(double));
  out.write(reinterpret_cast<const char*>(&average_coherence_score), sizeof(double));
  out.write(reinterpret_cast<const char*>(&achievement_score), sizeof(double));

  auto time = (uint64_t)session_length.count();
  out.write(reinterpret_cast<const char*>(&time), sizeof(uint64_t));
}

Session::Session() : id{0}, start_time(0) {}

Session::Session(SessionId id) : id{id}, start_time(time(nullptr)) {}

Session::Session(std::istream& in) {
  in.read(reinterpret_cast<char*>(&id), sizeof(SessionId));
  Q_ASSERT(id.id != 0);

  uint64_t time64 = 0;
  in.read(reinterpret_cast<char*>(&time64), sizeof(uint64_t));

  start_time = (time_t)time64;

  qDebug() << "Date: " << start_time;

  int num_samples = 0;
  in.read(reinterpret_cast<char*>(&num_samples), sizeof(size_t));

  qInfo() << "Deserializing session with " << num_samples << " samples";

  // Initialize the vector to the correct size.
  samples.resize(num_samples);

  // Read in raw bytes.
  in.read(reinterpret_cast<char*>(samples.data()), num_samples * sizeof(Sample));
}

SessionId Session::get_id() const {
  return id;
}

time_t Session::get_start_time() const {
  return start_time;
}

const std::vector<Sample>& Session::get_samples() const {
  return samples;
}

void Session::add_reading(Sample sample) {
  samples.push_back(sample);
}

void Session::serialize(std::ostream& out) const {
  out.write(reinterpret_cast<const char*>(&id), sizeof(SessionId));

  auto time = (uint64_t)start_time;
  out.write(reinterpret_cast<const char*>(&time), sizeof(uint64_t));

  auto num_samples = samples.size();
  out.write(reinterpret_cast<const char*>(&num_samples), sizeof(size_t));

  qInfo() << "Writing " << samples.size() << " samples to file.";

  // Write out raw bytes.

  // SAFETY: Make sure that sizeof(std::chrono::milliseconds) is the same on all
  // platforms that we run on.
  auto size = samples.size() * sizeof(Sample);
  out.write(reinterpret_cast<const char*>(samples.data()), size);
}
