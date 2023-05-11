#pragma once

#include <QObject>
#include <QTimer>
#include <chrono>

/**
 * @brief Simulates a battery sensor that periodically reports the battery level and notifies
 * when it is fully discharged.
 *
 * The sensor emits two signals for when the battery level changes, and when the battery is
 * fully discharged. The sensor can be started and stopped using the corresponding slots.
 */
class BatterySensor : public QObject {
  Q_OBJECT
  public:
    /**
     * @brief Creates a battery sensor.
     *
     * @param initial_charge Initial charge in arbitrary units (default is 1000).
     * @param discharge_rate Discharge rate in units of initial charge per second (default is 1).
     * @param parent The parent object.
     */
    explicit BatterySensor(
      int initial_charge = 1000,
      int discharge_rate = 1,
      QObject* parent = nullptr);

    /**
     * @brief Returns the current battery level.
     *
     * @return Current battery level as a normalized fraction.
     */
    double level() const;

  signals:
    /**
     * @brief Emitted when the battery level changes.
     *
     * @param level Current battery level as a normalized fraction.
     */
    void level_changed(double level);

    /**
     * @brief Emitted when the battery is fully discharged.
     */
    void fully_discharged();

  public slots:
    /**
     * @brief Starts the sensor.
     */
    void start();

    /**
     * @brief Stops the sensor.
     */
    void stop();

  private slots:
    /**
     * @brief Periodically updates the battery charge based on a linear discharge model, and emits
     * signals whenever the battery level changes and once the battery is fully discharged.
     */
    void on_timer();

  private:
    /// Initial charge in arbitrary units.
    int initial_charge;

    /// Discharge rate in units of initial charge per second.
    int discharge_rate;

    /// Current charge in units of initial charge.
    int charge;

    /// Timer used for periodically depleting the battery.
    QTimer timer;
};
