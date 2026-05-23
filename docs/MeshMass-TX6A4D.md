# Sourcekit® MeshMass TX6A4D

Version: 1.0.0

Designer:
Weihong Guan [<span class="mdi mdi-github" style="color: #000;" />](https://github.com/aguegu/) [<span class="mdi mdi-twitter" style="color: #1da1f2;" />](https://twitter.com/BG5USN),
Shengyuan Fang,
Donghao Chen [<span class="mdi mdi-printer-3d-nozzle" style="color: #0c0;"/>](https://makerworld.com.cn/zh/@cdhchaoren) [<span class="mdi mdi-television-classic" style="color: #00C;" />](https://space.bilibili.com/24674093)

## Overview

Sourcekit® MeshMass TX6A4D is a programmable remote control transmitter module designed for RC enthusiasts, STEM education, and the 3D printing community. It is the first product in the MeshMass series of affordable, programmable RC solutions.

The TX6A4D features dual joysticks, rotary knobs, and programmable buttons, making it ideal for building custom remote control systems for toys, brick builds, and 3D printed vehicles.

![TX6A4D Controller](/images/MeshMass-TX6A4D/main.png)

```
       ┌──┐     ┌──┐                                 ┌──┐     ┌──┐         
┌────┬─└──┘─┬─┬─└──┘─┬──┬─────────────┬────┬────┬──┬─└──┘─┬─┬─└──┘─┬────┐  
│    │ BTN0 │ │ BTN1 │  │ Onboard ANT │    │PROG│  │ BTN2 │ │ BTN3 │    │  
│    └──────┘ └──────┘  └─────────────┘    └────┘  └──────┘ └──────┘┌───┌─┐
│                        ┌───┐                                      │PWR└─┘
│          STK2          │EXT│     SOURCEKIT             STK1       │ SW│  
│            ▲           │ANT│     MeshMass                ▲        └───┤  
│            │           └───┘     TX6A4D                  │            │  
│     ◄──────┼──────► STK3                     STK0 ◄──────┼──────►     │  
│            │                  ┌────┐ ┌────┐              │            │  
│            ▼                  │OLED│ │PAIR│              ▼            │  
│                               └────┘ └────┘                     ┌─────┤  
│                       ┌──────┐         ┌──────┐      ┌────────┐ │ USB │  
│ ┌──────┐              │      │         │      │      │DC Power│ │CHARGE  
│ │BUZZER│              │ STK4 │         │ STK5 │      │3.7-4.2v│ └─────┤  
│ └──────┘              │      │         │      │      │ +    - │       │  
└───────────────────────┴──────┴─────────┴──────┴──────┴────────┴───────┘  
```

## Features

- **Dual Joysticks**: Two dual-axis joysticks providing 4 analog input channels
- **Rotary Knobs**: 2 knobs providing 2 analog input channels, programmable for throttle, speed or parameter adjustment
- **Programmable Buttons**: 4 shoulder buttons + 2 joystick press buttons for custom functions
- **OLED Display Interface**: 6-pin SH1.0 connector supports 128x64 SPI OLED (sold separately) showing battery voltage, signal strength, and raw input values
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
| **A**nalog | 6 | 4 from joysticks, 2 from knobs |
| **D**igital | 4 | 4 programmable shoulder buttons + 2 joystick press buttons (parallel-connected) |
| System | 1 | Pairing button (firmware-controlled) |

**Note:** Each joystick includes a built-in press button:
- **Left Joystick Press**: Connected in parallel with left edge button (Button 0 / BTN0, `getButton(0)`)
- **Right Joystick Press**: Connected in parallel with right edge button (Button 3 / BTN3, `getButton(3)`) |

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
| Display Interface | 6-pin SH1.0 connector, SPI interface for 128x64 OLED (sold separately with cable) |
| Programming Interface | 6-pin SH1.0 connector for MeshMass USB Flashing Dongle (sold separately with cable), also provides serial console output (OLED display recommended for visual debugging) |
| Display Shows | Battery voltage, Wireless signal strength, Raw input values (6 analog: -127 to 127, 4 digital: 0/1) on TX6A4D; Debugging values including channel values, motor outputs, and servo outputs on RX4M4S |
| Buzzer | Lost connection alarm |

**Display Note:** MeshMass shows raw decimal values (not scroll bars or progress indicators) for precise verification. Students can directly see how their code translates physical inputs to numerical outputs. The transmitter OLED displays system status (battery voltage, signal strength) since the user holds it in hand, while the receiver OLED focuses on output debugging. The OLED screen is sold separately, making it optional for fixed installations and friendly to budget-conscious builders.

### Connectivity

| Feature | Description |
|---------|-------------|
| Wireless | 2.4GHz auto-hopping (BLE PHY layer only, no GATT) |
| Antenna | Onboard PCB antenna + IPEX-1 connector for external 2.4GHz antenna |
| Range | ~40 meters in open field (onboard PCB antennas), extends with external antenna |

## Pairing

The TX6A4D follows the standard MeshMass pairing system described in the [MeshMass Introduction](/MeshMass-Introduction#pairing-system). Key details specific to the TX6A4D:

- The pairing button is labeled **"PAIR"** on the PCB, separate from the programmable shoulder buttons (BTN0-BTN3)
- It's controlled by firmware and cannot be reprogrammed for other functions
- The OLED display shows pairing status and confirmation

For complete pairing instructions including EEPROM storage, one-to-one exclusive pairing, and the detailed pairing process, refer to the [Pairing System](/MeshMass-Introduction#pairing-system) section in the MeshMass Introduction.

## Development Guide

The TX6A4D is programmable via the MeshMass online platform at [meshmass.com](https://meshmass.com) (global access) or [meshmass.y77.cc](https://meshmass.y77.cc) (China mainland) using a web browser and the MeshMass USB flashing dongle (sold separately). The CH571F runs pre-built firmware scaffolds that handle low-level RF communication, while users focus on application-level input mapping logic.

> **Note**: The TX6A4D USB-C port is for charging only. Firmware flashing requires the separate USB dongle.

### Programming Philosophy

MeshMass adopts a code-based programming approach that combines open hardware flexibility with consumer product accessibility. For detailed discussion of design philosophy, competitive advantages, educational value, and system architecture, see the [MeshMass Introduction](/MeshMass-Introduction) page.

**Key advantages for TX6A4D:**
- Simple C API for mapping physical inputs to wireless channels
- Web-based programming with immediate visual feedback via OLED
- Comprehensive library of examples for common RC scenarios

**What you program:** On TX6A4D, you define how physical inputs (joysticks, knobs, buttons) map to 16 wireless channels. How these channels control motors and servos is determined by the receiver (RX) firmware.

## Firmware Architecture

The TX6A4D runs a pre-built firmware scaffold that handles low-level hardware operations while exposing a simple API for application programming. This architecture separates hardware complexity from application logic, allowing users to focus on channel mapping.

### Channel System
The firmware defines 16 signed bytes (-128 to 127) as wireless channels. These channels form the communication bridge between transmitter and receiver. Applications map physical inputs (joysticks, knobs, buttons) to these channels, which are then transmitted wirelessly to paired receivers.

**PCB Labels:** The PCB is labeled with STK0-STK5 for analog inputs and BTN0-BTN3 for digital buttons, corresponding directly to API indices.

**Analog Input Mapping** (via `getStick(n)`):
| Index | PCB Label | Physical Input          | Description                               |
|-------|-----------|-------------------------|-------------------------------------------|
| 0     | STK0      | Right Joystick X-axis   | Left/right movement of right stick        |
| 1     | STK1      | Right Joystick Y-axis   | Up/down movement of right stick           |
| 2     | STK2      | Left Joystick Y-axis    | Up/down movement of left stick            |
| 3     | STK3      | Left Joystick X-axis    | Left/right movement of left stick         |
| 4     | STK4      | Knob Left               | Rotary knob, typically for throttle       |
| 5     | STK5      | Knob Right              | Rotary knob, typically for parameter      |

**Digital Input Mapping** (via `getButton(n)`):
| Index | PCB Label | Physical Input          | Description                               |
|-------|-----------|-------------------------|-------------------------------------------|
| 0     | BTN0      | Button 0 (left edge)    | Programmable shoulder button + left joystick press |
| 1     | BTN1      | Button 1 (left middle)  | Programmable shoulder button              |
| 2     | BTN2      | Button 2 (right middle) | Programmable shoulder button              |
| 3     | BTN3      | Button 3 (right edge)   | Programmable shoulder button + right joystick press |
| -     | PAIR      | Pairing Button          | System button (firmware-controlled)       |

**Note:** Joystick press buttons are connected in parallel with shoulder buttons:
- **Left Joystick Press**: Activates `getButton(0)` (same as Button 0 / left edge button)
- **Right Joystick Press**: Activates `getButton(3)` (same as Button 3 / right edge button) |

### Timing and Execution

**Execution Model:** The `loop()` function is called every 20ms (50Hz) by the firmware scaffold. This matches the typical update frequency of analog servos, ensuring smooth control updates.

**Firmware Cycle Details:** Before each `loop()` call, the firmware automatically refreshes all analog inputs (joysticks, knobs) and digital inputs (buttons), storing their latest values in memory. The `getStick()` and `getButton()` functions return these pre-fetched values. During `loop()`, `setChannel()` updates values in a 16-byte transmission frame buffer. Channels not explicitly set retain their previous values. After `loop()` completes, the entire frame buffer (all 16 int8_t channel values) is broadcast wirelessly.

**Important:** Avoid using busy-waiting or delay functions inside `loop()`. The firmware runs a Real-Time Operating System (RTOS) in the background. Blocking operations can prevent critical system tasks from running, potentially causing system failures or unpredictable behavior.

### Application Code Examples

The scaffold provides a simple API for reading inputs and setting channels. Users have complete flexibility in mapping inputs to channels, enabling complex control behaviors. Here's an example showing various mapping techniques using proper stdint.h types:

**Architecture Note:** The code on TX6A4D only controls the mapping from physical inputs (joysticks, knobs, buttons) to wireless channels. How these channel values are interpreted and reflected on the receiver module (RX) or vehicle is determined by the application code running on the RX modules.

**Note:** The `app.h` header file already includes `<stdbool.h>` and `<stdint.h>` headers, so you don't need to include them in your application code. On meshmass.com, you can view the `app.h` file for reference, but it's not recommended to edit it.

```c
#include "app.h"

// Variables that persist between loop() calls should be declared globally
// or as static inside loop() (using 'static' keyword)
static bool button2_was_pressed = false;  // Tracks button 2 press state

void loop() {
  // --- Basic Input Mapping Examples ---

  // Example 1: Direct mapping - stick 0 controls channel 0
  // Stick values range from -127 (full left/down) to 127 (full right/up)
  setChannel(0, getStick(0));

  // Example 2: Reversed mapping - stick 1 controls channel 1 with inverted direction
  // Useful for motors that need opposite rotation direction
  setChannel(1, -getStick(1));

  // Example 3: Scaled mapping - stick 2 controls channel 2 with halved sensitivity
  // Divide by 2 to reduce sensitivity for fine control applications
  setChannel(2, getStick(2) / 2);

  // Example 4: Mixed control - use stick 3 for auxiliary control
  setChannel(3, getStick(3));

  // Example 5: Deadzone handling - ignore small stick movements near center
  // Prevents unintended movements from joystick drift
  if (abs(getStick(4)) > 10) {
    setChannel(4, getStick(4));
  } else {
    setChannel(4, 0);  // Center position when stick is near middle
  }

  // --- Button Control Examples ---

  // Example 6: Button-controlled increment/decrement
  // Button 0 increases channel 6, Button 1 decreases it (range-limited)
  if (getButton(0) && getChannel(6) < 127) {
    setChannel(6, getChannel(6) + 1);
  }
  if (getButton(1) && getChannel(6) > -127) {
    setChannel(6, getChannel(6) - 1);
  }

  // Example 7: Button latch - toggle channel 7 on button press
  // Pressing button 2 toggles channel 7 between positive and negative values
  if (getButton(2) && !button2_was_pressed) {
    setChannel(7, -getChannel(7));  // Toggle between positive and negative
    button2_was_pressed = true;     // Mark button as pressed
  }
  if (!getButton(2)) {
    button2_was_pressed = false;    // Reset when button released
  }

  // --- Advanced Mixing Examples ---

  // Example 8: Complex mixing - combine multiple inputs for tank steering
  // Right and left vertical stick averaging for differential drive vehicles
  setChannel(8, (getStick(1) + getStick(2)) / 2);

  // Example 9: Exponential response for fine control
  // Square the stick value (preserving sign) for non-linear response
  int8_t stick_val = getStick(5);
  int8_t sign = (stick_val > 0) ? 1 : ((stick_val < 0) ? -1 : 0);
  setChannel(9, (stick_val * stick_val * sign) / 127);

  // Example 10: Dual-button safety latch - requires two buttons pressed
  // Button 3 acts as safety, must be held while button 2 triggers action
  if (getButton(3) && getButton(2)) {
    setChannel(10, 127);  // Full speed in one direction when safety + trigger pressed
  } else {
    setChannel(10, 0);    // Stop otherwise
  }
}
```

### Quick Reference

**Core Functions:**
- `getStick(n)` - Read analog input (joystick/knob) value (-127 to 127)
- `getButton(n)` - Read digital button state (true/false)
- `setChannel(n, value)` - Set wireless channel value (-128 to 127)
- `getChannel(n)` - Get current channel value
- `loop()` - Main application function called every 20ms

*For complete function documentation with parameters, return values, and usage notes, see the [API Reference](#api-reference) section below.*

**State Persistence**: Variables that need to retain values between `loop()` calls should be declared as `static` inside `loop()` or as global variables outside functions.

**Standard Library**: Common C standard library functions like `abs()` are available for mathematical operations.

The API enables flexible mappings:
- **Direct mapping**: `setChannel(0, getStick(0))`
- **Reversed direction**: `setChannel(1, -getStick(1))`
- **Scaled sensitivity**: `setChannel(2, getStick(2) / 2)`
- **Deadzone handling**: Conditionally set channels based on input thresholds
- **Button latch**: Toggle channels on button presses using state variables
- **Button increment/decrement**: Adjust channel values with button presses
- **Exponential response**: Non-linear mapping for fine control (e.g., `(stick*stick)/127`)
- **Dual-button safety**: Require multiple buttons pressed simultaneously for safety-critical functions
- **Complex mixing**: Combine multiple inputs with mathematical operations

### API Reference
::: details TX6A4D Application Header File
<<< @/code/en/MeshMass-TX6A4D/app.h{c}
:::

### Firmware-Managed Features
The scaffold handles several system functions automatically:
- **OLED Display**: Real-time debugging display showing battery voltage, wireless signal strength, and all input values (6 analog: -127 to 127, 4 digital: 0/1). RX4M4S displays debugging values including channel values, motor outputs, and servo outputs for system inspection and mapping verification. Displays raw decimal values (not simplified visualizations) for precise code verification. The OLED is sold separately, making it optional for fixed installations while maintaining budget-friendly flexibility.
- **Buzzer**: Provides lost connection alarms and system feedback
- **Wireless Communication**: Manages 2.4GHz packet transmission with auto-hopping
- **Battery Management**: Monitors voltage and provides low-battery warnings

This separation allows users to focus on application logic (channel mapping) while the firmware handles hardware complexities.

## System Architecture

MeshMass separates transmitter and receiver concerns:

- **TX6A4D (Transmitter)**: Maps physical inputs (joysticks, knobs, buttons) to 16 wireless channels
- **RX4M4S (Receiver)**: Maps received channels to physical outputs (motors, servos)

This abstraction lets users focus on what matters most for their specific build without worrying about RF protocol details. The transmitter defines *what* to send (channel values), while the receiver defines *how* to actuate (motor/servo outputs).

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

## 3D Printing & Customization

The TX6A4D is designed with the 3D printing community in mind. Community members have created custom designs to enhance your building experience:

- **3D Printed Case Design**: [CDHCHAOREN](https://makerworld.com.cn/zh/@cdhchaoren) has designed a 3D printable case for the TX6A4D. The STL file is available for download on [MakerWorld](https://makerworld.com.cn/zh/models/2193372-16tong-dao-ke-bian-cheng-zi-ding-yi-shua-ji-yao-ko). This simple enclosure protects the electronics and provides mounting support (requires 3D printer and filament).

The TX6A4D's M2.5 mounting holes make it easy to integrate into custom 3D printed enclosures or vehicle designs. Share your creations with the community!

## Discussion and Show Cases

- [Forum (Powered by GitHub Discussion)](https://github.com/aguegu/sourcekit.cc/discussions)
- [bilibili - CDHCHAOREN - Programmable RC module](https://space.bilibili.com/24674093/lists/6826437)
- [MakerWorld - 3D printed case for TX6A4D by CDHCHAOREN](https://makerworld.com.cn/zh/models/2193372-16tong-dao-ke-bian-cheng-zi-ding-yi-shua-ji-yao-ko)

## Where to Buy

- [Taobao - cdhchaoren](https://dti9o8bd7lkwm7d4o9slcd2h6apezgn.taobao.com)

## Related Products

- [RX4M4S Receiver](/MeshMass-RX4M4S) - 4 DC Motor + 4 Servo receiver module
- USB Flashing Dongle - Browser-based programming tool (coming soon)
