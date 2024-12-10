# ESP Bluetooth Movement Controller 🚀

Welcome to the *ESP Bluetooth Movement Controller! This project seamlessly integrates an **ESP microcontroller* with *Bluetooth communication* and an *Android app* to create an intuitive movement control system. This project provides an easy-to-use and flexible solution for wireless control. 🎮📱

---

## 🌟 Features

- *Bluetooth Communication*: Smooth and real-time connection between the ESP and Android app.
- *Customizable Controls*: Configure and map controls in the app to your specific use case.
- *Multi-Axis Movement*: Support for controlling devices along multiple axes.
- *Responsive Feedback*: Get live updates on device status directly in the app.
- *Expandable Design*: Add new sensors, features, or control modes with ease.

---

## 🛠 Getting Started

### Requirements

1. *ESP32 Microcontroller*
   - *Description*: The ESP32 serves as the brain of your car, handling Bluetooth communication with the Android app and processing control signals for the motors.  
   - *Link*: [ESP32](https://www.sigmanortec.ro/placa-dezvoltare-esp32-cu-wifi-si-bluetooth)  

2. *Arduino Nano*
   - **Description**: This microcontroller can assist the ESP32 by offloading tasks, such as motor control or sensor data processing.  
   - **Link**: [Arduino Nano](https://store.arduino.cc/en-ro/products/arduino-nano)  

3. *L298N Motor Driver*  
   - **Description**: A dual H-bridge motor driver that allows you to control the speed and direction of up to four DC motors.  
   - **Link**: [L298N](https://components101.com/modules/l293n-motor-driver-module)  

4. *DC Motors with Wheels* (x4)  
   - *Description*: Standard DC motors paired with wheels for propelling your car forward, backward, and turning.  
   - *Link*: [DC Motors](https://www.wiltronics.com.au/product/10137/yellow-motor-3-12vdc-2-flats-shaft/)  

5. *4x AAA Batteries*  
   - *Description*: The primary power source for the motors or the entire system. A battery holder ensures secure connections.  

- *Software*:
  - Arduino IDE (for ESP firmware)
  - Android Studio (for customizing the app)

---

### Usage
1. *Pair the ESP device*:
   - Enable Bluetooth on your Android device.
   - Pair with the ESP32/ESP8266 module.
2. *Connect via the app*:
   - Open the Android app.
   - Select your ESP device from the list of available connections.
3. *Control the movement*:
   - Use the app's joystick or button controls to send commands to your device.

---

## 🤖 Customization

### ESP Firmware
- Update config.h to adjust pin mappings and movement logic.

### Android App
- Modify UI and functionality in the AndroidApp/ directory using Android Studio.

---
