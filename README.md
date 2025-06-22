# Gas Leakage Detection and Auto Regulator Control System

## 📄 Project Overview

This project uses an MQ-2 gas sensor to detect gas leakage in environments like kitchens. When gas leakage is detected:

* The fan turns on to reduce gas concentration.
* A buzzer sounds an alert.
* A servo motor rotates to automatically turn off the gas regulator.

This system helps prevent accidents by taking action at the right time.

---

## 🧠 Project Algorithm

1. Initialize all hardware (sensor, fan, servo, buzzer).
2. Continuously read the analog value from MQ-2 gas sensor.
3. If gas value exceeds a defined threshold:

   * Turn on the fan
   * Activate the buzzer
   * Rotate the servo to shut the gas regulator
4. If gas level is normal:

   * Turn off the fan and buzzer
   * Reset the servo to open regulator position
5. Loop the process every 500 milliseconds.

---

## 🔌 Final Circuit Connection

### 1. MQ-2 Sensor:

* VCC → Arduino 5V
* GND → Arduino GND
* AOUT → Arduino A0

### 2. Passive Buzzer:

* +ve → Arduino D7
* –ve → Arduino GND

### 3. Servo Motor (SG90):

* Red → External 5V (or Arduino 5V if single servo)
* Brown → Arduino GND
* Orange (Signal) → Arduino D9

### 4. Fan:

* +ve → Arduino D8
* –ve → Arduino GND

---

## 🔧 Hardware Requirements

| Component                 | Quantity  |
| ------------------------- | --------- |
| Arduino Uno               | 1         |
| MQ-2 Gas Sensor           | 1         |
| SG90 Servo Motor          | 1         |
| Passive Buzzer            | 1         |
| 5V Mini Fan               | 1         |
| Breadboard & Jumper Wires | As needed |

---

## 💻 Software Tools

* Arduino IDE
* USB Driver for Arduino Board
* Serial Monitor (for testing)

---

## 🔑 Key Features

* Real-time gas monitoring
* Automatic regulator shut-off
* Buzzer alarm system
* Automatic fan activation
* Simple and compact safety system

---

## ➕ Optional Features to Add

* LCD display to show gas values and system status
* IoT Notification (via NodeMCU/ESP8266)
* SMS alerts using GSM module
* Mobile app monitoring system
* LED indicators for visual alerts

---

## 🏁 Conclusion

This project is a low-cost, real-life safety system ideal for preventing gas leak accidents in homes and small businesses. It can be enhanced further by integrating with smart home or IoT platforms for remote monitoring and control.
