# Sourcekit® MeshMass RX4M4S

Version: 1.0.0

Designer: Weihong Guan [<span class="mdi mdi-github" style="color: #000;"></span>](https://github.com/aguegu/) [<span class="mdi mdi-twitter" style="color: #1da1f2;"></span>](https://twitter.com/BG5USN)

## Overview

Sourcekit® MeshMass RX4M4S is a programmable receiver module designed for RC applications. It is the companion receiver to the TX6A4D transmitter, forming a complete programmable RC control system.

The RX4M4S provides 4 DC motor outputs and 4 servo outputs, making it ideal for controlling complex vehicles like construction equipment, RC cars, cranes, and custom 3D printed builds.

![RX4M4S Receiver](/images/MeshMass-RX4M4S/main.jpg)

## Features

- **4 DC Motor Outputs**: For brushed DC motor control (N20, 370, etc.)
- **4 Servo Outputs**: Standard servo PWM outputs (5V, compatible with 9g servos and more)
- **Programmable Channel Mapping**: Map any of the 16 wireless channels to any output
- **Mixing Support**: Combine multiple channels for complex behaviors (tank steering, crane controls)
- **OLED Display Interface**: 6-pin SH1.0 connector for 128x64 SPI OLED (sold separately)
- **Low Latency**: 2.4GHz proprietary protocol optimized for real-time control
- **External Antenna Option**: IPEX-1 connector for external 2.4GHz antenna
- **Buzzer**: Lost connection alarm and system feedback
- **Compact Design**: Easy to integrate into custom builds

## Specification

### Microcontroller

The RX4M4S is powered by the same WCH CH571F microcontroller as the TX6A4D transmitter, ensuring full protocol compatibility and optimized performance.

| Component | Specification |
|-----------|---------------|
| MCU | WCH CH571F (part of CH57x series) |
| Architecture | 32-bit RISC-V (QingKe V3A core) |
| CPU Speed | 48 MHz (typical) |
| Memory | 32KB SRAM, 256KB Flash |
| Wireless | 2.4GHz proprietary protocol (raw PHY layer for minimum latency) |
| GPIO | Multiple configurable I/O pins |
| PWM | Hardware PWM outputs (used for WS2812 LED control) |
| Timer | Advanced timer for servo PWM generation |
| Peripherals | SPI, UART |

The CH571F's advanced timer capabilities are particularly important for the RX4M4S, enabling precise servo PWM signal generation with minimal CPU overhead. Like the TX6A4D, the receiver utilizes the raw 2.4GHz physical layer for minimum latency in real-time control applications.

### Outputs

| Type | Count | Connector | Description |
|------|-------|-----------|-------------|
| DC Motor | 4 | PH2.0 | Brushed DC motor driver outputs (0-3) |
| Servo | 4 | 2.54mm servo header (3-pin) | Standard PWM servo outputs (5V) |

**Motor Outputs (M0-M3):**
- 4x PH2.0 connectors for brushed DC motors
- Driven by 4x HXA2820 H-bridge motor drivers (one per channel)
- HXA2820 specifications:
  - Max working voltage: 10.5V (compatible with 2S LiPo)
  - Max continuous current: 2A per channel
  - Max peak current: 3.5A
  - Overtemperature protection: 150°C
- **Key Advantage**: Built-in motor drivers eliminate the need for external ESCs or motor driver boards. Most RC receivers require separate electronic speed controllers (ESCs) for each DC motor, adding cost, weight, and wiring complexity. The RX4M4S integrates 4 motor drivers directly on the board.
- Supports a wide range of low-voltage brushed DC motors (3V-7.4V, 2S LiPo range):
  - **Micro motors**: N20, 610, 716, 718 (micro robots, small mechanisms)
  - **Coreless motors**: 8515, 8520, 1020, 1220 (high-speed, fast response)
  - **Standard RC motors**: 130, 140, 180, 260, 270, 280 series (1/10 scale vehicles)
  - **Medium motors**: R300, 350, 370, 380, 390 series (higher torque applications)
  - **Gear motors**: Any of the above with gearbox reduction for precise control
- PWM speed control with forward/reverse/brake capability

**Servo Outputs (SM0-SM3):**
- 4x standard 2.54mm servo headers (3-pin, Dupont style) for standard servos
- Pinout: GND (black) / 5V (red) / Signal (yellow)
- 5V power supply for servos
- Compatible with 9g servos and standard analog/digital servos
- PWM signal: 50Hz (20ms frame), 1000-2000μs pulse width

**Note:** SM1 and SM2 share pins with the buzzer. When using these servo ports, the buzzer function is unavailable.

### Power

| Specification | Value |
|---------------|-------|
| Input Voltage | 2S LiPo (7.4V - 8.4V) |
| Battery Connector | XH2.54 |
| Servo Power | 5V regulated output |
| Motor Power | Direct battery input (2S) |
| **Warning** | Only supports 2S LiPo battery. Using other voltage may damage the board. |

### Physical

| Specification | Value |
|---------------|-------|
| Dimensions | TBD |
| Mounting | TBD |
| Weight | TBD |
| PCB Color | Black |

### Display & Feedback

| Component | Description |
|-----------|-------------|
| Display Interface | 6-pin SH1.0 connector, SPI interface for 128x64 OLED (sold separately) |
| Programming Interface | 6-pin SH1.0 connector for MeshMass USB Flashing Dongle (sold separately), also provides serial console output |
| Display Shows | Battery voltage, Wireless signal strength, All 16 channel values (-128 to 127) |
| LED Indicators | 4 LEDs for motor channel status (0-3) |
| Buzzer | Lost connection alarm (shared with SM1, SM2) |

**Display Note:** MeshMass shows raw decimal values (not scroll bars or progress indicators) for precise verification. The OLED displays all 16 channel values received from the transmitter, allowing students to directly verify the wireless communication is working correctly. The OLED screen is sold separately, making it optional for fixed installations and friendly to budget-conscious builders.

### Connectivity

| Feature | Description |
|---------|-------------|
| Wireless | 2.4GHz auto-hopping (BLE PHY layer only, no GATT) |
| Protocol | Proprietary low-latency RC protocol |
| Pairing | One-to-one binding with TX6A4D via pairing procedure |
| Antenna | Onboard PCB antenna + IPEX-1 connector for external 2.4GHz antenna |
| Range | ~40 meters in open field (onboard PCB antennas), extends with external antenna |

## Pairing

The RX4M4S must be paired with a TX6A4D transmitter before use. The pairing process establishes an exclusive one-to-one wireless connection between the transmitter and receiver.

### EEPROM Storage

Pairing information is stored in **EEPROM** (Electrically Erasable Programmable Read-Only Memory), a non-volatile memory that retains data even when power is removed. Once an RX4M4S receiver is paired with a TX6A4D transmitter, their connection information persists across power cycles and reboots. This means you don't need to re-pair devices every time you use them—the established connection is automatically restored when both devices are powered on.

### One-to-One Exclusive Pairing

MeshMass pairing is **bi-directional and exclusive**:
- When a receiver pairs with a new transmitter, its previous transmitter can no longer control it
- When a transmitter pairs with a new receiver, it loses access to any previously paired receiver

This one-to-one relationship ensures that each transmitter controls exactly one receiver at a time, and each receiver responds to exactly one transmitter. If you need to control multiple receivers simultaneously, you'll need multiple transmitter modules.

### Pairing Process

To pair an RX4M4S receiver with a TX6A4D transmitter:

1. **Enter pairing mode on the first device**:
   - Press and hold the **Pair button** for **more than 5 seconds**
   - The OLED screen will indicate pairing mode (typically showing "PAIRING" or similar message)

2. **Enter pairing mode on the second device**:
   - While the first device is in pairing mode, press and hold the **Pair button** on the second device
   - This device will also enter pairing mode with appropriate screen indication

3. **Automatic identity exchange**:
   - When both devices are in pairing mode and within wireless range, they automatically exchange identification information
   - This process typically completes within a few seconds

4. **Return to normal operation**:
   - Both devices automatically exit pairing mode and return to normal operation
   - The OLED displays revert to showing channel values and system status
   - The devices are now paired and ready for use

**Note:** The pairing button is labeled "PAIR" on the PCB. It's controlled by the firmware and cannot be reprogrammed for other functions.

**Aborting Pairing:** If a device is in pairing mode, pressing the Pair button again will abort the pairing process. Since no new pairing information gets stored, the previous pairing record remains intact and will continue to be used when the device returns to normal mode.

## Programming

The RX4M4S is programmable via the [MeshMass online platform](https://meshmass.com). Users can:

- Map any of the 16 wireless channels to motor and servo outputs
- Create mixing functions (e.g., differential steering, crane articulation)
- Configure motor direction and speed curves
- Set servo travel limits, center points, and exponential response
- Implement custom logic for buttons and switches

Programming is done through a web browser using the MeshMass USB flashing dongle (sold separately). The CH571F runs pre-built firmware scaffolds that handle the low-level RF communication, while users focus on application-level output mapping logic.

> **Note**: The RX4M4S does not have a built-in charging circuit. Programming and power are supplied through separate connectors.

### Why Code-Based Programming?

Traditional RC receiver solutions fall into two categories with significant drawbacks:

**A. Fixed-Function Receivers**
- Pre-defined channel-to-output mapping (cannot be changed)
- No mixing or custom logic support
- Limited to basic throttle/steering configurations
- Cannot implement complex behaviors (excavator arms, crane controls)

**B. Expensive Programmable Receivers**
- Rely on complex menu systems with poor UX
- Limited to predefined mixing options
- Expensive ($150-400+ for comparable functionality)
- Cannot implement truly custom behaviors

**MeshMass RX4M4S: The Best of Both Worlds**
- **Simple**: Write clean C code with a minimal API
- **Powerful**: Complete flexibility in channel-to-output mapping
- **Affordable**: Professional-grade control at hobbyist prices
- **Accessible**: Web-based editor, no complex toolchain installation
- **Example-Driven**: Comprehensive library of working code examples for common vehicle types

### Competitive Comparison

| Feature | Fixed Receivers | Expensive Programmable | MeshMass RX4M4S |
|---------|-----------------|------------------------|-----------------|
| **Price** | Low ($20-50) | High ($150-400+) | Affordable |
| **Learning Curve** | None (fixed function) | Moderate (complex menus) | Gentle (simple C API) |
| **Flexibility** | None (fixed mapping) | Limited (preset options) | High (code-based mapping) |
| **Setup Time** | Minutes | Hours | Minutes |
| **Custom Behaviors** | Impossible | Limited | Fully programmable |
| **Debugging** | None | Limited | Visual debugging via OLED |

### From Idea to Working Vehicle

**Traditional Approach with Fixed Receiver:**
1. Buy receiver, discover it can't do your desired mixing
2. Need to buy additional hardware (Y-harnesses, servo reversers)
3. Limited by what the receiver supports
4. Often need to buy a different receiver

**MeshMass RX4M4S Approach:**
1. Connect RX4M4S to motors and servos (5 minutes)
2. Select from pre-built examples or modify code in web editor (5-15 minutes)
3. Flash and test (1 minute)
4. Refine code as needed (5-15 minutes)
**Total: 15-35 minutes**

*With comprehensive examples and tutorials available on meshmass.com, most users can find working code for their specific vehicle type in minutes.*

## System Architecture

The MeshMass system separates concerns between transmitter and receiver:

- **TX6A4D (Transmitter)**: Maps physical inputs (joysticks, knobs, buttons) to 16 wireless channels
- **RX4M4S (Receiver)**: Maps received channels to physical outputs (motors, servos)

This abstraction allows users to focus on what matters for their specific build without worrying about RF protocol details.

### Typical Signal Flow

```
TX6A4D Joystick → getStick() → setChannel() → Wireless Transmission
                                                              ↓
RX4M4S Reception → getChannel() → setMotor()/setServo() → Motor/Servo
```

All mappings are configurable through meshmass.com.

## Firmware Scaffold

The RX4M4S runs a pre-built firmware scaffold that handles low-level hardware operations while exposing a simple API for application programming.

### Channel System

The firmware receives 16 signed bytes (-128 to 127) as wireless channels from the paired TX6A4D transmitter. These channels form the communication bridge between transmitter and receiver:
- Channels 0-5: Typically mapped from analog inputs (joysticks, knobs)
- Channels 6-15: Typically mapped from digital inputs (buttons, logic)

**Note:** The channel values received on RX4M4S are exactly what the TX6A4D transmitter sends. The TX6A4D only controls the mapping from physical inputs to channels. How these channel values are interpreted and converted to motor/servo outputs is determined by the application code running on the RX4M4S.

### Application Code Examples

The scaffold provides a simple API for reading channels and controlling outputs. Here's an example showing various output control techniques:

**Timing Note:** The `loop()` function is called every 20ms (50 times per second, or 50Hz), which matches the typical update frequency of analog servos and ESCs. This consistent timing ensures smooth control updates.

**Firmware Cycle Details:** After each `loop()` call completes, the motor and servo outputs are updated with the new values. Motor outputs use PWM for speed control, while servo outputs use PWM signal (center ~150, range approximately 100-200) for position control.

**Important:** Avoid using busy-waiting or delay functions inside `loop()`. The firmware runs a Real-Time Operating System (RTOS) in the background. Blocking operations can prevent critical system tasks from running, potentially causing system failures or unpredictable behavior.

```c
#include "app.h"

// Variables that persist between loop() calls should be declared globally
// or as static inside loop() (using 'static' keyword)
static uint8_t servo_center = 150;  // Servo center point (~150)

void loop() {
  // --- Default Configuration (from app.c) ---
  // Direct channel to motor mapping for motors 0-3
  setMotor(0, getChannel(0));
  setMotor(1, getChannel(1));
  setMotor(2, getChannel(2));
  setMotor(3, getChannel(3));

  // Servo control with center offset and scaled travel
  // Channel values (-127 to 127) converted to servo range (~100-200)
  setServo(0, 150 + getChannel(4) * 2 / 5);
  setServo(1, 150 + getChannel(5) * 2 / 5);
  setServo(2, 150 + getChannel(6) * 2 / 5);
  setServo(3, 150 + getChannel(7) * 2 / 5);

  // --- Basic Motor Control Examples ---

  // Example 1: Reversed motor direction
  // Useful for motors that need opposite rotation
  setMotor(1, -getChannel(1));

  // Example 2: Scaled motor speed
  // Reduce sensitivity for fine control
  setMotor(2, getChannel(2) / 2);

  // Example 3: Motor with deadzone
  // Ignore small channel values to prevent motor creep
  int8_t motor_val = getChannel(3);
  if (abs(motor_val) > 10) {
    setMotor(3, motor_val);
  } else {
    setMotor(3, 0);  // Stop motor when near center
  }

  // --- Basic Servo Control Examples ---

  // Example 4: Direct channel to servo mapping with custom center
  // Channel values (-127 to 127) scaled to servo range
  // Formula: center + channel * 2 / 5 gives range ~100-200
  setServo(0, servo_center + getChannel(4) * 2 / 5);

  // Example 5: Servo with adjustable center point
  // Change servo_center variable to adjust mechanical alignment
  setServo(1, servo_center + getChannel(5) * 2 / 5);

  // Example 6: Servo with travel limit
  // Restrict servo movement range
  int8_t servo_val = getChannel(6);
  if (servo_val > 100) servo_val = 100;
  if (servo_val < -100) servo_val = -100;
  setServo(2, 150 + servo_val * 2 / 5);

  // --- Mixing Examples ---

  // Example 7: Tank steering (differential drive)
  // Combine two channels for throttle and steering
  int8_t throttle = getChannel(0);
  int8_t steering = getChannel(1);
  setMotor(0, throttle + steering);  // Left motor
  setMotor(1, throttle - steering);  // Right motor

  // Example 8: Crane articulation
  // Multiple servos working together
  int8_t crane_base = getChannel(2);
  int8_t crane_arm = getChannel(3);
  setServo(0, 150 + crane_base * 2 / 5);  // Base rotation
  setServo(1, 150 + crane_arm * 2 / 5);   // Arm articulation

  // Example 9: Three-way mixing for excavator
  // Swing, boom, and arm control
  setServo(0, 150 + getChannel(0) * 2 / 5);  // Swing
  setServo(1, 150 + getChannel(1) * 2 / 5);  // Boom
  setServo(2, 150 + getChannel(2) * 2 / 5);  // Arm
}
```

### API Functions

- `int8_t getChannel(uint8_t n)`: Returns received signed 8-bit value (-128 to 127) from wireless channel `n` (0-15)
- `void setMotor(uint8_t n, int8_t value)`: Sets motor `n` (0-3) to `value` (-127 to 127). Positive values = forward, negative = reverse, 0 = stop
- `void setServo(uint8_t n, uint8_t value)`: Sets servo `n` (0-3) position. Center point is ~150, typical range 100-200. Use formula `150 + channel * 2 / 5` to convert channel values (-127 to 127) to servo range.
- `void loop()`: Application main loop function called every 20ms (50Hz). Implement this function to define your output control logic.

**State Persistence**: Variables that need to retain values between `loop()` calls should be declared as `static` inside `loop()` or as global variables outside functions.

**Standard Library**: Common C standard library functions like `abs()` are available for mathematical operations.

### Firmware-Managed Features

The scaffold handles several system functions automatically:
- **OLED Display**: Real-time debugging display showing battery voltage, wireless signal strength, and all 16 channel values (-128 to 127). Displays raw decimal values (not simplified visualizations) for precise verification. The OLED is sold separately, making it optional for fixed installations.
- **Buzzer**: Provides lost connection alarms and system feedback (shared pins with SM1, SM2)
- **LED Indicators**: 4 LEDs show motor channel activity (0-3)
- **Wireless Communication**: Manages 2.4GHz packet reception with auto-hopping
- **Battery Monitoring**: Monitors input voltage and provides low-battery warnings

This separation allows users to focus on application logic (output mapping) while the firmware handles hardware complexities.

## Applications

Sample applications and code templates are available on meshmass.com for:

- **Forklift**: 3 N20 motors + 1 9g servo for fork control
- **Dump Truck**: 1 370 motor for drive, 1 N20 motor for dump bed, 1 servo for steering
- **Excavator**: Multiple servos and motors for swing, boom, arm, and bucket control
- **Tank**: Dual motor differential steering with turret control
- **RC Cars**: Throttle and steering with optional multi-gear transmission
- **Cranes**: Multi-axis control with precise servo positioning
- **Custom 3D printed vehicles**: Fully customizable control schemes
- **Small scale RC airplanes and drones**: Multi-channel control for flight surfaces
- **Sandbox models and dioramas**: Interactive display models
- **STEM education projects**: Hands-on learning with immediate feedback
- **Custom robotics and automation**: Programmable multi-axis platforms

## Discussion and Show Cases

- [Forum (Powered by GitHub Discussion)](https://github.com/aguegu/sourcekit.cc/discussions)
- [bilibili - 猥琐老虎 - 合集-可编程遥控模块](https://space.bilibili.com/24674093/lists/6826437)

## Where to Buy

- [Taobao - 猥琐老虎遥控玩物](https://dti9o8bd7lkwm7d4o9slcd2h6apezgn.taobao.com)

## Related Products

- [TX6A4D Transmitter](/MeshMass-TX6A4D) - Dual joystick transmitter module
- USB Flashing Dongle - Browser-based programming tool (coming soon)
