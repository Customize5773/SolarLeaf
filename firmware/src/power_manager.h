#ifndef POWER_MANAGER_H
#define POWER_MANAGER_H

#include <LowPower.h>

void goToSleep(uint8_t minutes) {
  // Convert minutes to 8-second sleep cycles
  uint8_t cycles = minutes * 7.5; 
  
  digitalWrite(LCD_BACKLIGHT_PIN, LOW);
  
  for (uint8_t i = 0; i < cycles; i++) {
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    if (displayRequested) break;
  }
}

#endif
