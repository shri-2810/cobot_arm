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
- 1x Arduino Uno
- 3x SG90 Servo Motors
- 3x MG995 Servo Motors
- 1x HC-05/HC-06 Bluetooth Module
- 1x Supercapacitor **(suitable for low-power sensors)**
- Neodymium Magnets
- Standard Coil for Energy Harvesting
- Connecting Wires
- Power Supply **(for initial servo operation)**

### Mechanical
- Cobot Arm Frame (3D Printed)
- Mounting Brackets for Servo Motors
- Bearings and Screws
  
## Circuit Connections

### Bluetooth Module
| Component | Arduino Pin | 
|-----------|------------| 
| VCC | 5V | 
| GND | GND | 
| TX | RX (Arduino) | 
| RX | TX (Arduino) | 

### Servo Motors
| Component | Arduino Pin | Other Connections |
|-----------|------------|-------------------|
| Servo 1 Signal | D3 | Power to external 5V, GND to Arduino GND |
| Servo 2 Signal | D5 | Power to external 5V, GND to Arduino GND |
| Servo 3 Signal | D6 | Power to external 5V, GND to Arduino GND |
| Servo 4 Signal | D9 | Power to external 5V, GND to Arduino GND |
| Servo 5 Signal | D10 | Power to external 5V, GND to Arduino GND |
| Servo 6 Signal | D11 | Power to external 5V, GND to Arduino GND |

## Self-Energizing Circuit
The energy harvesting system consists of neodymium magnets attached to moving parts of the cobot arm. As the arm moves, the changing magnetic field induces voltage in a standard coil placed strategically near the motion path. The induced AC voltage is then rectified using a diode bridge and stored in a supercapacitor. The stored energy is used to power low-power sensors in the system.
- **Neodymium Magnet:** Fixed on moving parts of the cobot arm.
- **Standard Coil:** Placed near moving parts to capture electromagnetic energy.
- **Supercapacitor Storage:** Stores harvested energy for powering low-power sensors.

## Software Setup
1. Install the Arduino IDE.
2. Install the necessary libraries:
```cpp
#include <Servo.h>
```
3.Upload the Arduino code for Bluetooth control and servo operation
4.Use a mobile app like **"Arduino Bluetooth Controller"** to send commands.

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


