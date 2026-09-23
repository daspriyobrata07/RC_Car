# 🏎️ IR Remote Controlled Arduino RC Car

A lightweight C++ project built in **PlatformIO** to control a 4WD chassis using an IR remote and L298N motor driver.

---

## 🔌 Pin Mapping

| Component | Pin Name | Arduino Pin |
| :--- | :--- | :--- |
| **IR Receiver** | Signal | **D2** |
| **L298N Driver** | IN1, IN2 | **D8, D9** (Left Motor) |
| **L298N Driver** | IN3, IN4 | **D10, D11** (Right Motor) |

---

## 🎮 IR Remote Commands

| Action | Hex Code |
| :--- | :--- |
| **Forward** | `0x46` |
| **Backward** | `0x15` |
| **Left** | `0x44` |
| **Right** | `0x43` |
| **Stop** | `0x40` |

---

## 📐 Circuit Diagram

![Circuit Diagram](schematic/circuit_diagram.png)

---

## 🚀 Quick Start (PlatformIO)

1. Clone repo: `git clone https://github.com/YOUR_USERNAME/RC_Car.git`
2. Open in **VS Code** with **PlatformIO**.
3. Build & Upload to your board.
4. Open **Serial Monitor** at `9600 baud` for debugging logs.