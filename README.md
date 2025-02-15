# Cobot Arm using Arduino Uno

## Overview
This project is a collaborative robotic arm (cobot) controlled using an Arduino Uno and servo motors. The arm operates via a mobile device using Bluetooth communication. It is self-energizing, incorporating neodymium magnets on moving parts to generate energy via standard coils, which is then stored in supercapacitors to power low-power sensors.

## Features
- **Arduino Uno-based Control**: The central microcontroller for processing commands.
- **Servo Motor Actuation**: Uses 3 SG90 and 3 MG995 servos for precise movement.
- **Bluetooth Control**: Enables wireless operation through a mobile app.
- **Self-Energizing System**: Neodymium magnets and standard coils generate energy.
- **Supercapacitor Storage**: Stores generated energy for low-power sensors.

## Components Required

### Electronics
- **1x Arduino Uno**
- **3x SG90 Servo Motors**
- **3x MG995 Servo Motors**
- **1x HC-05/HC-06 Bluetooth Module**
- **1x Supercapacitor (suitable for low-power sensors)**
- **Neodymium Magnets**
- **Standard Coil for Energy Harvesting**
- **Connecting Wires**
- **Power Supply (for initial servo operation)**

### Mechanical
- **Cobot Arm Frame** (3D Printed)
- **Mounting Brackets for Servo Motors**
- **Bearings and Screws**

## Circuit Connection
### Connect the HC-05 Bluetooth module:
- **VCC** → 5V (Arduino)
- **GND** → GND
- **TX** → RX (Arduino)
- **RX** → TX (Arduino)

### Connect the servo motors:
- **Power (Red)** → External 5V supply
- **Ground (Black/Brown)** → GND
- **Signal (Orange/Yellow)** → Arduino PWM Pins (e.g., D3, D5, D6, D9, D10, D11)

### Connect Energy Harvesting Circuit:
1. **Neodymium magnet oscillates near a coil** to induce voltage.
2. **Rectifier circuit conditions the output.**
3. **Output stored in the supercapacitor.**
4. **Low-power sensors connected to the supercapacitor circuit for power.**

## Software Setup
### Install the Arduino IDE.
### Install the necessary libraries:
```cpp
#include <Servo.h>
```

### Upload the Arduino code for Bluetooth control and servo operation

### Use a mobile app like **"Arduino Bluetooth Controller"** to send commands.

## Installation and Usage
1. **Clone this repository:**
   ```sh
   git clone https://github.com/yourusername/cobot-arm.git
   cd cobot-arm
   ```
2. **Upload the provided Arduino code** to your Arduino Uno.
3. **Follow the circuit diagram** and assemble the components.
4. **Pair your mobile device** with the HC-05/HC-06 module and use the app to control the arm.

## Future Enhancements
- Implement **Machine Learning for Gesture-based Control**.
- Improve **Power Storage using Advanced Capacitors**.
- Integrate **IoT Connectivity for Remote Access**.

## License
This project is open-source. Feel free to modify and share!


