#ifndef SENSORS_H
#define SENSORS_H

#include <AM2302-Sensor.h>

// Sensor Pins
#define DHT_PIN 8
#define LIGHT_SENSOR_PIN A0
#define RAIN_SENSOR_PIN A1  // Capacitive rain sensor

struct SensorData {
  float temperature;
  float humidity;
  float sunlight;
  float rainfall;
};

extern AM2302::AM2302_Sensor am2302;

void initSensors();
void takeMeasurements(SensorData &data);

#endif
