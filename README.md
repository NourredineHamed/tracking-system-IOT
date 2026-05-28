# RFID Factory Traceability System Using ESP32 and Firebase

> 🏭 Industry 4.0 smart factory prototype for RFID-based product classification, real-time cloud logging, and live production monitoring.

---

## 1) Project Overview

This project is an **IoT embedded systems prototype** for factory traceability. It uses **two ESP32 microcontrollers** and **two PN532 RFID readers** to scan product tags on a production line and classify items as **GOOD** or **BAD**.

Each ESP32 sends RFID product data to **Firebase Realtime Database** over WiFi. A web dashboard provides live monitoring and traceability tools for industrial environments.

### 🎯 Objectives
- Automate product identification using RFID
- Classify products in real time (GOOD/BAD)
- Store production records in the cloud
- Enable instant traceability and monitoring

---

## 2) Features

- ✅ RFID product identification via PN532
- ✅ GOOD/BAD product classification
- ✅ Cloud storage using Firebase Realtime Database
- ✅ Real-time dashboard updates
- ✅ Product search by RFID UID
- ✅ Live production counters (GOOD/BAD)
- ✅ Inventory tracking and traceability history
- ✅ Industry 4.0 monitoring prototype

---

## 3) Hardware Components

| Component | Quantity | Purpose |
|---|---:|---|
| ESP32 Development Board | 2 | Main IoT controllers |
| PN532 RFID Module | 2 | RFID tag scanning |
| RFID Tags/Cards | Multiple | Product identifiers |
| Breadboard + Jumper Wires | As needed | Prototyping and wiring |
| USB Cables / Power Supply | 2 | ESP32 power and programming |

---

## 4) Software Technologies

| Technology | Role |
|---|---|
| Arduino IDE | Firmware development and flashing |
| C++ | ESP32 embedded programming |
| Firebase Realtime Database | Cloud data storage + sync |
| HTML | Dashboard structure |
| CSS | Dashboard styling |
| JavaScript | Dashboard logic + real-time UI updates |
| WiFi | ESP32-to-cloud communication |

---

## 5) System Architecture

### 🧩 Data Flow

**RFID Tag → PN532 → ESP32 → WiFi → Firebase → Dashboard**

```text
┌───────────┐    ┌────────┐    ┌────────┐    ┌──────┐    ┌──────────────────────┐    ┌───────────────────┐
│ RFID Tag  │ -> │ PN532  │ -> │ ESP32  │ -> │ WiFi │ -> │ Firebase Realtime DB │ -> │ Web Dashboard     │
└───────────┘    └────────┘    └────────┘    └──────┘    └──────────────────────┘    └───────────────────┘
                                                                                          GOOD/BAD counters
                                                                                          UID search
                                                                                          Traceability logs
```

### ⚙️ Multi-Node Layout

- **Node A (ESP32 + PN532):** scans line/station A and pushes events
- **Node B (ESP32 + PN532):** scans line/station B and pushes events
- **Cloud Layer (Firebase):** central real-time storage
- **Presentation Layer (Dashboard):** monitoring and analytics view

---

## 6) Installation

### Prerequisites

- Arduino IDE installed
- ESP32 board package installed in Arduino IDE
- PN532 library installed
- Firebase client library for ESP32 installed
- A Firebase project with Realtime Database enabled

### Clone the Repository

```bash
git clone https://github.com/your-username/your-repo-name.git
cd your-repo-name
```

### Install Arduino Libraries

In **Arduino IDE**:
1. Go to **Sketch → Include Library → Manage Libraries**
2. Install required libraries (examples):
   - `Adafruit PN532`
   - `WiFi` (ESP32 core)
   - `Firebase ESP Client` (or your chosen Firebase library)

---

## 7) Wiring

> 📌 Adjust pin mapping according to your exact ESP32 board and PN532 communication mode (SPI/I2C/UART).

### Example PN532 ↔ ESP32 (I2C mode)

| PN532 Pin | ESP32 Pin (Example) |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

If you are using **SPI** or **UART**, update both wiring and firmware pin configuration accordingly.

---

## 8) Firebase Setup

### 1. Create Firebase Project
- Go to [Firebase Console](https://console.firebase.google.com/)
- Create a new project

### 2. Enable Realtime Database
- Build → Realtime Database → Create Database
- Start in test mode (for development), then secure with rules later

### 3. Get Firebase Credentials
- Database URL (e.g., `https://your-project-id-default-rtdb.firebaseio.com/`)
- API key / auth details required by your Firebase client library

### 4. Configure Firmware
Update your ESP32 firmware settings:

```cpp
// WiFi credentials
const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

// Firebase credentials
#define FIREBASE_HOST "your-project-id-default-rtdb.firebaseio.com"
#define FIREBASE_API_KEY "YOUR_FIREBASE_API_KEY"
```

### 5. Suggested Database Structure

```json
{
  "products": {
    "UID_04A1B2C3": {
      "status": "GOOD",
      "station": "A",
      "timestamp": "2026-05-28T07:30:00Z"
    },
    "UID_0499D8E7": {
      "status": "BAD",
      "station": "B",
      "timestamp": "2026-05-28T07:31:12Z"
    }
  }
}
```

---

## 9) Running the Project

### Step 1: Upload Firmware to ESP32 Boards
- Connect each ESP32 via USB
- Select the correct board and COM port in Arduino IDE
- Upload firmware for Node A and Node B

### Step 2: Verify Serial Output
- Open Serial Monitor
- Confirm:
  - WiFi connection is successful
  - RFID tags are detected
  - Data is pushed to Firebase

### Step 3: Launch Dashboard
- Open dashboard files in your browser (or use a local server)
- Connect dashboard JavaScript to Firebase
- Validate:
  - Live GOOD/BAD counters update
  - UID search works
  - New scans appear in real time

---

## 10) Dashboard Preview

> 🖥️ Add screenshots/GIFs of your dashboard here for GitHub presentation.

Suggested assets:
- `docs/dashboard-overview.png`
- `docs/live-counters.png`
- `docs/uid-search.png`

Example markdown:

```md
![Dashboard Overview](docs/dashboard-overview.png)
![Live Counters](docs/live-counters.png)
![UID Search](docs/uid-search.png)
```

---

## 11) Future Improvements

- 🚀 Add role-based authentication for dashboard access
- 🚀 Implement secure Firebase rules for production
- 🚀 Add anomaly detection and alerts for BAD spikes
- 🚀 Export reports (CSV/PDF) for quality teams
- 🚀 Integrate MQTT/OPC-UA for industrial interoperability
- 🚀 Build a mobile monitoring companion app

---

## 12) Author

**Nouri**  
Embedded Systems & IoT Developer

---

## 📄 License

This project is intended for educational and prototyping purposes.  
Add your preferred open-source license (e.g., MIT) if publishing publicly.

