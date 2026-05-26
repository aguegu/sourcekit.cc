# MeshMass Mini Tank Starter Kit

Version: 1.0.0

## Overview

The Mini Tank Starter Kit is a beginner-friendly, 3D-printable tank **chassis** kit designed specifically for the MeshMass RX4M4S receiver. It combines the TX6A4D transmitter and RX4M4S receiver to create a complete programmable RC tank chassis experience.

This is a **starter kit** with a minimum setup:
- **2 motors** for differential track drive (one motor per side)
- No turret - tracks and forward/reverse only
- Upgrade paths available for adding servos and more

**Turret Expansion:** The chassis is designed to be extended with custom turrets. Popular community designs include:
- Cannon
- Crane
- Forklift
- Crawler arm
- And more...

## Concept Coverage

This kit covers fundamental concepts through hands-on practice:

**Sessions:**
- Session 1: Get Running First! (no programming)
- Session 2: Code Your Tank

**Concepts:**
- Mechanical Basics - Tank tracks, gear reduction, steering
- Electronics Basics - Voltage, current, DC motors, PWM
- Digital Logic - Binary, bytes, communication protocols
- 3D Printing Basics - Layer manufacturing, model sources
- C Programming Introduction - Variables, functions, control flow

## Session 1: Get Running First! (2 Hours)

No programming required - firmware is pre-flashed. Just assemble and play!

### Step 1: Power Up - Electronics Basics

Learn about batteries and motors:

**1.1 Battery Introduction**

**1.1.1 Battery is Everywhere**
- What do smartphones, remote controls, electric cars, submarines, and the International Space Station have in common?
- They all need portable power - and batteries make it possible!
- **Electric cars** - thousands of batteries working together to power a vehicle
- **Submarines** - batteries let them operate underwater without surfacing
- **Satellites** - solar panels charge batteries that power everything in space
- **Your remote control** - just two small batteries make it work!
- Our kit uses rechargeable LiPo (Lithium Polymer) batteries - the same type used in drones and action cameras

**1.1.2 Positive and Negative Terminals**

Think of a battery like a water tower:
- The **positive terminal (+)** is like the top of the tower - water wants to flow OUT from here
- The **negative terminal (-)** is like the bottom - water wants to flow IN here
- Electricity works the same way - electrons (tiny particles!) want to flow from + to -

**Fun fact:** Lightning is nature's way of moving electrons from clouds (positive) to the ground (negative)!

**⚠️ Short Circuit = Danger!**

What happens if you connect a wire directly from + to -?
- It's like removing ALL the pipes between a water tower's top and bottom
- Water rushes out so fast that the tower can burst!
- Electricity: the battery drains instantly, gets VERY hot, and can cause burns or fire

**Safety Rules:**
1. Never put metal (coins, keys, screwdrivers) across battery terminals
2. Always be careful when connecting battery packs
3. "Red is +, Black is -" - remember this when wiring!

**⚠️ Warning for Teachers:** Household sockets have 110V AC (USA) or 220V AC (China/Europe) - this is DANGEROUS for kids! Never let children touch wall sockets. Our kit uses safe low voltages (3.7V-7.4V).

**1.1.3 What is Voltage?**

Think of voltage like **water pressure** in pipes:

- More pressure = water pushes harder = more flow
- More voltage = electrons push harder = more power

**Analogy Time!**
- A tiny battery (1.5V AA) = garden hose spray - gentle
- A bigger battery (3.7V LiPo) = pressure washer - much stronger!
- A car battery (12V) = fire hose - super powerful!

**Our Kit Uses:**
- TX6A4D transmitter: **1S LiPo = 3.7V** (small, lightweight)
- RX4M4S receiver: **2S LiPo = 7.4V** (stronger for motors!)
- Why motors need more voltage: they need more "push" to spin

> **💡 Tip for Teachers:** A digital multimeter ($10-20) is a great investment for the classroom! You can:
> - Measure battery voltage to confirm it's charged (3.7V per cell = full, below 3.5V = needs charging)
> - Show students how voltage adds up when batteries are connected in series
> - Test that circuits are working correctly

**1.1.4 Series Circuit**
- When batteries are connected in series, voltages add up
- 1S + 1S = 2S (3.7V + 3.7V = 7.4V)
- TX6A4D uses 1S (3.7V) - small battery
- RX4M4S uses 2S (7.4V) - bigger battery for motors

**1.2 DC Motor Introduction**

**What is a Motor?**
- A motor is the opposite of a battery!
- Battery: **Chemical energy → Electrical energy**
- Motor: **Electrical energy → Mechanical energy (spinning!)**

