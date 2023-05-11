#pragma once

#include "Sample.hpp"

#include <cstdint>
#include <ctime>
#include <iostream>
#include <vector>

/// @brief A unique identifier for a session. These are guaranteed to be unique
/// for the lifetime of a session, persisted between runs of the application.
///
/// @details Session ids are preferred to pointers because they can be persisted
/// trivially across runs of the application, and because they are useful as
/// weak pointers without the implementation burden of actually using smart
/// pointers. A more complex system with generational handles would be more
/// appropriate if we needed to do fancier things with sessions, but an
/// monotonically incrementing integer is sufficient for identifying which
/// session to delete.
struct SessionId {
  size_t id;
};

/// @brief Class that simulates a session and stores data about the session.
struct Session {
public:
  /// @brief Default-constructs an empty session.
  Session();

  /// @brief Create a new session.
  Session(SessionId id);

  /// @brief Deserialize a session from a stream.
  ///
  /// @param in The stream to deserialize from.
  Session(std::istream& in);

  /// @brief Returns the ID of the session.
  /// @return SessionId
  SessionId get_id() const;

  /// @brief Returns the machine local instant that the session started recordig.
  /// @return time_t
  time_t get_start_time() const;

  /// @brief Returns the samples recorded in the session.
  /// @return std::vector<Sample>
  const std::vector<Sample>& get_samples() const;

  /// @brief Add a pulse reading in milliseconds since the start of the
  /// session.
  void add_reading(Sample sample);

  /// @brief Serialize the session to a stream.
  ///
  /// @param out The stream to serialize to.
  void serialize(std::ostream& out) const;

private:
  SessionId id;

  time_t start_time;

  std::vector<Sample> samples;
};

/// @brief A session that is currently being recorded.
struct RecordingSession {
  Session session;

  // FOR SIMULATION ONLY
  std::vector<double> coherence_scores;

  double achievement_score;

  std::chrono::milliseconds duration;

  std::chrono::milliseconds since_last_coherence_update;
};

struct Summary {
  /// @brief Default-constructs an empty summary.
  explicit Summary() = default;

  /// @brief Constructs a summary of the session.
  explicit Summary(const RecordingSession& session);

  /// @brief Deserialize a session summary from a stream.
  /// @param in
  explicit Summary(std::istream& in);

  /// @brief Serialize the session summary to a stream.
  /// @param out
  void serialize(std::ostream& out) const;

  double percent_at_high_coherence = 0.0;
  double percent_at_medium_coherence = 0.0;
  double percent_at_low_coherence = 0.0;
  double average_coherence_score = 0.0;
  double achievement_score = 0.0;
  std::chrono::milliseconds session_length;
};
