#pragma once

#include "Session.hpp"

#include <vector>

struct HistoricalSession {
  Session session;
  Summary summary;
};

/// @brief A record of previously recorded sessions. This class is responsible
/// for persisting sessions across runs of the application.
class SessionHistory {
public:
  SessionHistory();
  ~SessionHistory();

  /// @brief Retrieves the next session ID to use to create a new session.
  ///
  /// @return SessionID
  ///
  /// @details This method was chosen (as opposed to a GUID or some other
  /// mechanism) for its simplicity, and because the only requirement is that
  /// the ID be unique for all sessions in the current application lifetime.
  SessionId next_session_id();

  void add_session(Session session, Summary summary);

  bool remove_session(SessionId session_id);

  const std::vector<HistoricalSession>& get_sessions() const;

  void clear();

private:
  SessionId next_id;

  std::vector<HistoricalSession> sessions;

  bool serialize();

  bool deserialize();
};
