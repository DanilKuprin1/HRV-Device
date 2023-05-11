#include "BatterySensor.hpp"

#include <QDebug>

BatterySensor::BatterySensor(int initial_charge, int discharge_rate, QObject* parent)
  : QObject{parent}
  , initial_charge{initial_charge}
  , discharge_rate{discharge_rate}
  , charge{initial_charge} {
  connect(&timer, &QTimer::timeout, this, &BatterySensor::on_timer);
}

void BatterySensor::start() {
  timer.start(1000);
}

void BatterySensor::stop() {
  timer.stop();
}

void BatterySensor::on_timer() {
  charge -= discharge_rate;

  if (charge < 0) {
    charge = 0;
    stop();
    emit fully_discharged();
  }

  emit level_changed(level());
}

auto BatterySensor::level() const -> double {
  return static_cast<double>(charge) / initial_charge;
}
