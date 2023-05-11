#include "PulseSensor.hpp"

PulseSensor::PulseSensor(const QString& filename, QObject* parent)
  : QObject{parent}, file{filename}, stream{&file}, buffer{""}, timer{this} {
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw std::runtime_error{file.errorString().toStdString()};
  }

  timer.setSingleShot(true);

  connect(&timer, &QTimer::timeout, this, &PulseSensor::on_timer);
}

void PulseSensor::start() {
  if (timer.isActive() || stream.atEnd()) {
    return;
  }

  time = std::chrono::milliseconds{0};
  on_timer();
}

void PulseSensor::stop() {
  if (!timer.isActive()) {
    return;
  }

  timer.stop();
}

void PulseSensor::on_timer() {
  if (stream.atEnd() || !stream.readLineInto(&buffer, 16)) {
    emit sampled(Status::hardware_failure, std::nullopt);
    return;
  }

  auto ok = false;
  auto interval = buffer.toInt(&ok);
  if (!ok) {
    emit sampled(Status::bad_sample, std::nullopt);
    timer.start(0);
    return;
  }

  time += std::chrono::milliseconds{interval};
  emit sampled(
    Status::ok,
    Sample{time, std::chrono::milliseconds{interval}, uint64_t(60.0 / interval * 1e3)});
  timer.start(interval);
}
