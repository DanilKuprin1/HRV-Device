#pragma once

#include <QElapsedTimer>
#include <QProgressBar>
#include <QTimer>

class BreathPacerWidget : public QProgressBar {
  Q_OBJECT

  public:
    explicit BreathPacerWidget(QWidget* parent = nullptr);

  private:
    QTimer timer;
    double progress;
    double interval;
    int direction;

  private slots:
    void update_progress();
};
