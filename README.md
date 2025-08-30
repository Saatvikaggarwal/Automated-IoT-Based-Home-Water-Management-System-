# Smart Water Tank Filling System with Remote Monitoring 🚰

A microcontroller-based project that automates water tank filling, monitors water quality, and enables **remote monitoring via Bluetooth**.  
The system is built around **Arduino Uno**, sensors, and a mobile app to reduce wastage, ensure safe water, and make water management easier.

---

## 📌 Features
- ✅ Automatic pump control based on tank level  
- ✅ Real-time water level and turbidity monitoring  
- ✅ LCD display for local feedback  
- ✅ Remote monitoring via Bluetooth mobile app  
- ✅ Reduced water wastage and energy efficiency  

---

## 🏗️ System Architecture
- **Arduino Uno** – Central processing unit  
- **Water Level Sensor** – Detects fill level  
- **Turbidity Sensor** – Monitors water quality  
- **Water Flow Sensor** – Measures supply flow  
- **Relay Module** – Controls water pump  
- **LCD Display** – Local real-time status  
- **Bluetooth Module (HC-05)** – Enables remote monitoring  

---

## ⚙️ Working Principle
1. Sensors collect water level, flow, and quality data.  
2. Arduino processes the data and decides pump ON/OFF.  
3. Relay switches pump accordingly.  
4. LCD shows current status locally.  
5. Mobile app (via Bluetooth) displays tank status and alerts.  

---

## 🖥️ Software Implementation
- **Arduino IDE** (C/C++) for microcontroller logic  
- **Decision Algorithm**  
  - IF tank level < threshold → Pump **ON**  
  - IF tank full → Pump **OFF**  
  - IF turbidity > safe limit → Warning alert  
- **Mobile App (Bluetooth-based)**  
  - Displays tank water level  
  - Shows pump status  
  - Notifies water quality alerts  

---

## 🔧 Hardware Components
- Arduino Uno  
- Water Level Sensor  
- Turbidity Sensor  
- Water Flow Sensor  
- Relay Module  
- LCD Display  
- Bluetooth HC-05 Module  
- Water Pump  

---

## 🧪 Testing & Validation
- Tank tested under multiple capacities  
- Turbidity sensor verified with water samples  
- Bluetooth stable within ~10m range  
- Pump tested under continuous usage  

---

## ⚡ Challenges & Solutions
- **Sensor calibration issues** → Calibrated manually with noise filtering  
- **Bluetooth range limitation** → Used HC-05 with antenna  
- **Relay overheating** → Upgraded to high-current relay with heat sink  

---

## 🚀 Future Enhancements
- IoT Cloud integration for **global monitoring**  
- Solar-powered pump for **sustainability**  
- Mobile app with **analytics & usage trends**  
- AI-based **water consumption prediction**  

# 💧 Smart Water Tank Filling System with Remote Monitoring  

## 📖 Introduction  
The **Smart Water Tank Filling System** is designed to automate the water tank filling process while providing real-time monitoring of water level, flow, and quality. The system uses Arduino as the central controller, multiple sensors for data collection, and Bluetooth for remote communication.  

---

## 🎯 Objectives  
- Automate water filling process using Arduino and sensors  
- Ensure water quality monitoring with turbidity detection  
- Provide real-time status updates via LCD display and mobile app  
- Enhance convenience and efficiency in water management  

---

## ⚙️ System Architecture  
1. **Arduino Uno** as the central controller  
2. **Sensors** (Water Level, Turbidity, Water Flow) for data collection  
3. **Relay Module** to control the water pump  
4. **LCD Display** for real-time monitoring  
5. **Bluetooth Module** for smartphone communication  

---

## 📡 Hardware Description  

### 1. Arduino Uno (Central Controller)  
- Microcontroller board based on ATmega328P  
- **Specs:** 5V operating voltage, 16 MHz clock, 14 Digital I/O, 6 Analog inputs  
- **Role:** Collects sensor data, processes logic, and controls pump + Bluetooth  

---

### 2. Water Level Sensor  
- Detects tank water levels using probes  
- **Specs:** Analog output, low power, multi-level detection  
- **Role:** Turns pump **ON** when water is low, **OFF** when full  

---

### 3. Turbidity Sensor  
- Monitors water quality by measuring clarity  
- **Specs:** IR LED + photodiode, 5V, analog output  
- **Role:** Alerts user if water quality is poor  

---

### 4. Water Flow Sensor  
- Measures rate of water inflow using Hall-effect sensor  
- **Specs:** 5–24V, 1–30 L/min, pulse output  
- **Role:** Detects water supply and calculates usage  

---

### 5. Relay Module  
- Electronic switch for high-voltage devices  
- **Specs:** 5V control signal, supports AC up to 250V  
- **Role:** Safely switches pump ON/OFF  

---

### 6. LCD Display (16x2 / 20x4)  
- Displays water tank status and alerts  
- **Specs:** Alphanumeric (16x2 or 20x4), optional I2C interface  
- **Role:** Shows *“Tank Filling”, “Tank Full”, “Low Quality Water”*  

---

### 7. Bluetooth Module (HC-05 / HC-06)  
- Enables wireless smartphone connection  
- **Specs:** UART interface, ~10m range, AT command support  
- **Role:** Remote monitoring and control via mobile app  

---

## 📊 Hardware Summary Table  

| Component        | Function                  | Key Specs                        | Role in System                          |
|------------------|---------------------------|----------------------------------|-----------------------------------------|
| **Arduino Uno**  | Central microcontroller   | 5V, 16 MHz, 14 I/O pins          | Brain of system                          |
| **Water Level Sensor** | Detects tank levels | Analog output, multi-level detect | Controls pump ON/OFF                     |
| **Turbidity Sensor**   | Checks water quality | IR-based, 5V, analog output       | Alerts on dirty water                    |
| **Water Flow Sensor**  | Measures flow rate   | 5–24V, 1–30 L/min, pulse output  | Tracks water supply                      |
| **Relay Module** | Switch for pump           | 5V control, 250V AC support       | Operates pump safely                     |
| **LCD Display**  | Visual status             | 16x2 / 20x4 chars, I2C compatible| Displays water level, quality, pump state|
| **Bluetooth Module** | Wireless comms        | HC-05/06, UART, ~10m range       | Mobile app monitoring                    |

---

## 🔮 Future Enhancements  
- Add **IoT Cloud integration** (Blynk, Firebase, or ThingsBoard)  
- SMS/Push notifications for water quality alerts  
- Solar-powered pump system for sustainability  
- AI-based predictive filling based on usage patterns  

---

## 📷 Media (To Add)  
- `images/circuit-diagram.png` → Circuit Diagram  
- `images/hardware-setup.png` → Prototype Setup  
- `images/app-ui.png` → Mobile App Screenshot  

---

## 📚 References  
- Arduino Documentation: [https://www.arduino.cc/](https://www.arduino.cc/)  
- Sensor Datasheets (Turbidity, Water Flow, Water Level)  
- IoT and Smart Water Management Research Papers  

---
