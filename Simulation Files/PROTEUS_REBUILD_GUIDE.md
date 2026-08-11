# Proteus Simulation — Rebuild Guide

> **Note:** The original `.pdsprj` Proteus project files were lost. Proteus project
> files are a proprietary Labcenter Electronics binary format, so they can't be
> auto-generated from text or from the research paper — but they're quick to
> rebuild manually. This guide gives you the exact components, pin mapping, and
> wiring (taken directly from Fig. 2, Fig. 3, Fig. 4, and Fig. 6 of the research
> paper) so you can recreate both simulations in Proteus in a few minutes.

## Components Needed (Proteus Library)

| Component | Proteus Search Name |
|---|---|
| Microcontroller | `Arduino Uno` (or `SIMULINO UNO`) |
| Ultrasonic Sensor | `ULTRASONIC` (HC-SR04 model) |
| LEDs (x7) | `LED-RED` |
| Mini Servo Motor | `MOTOR-PWMSERVO` |
| Potentiometer (sensor bias, optional) | `POT-HG` |

---

## 1️⃣ Smart Zebra Crossing Circuit (Fig. 2)

**Purpose:** Detects a pedestrian and sequentially lights 7 red LEDs.

### Connections

| Component Pin | Arduino Uno Pin |
|---|---|
| Ultrasonic **Echo** | Digital Pin **13** |
| Ultrasonic **Trig** | Digital Pin **12** |
| Ultrasonic **VCC** | **5V** |
| Ultrasonic **GND** | **GND** |
| LED 1 | Digital Pin **2** |
| LED 2 | Digital Pin **3** |
| LED 3 | Digital Pin **4** |
| LED 4 | Digital Pin **5** |
| LED 5 | Digital Pin **6** |
| LED 6 | Digital Pin **7** |
| LED 7 | Digital Pin **8** |

### Build Steps in Proteus
1. Place an `Arduino Uno` and an `ULTRASONIC` sensor on the schematic sheet.
2. Wire Echo → Pin 13, Trig → Pin 12, VCC → 5V, GND → GND (as per table above).
3. Place 7 `LED-RED` components in a row (to mimic the embedded crossing lights).
4. Wire each LED's anode to its Arduino pin (2–8) through the Arduino's digital
   output, and each LED's cathode to GND.
5. Double-click the Arduino, load the compiled `.hex` from
   `Source Code/smart_zebra_crossing.ino` (Arduino IDE → Sketch → Export Compiled Binary).
6. Run the simulation — dragging the ultrasonic sensor's target object closer
   simulates "Crossing ON" (pedestrian detected); moving it away simulates
   "Crossing OFF" (standby).

---

## 2️⃣ Smart Speed Breaker Circuit (Fig. 6)

**Purpose:** Detects vehicle speed and raises/lowers a speed breaker via servo.

### Connections

| Component Pin | Arduino Uno Pin |
|---|---|
| Ultrasonic **Echo** | Digital Pin **6** |
| Ultrasonic **Trig** | Digital Pin **5** |
| Ultrasonic **VCC** | **5V** |
| Ultrasonic **GND** | **GND** |
| Servo **Signal (orange)** | Digital Pin **7** |
| Servo **GND (brown)** | **GND** |
| Servo **VCC (red)** | **5V / 3.3V** |

### Build Steps in Proteus
1. Place an `Arduino Uno`, an `ULTRASONIC` sensor, and a `MOTOR-PWMSERVO`
   (mini servo) on the schematic sheet.
2. Wire the ultrasonic sensor and servo exactly as per the table above.
3. Load the compiled `.hex` from `Source Code/smart_speed_breaker.ino` onto
   the Arduino.
4. Run the simulation — moving the sensor's target object to simulate a fast
   approach (>60 km/h equivalent distance change) should rotate the servo
   90° clockwise (breaker up) for 5 seconds, then back to 0° (breaker down).

---

## Reference Figures (from the research paper)

- **Fig. 1** — Flowchart of Smart Zebra Crossing
- **Fig. 2** — Circuit Diagram of Smart Zebra Crossing
- **Fig. 3(a)/(b)** — Simulation: Crossing OFF / Crossing ON
- **Fig. 5** — Flowchart of Smart Speed Breaking
- **Fig. 6** — Circuit Diagram of Smart Breaking System
- **Fig. 4(a)/(b)** — Simulation: Breaker OFF / Breaker ON

See `Documents/Research Paper 2 - Smart Infrastructure Zebra Crossing and Speed Breaking (IJRASET).pdf`
for the original diagrams these connections are based on.
