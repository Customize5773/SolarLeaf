# Bill of Materials (BOM)  
---

## Core Electronics  
| Qty | Component                 | Specifications                          | Notes                                                                 |
|-----|---------------------------|----------------------------------------|-----------------------------------------------------------------------|
| 1   | Microcontroller           | Arduino Pro Mini 3.3V (8MHz)           | Low-power ATmega328P board                                            |
| 1   | Temperature/Humidity Sensor | DHT22 (AM2302)                         | ±0.5°C accuracy, digital output                                      |
| 1   | Light Sensor              | Photoresistor (GL5528)                 | Paired with 10kΩ resistor for voltage divider                         |
| 1   | Capacitive Rain Sensor    | Capacitive Soil Moisture Sensor v1.2   | Analog output, waterproof probe                                      |
| 1   | Display                   | 1.8" SPI TFT (128x160)                 | ST7735 driver, 3.3V logic                                             |
| 1   | Power Management IC       | AP2112K-3.3 Voltage Regulator          | 600mA buck converter (battery to 3.3V)                               |
| 1   | Charging Module           | TP4056 w/ Battery Protection           | For 18650 Li-ion charging + over-discharge protection                |
| 1   | MOSFET                    | IRLZ34N Logic-Level MOSFET             | For sensor power switching (gate controlled by MCU)                  |

---

## Power System  
| Qty | Component                 | Specifications                          | Notes                                                                 |
|-----|---------------------------|----------------------------------------|-----------------------------------------------------------------------|
| 1   | Solar Panel               | 6V 2W Polycrystalline                  | 120x60mm                                                             |
| 1   | Battery                   | 18650 Li-ion (3400mAh)                 | Protected cell (e.g., LG MJ1)                                         |
| 1   | Battery Holder            | Single 18650 Holder                    | With JST connector                                                    |
| 1   | Diode                     | 1N5817 Schottky                        | Prevents reverse current from battery to solar                        |

---

## Passive Components  
| Qty | Component                 | Specifications                          | Notes                                                                 |
|-----|---------------------------|----------------------------------------|-----------------------------------------------------------------------|
| 2   | Resistor                  | 10kΩ 1/4W                              | Light sensor voltage divider                                          |
| 1   | Resistor                  | 4.7kΩ 1/4W                             | DHT22 pull-up (if not built-in)                                       |
| 3   | Capacitor                 | 100µF 16V Electrolytic                 | Power supply decoupling                                               |
| 1   | Tactile Switch            | 6x6mm SPST                             | Wake-from-sleep button                                               |

---

## Enclosure & Hardware  
| Qty | Component                 | Specifications                          | Notes                                                                 |
|-----|---------------------------|----------------------------------------|-----------------------------------------------------------------------|
| 1   | Main Enclosure            | 3D-Printed (PETG)                     | Weather-resistant design                                              |
| 1   | Rain Sensor Mount         | 3D-Printed Angled Bracket              | Positions sensor horizontally                                         |
| 4   | M3 Screw/Nut             | 12mm Length                            | Enclosure assembly                                                    |
| 1   | Waterproof Gasket        | Silicone Rubber Sheet (1.5mm)          | Display/seam sealing                                                 |
| 1   | Cable Gland              | PG7 IP68                               | Solar panel entry point                                              |

---

## Connectivity  
| Qty | Component                 | Specifications                          | Notes                                                                 |
|-----|---------------------------|----------------------------------------|-----------------------------------------------------------------------|
| 1   | JST Connector Set         | 2-pin PH Series                        | Battery connections                                                  |
| 1   | Header Pins               | 40-pin Male/Female Set                 | Sensor/display connections                                           |
| -   | Wire                      | 22 AWG Silicone-coated                 | High-flexibility                                                     |

---

## Estimated Costs  
| Category               | Cost Range   |
|------------------------|--------------|
| Electronics            | $18-$22      |
| Power System           | $12-$15      |
| Mechanical Components  | $5-$8        |
| **Total**              | **$35-$45**  |

---

## Sourcing Notes  
1. **Capacitive Rain Sensor**:  
   - Look for "V1.2" modules with analog output (avoid resistive sensors)  
   - Calibration required: Record values when dry (0% wet) and water-submerged (100% wet)  
2. **Solar Panel**:  
   - Minimum 120x60mm size for reliable 6V output  
   - Mount at 30-45° angle toward equator  
3. **3D Printing**:  
   - Use PETG filament for UV/weather resistance  
   - 0.2mm layer height, 25% infill, 3 perimeters  

---

## Power Consumption Profile  
| State                 | Current Draw | Duration       | Notes                                  |
|-----------------------|--------------|----------------|----------------------------------------|
| **Active Measurement** | 85-100mA     | 5 seconds      | All sensors + display on               |
| **Display Sleep**     | 35mA         | 25 seconds     | Display off, sensors active            |
| **Deep Sleep**        | 0.45mA       | 9 min 30 sec   | All peripherals powered off            |
| **Daily Average**     | ~0.82mA      | -              | Enables 6+ months operation on single charge |

> **Battery Life Calculation**:  
> `3400mAh / 0.82mA ≈ 4146 hours ≈ 173 days` (without solar input)

---

> [!NOTE]  
> **Sensor calibration guide: [CALIBRATION.md](docs/CALIBRATION.md)**
