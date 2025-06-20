# SolarLeaf Setup Guide
**Estimated Build Time:** 2-3 hours  
**Difficulty:** Intermediate  
**Tools Required:** Soldering iron, wire strippers, 3D printer, multimeter  

---

## 1. Component Preparation
### PCB Assembly:
```mermaid
graph LR
    A[Arduino Pro Mini] --> B[Install Headers]
    B --> C[Solder Voltage Regulator]
    C --> D[Connect MOSFET Gate to Pin 7]
```

### Sensor Wiring:
| Sensor        | Arduino Pin | Connection Notes          |
|---------------|-------------|---------------------------|
| DHT22         | D8          | 4.7kΩ pull-up resistor    |
| Light Sensor  | A0          | Voltage divider circuit   |
| Rain Sensor   | A1          | No pull-up needed         |
| Display       | SPI Pins    | CS=40, DC=38, RESET=41    |

---

## 2. Mechanical Assembly
### Enclosure Steps:
1. **Print Parts**:
   - Use PETG filament (0.2mm layer height)
   - Print orientation: Base flat, sensor mounts vertical

2. **Sensor Mounting**:
   ```mermaid
   graph TB
       A[Main Enclosure] --> B[Insert DHT22 through side vent]
       A --> C[Glue light sensor to top dome]
       A --> D[Attach rain sensor bracket at 30° angle]
   ```

3. **Weatherproofing**:
   - Apply silicone sealant around display edges
   - Install PG7 cable gland for solar panel wires
   - Add desiccant packet inside enclosure

---

## 3. Electrical Connections
### Power System Wiring:
```plaintext
Solar Panel (+) → Diode → TP4056 IN+
TP4056 OUT+ → Battery + 
TP4056 OUT- → Battery -
Battery + → AP2112 IN
AP2112 OUT (3.3V) → Arduino VCC
```

### Critical Checks:
1. Verify 3.3V output before connecting Arduino
2. Test MOSFET switching (Pin 7 HIGH = 3.3V at sensor VCC)
3. Confirm battery protection circuit triggers at 3.0V

---

## 4. Firmware Upload
1. **Install Libraries**:
   ```bash
   cd firmware/libraries
   git clone https://github.com/rocketscream/Low-Power.git
   ```
   
2. **Upload Sketch**:
   - Select board: "Arduino Pro or Pro Mini"
   - Processor: "ATmega328P (3.3V, 8MHz)"
   - Port: [Your COM port]
   - Upload `SolarLeaf.ino`

---

## 5. First Boot Test
**Expected Behavior**:
1. Red LED on TP4056 blinks during charging
2. Press button: Display shows readings for 30s
3. After 30s: Display turns off (sleep mode)

> **Troubleshooting**: See [FAQ.md](FAQ.md) if no display appears
