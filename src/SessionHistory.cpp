#include "SessionHistory.hpp"

#include "Session.hpp"

#include <QtGlobal>
#include <fstream>
#include <iostream>
#include <utility>

const uint64_t DATA_FORMAT_ID = 7;

SessionHistory::SessionHistory() : next_id{1} {
  deserialize();
}

SessionHistory::~SessionHistory() {
  serialize();
}

SessionId SessionHistory::next_session_id() {
  auto id = next_id;
  next_id.id++;
  qInfo("Next session ID is %zu", id.id);
  return id;
}

void SessionHistory::add_session(Session session, Summary summary) {
  sessions.push_back(HistoricalSession{std::move(session), summary});
}

bool SessionHistory::remove_session(SessionId session_id) {
  // Without hundreds of sessions, this is probably fine. The alternative is
  // either an unordered map, or a sorted vector, which are both more complex
  // than we need here.

  for (auto it = sessions.begin(); it != sessions.end(); it++) {
    if (it->session.get_id().id == session_id.id) {
      sessions.erase(it);
      return true;
    }
  }

  return false;
}

const std::vector<HistoricalSession>& SessionHistory::get_sessions() const {
  return sessions;
}

bool SessionHistory::serialize() {
  // Causes a prior file (if it exists), to be overwritten.
  std::ofstream out("SessionData.bin", std::ios::trunc | std::ios::out | std::ios::binary);

  if (!out.is_open()) {
    qWarning("Couldn't open the file for writing.");
    return false;
  }

  out.write(reinterpret_cast<const char*>(&DATA_FORMAT_ID), sizeof(uint64_t));

  auto num_sessions = sessions.size();
  out.write(reinterpret_cast<const char*>(&num_sessions), sizeof(size_t));

  std::cout << "Writing " << sessions.size() << " sessions to file." << std::endl;

  int i = 0;
  for (HistoricalSession& session : sessions) {
    std::cout << "Writing session " << i++ + 1 << " to file." << std::endl;

    session.session.serialize(out);
    session.summary.serialize(out);
  }

  out.close();

  return true;
}

bool SessionHistory::deserialize() {
  std::ifstream in("SessionData.bin", std::ios::in | std::ios::binary);

  this->clear();

  qInfo("Deserializing sessions from file.");

  if (!in.is_open()) {
    qWarning("Couldn't open the file for reading.");
    this->next_id = SessionId{1};
    return false;
  }

  uint64_t data_format_id = 0;
  in.read(reinterpret_cast<char*>(&data_format_id), sizeof(uint64_t));

  if (data_format_id != DATA_FORMAT_ID) {
    qWarning("The data format ID in the file is not the same as the current data format ID.");
    this->next_id = SessionId{1};
    this->clear();
    return false;
  }

  size_t num_sessions = 0;
  in.read(reinterpret_cast<char*>(&num_sessions), sizeof(size_t));

  qInfo("Found %zu sessions.", num_sessions);

  this->sessions.reserve(num_sessions);

  SessionId max{0};

  while (sessions.size() < num_sessions && !in.eof()) {
    Session session(in);
    Summary summary(in);

    Q_ASSERT(session.get_id().id != 0);

    if (session.get_id().id > max.id) {
      max = session.get_id();
    }

    sessions.push_back(HistoricalSession{std::move(session), summary});
  }

  this->next_id = SessionId{max.id + 1};

  if (num_sessions != sessions.size()) {
    qWarning(
      "The number of sessions read from the file is not the same as the number of sessions stored in the file.");
    return false;
    this->clear();
  }

  in.close();

  return true;
}

void SessionHistory::clear() {
  sessions.clear();
}
