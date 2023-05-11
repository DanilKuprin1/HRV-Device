#include "BatteryIndicatorWidget.hpp"

BatteryIndicatorWidget::BatteryIndicatorWidget(QWidget* parent) : QProgressBar{parent} {
  setRange(0, 100);
}

void BatteryIndicatorWidget::on_level_changed(double level) {
  setValue(static_cast<int>(level * 100));
}
