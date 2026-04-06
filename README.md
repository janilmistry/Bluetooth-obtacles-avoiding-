# 🤖 Bluetooth Obstacle Avoiding Robot

An intelligent 4-wheel drive robot that uses an ultrasonic sensor and servo motor to detect and navigate around obstacles. This version includes visual (LED) and audible (Buzzer) alerts.

## ✨ New Features
* **Modular Configuration:** Easily change motor pins and distances at the top of the code.
* **Proximity Alerts:** Integrated Buzzer and LED feedback when an obstacle is detected.
* **Smart Navigation:** Scans Left and Right using a Servo to find the clearest path.

## 🛠️ Hardware Components
* **Microcontroller:** Arduino Uno
* **Motor Driver:** L298N H-Bridge
* **Sensor:** HC-SR04 Ultrasonic Sensor
* **Actuators:** 4x TT Gear Motors, 1x MG90S Servo
* **Alerts:** 1x LED, 1x Active Buzzer
* **Power:** 2x 18650 Li-ion Batteries

## 🔌 Updated Wiring
| Component | Pin |
| :--- | :--- |
| **Ultrasonic Trig** | A1 |
| **Ultrasonic Echo** | A2 |
| **Servo Signal** | 11 |
| **Buzzer (+)** | 12 |
| **LED** | 13 |
| **Motor Driver (L/R)** | 2, 3, 4, 5 |

## 🚀 Installation
1. Download the `NewPing` library provided in the repo.
2. Open `code.ino` in Arduino IDE.
3. Adjust `speedSet` or `safeDistance` in the **Configuration Section** if needed.
4. Upload and enjoy!

---
*Developed by [Janil Mistry](https://github.com/janilmistry) - GPA Ahmedabad.*
