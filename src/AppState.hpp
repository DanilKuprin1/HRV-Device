#pragma once

#include "Sample.hpp"
#include "SessionHistory.hpp"

#include <chrono>
#include <cstdint>
#include <optional>
#include <variant>
#include <vector>

/// @brief A dummy session object used to represent the absence of a session
/// (during the `IDLE` state).
class EmptySession {};

/// @brief Enumeration of states that the app logic can be in.
enum class AppStates {
  /// @brief The app has just been started.
  ///
  /// @details The app is in this state when it is first started, and can
  /// transition to the `RECORDING` or the `REVIEWING` states.
  IDLE,
  /// @brief The app is recording a session.
  ///
  /// @details The app is recording samples from a pulse sensor. It _must_
  /// transition to the `REVIEWING` state when recording is complete.
  RECORDING,
  /// @brief The app is displaying the results of a previous session.
  ///
  /// @details The app is displaying the results of a previous session. It may
  /// be either the most recently recorded session, or a session from the past.
  REVIEWING,
};

/// @brief Application state machine.
///
/// @details The `AppState` struct is responsible for managing most of the state
/// of the app. Some display and translation logic is delegated to the
/// `MainWindow` class.
///
/// Functionally, this struct operates like a value-bearing enum, accompanied by
/// a mechanism for persisting session information between runs of the
/// application. This was done for simplicity, and to concentrate all of the
/// device logic in one place. Data is for the most part left in a raw form,
/// which is translated at the GUI layer for display in order to minimize clutter here (where bugs
/// are the most impactful on the rest of the codebase).
struct AppState {
public:
  AppState();

  ~AppState();

  /// @brief Gets the current state of the app logic.
  ///
  /// @return The current state of the app logic.
  AppStates get_state() const;

  /// @brief Starts a new recording session.
  ///
  /// The app must be in the `IDLE` or `REVIEWING` states to start a new
  /// session, and will panic otherwise.
  ///
  /// Call `record_sample` to add pulse samples to the session, and
  /// `stop_session` to end recording.
  void start_session();

  /// @brief Records a pulse sample to the current session. The app must be in
  /// the `RECORDING` state and will panic otherwise.
  ///
  /// @param sample The sample to record
  ///
  /// @return The coherence score every 5 seconds, returns `nullopt` between
  /// updated.
  std::optional<double> record_sample(Sample sample);

  /// @brief Ends the current recording session. The app must be in the
  /// `RECORDING` state and will panic otherwise.
  ///
  /// @return Returns the ID of the session that was just ended.
  SessionId stop_session();

  /// @brief Starts a review session for the given session ID. The app must be
  /// in either the `IDLE` or `REVIEWING` states and will panic otherwise.
  ///
  /// @param session_id
  ///
  /// @return A reference to the requested session.
  const HistoricalSession& review_session(SessionId session_id);

  /// @brief Deletes the session with the given ID. The app must be in either
  /// the `IDLE` or `REVIEWING` states and will panic otherwise.
  ///
  /// @param session_id
  void delete_session(SessionId session_id);

  /// @brief Deletes all sessions. The app must be in the `IDLE` or `REVIEWING`
  /// states and will panic otherwise.
  void clear_session_history();

  /// @brief Retrieves the current recording session. The app must be in the
  /// `RECORDING` state and will panic otherwise.
  ///
  /// @return A reference to the current recording session.
  const RecordingSession& get_recording_session() const;

  /// @brief Retrieves every session in the session history.
  ///
  /// @return A reference to every session in the session history.
  const std::vector<HistoricalSession>& get_session_history();

private:
  AppStates state;

  SessionHistory history;

  std::variant<EmptySession, RecordingSession, HistoricalSession*> current_session;
};
