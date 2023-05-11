#include "BreathPacerWidget.hpp"

BreathPacerWidget::BreathPacerWidget(QWidget* parent)
  : QProgressBar{parent}, timer{this}, progress{0.0}, interval{5.0}, direction{1} {
  connect(&timer, &QTimer::timeout, this, &BreathPacerWidget::update_progress);
  timer.setInterval(16);
  timer.start();
}

void BreathPacerWidget::update_progress() {
  progress += direction * (1e-3 / interval) * timer.interval();

  if (progress >= 1.0 || progress <= 0.0) {
    direction = -direction;
  }

  setValue(static_cast<int>(progress * 1000));
}
