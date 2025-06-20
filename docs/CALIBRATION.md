# Sensor Calibration Guide
Calibrate sensors **before final enclosure assembly** for best results

---

## Light Sensor Calibration
1. **Setup**:
   - Connect multimeter to light sensor output (A0)
   - Use smartphone light meter app as reference

2. **Procedure**:
   | Condition      | Expected Voltage | Calibration Value |
   |----------------|------------------|-------------------|
   | Complete dark  | 0V → 0%          | `darkValue = analogRead(A0)` |
   | 100,000 lux    | 3.3V → 100%      | `brightValue = analogRead(A0)` |

3. **Update Code**:
   ```cpp
   // In sensors.cpp
   float sunlight = map(analogRead(LIGHT_SENSOR_PIN), darkValue, brightValue, 0, 100);
   ```

---

## Capacitive Rain Sensor
### Dry/Wet Calibration:
1. Leave sensor completely dry for 24 hours
   ```bash
   Dry baseline:  # Serial monitor command
   > CAL_RAIN DRY
   > Value saved: 582
   ```

2. Submerge sensor in distilled water
   ```bash
   Wet baseline:
   > CAL_RAIN WET
   > Value saved: 183
   ```

### Field Calibration:
| Rainfall | Expected Reading | Adjustment               |
|----------|------------------|--------------------------|
| 1mm      | 15-20%           | Increase sensitivity if <15% |
| 5mm      | 60-70%           | Decrease if >80%         |

### Code Implementation:
```cpp
// In takeMeasurements()
int rainRaw = analogRead(RAIN_SENSOR_PIN);
data.rainfall = constrain(map(rainRaw, dryValue, wetValue, 0, 100), 0, 100);
```

---

## DHT22 Temperature Compensation
1. **Ice Bath Test**:
   - Submerge sensor in 0°C ice slurry
   - Record temperature offset:
   ```cpp
   tempOffset = measuredTemp - 0.0;
   ```

2. **Body Test**:
   - Hold sensor in hand (should read 32-36°C)
   - Adjust if deviation >0.5°C

---

## Sleep Cycle Optimization
1. Measure current draw with multimeter
2. Adjust sleep cycles in `power_manager.h`:
   ```cpp
   // Current: 0.45mA (good)
   // Target battery life: 6 months
   uint8_t cycles = minutes * 7.5;  // 8s/cycle
   ```
3. Balance between data frequency and battery life
