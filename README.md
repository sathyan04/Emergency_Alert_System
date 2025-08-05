# Emergency Alert System for Visually Impaired and Loss of Hearing People

[![Published in IEEE](https://img.shields.io/badge/IEEE-Published-blue)](https://ieeexplore.ieee.org/document/10962765)

## Overview

This project presents a low-cost, wireless **Emergency Alert System** tailored for visually and hearing-impaired individuals using **ESP32 microcontrollers** and the **ESP-NOW protocol**. Designed for immediate response, it delivers alerts via **vibration** (for the visually impaired) and **buzzer** (for the hearing impaired), triggered through a simple push-button interface.

This project was successfully published in the **IEEE Xplore Digital Library** at the 2024 ICICCS Conference.

## Key Features

- One-button emergency alert activation
- Wireless communication using ESP-NOW (peer-to-peer, no Wi-Fi needed)
- Dual-alert mechanism:
  - Vibration for visually impaired users
  - Buzzer for hearing impaired users
- MAC address scanning for dynamic pairing
- Compact and cost-effective hardware design

## Technologies Used

- ESP32 Microcontroller
- Arduino IDE
- ESP-NOW Protocol
- Buzzer
- Vibration Motor
- Push Button
- Breadboard and Jumper Wires

## How It Works

1. **MAC Address Setup**: Use `MAC_CODE.ino` to get each ESP32’s MAC address.
2. **Transmitter (TX)**:
   - Waits for button press
   - Sends alert wirelessly using ESP-NOW
3. **Receiver (RX)**:
   - Receives signal
   - Triggers both buzzer and vibration motor

## Applications

- Smart alert systems in public spaces
- Personal emergency devices for the differently-abled
- School/college/home safety assist systems

## Visuals

| Circuit Diagram | Physical Setup |
|-----------------|----------------|
| ![Circuit Diagram](docs/images/circuit_diagram.png) | ![Setup Photo](docs/images/setup_photo.jpg) |

## Publication

This project was published at the **2024 5th International Conference on Intelligent Computing and Control Systems (ICICCS)**.

- **IEEE Paper**: [Emergency Alert System for Visually and Loss of Hearing People](https://ieeexplore.ieee.org/document/10962765)
- **DOI**: [10.1109/ICICV57966.2024.10962765](https://doi.org/10.1109/ESIC64052.2025.10962765)

### Citation (BibTeX)

```bibtex
@inproceedings{sathyan2024emergency,
  title={Emergency Alert System for Visually and Hearing Impaired Users},
  author={Sathyan, S. S. and [Your Co-authors]},
  booktitle={2024 5th International Conference on Intelligent Computing and Control Systems (ICICCS)},
  year={2024},
  organization={IEEE},
  doi={10.1109/ICICV57966.2024.10962765}
}
