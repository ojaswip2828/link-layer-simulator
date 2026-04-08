# 🚀 Link Layer Protocol Visualizer (Stop-and-Wait ARQ)

A graphical simulation of the Stop-and-Wait ARQ protocol built using C++ and SFML.  
This project visually demonstrates packet transmission, acknowledgment (ACK), packet loss, and retransmission at the link layer.

---

## 📌 Features

- 📡 Packet transmission from Sender to Receiver  
- 📩 ACK (Acknowledgment) mechanism  
- ❌ Packet loss simulation using randomness  
- 🔁 Automatic retransmission (Stop-and-Wait ARQ logic)  
- 🎥 Real-time graphical visualization using SFML  

---

## 🧠 Concept

Stop-and-Wait ARQ is a fundamental link-layer protocol used to ensure reliable data transmission.

Workflow:
1. Sender sends one packet  
2. Waits for ACK  
3. If ACK received → send next packet  
4. If packet lost → retransmit  

This project simulates the above process visually.

---

## 🛠 Tech Stack

- **C++**
- **SFML (Simple and Fast Multimedia Library)**
- **Object-Oriented Programming**
- **Computer Networks (Link Layer Concepts)**

---

## ▶️ How to Run

1. Install SFML  
2. Compile using:

```bash
g++ main.cpp -IC:/SFML/include -LC:/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -o app.exe

