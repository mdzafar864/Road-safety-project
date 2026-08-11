# 🚦 Smart Zebra Crossing and Speed Breaker System

A B.Tech final year project (Electrical Engineering) that enhances road safety near high-risk zones — schools, hospitals, and pedestrian crossings — using an Arduino-based smart zebra crossing and a dynamic, speed-responsive speed breaker.

[![Platform](https://img.shields.io/badge/Platform-Arduino-00979D?logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Language](https://img.shields.io/badge/Language-C%2FC%2B%2B-blue)]()
[![Simulation](https://img.shields.io/badge/Simulation-Proteus-orange)]()
[![Published](https://img.shields.io/badge/Published-IJRASET%202024-brightgreen)](https://doi.org/10.22214/ijraset.2024.64865)
[![License](https://img.shields.io/badge/License-MIT-yellow)]()

---

## 📖 About the Project

Road traffic accidents claim roughly **1.3 million lives annually** worldwide, with over-speeding responsible for more than 70% of them. Traditional zebra crossings and static speed breakers are passive — they don't adapt to real conditions like low visibility or actual vehicle speed.

This project introduces two connected smart-infrastructure systems:

- **Smart Zebra Crossing** — Uses an ultrasonic sensor to detect pedestrians and sequentially illuminates embedded red LEDs, improving visibility for drivers, especially in low-light or poor-weather conditions.
- **Smart Speed Breaker** — Uses an ultrasonic sensor to estimate the speed of an approaching vehicle. If it exceeds a **60 km/h threshold**, a servo-actuated breaker rises for 5 seconds to force deceleration, then lowers automatically — unlike static breakers that disrupt all traffic regardless of speed.

Both systems are designed to integrate with a central traffic management network for real-time speed-limit adjustments and driver alerts.

This work has been published/presented at:
- 📄 *International Journal for Research in Applied Science & Engineering Technology (IJRASET)*, Vol. 12, Issue X, Oct 2024 — [DOI: 10.22214/ijraset.2024.64865](https://doi.org/10.22214/ijraset.2024.64865)
- 🎓 International Conference on Advances in Communication

## ✨ Features

- 🚶 Real-time pedestrian detection via ultrasonic sensing
- 💡 Sequential red LED illumination for high visibility, day or night
- 🚗 Speed-based automatic breaker activation (only triggers for speeding vehicles)
- ⚙️ Servo-controlled breaker mechanism using PWM for precise, smooth motion
- 🔁 Fully autonomous — no manual intervention needed
- 🏥 Designed for deployment in high-risk zones: schools, hospitals, sharp curves

## 🧰 Hardware Components Used

| Component | Purpose |
|---|---|
| Arduino UNO (ATmega328P) | Core microcontroller for sensing and control logic |
| Ultrasonic Sensor (HC-SR04) ×2 | Pedestrian detection (crossing) & vehicle speed estimation (breaker) |
| Red LEDs ×7 | Sequential visual alert system embedded in the crossing |
| Mini Servo Motor | Raises/lowers the physical speed breaker |
| Gear Motor | Torque-enhanced actuation support |

## 📁 Repository Structure

```
Road Safety Project - Smart Zebra Crossing and Speed Breaker/
├── Documents/
│   ├── Research Paper 1 - Development of Intelligent Zebra Crossings.pdf
│   ├── Research Paper 2 - Smart Infrastructure Zebra Crossing and Speed Breaking (IJRASET).pdf
│   ├── Certificate - IJRASET Publication.pdf
│   └── Certificate - International Conference on Advances in Communication.pdf
│
├── Source Code/
│   ├── smart_zebra_crossing.ino     # Pedestrian detection + sequential LED alert
│   └── smart_speed_breaker.ino      # Speed detection + servo-actuated breaker
│
├── Simulation Files/
│   └── PROTEUS_REBUILD_GUIDE.md     # Step-by-step guide to rebuild the Proteus circuit
│
└── README.md
```

> **Note on Simulation Files:** The original `.pdsprj` Proteus project files were
> lost. Since Proteus projects are a closed binary format, they can't be
> regenerated automatically — `PROTEUS_REBUILD_GUIDE.md` provides the exact
> component list and pin-by-pin wiring (from the paper's circuit diagrams) to
> recreate both simulations quickly.

## 🚀 Getting Started

### Prerequisites
- [Arduino IDE](https://www.arduino.cc/en/software)
- [Proteus Design Suite](https://www.labcenter.com/) (for circuit simulation)

### Running the Code
1. Open the desired sketch in `Source Code/` using the Arduino IDE.
2. Wire the hardware per the pin tables in `Simulation Files/PROTEUS_REBUILD_GUIDE.md`.
3. Upload the sketch to an Arduino UNO board.
4. Power on — the zebra crossing LEDs and/or speed breaker will respond automatically to sensor input.

### Running the Simulation
1. Open Proteus Design Suite.
2. Follow `Simulation Files/PROTEUS_REBUILD_GUIDE.md` to rebuild the circuit (takes a few minutes).
3. Load the corresponding compiled `.hex` file onto the virtual Arduino and run the simulation.

## 🔬 How It Works

**Smart Zebra Crossing**
1. Ultrasonic sensor continuously monitors for pedestrians near the crossing.
2. On detection, 7 embedded red LEDs light up **sequentially**, alerting drivers.
3. Once the pedestrian clears the crossing, the system reverts to standby.

**Smart Speed Breaker**
1. Ultrasonic sensor takes two distance readings a short time apart to estimate vehicle speed.
2. If speed exceeds **60 km/h**, the Arduino drives a servo motor to raise the breaker.
3. The breaker stays raised for **5 seconds**, then lowers automatically.
4. Vehicles within the speed limit pass without any obstruction.

## 🔮 Future Scope

- IoT integration for remote, real-time monitoring
- AI-based predictive analytics for adaptive traffic flow
- Vehicle-to-infrastructure (V2I) communication for advance speed-breaker alerts
- Central traffic management network integration for dynamic speed-limit control

## 👥 Team

Sujit Kumar, Deeba Ashique, Alka Choudhary, Md. Zafar
Government Engineering College, Banka, Bihar

## 📜 License

This project is intended for academic and educational purposes.
