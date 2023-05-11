#pragma once

#include <chrono>

/// @brief A sample from a pulse sensor.
struct Sample {
  std::chrono::milliseconds time_since_sensor_start;
  std::chrono::milliseconds time_since_last_sample;
  /// @brief The heart rate in beats per minute.
  uint64_t heart_rate;
};
