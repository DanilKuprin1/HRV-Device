#include "SessionListWidgetItem.hpp"

SessionListWidgetItem::SessionListWidgetItem(QListWidget* parent, SessionId id, time_t start_time)
  : QListWidgetItem(parent), id(id) {
  char buffer[100] = {0};
  std::strftime(buffer, sizeof(buffer), "%FT%TZ", std::localtime(&start_time));

  setText(buffer);
}
