#include "sensors.h"

AM2302::AM2302_Sensor am2302{DHT_PIN};

void initSensors() {
  am2302.begin();
}

void takeMeasurements(SensorData &data) {
  digitalWrite(SENSOR_POWER_PIN, HIGH);  // Power on sensors
  delay(2000);  // Warm-up time
  
  // Read AM2302 (DHT22)
  am2302.read();
  data.temperature = am2302.get_Temperature();
  data.humidity = am2302.get_Humidity();
  
  // Read sunlight (0-100%)
  int lightRaw = abs(analogRead(LIGHT_SENSOR_PIN) - 1023);
  data.sunlight = (lightRaw / 1023.0) * 100.0;
  
  // Read capacitive rain (0-100% wetness)
  int rainRaw = analogRead(RAIN_SENSOR_PIN);
  data.rainfall = (rainRaw / 1023.0) * 100.0;
  
  digitalWrite(SENSOR_POWER_PIN, LOW);  // Power off sensors
}
