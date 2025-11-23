
# 🎧 Audio Source Localization Robot (ESP32 + DSP)

A **real-time audio localization robot** that detects and turns toward the direction of a sound source using **Digital Signal Processing (DSP)** techniques on an **ESP32 microcontroller**.

---

## 📘 Project Overview

This project implements an **Audio Source Localization Robot** using a **stereo I2S microphone array** and the **GCC-PHAT (Generalized Cross-Correlation with Phase Transform)** algorithm to estimate the **Time Difference of Arrival (TDOA)** between two audio signals.

By computing the sound direction in real time, the robot can physically rotate toward the detected sound source. The project demonstrates an integration of **real-time audio processing**, **signal filtering**, **cross-correlation**, and **motor control** on an embedded platform.

---

## ⚙️ System Architecture

**Core Components**

* **Microcontroller:** ESP32 Dev Kit (Dual-core, Floating-point unit)
* **Microphones:** INMP441 or compatible stereo I2S microphones
* **Motor Driver:** L298N dual H-bridge driver
* **Robot Base:** Two-wheel differential drive chassis

**Signal Processing Pipeline**

1. **I2S Audio Acquisition** – 24-bit stereo sampling at 44.1 kHz
2. **FIR Bandpass Filtering** – Removes noise and isolates target frequencies
3. **FFT and GCC-PHAT** – Calculates cross-correlation to find TDOA
4. **Angle Estimation** – Determines sound direction from time delay
5. **Motor Control** – Adjusts robot orientation accordingly

---

## 🧠 DSP Methodology

| Technique               | Description                        | Role in Project                      |
| ----------------------- | ---------------------------------- | ------------------------------------ |
| **FIR Bandpass Filter** | Removes out-of-band noise          | Pre-processing of microphone signals |
| **FFT / IFFT**          | Frequency-domain transformation    | Efficient filtering and correlation  |
| **GCC-PHAT**            | Normalized cross-correlation       | Robust estimation of TDOA            |
| **TDOA Estimation**     | Time difference of signal arrivals | Determines sound source direction    |

---

## 💻 Software Details

* Developed in **C++** using **PlatformIO** with the **Arduino framework**.

* Modular source structure:

  ```
  ├── include/
  │   ├── config.h
  │   ├── fir.h
  │   ├── tdoa.h
  │   ├── motor.h
  │   └── fft.h
  ├── src/
  │   ├── main.cpp
  │   ├── fir.cpp
  │   ├── tdoa.cpp
  │   ├── motor.cpp
  │   └── fft.cpp
  └── platformio.ini
  ```

* **Main Loop Functions:**

  1. Read I2S audio samples.
  2. Apply FIR filter to left and right channels.
  3. Compute TDOA via GCC-PHAT.
  4. Move robot toward detected direction.

---

## 🔧 Hardware Connections

| Component   | ESP32 Pin   |
| ----------- | ----------- |
| I2S WS      | GPIO 15     |
| I2S SD      | GPIO 13     |
| I2S SCK     | GPIO 2      |
| Motor1      | GPIO 25, 26 |
| Motor2      | GPIO 32, 33 |
| Enable Pins | GPIO 22, 23 |

---

## 🚀 How to Run

1. **Install Requirements**

   * [PlatformIO IDE](https://platformio.org/install)
   * Arduino-compatible ESP32 board package

2. **Clone the Repository**

   ```bash
   git clone https://github.com/alanfellerv/Audio-Source-Localisationbot
   cd Audio-Source-Localisationbot
   ```

3. **Build and Upload**

   ```bash
   pio run --target upload
   ```

4. **Run the Robot**

   * Power the ESP32 and robot chassis.
   * Clap or make a sound — the robot turns toward it!

---
