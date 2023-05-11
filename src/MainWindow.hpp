#pragma once

#include "AppState.hpp"
#include "data/BatterySensor.hpp"
#include "data/PulseSensor.hpp"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
  class MainWindow;
}
QT_END_NAMESPACE

/// @brief The main window of the application.
///
/// @details The `MainWindow` class is responsible for handling the GUI, as well
/// as coordinating the different moving parts that make up the device
/// simulation. In a real device, this class would likely be replaced by a
/// `Device` class that fulfills the same purpose.
class MainWindow : public QMainWindow {
  Q_OBJECT

  public:
    MainWindow(QWidget* parent = nullptr);

    ~MainWindow();

  private:
    void init_widgets();

    void connect_sensors();

    void startup();

    void shutdown();

    Ui::MainWindow* ui;

    AppState state;

    BatterySensor battery_sensor;

    PulseSensor pulse_sensor;

    /// @brief A flag indicating whether the sensor has been interrupted.
    ///
    /// @details When the sensor is interrupted, the sensor clock will continue,
    /// but samples will not make it from the sensor to the app logic.
    /// Simulating sensor interruption was done this way for simplicity, and to
    /// avoid plumbing interruption logic through the `PulseSensor` class.
    bool is_sensor_interrupted;
};
