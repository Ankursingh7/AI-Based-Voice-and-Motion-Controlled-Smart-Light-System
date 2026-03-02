# AI-Based Voice and Motion Controlled Smart Light System (ESP32)

## 📌 Project Overview

This project implements an IoT-based smart lighting system using ESP32.  
The system automatically turns ON the light when motion is detected and also allows remote control via WiFi using HTTP requests.

It combines:
- Embedded Systems
- IoT Communication
- Sensor-based Automation
- Web-based Control

---

## 🎯 Features

- Motion detection using PIR sensor
- Automatic light ON when motion detected
- Auto OFF after 30 seconds of no motion
- WiFi-based remote control
- HTTP endpoints:
  - `/on` → Turn light ON
  - `/off` → Turn light OFF

---

## 🏗 System Architecture


PIR Sensor → ESP32 → Relay Module → Light
↓
WiFi Server
↓
Browser / HTTP Client


---

## 🛠 Hardware Requirements

- ESP32 Dev Module
- PIR Motion Sensor (HC-SR501)
- 1-Channel Relay Module
- Light Bulb
- Jumper Wires
- 5V Power Supply

---

## 🔌 Pin Configuration

| Component | ESP32 Pin |
|------------|------------|
| PIR OUT    | GPIO 14    |
| Relay IN   | GPIO 27    |

Pins can be changed inside `config.h`.

---

## 📂 Project Structure


AI-Based-Voice-and-Motion-Controlled-Smart-Light-System/
│
├── platformio.ini
├── README.md
│
├── include/
│ ├── config.h
│ ├── motion.h
│ ├── relay.h
│ └── wifi_server.h
│
├── src/
│ ├── main.cpp
│ ├── motion.cpp
│ ├── relay.cpp
│ └── wifi_server.cpp
│
├── lib/
└── test/


## 📁 File Descriptions

### platformio.ini
Defines:
- Target board (ESP32 Dev Module)
- Framework (Arduino)
- Build configuration

---

### include/config.h
Contains:
- Pin definitions
- WiFi credentials
- Central configuration file

---

### include/relay.h & src/relay.cpp
Handles:
- Relay initialization
- Turning light ON
- Turning light OFF

---

### include/motion.h & src/motion.cpp
Handles:
- PIR sensor initialization
- Motion detection logic
- Auto OFF timing (30 seconds)

---

### include/wifi_server.h & src/wifi_server.cpp
Handles:
- WiFi connection
- HTTP server
- Parsing `/on` and `/off` requests

---

### src/main.cpp
Main control loop:
- Initializes modules
- Continuously checks:
  - Motion detection
  - WiFi requests

Acts as the system controller.

---

## 🌐 How to Use

1. Update WiFi credentials in `config.h`
2. Upload code to ESP32 using PlatformIO
3. Open Serial Monitor (optional)
4. Find ESP32 IP address
5. In browser:


http://ESP32_IP/on
http://ESP32_IP/off


---

## ⚙️ How It Works

1. PIR detects motion → Relay turns ON
2. If no motion for 30 seconds → Relay turns OFF
3. If HTTP request `/on` received → Relay ON
4. If HTTP request `/off` received → Relay OFF

---

## 🚀 Future Improvements

- Add MQTT protocol
- Add mobile app dashboard
- Add Google Assistant integration
- Add energy consumption monitoring
- Add multiple room support
- Implement FreeRTOS task separation

---

## 🧠 Concepts Used

- Embedded C++
- GPIO Control
- HTTP Server (ESP32)
- Event-based Programming
- IoT Architecture Design

---

## 👨‍💻 Developed By
Ankur Singh
B.Tech CSE (AI & ML)
Section 2E

Rudraksha Sharma  
B.Tech CSE (AI & ML)  
Section 2E

Himanshu Yadav  
B.Tech CSE (AI & ML)  
Section 2E

---

## 📜 License

This project is developed for academic and educational purposes.
