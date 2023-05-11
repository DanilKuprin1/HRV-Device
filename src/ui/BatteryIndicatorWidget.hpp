#pragma once

#include <QProgressBar>

class BatteryIndicatorWidget : public QProgressBar {
  Q_OBJECT

  public:
    explicit BatteryIndicatorWidget(QWidget* parent = nullptr);

  public slots:
    void on_level_changed(double level);
};
