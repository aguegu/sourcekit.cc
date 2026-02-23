# Sourcekit® MeshMass TX6A4D

Version: 1.0.0

Designer: Weihong Guan [<span class="mdi mdi-github" style="color: #000;"></span>](https://github.com/aguegu/) [<span class="mdi mdi-twitter" style="color: #1da1f2;"></span>](https://twitter.com/BG5USN)

## Overview

Sourcekit® MeshMass TX6A4D is a programmable remote control transmitter module designed for RC enthusiasts, STEM education, and the 3D printing community. It is the first product in the MeshMass series of affordable, programmable RC solutions.

The TX6A4D features dual joysticks, rotary knobs, and programmable buttons, making it ideal for building custom remote control systems for toys, brick builds, and 3D printed vehicles.

![TX6A4D Controller](/images/MeshMass-TX6A4D/main.jpg)

## Features

- **Dual Joysticks**: Two dual-axis joysticks providing 4 analog input channels
- **Rotary Knobs**: 2 knobs for throttle, speed, or parameter adjustment
- **Programmable Buttons**: 4 shoulder buttons for custom functions
- **OLED Display Interface**: Supports 128x64 SPI OLED showing battery voltage and signal strength
- **Type-C Charging**: Built-in charging circuit for 1S LiPo battery
- **Antenna Options**: Onboard PCB antenna + IPEX-1 socket for external 2.4GHz antenna
- **Lost Connection Alarm**: Buzzer alerts when connection to receiver is lost
- **M2.5 Mounting**: 4 mounting holes for secure installation

## Specification

### Microcontroller

The TX6A4D is powered by the WCH CH571F microcontroller from Nanjing WCH. This chip provides the core processing and wireless communication capabilities.

| Component | Specification |
|-----------|---------------|
| MCU | WCH CH571F (part of CH57x series) |
| Architecture | 32-bit RISC-V (QingKe V3A core) |
| CPU Speed | 48 MHz (typical) |
| Memory | 32KB SRAM, 256KB Flash |
| Wireless | 2.4GHz proprietary protocol (raw PHY layer for minimum latency) |
| ADC | 12-bit, 8 channels (6 used for joysticks/knobs) |
| GPIO | Multiple configurable I/O pins |
| Peripherals | SPI, UART |

The CH571F's RISC-V architecture provides efficient processing while the integrated 2.4GHz radio enables reliable wireless communication. The TX6A4D utilizes the raw 2.4GHz physical layer for minimum latency in real-time control applications.

### Inputs

| Type | Count | Description |
|------|-------|-------------|
| Analog (ADC) | 6 | 4 from joysticks, 2 from knobs |
| Digital | 4 | 4 programmable shoulder buttons |
| System | 1 | Pairing button (firmware-controlled) |

### Power

| Specification | Value |
|---------------|-------|
| Battery | 1S LiPo (3.7V - 4.2V) |
| Battery Connector | PH2.0 |
| Charging | Type-C USB |
| **Warning** | Ensure correct battery polarity (+/-) or damage may occur |

### Physical

| Specification | Value |
|---------------|-------|
| Dimensions | 100mm x 50mm |
| Mounting | 4x M2.5 holes |
| Weight | TBD |

### Display & Feedback

| Component | Description |
|-----------|-------------|
| Screen Interface | SPI, supports 128x64 OLED |
| Display Shows | Battery voltage, signal strength |
| Buzzer | Lost connection alarm |

### Connectivity

| Feature | Description |
|---------|-------------|
| Wireless | 2.4GHz auto-hopping (BLE PHY layer only, no GATT) |
| Antenna | Onboard PCB antenna + IPEX-1 connector for external 2.4GHz antenna |
| Range | ~40 meters in open field (onboard PCB antennas), extends with external antenna |

## Programming

The TX6A4D is programmable via the [MeshMass online platform](https://meshmass.com). Users can:

- Map joystick axes, knobs, and buttons to output channels
- Create custom control mixing (e.g., tank steering, crane controls)
- Configure button behaviors for specific functions

Programming is done through a web browser using the MeshMass USB flashing dongle (sold separately). The CH571F runs pre-built firmware scaffolds that handle the low-level RF communication, while users focus on application-level input mapping logic.

> **Note**: The TX6A4D USB-C port is for charging only. Firmware flashing requires the separate USB dongle.

## System Architecture

The MeshMass system separates concerns between transmitter and receiver:

- **TX6A4D (Transmitter)**: Maps physical inputs (joysticks, knobs, buttons) to wireless channels
- **RX4M4S (Receiver)**: Maps received channels to physical outputs (motors, servos)

This abstraction allows users to focus on what matters for their specific build without worrying about RF protocol details.

## Applications

Sample applications and code templates are available on meshmass.com for:

- Construction vehicles (Forklift, Dump Truck, Excavator)
- RC cars and trucks
- Cranes and manipulators
- Custom 3D printed vehicles
- Small scale RC airplanes and drones
- Sandbox models and dioramas
- STEM education projects
- Custom robotics and automation

## Discussion and Show Cases

- [Forum (Powered by GitHub Discussion)](https://github.com/aguegu/sourcekit.cc/discussions)

## Where to Buy

Coming soon. Currently available in batch quantities (PCB only).

## Related Products

- [RX4M4S Receiver](/MeshMass-RX4M4S) - 4 DC Motor + 4 Servo receiver module
- USB Flashing Dongle - Browser-based programming tool (coming soon)
