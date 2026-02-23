# Sourcekit® MeshMass RX4M4S

Version: 1.0.0

Designer: Weihong Guan [<span class="mdi mdi-github" style="color: #000;"></span>](https://github.com/aguegu/) [<span class="mdi mdi-twitter" style="color: #1da1f2;"></span>](https://twitter.com/BG5USN)

## Overview

Sourcekit® MeshMass RX4M4S is a programmable receiver module designed for RC applications. It is the companion receiver to the TX6A4D transmitter, forming a complete programmable RC control system.

The RX4M4S provides 4 DC motor outputs and 4 servo outputs, making it ideal for controlling complex vehicles like construction equipment, RC cars, cranes, and custom 3D printed builds.

## Features

- **4 DC Motor Outputs**: For brushed DC motor control
- **4 Servo Outputs**: Standard servo PWM outputs (compatible with 9g servos and more)
- **Programmable Channel Mapping**: Map any input channel to any output
- **Mixing Support**: Combine multiple channels for complex behaviors (tank steering, crane controls)
- **Low Latency**: 2.4GHz proprietary protocol optimized for real-time control
- **Compact Design**: Easy to integrate into custom builds

## Specification

### Microcontroller

| Component | Specification |
|-----------|---------------|
| MCU | WCH CH571F |
| Architecture | RISC-V with BLE |
| Wireless | 2.4GHz proprietary protocol (raw PHY layer for minimum latency) |

### Outputs

| Type | Count | Description |
|------|-------|-------------|
| DC Motor | 4 | Brushed DC motor driver outputs |
| Servo | 4 | Standard PWM servo outputs (5V) |

### Power

| Specification | Value |
|---------------|-------|
| Input Voltage | TBD |
| Motor Output | TBD |
| Servo Output | 5V |

### Physical

| Specification | Value |
|---------------|-------|
| Dimensions | TBD |
| Mounting | TBD |
| Weight | TBD |

### Connectivity

| Feature | Description |
|---------|-------------|
| Wireless | 2.4GHz auto-hopping (BLE PHY layer only, no GATT) |
| Protocol | Proprietary low-latency RC protocol |
| Pairing | Bind with TX6A4D via pairing procedure |

## Programming

The RX4M4S is programmable via the [MeshMass online platform](https://meshmass.com). Users can:

- Map input channels to motor and servo outputs
- Create mixing functions (e.g., differential steering, crane articulation)
- Configure motor direction and speed curves
- Set servo travel limits and center points

Programming is done through a web browser using the MeshMass USB flashing dongle (sold separately).

## System Architecture

The MeshMass system separates concerns between transmitter and receiver:

- **TX6A4D (Transmitter)**: Maps physical inputs (joysticks, knobs, buttons) to wireless channels
- **RX4M4S (Receiver)**: Maps received channels to physical outputs (motors, servos)

This abstraction allows users to focus on what matters for their specific build without worrying about RF protocol details.

### Typical Signal Flow

```
TX6A4D Joystick → Wireless Channel 1 → RX4M4S Motor 1
TX6A4D Joystick → Wireless Channel 2 → RX4M4S Motor 2
TX6A4D Knob → Wireless Channel 3 → RX4M4S Servo 1
TX6A4D Button → Wireless Channel 4 → RX4M4S Servo 2
```

All mappings are configurable through meshmass.com.

## Applications

Sample applications and code templates are available on meshmass.com for:

- **Forklift**: 3 N20 motors + 1 9g servo
- **Dump Truck**: 1 370 motor + 1 N20 motor + 1 servo
- **Excavator**: Multiple servos and motors for articulated control
- Custom RC vehicles

## Pairing

The RX4M4S must be paired with a TX6A4D transmitter before use. The pairing process is handled by firmware on both devices.

> TODO: Add detailed pairing procedure

## Discussion and Show Cases

- [Forum (Powered by GitHub Discussion)](https://github.com/aguegu/sourcekit.cc/discussions)

## Where to Buy

Coming soon. Currently available in batch quantities (PCB only).

## Related Products

- [TX6A4D Transmitter](/MeshMass-TX6A4D) - Dual joystick transmitter module
- USB Flashing Dongle - Browser-based programming tool (coming soon)
