#include "MainWindow.hpp"

#include "ui/SessionListWidgetItem.hpp"
#include "ui_MainWindow.h"

#include <QDebug>
#include <iostream>

MainWindow::MainWindow(QWidget* parent)
  : QMainWindow{parent}
  , ui{new Ui::MainWindow{}}
  , battery_sensor{BatterySensor{}}
  , pulse_sensor{PulseSensor{":/data/demo/pulse.txt"}} {
  ui->setupUi(this);
  init_widgets();
  connect_sensors();
  battery_sensor.start();
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::init_widgets() {
  ui->HRContactLabel->hide();
  ui->coherenceIndicator->hide();
  ui->breathPacer->hide();

  ui->coherenceMetricsGroup->hide();

  // The connection of the GUI to the application is done here rather than by
  // defining slots in the class for two reasons: the first is that that all the
  // slots can be bound in one place (improving locality and reducing surprise),
  // and the second is because the main window as the app 'carrier' is
  // thematically separate from the actual widgets that make up the UI.

  // Some refactoring could be done to reduce code duplication here, but it's of
  // questionable value when there is so little code in the project (<1000 sloc).

  connect(ui->startSession, &QToolButton::clicked, [this]() {
    ui->sessionHistoryListWidget->setEnabled(false);
    ui->sessionHistoryListWidget->setCurrentItem(nullptr);

    ui->deleteSession->setEnabled(false);
    ui->clearSessionHistory->setEnabled(false);

    ui->startSession->setEnabled(false);
    ui->stopSession->setEnabled(true);

    ui->coherenceScoreLabel->setText("Coherence Score");
    ui->coherenceMetricsGroup->hide();

    ui->coherenceIndicator->show();
    ui->coherenceIndicator->setEnabled(true);
    ui->HRContactLabel->show();
    ui->breathPacer->show();

    ui->sessionLengthLCDNumber->setEnabled(true);
    ui->sessionLengthLCDNumber->display(0);

    ui->achievementScoreLCDNumber->setEnabled(true);
    ui->achievementScoreLCDNumber->display(0);

    ui->coherenceScoreLCDNumber->setEnabled(true);
    ui->coherenceScoreLCDNumber->display(0);

    ui->hrvGraph->clear();

    this->state.start_session();
    this->pulse_sensor.start();
  });

  connect(ui->stopSession, &QToolButton::clicked, [this]() {
    ui->sessionHistoryListWidget->setEnabled(true);
    ui->deleteSession->setEnabled(true);
    ui->clearSessionHistory->setEnabled(true);

    ui->startSession->setEnabled(true);
    ui->stopSession->setEnabled(false);

    ui->coherenceIndicator->hide();
    ui->coherenceIndicator->setEnabled(false);
    ui->HRContactLabel->hide();
    ui->breathPacer->hide();

    ui->sessionLengthLCDNumber->setEnabled(false);
    ui->sessionLengthLCDNumber->display(0);

    ui->achievementScoreLCDNumber->setEnabled(false);
    ui->achievementScoreLCDNumber->display(0);

    ui->coherenceScoreLCDNumber->setEnabled(false);
    ui->coherenceScoreLCDNumber->display(0);

    this->pulse_sensor.stop();

    auto sess_id = this->state.stop_session();
    const auto& session = this->state.review_session(sess_id);

    auto* widget = new SessionListWidgetItem(
      ui->sessionHistoryListWidget,
      sess_id,
      session.session.get_start_time());

    ui->sessionHistoryListWidget->setCurrentItem(widget);

    // transition to "REVIEWING" state
    ui->hrvGraph->seal();
  });

  connect(ui->clearSessionHistory, &QToolButton::clicked, [this]() {
    this->state.clear_session_history();
    ui->sessionHistoryListWidget->clear();
  });

  connect(ui->deleteSession, &QToolButton::clicked, [this]() {
    auto* history = ui->sessionHistoryListWidget;

    auto* item = history->currentItem();
    if (item) {
      auto* session_item = dynamic_cast<SessionListWidgetItem*>(item);
      if (session_item) {
        this->state.delete_session(session_item->id);
        delete item;
      }
    }
  });

  connect(
    ui->sessionHistoryListWidget,
    &QListWidget::currentItemChanged,
    [this](auto* item, auto* prev) {
      if (!item)
        return;

      ui->hrvGraph->clear();

      auto* session_item = dynamic_cast<SessionListWidgetItem*>(item);
      if (!session_item)
        return;

      const auto& session = this->state.review_session(session_item->id);
      const auto& samples = session.session.get_samples();

      for (auto sample : samples) {
        ui->hrvGraph->add_point(sample.time_since_sensor_start.count() * 1e-3, sample.heart_rate);
      }

      ui->sessionLengthLCDNumber->display(
        static_cast<double>(session.summary.session_length.count()));
      ui->coherenceScoreLCDNumber->display(session.summary.average_coherence_score);
      ui->achievementScoreLCDNumber->display(session.summary.achievement_score);

      ui->coherenceMetricsGroup->show();
      ui->coherenceScoreLabel->setText("Average Coherence Score");

      ui->highCoherencePercent->display(100.0 * session.summary.percent_at_high_coherence);
      ui->mediumCoherencePercent->display(100.0 * session.summary.percent_at_medium_coherence);
      ui->lowCoherencePercent->display(100.0 * session.summary.percent_at_low_coherence);

      ui->hrvGraph->seal();
    });

  connect(ui->powerButton, &QToolButton::clicked, [this]() {
    // Use historyGroupBox as a proxy for shutdown status
    if (this->ui->historyGroupBox->isEnabled()) {
      this->shutdown();
    } else if (this->battery_sensor.level() > 0.0) {
      this->startup();
    }
  });

  connect(ui->interruptSensor, &QPushButton::pressed, [this]() {
    this->is_sensor_interrupted = true;
    this->ui->HRContactLabel->hide();
  });

  connect(ui->interruptSensor, &QPushButton::released, [this]() {
    this->is_sensor_interrupted = false;
    this->ui->HRContactLabel->show();
  });

  auto history_widget = ui->sessionHistoryListWidget;
  const auto& sessions = state.get_session_history();
  for (const auto& session : sessions) {
    new SessionListWidgetItem(
      history_widget,
      session.session.get_id(),
      session.session.get_start_time());
  }

  history_widget->setCurrentItem(nullptr);
  history_widget->setFocusPolicy(Qt::NoFocus);
}

void MainWindow::connect_sensors() {
  connect(
    &battery_sensor,
    &BatterySensor::level_changed,
    ui->batteryIndicator,
    &BatteryIndicatorWidget::on_level_changed);

  // This single slot is the key driver of the simulation.
  connect(
    &pulse_sensor,
    &PulseSensor::sampled,
    [this](auto status, std::optional<Sample> maybe_sample) {
      if (status == PulseSensor::Status::ok && !this->is_sensor_interrupted) {
        auto sample = maybe_sample.value();
        ui->hrvGraph->add_point(sample.time_since_sensor_start.count() * 1e-3, sample.heart_rate);
        auto coherence_update = this->state.record_sample(sample);

        const auto& session = this->state.get_recording_session();

        auto seconds = std::chrono::duration_cast<std::chrono::seconds>(session.duration);
        ui->sessionLengthLCDNumber->display(static_cast<int>(seconds.count()));

        if (coherence_update.has_value()) {
          ui->achievementScoreLCDNumber->display(session.achievement_score);

          CoherenceLevel level = ui->coherenceIndicator->get_level();

          ui->coherenceScoreLCDNumber->display(coherence_update.value());

          // Coherence levels at challenge level 1
          if (coherence_update.value() <= 0.5) {
            if (level != CoherenceLevel::Low) {
              ui->coherenceIndicator->set_level(CoherenceLevel::Low);
              QApplication::beep();
            }
          } else if (coherence_update.value() <= 0.9) {
            if (level != CoherenceLevel::Medium) {
              ui->coherenceIndicator->set_level(CoherenceLevel::Medium);
              QApplication::beep();
            }
          } else {
            if (level != CoherenceLevel::High) {
              ui->coherenceIndicator->set_level(CoherenceLevel::High);
              QApplication::beep();
            }
          }
        }
      }
    });

  connect(&battery_sensor, &BatterySensor::fully_discharged, [this]() { this->shutdown(); });
}

void MainWindow::startup() {
  this->ui->historyGroupBox->setEnabled(true);
  this->ui->metricsGroupBox->setEnabled(true);
  this->ui->coherenceMetricsGroup->setEnabled(true);
  this->ui->startSession->setEnabled(true);
  this->ui->stopSession->setEnabled(false);

  this->battery_sensor.start();
}

void MainWindow::shutdown() {
  this->ui->historyGroupBox->setEnabled(false);
  this->ui->metricsGroupBox->setEnabled(false);
  this->ui->coherenceMetricsGroup->setEnabled(false);
  this->ui->startSession->setEnabled(false);
  this->ui->stopSession->setEnabled(false);

  qDebug() << "Current state: " << static_cast<int>(this->state.get_state());

  if (this->state.get_state() == AppStates::RECORDING) {
    this->state.stop_session();
  }
  this->battery_sensor.stop();
  this->pulse_sensor.stop();
}
