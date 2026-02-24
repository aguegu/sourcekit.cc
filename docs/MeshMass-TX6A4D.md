# Sourcekit® MeshMass TX6A4D

Version: 1.0.0

Designer: Weihong Guan [<span class="mdi mdi-github" style="color: #000;"></span>](https://github.com/aguegu/) [<span class="mdi mdi-twitter" style="color: #1da1f2;"></span>](https://twitter.com/BG5USN), Shengyuan Fang, Donghao Chen

## Overview

Sourcekit® MeshMass TX6A4D is a programmable remote control transmitter module designed for RC enthusiasts, STEM education, and the 3D printing community. It is the first product in the MeshMass series of affordable, programmable RC solutions.

The TX6A4D features dual joysticks, rotary knobs, and programmable buttons, making it ideal for building custom remote control systems for toys, brick builds, and 3D printed vehicles.

![TX6A4D Controller](/images/MeshMass-TX6A4D/main.jpg)

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
| Display Shows | Battery voltage, Wireless signal strength, Raw input values (6 analog: -127 to 127, 4 digital: 0/1) on TX6A4D; All 16 channel values (-128 to 127) on RX4M4S |
| Buzzer | Lost connection alarm |

**Display Note:** MeshMass shows raw decimal values (not scroll bars or progress indicators) for precise verification. Students can directly see how their code translates physical inputs to numerical outputs. The OLED screen is sold separately, making it optional for fixed installations and friendly to budget-conscious builders.

### Connectivity

| Feature | Description |
|---------|-------------|
| Wireless | 2.4GHz auto-hopping (BLE PHY layer only, no GATT) |
| Antenna | Onboard PCB antenna + IPEX-1 connector for external 2.4GHz antenna |
| Range | ~40 meters in open field (onboard PCB antennas), extends with external antenna |

## Pairing

MeshMass TX6A4D uses a secure one-to-one pairing system to establish exclusive wireless connections between transmitter and receiver modules. The pairing system ensures reliable communication and prevents interference from other nearby devices.

### EEPROM Storage

Pairing information is stored in **EEPROM** (Electrically Erasable Programmable Read-Only Memory), a non-volatile memory that retains data even when power is removed. Once a TX6A4D transmitter is paired with an RX4M4S receiver, their connection information persists across power cycles and reboots. This means you don't need to re-pair devices every time you use them—the established connection is automatically restored when both devices are powered on.

### One-to-One Exclusive Pairing

MeshMass pairing is **bi-directional and exclusive**:
- When a transmitter pairs with a new receiver, it loses access to any previously paired receiver
- When a receiver pairs with a new transmitter, its previous transmitter can no longer control it

This one-to-one relationship ensures that each transmitter controls exactly one receiver at a time, and each receiver responds to exactly one transmitter. If you need to control multiple receivers simultaneously, you'll need multiple transmitter modules.

### Pairing Process

To pair a TX6A4D transmitter with an RX4M4S receiver:

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
   - The OLED displays revert to showing input values and channel data
   - The devices are now paired and ready for use

**Note:** The pairing button is labeled "PAIR" on the PCB and is separate from the programmable shoulder buttons (BTN0-BTN3). It's controlled by the firmware and cannot be reprogrammed for other functions.

**Aborting Pairing:** If a device is in pairing mode, pressing the Pair button again will abort the pairing process. Since no new pairing information gets stored, the previous pairing record remains intact and will continue to be used when the device returns to normal mode.

## Programming

The TX6A4D is programmable via the [MeshMass online platform](https://meshmass.com). Users can:

- Map joystick axes, knobs, and buttons to output channels
- Create custom control mixing (e.g., tank steering, crane controls)
- Configure button behaviors for specific functions

Programming is done through a web browser using the MeshMass USB flashing dongle (sold separately). The CH571F runs pre-built firmware scaffolds that handle the low-level RF communication, while users focus on application-level input mapping logic.

> **Note**: The TX6A4D USB-C port is for charging only. Firmware flashing requires the separate USB dongle.

### Why Code-Based Programming?

Traditional RC control solutions fall into two categories with significant drawbacks:

**A. Complex Open Hardware Solutions**
- Require deep electronics knowledge to assemble and debug
- Involve multiple components (Arduino, RF modules, power regulation)
- Need complex software toolchains (Arduino IDE, platform configuration)
- High learning curve for beginners and hobbyists

**B. Expensive "Customizable" RC Controllers**
- Rely on complex menu systems with poor UX
- Limited to predefined mixing options
- Expensive ($200-500+ for comparable functionality)
- Cannot implement truly custom behaviors

**MeshMass TX6A4D: The Best of Both Worlds**
- **Simple**: Write clean C code with a minimal API
- **Powerful**: Programming flexibility for RC control without hardware complexity
- **Affordable**: Professional-grade control at hobbyist prices
- **Accessible**: Web-based editor, no complex toolchain installation
- **Example-Driven**: Comprehensive library of working code examples and tutorials for common use cases

### Competitive Comparison

| Feature | Traditional Open Hardware | Expensive RC Controllers | MeshMass TX6A4D |
|---------|---------------------------|--------------------------|-----------------|
| **Price** | Moderate ($50-100 + components) | High ($200-500+) | Affordable |
| **Learning Curve** | Steep (electronics + software) | Moderate (complex menus) | Gentle (simple C API) |
| **Flexibility** | High (but requires expertise) | Limited (predefined options) | Focused on RC control (code-based mapping) |
| **Setup Time** | Hours to days | Minutes to hours | Minutes |
| **Debugging** | Complex (hardware + software) | Limited (system menus) | Visual debugging via OLED (inputs & channels) |
| **Custom Behaviors** | Possible with expertise | Limited or impossible | Highly programmable mapping for RC scenarios |

### STEM Education Benefits

The TX6A4D transforms abstract math and programming concepts into tangible, interactive experiences:

**Math Comes Alive**
- **Variables & Functions**: Students see how `getStick(0)` reads physical joystick position
- **Coordinate Systems**: X/Y axes map directly to joystick movements (-127 to 127 range)
- **Algebraic Operations**: Mix inputs with `(getStick(1) + getStick(2)) / 2` for tank steering
- **Conditional Logic**: Implement safety features with `if (getButton(0)) { setChannel(0, 0); }`
- **Scaling & Transformation**: Apply `getStick(0) / 2` for reduced sensitivity

**Hands-On Learning Pipeline**
```c
// Student writes this code:
void loop() {
  // Math: Linear scaling with division
  setChannel(0, getStick(0) / 2);

  // Physics: Exponential response for fine control
  int8_t val = getStick(1);
  int8_t sign = (val > 0) ? 1 : ((val < 0) ? -1 : 0);
  setChannel(1, (val * val * sign) / 127);

  // Logic: Safety system with dual buttons
  if (getButton(0) && getButton(3)) {
    setChannel(2, getStick(2));  // Enable only when both safety buttons pressed
  } else {
    setChannel(2, 0);  // Emergency stop
  }
}
```

**Immediate Physical Feedback**
- Code changes → Immediate vehicle response
- Debug by watching the vehicle move
- **Visual debugging**: Watch input and channel values update on OLED displays in real-time (even without motors/servos attached)
- Learn programming through cause-and-effect
- No abstraction layers between code and physical motion

### From Idea to Working Controller

**Traditional Open Hardware Approach:**
1. Research components (2-4 hours)
2. Order parts, wait for delivery (3-7 days)
3. Assemble hardware, debug connections (4-8 hours)
4. Write firmware, debug RF communication (6-12 hours)
5. Test and refine (2-4 hours)
**Total: 15-35 hours over 3-7 days**

**MeshMass TX6A4D Approach:**
1. Plug in TX6A4D and USB dongle (2 minutes)
2. Select from pre-built examples or modify code in web editor (5-15 minutes)
3. Flash and test (1 minute)
4. Refine code as needed (5-15 minutes)
**Total: 10-30 minutes**

*With comprehensive examples and tutorials available on meshmass.com, most users can find working code for their specific use case in minutes. Beginners from the 3D printing community often find ready-to-use templates matching their vehicle designs.*

### Target Audiences

**For RC Enthusiasts:**
- Create professional-grade mixing that expensive transmitters can't match
- Implement custom behaviors for unique vehicles (tank steering, excavator controls)
- No more menu diving - just write the logic you need

**For STEM Education:**
- Teach real programming concepts with immediate physical feedback
- Students see their code control real hardware in minutes
- Perfect balance: simple enough for beginners, powerful enough for projects

**For 3D Printing Community:**
- Customize controls for your unique printed creations
- No electronics expertise needed - focus on your design
- Affordable way to bring custom vehicles to life

## Firmware Scaffold

The TX6A4D runs a pre-built firmware scaffold that handles low-level hardware operations while exposing a simple API for application programming. Key aspects of the firmware scaffold include:

### Channel System
The firmware defines 16 signed bytes (-128 to 127) as wireless channels. These channels form the communication bridge between transmitter and receiver. The value -128 is avoided by `getStick()` outputs to enable clean direction reversal in joystick inputs, but channels can be set to -128 for special purposes (e.g., braking in motor control):
- Channels 0-5: Typically mapped to analog inputs (joysticks, knobs)
- Channels 6-15: Available for custom mapping (buttons, logic, mixing)

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

### Application Code Examples
The scaffold provides a simple API for reading inputs and setting channels. Users have complete flexibility in mapping inputs to channels, enabling complex control behaviors. Here's an example showing various mapping techniques using proper stdint.h types:

**Architecture Note:** The code on TX6A4D only controls the mapping from physical inputs (joysticks, knobs, buttons) to wireless channels. How these channel values are interpreted and reflected on the receiver module (RX) or vehicle is determined by the application code running on the RX modules.

**Note:** The `app.h` header file already includes `<stdbool.h>` and `<stdint.h>` headers, so you don't need to include them in your application code. On meshmass.com, you can view the `app.h` file for reference, but it's not recommended to edit it.

**Timing Note:** The `loop()` function is called every 20ms (50 times per second, or 50Hz), which matches the typical update frequency of analog servos. This consistent timing ensures smooth control updates.

**Firmware Cycle Details:** Before each `loop()` call, the firmware automatically refreshes all analog inputs (joysticks, knobs) and digital inputs (buttons), storing their latest values in memory. The `getStick()` and `getButton()` functions simply return these pre-fetched values. During `loop()`, `setChannel()` updates values in a 16-byte transmission frame buffer. Channels not explicitly set retain their previous values. After `loop()` completes, the entire frame buffer (all 16 int8_t channel values) is broadcast wirelessly.

**Important:** Avoid using busy-waiting or delay functions inside `loop()`. The firmware runs a Real-Time Operating System (RTOS) in the background. Blocking operations can prevent critical system tasks from running, potentially causing system failures or unpredictable behavior.

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
    setChannel(10, 127);  // Full forward when safety + trigger pressed
  } else {
    setChannel(10, 0);    // Stop otherwise
  }
}
```

### API Functions
- `int8_t getStick(uint8_t n)`: Returns signed 8-bit value (-127 to 127) from analog input `n` (0-5). Value -128 is avoided by firmware to enable clean direction reversal.
- `bool getButton(uint8_t n)`: Returns boolean value `false` (not pressed) or `true` (pressed) for digital button `n` (0-3)
- `int8_t getChannel(uint8_t n)`: Returns current signed 8-bit value of channel `n` (0-15)
- `void setChannel(uint8_t n, int8_t value)`: Sets channel `n` to `value` (-128 to 127). Note: While `getStick()` avoids -128 to enable clean direction reversal, `setChannel()` can use -128 for special purposes like braking in motor control.
- `void loop()`: Application main loop function called every 20ms (50Hz). Implement this function to define your control logic.

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

### Firmware-Managed Features
The scaffold handles several system functions automatically:
- **OLED Display**: Real-time debugging display showing battery voltage, wireless signal strength, and all input values (6 analog: -127 to 127, 4 digital: 0/1). RX4M4S displays all 16 channel values (-128 to 127) for complete system inspection. Displays raw decimal values (not simplified visualizations) for precise code verification. The OLED is sold separately, making it optional for fixed installations while maintaining budget-friendly flexibility.
- **Buzzer**: Provides lost connection alarms and system feedback
- **Wireless Communication**: Manages 2.4GHz packet transmission with auto-hopping
- **Battery Management**: Monitors voltage and provides low-battery warnings

This separation allows users to focus on application logic (channel mapping) while the firmware handles hardware complexities.

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
- [bilibili - CDHCHAOREN - Programmable RC module](https://space.bilibili.com/24674093/lists/6826437)

## Where to Buy

- [Taobao - cdhchaoren](https://dti9o8bd7lkwm7d4o9slcd2h6apezgn.taobao.com)

## Related Products

- [RX4M4S Receiver](/MeshMass-RX4M4S) - 4 DC Motor + 4 Servo receiver module
- USB Flashing Dongle - Browser-based programming tool (coming soon)
