#pragma once

#include "../Session.hpp"

#include <QListWidgetItem>

// Custom class that is used display a row with session in the log history
class SessionListWidgetItem : public QListWidgetItem {
public:
  SessionListWidgetItem(QListWidget* parent, SessionId id, time_t start_time);

  SessionId id;
};