**Our N20 Motor**
- "N20" is just a size number (20mm diameter) - like shoe sizes!
- Has a tiny gearbox built in (that's the metal cylinder part)
- Gearbox does two important things:
  1. **Slows it down** - so it's controllable
  2. **Makes it stronger** - like bicycle gears!

**How to Control It?**
- Connect battery + to motor red wire, - to black wire → spins one way
- Flip the wires (swap + and -) → spins the other way!
- This is how your tank goes forward and backward

**Why Motors Need More Voltage Than Electronics?**
- Electronics (like your TV remote) need very little power
- Motors need "muscle" to spin wheels and lift things
- That's why RX4M4S uses a bigger 2S battery (7.4V)!

> **💡 Tip for Teachers:** Let students try the motor with a 1S battery first - it barely spins! Then try with the 2S battery - much stronger! This shows how voltage affects motor power directly.

**Think About It!**
- Great! The motor spins!
- But... how do we control the **SPEED**?
- How do race car drivers slow down? How do you control an electric scooter?

**The Problem:**
- With just a battery, motor runs at ONE speed (full speed)
- Real vehicles need VARIABLE speed control
- And we want wireless control - no messy wires!

**This is why we need MeshMass!**

### Step 2: MeshMass Pairing

Verify all electronics work:
- Power up TX6A4D and RX4M4S
- Pair transmitter with receiver
- Test motor outputs with sticks
- Confirm everything functional!

### Step 3: Assemble Transmitter

Build your custom controller:
- Install TX6A4D in controller chassis
- Attach screen stand
- Connect battery

### Step 4: Assemble Tank

Build your tank chassis:
- Install motors
- Mount RX4M4S receiver
- Connect battery
- Assemble tracks

### Step 5: Game Time!

Race your tank and learn:
- Differential steering (one track forward, one backward = turn)
- Tank track mechanics
- Have fun!

## Session 2: Code Your Tank

Learn programming with hands-on tank control!

### Step 1: Binary and Bytes

Computers speak in 1s and 0s:
- ON = 1, OFF = 0
- 8 bits = 1 byte
- Signed numbers: -128 to 127

### Step 2: Channels and Communication

Transmitter talks to receiver:
- 16 channels = 16 bytes
- Left stick = Channel 0
- Right stick = Channel 1

### Step 3: Your First Program

```c
// Tank steering: left stick controls both tracks
setMotor(0, getChannel(0));  // Left track
setMotor(1, getChannel(0));  // Right track
```

### Step 4: Customize Your Tank

Try different mixing formulas:
- Speed control
- Steering sensitivity
- Dead zone

## Learning Path

This starter kit guides you through fundamental MeshMass concepts through hands-on practice:

### Level 1: Mechanical Basics

**Continuous Track Mechanism**
- How tank tracks work (endless loop, wheels, tension)
- Differential steering (one track forward, one backward = turn)
- Simple machine: gear reduction in motors

### Level 2: Electronics Basics

**What is Electricity?**
- Voltage, current, and how batteries work
- Positive (+) and negative (-) terminals

**DC Motor Control**
- Motor direction changes with polarity
- Speed changes with voltage
- PWM (Pulse Width Modulation) explained visually

### Level 3: Digital Logic

**Binary and Bytes**
- Computers use ON/OFF (1/0)
- 8 bits = 1 byte = 256 possible values
- Signed vs unsigned numbers (-128 to 127)

**Communication Protocol**
- Sender → Channel → Receiver
- 16 channels = 16 bytes per message

### Level 4: 3D Printing Basics

**What is 3D Printing?**
- Layer-by-layer additive manufacturing
- From digital model to physical object

**Where to Find Models:** [MakerWorld](https://makerworld.com.cn), [Thingiverse](https://thingiverse.com), [Printables](https://printables.com)

### Level 5: MeshMass Programming

1. **Firmware Setup** - Connect boards and flash your first program via the web editor
2. **Motor Control** - Numbers control motor direction and speed
3. **Input Mapping** - Controller inputs map to channels
4. **Mixing** - Combine inputs for tank steering

## Bill of Materials

### Electronics

| Item | Quantity |
|------|----------|
| [RX4M4S Receiver](/MeshMass-RX4M4S) | 1 |
| [TX6A4D Transmitter](/MeshMass-TX6A4D) | 1 |
| USB Flashing Dongle | 1 |
| 128x64 OLED Display (SH1.0) | 1 |
| 6V 300 RPM N20 DC Motor with PH2.0 Connector | 2 |

### Batteries

| Item | Quantity |
|------|----------|
| 1S LiPo Battery (for TX6A4D) | 1 |
| 2S LiPo Battery (for RX4M4S) | 1 |

### 3D Printed Parts

**Remote Controller:**
| Part | Quantity |
|------|----------|
| Chassis | 1 |

**Mini Tank:**
| Part | Quantity |
|------|----------|
| Chassis | 1 |
| Horn | 1 |
| Front Wheel | 2 |
| Rear Wheel | 2 |
| Motor Cover | 2 |
| Screen Stand | 1 |
| Continuous Track | 2 |

**Tool:**
| Part | Quantity |
|------|----------|
| Socket Separator | 1 |
| USB 2S LiPo Charger (for 2S battery) | 1 |
| USB Type-C Cable (for TX6A4D charging) | 1 |
| Phillips Screwdriver | 1 |

### Hardware

| Part | Quantity |
|------|----------|
| PB2x5 Screw | 18 |
| PB2x8 Screw | 4 |

## Features

## Specifications

### Chassis

| Specification | Value |
|---------------|-------|
| Dimensions | TBD |
| Weight | TBD |
| Material | PETG (recommended) |
| Layer Height | 0.2mm |

### Drive System

## Assembly

All parts are pre-printed and wires are pre-soldered - just plug and screw!

### 1. Install Motors

### 2. Assemble Tracks and Wheels

### 3. Mount RX4M4S

### 4. Connect Battery

### 5. Install TX6A4D in Controller

## Programming

## Programming

## Where to Buy

## Related Products

- [TX6A4D Transmitter](/MeshMass-TX6A4D) - Dual joystick transmitter module
- [RX4M4S Receiver](/MeshMass-RX4M4S) - 4 DC motor + 4 servo receiver