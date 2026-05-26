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

#### Meet the Parts

**Battery Is Everywhere**

**Where do you see batteries in everyday life?** Let students answer first - this also gives a quick read on their English vocabulary for everyday objects. After they have shared, enrich with a few examples they may not have thought of:

- **Electric cars** - thousands of batteries working together to power a vehicle.
- **Submarines** - batteries let them operate underwater without surfacing.
- **Satellites** - solar panels charge batteries that power everything in space.

Our kit uses **rechargeable LiPo (Lithium Polymer) batteries** - the same type used in drones and action cameras.

**Positive and Negative Terminals**

Think of a battery like a water tower:
- The **positive terminal (+)** is like the top of the tower - water wants to flow OUT from here
- The **negative terminal (-)** is like the bottom - water wants to flow IN here
- Electricity works the same way - electrons (tiny particles!) want to flow from + to -

::: danger Safety Rules

1. Never put metal (coins, keys, screwdrivers) across battery terminals.
2. Always be careful when connecting battery packs.

:::

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

#### Make the Motor Spin

::: info Experiment #1: A Simple Circuit

With just one 1S battery and one N20 motor, students can build the smallest possible electric circuit. **Wiring convention:** red = **+**, black = **−** (this matches the coloured wires on both the battery's connector and the motor).

- Motor's red wire → battery's **+** terminal
- Motor's black wire → battery's **-** terminal

The motor spins.

A **circuit** is a closed loop that lets electricity flow from the battery, through the motor, and back. Break the loop anywhere - lift a wire - and the motor stops.

> **⚠️ Safety:** The motor must always stay in the loop. Never let a bare wire (or a coin, paperclip, finger) connect the battery's **+** directly to **-** without the motor in between - that is a **short circuit**, and the battery will overheat.

**On/off control:** Keep one wire firmly attached and just tap the other wire on and off its terminal. The motor turns on and off. Breaking the loop at *any* single point stops it - that is exactly how a **switch** works.

**Reversing direction:** swap the wires (red to **-**, black to **+**) and the motor spins the other way. That is how your tank will go both forward and backward.

> **💡 Tip for Teachers:** Draw the loop on the board: battery → motor → battery. The word "circuit" shares a root with "circular" - a closed path. The tap-on/tap-off step is a natural moment to introduce the word "switch".

:::

#### What About Speed?

A natural question after the first experiment: how do we make the motor spin *faster* or *slower*? A sensible first guess is to try a different battery.

::: info Experiment #2: Trying a Bigger Battery

Run the same simple circuit, but with the **2S battery** instead of the 1S:
- Motor's red wire → 2S battery's **+** terminal
- Motor's black wire → 2S battery's **-** terminal

The motor spins clearly faster than it did on the 1S battery.

This experiment shows that **the size of the voltage controls how fast the motor spins**. Higher voltage = faster spin. Lower voltage = slower spin.

> **💡 Tip for Teachers:** "Use a bigger battery" is partly right and worth celebrating - it leads directly to this experiment. But a tank driver doesn't carry a box of different batteries to change speed mid-drive, so this isn't the full answer.

:::

**What is Voltage?**

Think of voltage like **water pressure** in pipes:

- More pressure = water pushes harder = more flow
- More voltage = electrons push harder = more power

Voltage is measured in **volts** (**V**). The unit is named after **Alessandro Volta**, the Italian scientist who built the first real battery (a "voltaic pile") around the year 1800. So "3.7V" on a LiPo battery means "3.7 volts" - the strength of that battery's push.

**Analogy Time!**
- A tiny battery (1.5V AA) = garden hose spray - gentle
- A bigger battery (3.7V LiPo) = pressure washer - much stronger!
- A car battery (12V) = fire hose - super powerful!

> **💡 Tip for Teachers:** A digital multimeter ($10-20) is a great investment for the classroom! You can:
> - Measure battery voltage to confirm it's charged (3.7V per cell = full, below 3.5V = needs charging)
> - Show students how voltage adds up when batteries are connected in series
> - Test that circuits are working correctly

**Series Circuit**
- When batteries are connected in series, voltages add up
- 1S + 1S = 2S (3.7V + 3.7V = 7.4V)

**Why the Receiver Uses a 2S Battery**

Motors need more electrical power than small electronics. A TV remote needs very little voltage; a motor that spins a wheel needs *muscle*. That is why our kit uses two different batteries:

- **TX6A4D transmitter:** 1S LiPo (3.7V) - small, lightweight, enough for buttons, sticks, and display.
- **RX4M4S receiver:** 2S LiPo (7.4V) - the stronger push the motors need.

#### Variable Speed With One Battery

**The Speed Problem**

Real vehicles don't swap batteries to control speed. An electric scooter, an electric car, a remote-control car - they all run on a single battery, and the driver still controls speed smoothly from zero to top.

So the harder question is: **how do we vary speed with the same battery?**

For the rest of the lesson, switch the demo back to the 1S battery. At 1S, the motor still spins at a fair speed - the difference between 1S and 2S is the *maximum* speed available, not whether the motor works.

> **💡 Tip for Teachers:** Switching back to 1S keeps the remaining demos safer and more predictable. The point of Experiment #2 was to show voltage affects speed - not to declare 1S too weak. For everything that follows, 1S works fine.

**⚠️ Warning for Teachers:** Household sockets have 110V AC (USA) or 220V AC (China/Europe) - this is DANGEROUS for kids! Never let children touch wall sockets. Our kit uses safe low voltages (3.7V-7.4V).

This experiment builds on the on/off trick from Experiment #1.

::: info Experiment #3: Speed Control by Timing

Same setup - 1S battery, N20 motor, two wires. But instead of tapping randomly, do it with a steady rhythm:

- Tap **on** for one second
- **Off** for one second
- **On** for one second
- **Off** for one second
- ... and so on

Watch the motor over a 2-second window. It is connected for 1 second, disconnected for 1 second. On average, it gets half the power - not because the battery is smaller, just because we changed *when* it is connected. The motor runs at about half speed.

This is the key idea: **we can control speed by controlling when the motor is on**.

> **💡 Tip for Teachers:** If students are stuck on "how do we vary speed with the same battery?", this experiment is the unlock. Frame it as: "remember tapping the wire on and off? What if you do it on purpose, with timing?"

:::

**Naming What We Just Did: PWM**

Switching the motor on and off rapidly to control its speed has a real name: **PWM** - *Pulse Width Modulation*. Break the name apart:

- **Pulse** - a short burst of power (the on-time).
- **Width** - how long each pulse lasts.
- **Modulation** - varying, changing.

So PWM means **varying the width of the on-pulses to control average power**. Longer on-pulse → more average power → faster motor. Shorter on-pulse → less power → slower motor.

In Experiment #3, the rhythm was **on = 1s, off = 1s** → motor at about 50% speed. The same idea scales:

- **on = 1.5s, off = 0.5s** → about 75% speed
- **on = 0.5s, off = 1.5s** → about 25% speed

When students do this with their fingers, it is called **manual PWM**.

**Manual PWM Has a Problem**

Manual PWM works as a demo, but for a real mini tank it has a problem: **a person is too big and too heavy to ride on the tank and tap wires while it drives**. We also can't tap fast enough - a real motor wants PWM hundreds of times per second, not once per second.

What we need is a small, fast, *automatic* PWM-maker that fits on the tank itself. And we want the controller in our hands instead of on the tank - so a wireless link, too.

That is exactly what MeshMass provides:
- The **receiver** (on the tank) generates PWM automatically
- The **transmitter** (in your hand) sends instructions wirelessly

In the next step, we meet them.

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

### Tools and Accessories

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

## Where to Buy

## Related Products

- [TX6A4D Transmitter](/MeshMass-TX6A4D) - Dual joystick transmitter module
- [RX4M4S Receiver](/MeshMass-RX4M4S) - 4 DC motor + 4 servo receiver