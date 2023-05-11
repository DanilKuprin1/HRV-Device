#pragma once

#include "../Sample.hpp"

#include <QFile>
#include <QObject>
#include <QString>
#include <QTextStream>
#include <QTimer>
#include <chrono>
#include <memory>
#include <optional>
#include <stdexcept>

/**
 * @brief Simulates a pulse sensor that emits instantaneous heart rates at beat times.
 *
 * The sensor is created from a text file containing one interbeat interval in milliseconds per
 * line. Once started, the sensor continuously emits a `sampled` event with a status flag, and the
 * relative time of each heartbeat in milliseconds with the corresponding instantaneous heart rate
 * in beats per minute, if sampling is successful.
 */
class PulseSensor : public QObject {
  Q_OBJECT

  public:
    /**
     * @brief The status after a sampling attempt.
     */
    enum class Status {
      /// Sampling done and the value was valid. Sampling will continue.
      ok,
      /// Sampling done but the value was invalid. Sampling will continue.
      /// Internally, this indicates a line in the input file with an unexpected data type.
      bad_sample,
      /// Sampling failed due to unrecoverable hardware failure. Sampling will stop indefinitely.
      /// Internally, this indicates a file error or end-of-file.
      hardware_failure,
    };

    /**
     * @brief Creates a pulse sensor from a text file.
     *
     * The file is expected to contain one interbeat interval in milliseconds per line.
     *
     * @param filename The name of the file to read the pulse data from.
     * @param parent The parent object.
     *
     * @throws Standard runtime error if the file cannot be opened for reading.
     */
    explicit PulseSensor(QString const& filename, QObject* parent = nullptr);

  signals:
    /**
     * @brief Emitted after a sampling attempt.
     *
     * @param status The status after the sampling attempt.
     * @param sample The relative time of the heartbeat in milliseconds if sampling was successful.
     *
     * @note Emitted values will be null if sampling was unsuccessful.
     */
    void sampled(PulseSensor::Status status, std::optional<Sample> sample);

  public slots:
    /**
     * @brief Starts the sensor.
     *
     * This is a no-op if the sensor is already running or has encountered hardware failure.
     */
    void start();

    /**
     * @brief Stops the sensor.
     *
     * This is a no-op if the sensor is not running yet.
     */
    void stop();

  private slots:

    /**
     * @brief Simulates detecting a heartbeat by reading the next interbeat interval from the file.
     *
     * Be default, a success status with the relative heartbeat time and the instantaneous heart
     * rate values are emitted. In case of an error, a corresponding sensor status with null values
     * are emitted:
     * - File errors and end-of-file map to unrecoverable hardware failure which stop the sensor.
     * - Parse errors at a line map to bad sample errors which result in skipping the faulty line.
     */
    void on_timer();

  private:
    /// The input file containing one interbeat interval in milliseconds per line.
    QFile file;

    /// The text stream used for reading the input file.
    QTextStream stream;

    /// The buffer used to read the next line of the file into.
    QString buffer;

    /// The timer used for generating the heartbeats at proper times.
    QTimer timer;

    /// The elapsed time in milliseconds since the sensor was started.
    std::chrono::milliseconds time;
};
