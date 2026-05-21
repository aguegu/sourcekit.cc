# Sourcekit® MeshMass RX4M4S

Version: 1.0.0

Designer:
Weihong Guan [<span class="mdi mdi-github" style="color: #000;" />](https://github.com/aguegu/) [<span class="mdi mdi-twitter" style="color: #1da1f2;" />](https://twitter.com/BG5USN),
Shengyuan Fang,
Donghao Chen [<span class="mdi mdi-printer-3d-nozzle" style="color: #0c0;"/>](https://makerworld.com.cn/zh/@cdhchaoren) [<span class="mdi mdi-television-classic" style="color: #00C;" />](https://space.bilibili.com/24674093)

## Overview

Sourcekit® MeshMass RX4M4S is a programmable receiver module designed for RC applications. It is the companion receiver to the TX6A4D transmitter, forming a complete programmable RC control system.

The RX4M4S provides 4 DC motor outputs and 4 servo outputs, making it ideal for controlling complex vehicles like construction equipment, RC cars, cranes, and custom 3D printed builds. Designed with 3D printing hobbyists in mind, it offers space-efficient integration, built-in motor drivers, and easy programming through a web-based editor.

![RX4M4S Receiver](/images/MeshMass-RX4M4S/front.png)

## Features

- **4 DC Motor Outputs**: For brushed DC motor control (N20, 370, etc.)
- **4 Servo Outputs**: 50Hz PWM outputs (5V, compatible with 9g servos and more)
- **Programmable Channel Mapping**: Map any of the 16 wireless channels to any output
- **Mixing Support**: Combine multiple channels for complex behaviors (tank steering, crane controls)
- **OLED Display Interface**: 6-pin SH1.0 connector for 128x64 SPI OLED (sold separately)
- **WS2812 Neopixel Interface**: 4-pin SH1.0 connector for addressable RGB LED strips (vehicle head/turning/tail lights). **Shares signal pin with SM3** (not included, requires special firmware)
- **Audio Module Interface**: 4-pin SH1.0 connector for optional audio module (MP3 playback for engine start sound effects). **Shares pins with SM1, SM2** (sold separately, under development)
- **Low Latency**: 2.4GHz proprietary protocol optimized for real-time control
- **External Antenna Option**: IPEX-1 connector for external 2.4GHz antenna
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
| DC Motor | 4 | PH2.0 | Brushed DC motor driver outputs with ~220Hz PWM (DM0-DM3) |
| Servo | 4 | 2.54mm servo header (3-pin) | 50Hz PWM servo outputs (5V) |
| WS2812 Neopixels | 1 (shared) | 4-pin SH1.0 | Addressable RGB LED strips for vehicle lights (head/turning/tail). **Shares signal pin with SM3** (not included, requires special firmware) |
| Audio Module | 1 (optional) | 4-pin SH1.0 | MP3 playback for sound effects (engine start, horns). **Shares pins with SM1, SM2** (sold separately, under development) |

**Motor Outputs (DM0-DM3):**
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
- PWM speed control (~220Hz) with bidirectional control and braking capability

**Technical Note:** The RX4M4S generates two types of PWM signals:
- **Motor PWM**: ~220Hz frequency for smooth motor speed control. Each DC motor channel uses two complementary PWM outputs to drive the H-bridge for bidirectional control with braking.
- **Servo PWM**: 50Hz (20ms period) standard servo control. Each servo channel uses one PWM output for position control.

**Servo Outputs (SM0-SM3):**
- 4x standard 2.54mm servo headers (3-pin, Dupont style) for standard servos
- Pinout: GND (black) / 5V (red) / Signal (yellow)
- 5V power supply for servos
- Compatible with 9g servos and standard analog/digital servos
- PWM signal: 50Hz (20ms frame), programmable pulse width (typically 1000-2000μs, supports 500-2500μs for extended range servos)

**Pin Sharing & Firmware Variants:** The RX4M4S has configurable pin functions determined by firmware variant selection. Pins are shared between servo outputs and accessory interfaces, with specific firmware variants enabling different feature combinations. The WS2812 Neopixel interface (for vehicle head/turning/tail lights) **shares the signal pin with servo SM3**. The audio module interface (for MP3 sound effects like engine start) **shares pins with servos SM1 and SM2**. This creates three firmware variants with different capability trade-offs:

| Firmware Variant | DC Motors | Servos | WS2812 Neopixels | Audio Module | Availability |
|------------------|-----------|--------|------------------|--------------|--------------|
| **RX4M4S** | 4 | 4 (SM0-SM3) | Not enabled | Not enabled | Currently available |
| **RX4M3S1N** | 4 | 3 (SM0-SM2) | Enabled (uses SM3 pin) | Not enabled | Not released yet |
| **RX4M1S1N1A** | 4 | 1 (SM0 only) | Enabled (uses SM3 pin) | Enabled (uses SM1, SM2 pins) | Not released yet, audio module under development |

**Important:** When using WS2812 Neopixels, servo SM3 is unavailable. When using the audio module, servos SM1 and SM2 are unavailable. Choose the firmware variant that matches your project needs.

Contact Sourcekit for special firmware configurations based on your application needs.

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
| Dimensions | 40mm × 60mm |
| Mounting | 4× M2.5 mounting holes |
| Weight | ~15g (without connectors) |
| PCB Color | Black |

### Display & Feedback

| Component | Description |
|-----------|-------------|
| Display Interface | 6-pin SH1.0 connector, SPI interface for 128x64 OLED (sold separately) |
| Programming Interface | 6-pin SH1.0 connector for MeshMass USB Flashing Dongle (sold separately), also provides serial console output |
| Display Shows | Debugging values: channel values, 4 motor outputs, and 4 servo outputs displayed as signed 3-digit integers on 4-line OLED |

**Display Note:** MeshMass shows raw decimal values (not scroll bars or progress indicators) for precise verification. The 4-line OLED displays debugging information as signed 3-digit integers, including channel values, motor outputs, and servo outputs. This allows students to debug mapping and math operations from channels to outputs. The OLED screen is sold separately, making it optional for fixed installations and friendly to budget-conscious builders.

### Connectivity

| Feature | Description |
|---------|-------------|
| Wireless | 2.4GHz auto-hopping (BLE PHY layer only, no GATT) |
| Protocol | Proprietary low-latency RC protocol |
| Pairing | One-to-one binding with TX6A4D via pairing procedure |
| Antenna | Onboard PCB antenna + IPEX-1 connector for external 2.4GHz antenna |
| Range | ~40 meters in open field (onboard PCB antennas), extends with external antenna |

## Pairing

The RX4M4S follows the standard MeshMass pairing system described in the [MeshMass Introduction](/MeshMass-Introduction#pairing-system). Key details specific to the RX4M4S:

- The pairing button is labeled **"PAIR"** on the PCB
- It's controlled by firmware and cannot be reprogrammed for other functions
- The OLED display shows pairing status and confirmation

For complete pairing instructions including EEPROM storage, one-to-one exclusive pairing, and the detailed pairing process, refer to the [Pairing System](/MeshMass-Introduction#pairing-system) section in the MeshMass Introduction.

## Development Guide

The RX4M4S is programmable via the MeshMass online platform at [meshmass.com](https://meshmass.com) (global access) or [meshmass.y77.cc](https://meshmass.y77.cc) (China mainland) using a web browser and the MeshMass USB flashing dongle (sold separately). The CH571F runs pre-built firmware scaffolds that handle low-level RF communication and hardware drivers, while users focus on application-level output mapping logic.

> **Note**: The RX4M4S does not have a built-in charging circuit. Programming and power are supplied through separate connectors.

**What you program:** On RX4M4S, you define how received wireless channels map to motor, servo, and RGB LED outputs. How these channels are generated is determined by the transmitter (TX) firmware.

- Map any of the 16 wireless channels to motor, servo, and RGB LED outputs
- Create mixing functions (e.g., differential steering, crane articulation)
- Configure motor direction and speed curves
- Set servo travel limits, center points, and exponential response
- Implement custom logic for buttons and switches

The MeshMass system is built on a code-based programming approach that combines the flexibility of open hardware with the accessibility of consumer products. For detailed discussion of our design philosophy, competitive advantages, educational value, and system architecture, see the [MeshMass Introduction](/MeshMass-Introduction) page.

**Key advantages for RX4M4S:**

**Built-in Motor Drivers**
- Integrates 4 HXA2820 H-bridge motor drivers directly on the board
- Eliminates need for external ESCs or motor driver boards
- 10.5V max, 2A continuous, 3.5A peak per channel
- Brake capability for precise control
- Supports wide range: N20 micro motors to 370 series medium motors

**Pin Sharing & Firmware Variants**
- Pin functions defined by firmware variant selection
- WS2812 Neopixels share signal pin with SM3 (use either lights or servo SM3 based on firmware)
- Audio module shares pins with SM1, SM2 (use either sound effects or servos SM1, SM2 based on firmware)

**Scaffold Programming Approach**
- Low-level RF, timing, and driver code pre-built
- Focus on application logic and output mapping
- Safety features and connection loss handling built-in

**Real-time Performance**
- 50Hz update rate matches servo refresh
- Minimum latency wireless communication
- Event-driven loop() for responsive control

**Easy Visual Debugging**
- Firmware verification without plugging in executors (which can be powerful but dangerous)
- Transmitter displays battery voltage and signal strength (user holds it in hand)
- Receiver displays debugging values: channels, motor outputs, servo outputs (for mapping verification)
- Aligns with usage patterns: transmitter in hand for system status, receiver remote for output verification





## Firmware Architecture

The RX4M4S runs a pre-built firmware scaffold that handles low-level hardware operations while exposing a simple API for application programming. This architecture separates hardware complexity from application logic, allowing users to focus on output mapping.

### Channel System

The firmware receives 16 signed bytes (-128 to 127) as wireless channels from the paired TX6A4D transmitter. These channels form the communication bridge between transmitter and receiver. Application code interprets these channel values and maps them to motor, servo, and RGB LED outputs based on the specific vehicle's requirements.

**Note:** The channel values received on RX4M4S are exactly what the TX6A4D transmitter sends. The TX6A4D only controls the mapping from physical inputs to channels. How these channel values are interpreted and converted to motor, servo, and RGB LED outputs is determined by the application code running on the RX4M4S.

### Application Code Examples

The scaffold provides a simple API for reading channels and controlling outputs. Here's an example showing various output control techniques:

**Timing Note:** The `loop()` function is called by the firmware scaffold after each successfully received and verified wireless payload from the paired transmitter. Since the transmitter broadcasts at 50Hz (every 20ms), the receiver typically calls `loop()` at 50Hz under normal connection conditions. This matches the typical update frequency of analog servos and ESCs, ensuring smooth control updates.

**Firmware Cycle Details:** After each `loop()` call completes, the motor and servo outputs are updated with the new values. Motor outputs use ~220Hz PWM for speed control, while servo outputs use 50Hz PWM signal (center ~150, range approximately 100-200) for position control. **Safety Feature:** If wireless connection is lost or a payload fails verification, `loop()` is not called, and all outputs maintain their last valid values. This prevents unpredictable behavior during brief signal interruptions.

**Important:** Avoid using busy-waiting or delay functions inside `loop()`. The firmware runs a Real-Time Operating System (RTOS) in the background. Blocking operations can prevent critical system tasks from running, potentially causing system failures or unpredictable behavior.

```c
#include "app.h"

// Variables that persist between loop() calls should be declared globally
// or as static inside loop() (using 'static' keyword)
static uint8_t servo_center = 150;  // Servo center point (~150)

// One-time initialization function
void setup() {
  // Initialize Neopixel LED strip with 8 LEDs (for RX4M3S1N or RX4M1S1N1A variants)
  neoInit(8);

  // Other initialization tasks can be added here
  // (motor/servo defaults, variable initialization, etc.)
}

// Audio module ready callback (for RX4M1S1N1A variant)
void onPlayerReady() {
  // Set default audio volume when audio module is ready
  mpVolume(20);  // Volume level 20 out of 30 (0 = silent, 30 = maximum)

  // Optional: Play startup sound
  // mpPlay(1, true);  // Play file 0001 with force
}

void loop() {
  // --- Default Configuration (from app.c) ---
  // Direct channel to motor mapping for motors 0-3
  setMotor(0, getChannel(0));
  setMotor(1, getChannel(1));
  setMotor(2, getChannel(2));
  setMotor(3, getChannel(3));

  // Servo control with center offset and scaled travel
  // Channel values (-127 to 127) converted to servo range (~100-200)
  // Formula: 150 (center = 1.5ms) + channel * 2/5 (scaling factor 0.4)
  // This gives approximately ±50 units (±0.5ms) from center for full channel range
  setServo(0, 150 + getChannel(4) * 2 / 5);
  setServo(1, 150 + getChannel(5) * 2 / 5);
  setServo(2, 150 + getChannel(6) * 2 / 5);
  setServo(3, 150 + getChannel(7) * 2 / 5);

  // --- Basic Motor Control Examples ---

  // Example 1: Inverted motor direction
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

  // Example 4: Servo direction inversion
  // Use subtraction instead of addition to invert servo movement direction
  // Without changing transmitter configuration
  setServo(0, 150 - getChannel(4) * 2 / 5);

  // Example 5: Direct channel to servo mapping with custom center
  // Channel values (-127 to 127) scaled to servo range
  // Formula: center + channel * 2 / 5 gives range ~100-200
  setServo(1, servo_center + getChannel(5) * 2 / 5);

  // Example 6: Servo with adjustable center point
  // Change servo_center variable to adjust mechanical alignment
  setServo(2, servo_center + getChannel(6) * 2 / 5);

  // Example 7: Servo with travel limit
  // Restrict servo movement range
  int8_t servo_val = getChannel(7);
  if (servo_val > 100) servo_val = 100;
  if (servo_val < -100) servo_val = -100;
  setServo(3, 150 + servo_val * 2 / 5);

  // --- Mixing Examples ---

  // Example 8: Tank steering (differential drive)
  // Combine two channels for throttle and steering
  int8_t throttle = getChannel(0);
  int8_t steering = getChannel(1);
  setMotor(0, throttle + steering);  // Left motor
  setMotor(1, throttle - steering);  // Right motor

  // Example 9: Crane articulation
  // Multiple servos working together
  int8_t crane_base = getChannel(2);
  int8_t crane_arm = getChannel(3);
  setServo(0, 150 + crane_base * 2 / 5);  // Base rotation
  setServo(1, 150 + crane_arm * 2 / 5);   // Arm articulation

  // Example 10: Three-way mixing for excavator
  // Swing, boom, and arm control
  setServo(0, 150 + getChannel(0) * 2 / 5);  // Swing
  setServo(1, 150 + getChannel(1) * 2 / 5);  // Boom
  setServo(2, 150 + getChannel(2) * 2 / 5);  // Arm

  // --- Neopixel and Audio Integration Examples ---

  // Example 11: Vehicle lights based on motor speed (for RX4M3S1N or RX4M1S1N1A)
  // Set LED brightness proportional to motor speed
  // Assume 8 LEDs: 0-3 for front, 4-7 for rear
  int8_t speed = abs(getChannel(0));  // Use throttle channel for speed
  uint8_t brightness = speed * 2;     // Scale to 0-254 range
  if (brightness > 255) brightness = 255;

  // Front lights (white)
  neoSetColor(0, COLOR_WHITE, brightness);
  neoSetColor(1, COLOR_WHITE, brightness);

  // Rear lights (red)
  neoSetColor(4, COLOR_RED, brightness / 3);  // Dimmer red lights
  neoSetColor(5, COLOR_RED, brightness / 3);

  // Example 12: Direction indicator lights
  // Green for forward, red for reverse, yellow for stopped
  if (getChannel(0) > 20) {
    // Moving forward - green front lights
    neoSetColor(2, COLOR_GREEN, 200);
    neoSetColor(3, COLOR_GREEN, 200);
  } else if (getChannel(0) < -20) {
    // Moving backward - red front lights
    neoSetColor(2, COLOR_RED, 200);
    neoSetColor(3, COLOR_RED, 200);
  } else {
    // Stopped - yellow front lights
    neoSetColor(2, COLOR_YELLOW, 100);
    neoSetColor(3, COLOR_YELLOW, 100);
  }

  // Example 13: Audio feedback for engine sounds (for RX4M1S1N1A)
  // Play engine sound when throttle exceeds threshold
  static bool engine_playing = false;
  int8_t throttle = getChannel(0);

  if (abs(throttle) > 30) {
    // Engine running - play engine sound (file 0001)
    if (!engine_playing) {
      mpPlay(1, true);  // Force play engine sound
      engine_playing = true;
    }
  } else {
    // Engine idle or stopped
    if (engine_playing) {
      // Could play idle sound here (file 0002)
      engine_playing = false;
    }
  }

  // Example 14: Beep sound for button press
  // Play beep when button is pressed (channel 8 as button)
  static bool button_was_pressed = false;
  bool button_pressed = (getChannel(8) > 0);

  if (button_pressed && !button_was_pressed) {
    // Button just pressed - play beep sound (file 0003)
    mpPlay(3, false);  // Don't force - skip if already playing
  }
  button_was_pressed = button_pressed;
}
```

### Quick Reference

**Core Functions:**
- `getChannel(n)` - Read wireless channel value (-128 to 127)
- `setMotor(n, value)` - Set motor speed and direction (127: 100% PWM one direction, -127: 100% PWM opposite direction, 0: stop, -128: brake)
- `getMotor(n)` - Get current motor output value
- `setServo(n, value)` - Set servo position (0.01ms units, 150 = 1.5ms center)
- `getServo(n)` - Get current servo output value
- `setup()` - One-time initialization function
- `loop()` - Main application function called after each received payload

**RGB LED (Neopixel) Functions:** (available to RX4M3S1N and RX4M1S1N1A)
- `neo()` - LED animation function called every 125ms
- `neoInit(pixelCount)` - Initialize Neopixel LED strip (1-16 LEDs)
- `neoSetHSL(n, hue, saturation, lightness)` - Set LED color using HSL color model
- `neoSetColor(index, color, lightness)` - Set LED color using simplified color value

**Audio Functions:** (available to RX4M1S1N1A)
- `mpPlay(filesn, force)` - Play audio file from MY1690 audio module (filesn: 1-9999, force: playback behavior control)
- `mpVolume(value)` - Set audio playback volume level (0-30, 0 = silent, 30 = maximum)
- `onPlayerReady()` - Callback function called when audio module initialization completes

*For complete function documentation with parameters, return values, and usage notes, see the [API Reference](#api-reference) section below.*

**State Persistence**: Variables that need to retain values between `loop()` calls should be declared as `static` inside `loop()` or as global variables outside functions.

**Standard Library**: Common C standard library functions like `abs()` are available for mathematical operations.

### API Reference

::: details RX4M4S Standard Firmware Header File
<<< @/code/en/MeshMass-RX4M4S/RX4M4S/app.h{c:highlightLines}
:::

::: details RX4M3S1N Neopixel Variant Firmware Header File
<<< @/code/en/MeshMass-RX4M4S/RX4M3S1N/app.h{c:highlightLines}
:::

::: details RX4M1S1N1A Neopixel + Audio Variant Firmware Header File
<<< @/code/en/MeshMass-RX4M4S/RX4M1S1N1A/app.h{c:highlightLines}
:::

### Firmware-Managed Features

The scaffold handles several system functions automatically:
- **OLED Display**: Real-time debugging display showing channel values, motor outputs, and servo outputs
- **WS2812 Neopixels**: Addressable RGB LED strips for vehicle lights (shares signal pin with SM3)
- **Audio Module**: MP3 playback for sound effects (shares pins with SM1, SM2)
- **Wireless Communication**: Manages 2.4GHz packet reception with auto-hopping
- **Battery Monitoring**: Monitors input voltage and provides low-battery warnings


This separation allows users to focus on application logic (output mapping) while the firmware handles hardware complexities.

## System Architecture

MeshMass separates transmitter and receiver concerns:

- **TX6A4D (Transmitter)**: Maps physical inputs (joysticks, knobs, buttons) to 16 wireless channels
- **RX4M4S (Receiver)**: Maps received channels to physical outputs (motors, servos)

This abstraction lets users focus on what matters most for their specific build without worrying about RF protocol details. The transmitter defines *what* to send (channel values), while the receiver defines *how* to actuate (motor/servo outputs).

## Applications

RX4M4S is ideal for 3D printed construction vehicles and RC models. Sample applications and code templates are available on meshmass.com:

### Construction & Engineering Vehicles
- **Forklift**: 3 N20 motors + 1 9g servo for fork control
- **Dump Truck**: 1 370 motor for drive, 1 N20 motor for dump bed, 1 servo for steering
- **Excavator**: Multiple servos and motors for swing, boom, arm, and bucket control
- **Cranes**: Multi-axis control with precise servo positioning
- **Loader**: Articulated arm control with multiple servo channels

### RC Vehicles & Robotics
- **Tank**: Dual motor differential steering with turret control
- **RC Cars**: Throttle and steering with optional multi-gear transmission
- **Custom 3D printed vehicles**: Fully customizable control schemes
- **Small scale RC airplanes and drones**: Multi-channel control for flight surfaces
- **Custom robotics and automation**: Programmable multi-axis platforms

### Education & Display
- **STEM education projects**: Hands-on learning with immediate feedback
- **Sandbox models and dioramas**: Interactive display models
- **Maker projects**: Combine 3D printing with programmable motion

### Popular Kit Integration
Many 3D printing kit designers create models specifically designed for MeshMass compatibility. These kits often include:
- Pre-flashed firmware for immediate operation
- 3D models designed around the RX4M4S form factor
- Complete wiring diagrams and assembly instructions
- Custom mixing behaviors for specific vehicle types

## Discussion and Show Cases

- [Forum (Powered by GitHub Discussion)](https://github.com/aguegu/sourcekit.cc/discussions)
- [bilibili - 猥琐老虎 - 合集-可编程遥控模块](https://space.bilibili.com/24674093/lists/6826437)

## Where to Buy

- [Taobao - 猥琐老虎遥控玩物](https://dti9o8bd7lkwm7d4o9slcd2h6apezgn.taobao.com)

## Photos

![RX4M4S Receiver - Main view](/images/MeshMass-RX4M4S/main.png)

## Related Products

- [TX6A4D Transmitter](/MeshMass-TX6A4D) - Dual joystick transmitter module
- USB Flashing Dongle - Browser-based programming tool (coming soon)
