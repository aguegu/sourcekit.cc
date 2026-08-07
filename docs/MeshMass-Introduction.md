# MeshMass Programmable RC System

**Official Online Platform:**
- **Global Access**: [meshmass.com](https://meshmass.com)
- **China Mainland Access**: [meshmass.y77.cc](https://meshmass.y77.cc)

## Overview

MeshMass is a family of affordable, programmable remote control modules designed for RC enthusiasts, STEM education, and the 3D printing community. The system consists of:

- **TX6A4D Transmitter**: Programmable controller with dual joysticks, rotary knobs, and buttons
- **RX4M4S Receiver**: 4-channel DC motor + 4-channel servo receiver with built-in motor drivers

Together, they form a complete wireless control system that bridges the gap between complex open hardware solutions and expensive proprietary RC systems.

## Design Philosophy

### Why Code-Based Programming?

Traditional RC control solutions fall into two categories with significant drawbacks:

**A. Complex Open Hardware Solutions**
- Require deep electronics knowledge to assemble and debug
- Involve multiple components (Arduino, RF modules, motor drivers, power regulation)
- Need complex software toolchains (Arduino IDE, platform configuration)
- High learning curve for beginners and hobbyists

**B. Expensive "Customizable" RC Systems**
- Rely on complex menu systems with poor UX
- Limited to predefined mixing options
- Expensive ($200-500+ for comparable functionality)
- Cannot implement truly custom behaviors

**MeshMass: The Best of Both Worlds**
- **Simple**: Write clean C code with minimal APIs focused on input/output mapping
- **Powerful**: Programming flexibility for RC control without hardware complexity
- **Affordable**: Professional-grade control at hobbyist prices
- **Accessible**: Web-based editor, no complex toolchain installation
- **Example-Driven**: Comprehensive library of working code examples and tutorials for common use cases

## Competitive Advantages

### Space Efficiency & Integration
- **Single PCB Solution**: 40mm × 60mm RX4M4S replaces receiver + 4 ESCs + wiring mess
- **Traditional Approach**: Multiple boards stacked with wires, difficult to mount in tight 3D printed spaces
- **Benefit**: Clean integration into designed models without redesigning body to fit components

### Total System Cost Advantage
- **MeshMass TX6A4D + RX4M4S**: Less expensive than Flysky transmitter alone
- **Traditional**: Flysky transmitter ($30+) + receiver ($30) + 4 ESCs ($40+) + wiring = $100+
- **Benefit**: Professional-grade control at hobbyist price point

### Programming Accessibility
- **Text-based C**: Reveals underlying math (e.g., `150 + centered(4, 0) * 2 / 5`)
- **Educational value**: Users see formulas controlling physical movement
- **vs. Visual programming**: Blocks obscure math, take more screen space for simple logic
- **Scaffold approach**: Low-level code (RTOS, RF, drivers) pre-built; users only write mapping logic

### Reusability & Flexibility
- **Easy re-flashing**: Modules can move between different prints
- **Traditional RC**: Complex menu navigation or physical rewiring required
- **One firmware, configurable board**: Two switches in the receiver's program decide whether the shared headers drive servos, a Neopixel strip, or an audio module — 4 motors + 4 servos by default, down to 4 motors + 1 servo with both accessories fitted

### Easy Visual Debugging
- **Firmware verification without executors**: Verify code without plugging in oscilloscopes or logic analyzers (which can be powerful but dangerous)
- **Transmitter-focused status display**: Battery voltage and signal strength shown on transmitter OLED (user holds it in hand)
- **Receiver-focused output debugging**: Channel values, motor outputs, and servo outputs shown on receiver OLED (for mapping verification)
- **Usage-aligned design**: Transmitter in hand for system status monitoring, receiver remote for output behavior verification
- **Immediate feedback**: Students see how code changes affect physical outputs in real-time


## System Architecture

### Separation of Concerns
The MeshMass system splits responsibilities between transmitter and receiver, but **not evenly** — and the imbalance is deliberate:

- **TX6A4D (Transmitter)**: Reads the physical inputs and forwards them raw onto 16 wireless channels. One program, the same on every controller.
- **RX4M4S (Receiver)**: Interprets those channels and drives everything physical — motors, servos, lights, sound. This is where a build's behaviour lives.

The reason is simply what the two ends *are*. A controller always looks the same: two sticks, two knobs, four buttons, held in your hands. A receiver gets bolted into a different machine every time — a tank, an excavator, a forklift, a dump truck — each wanting its own mixing, its own limits, its own lights and engine sounds.

The Neopixel and audio interfaces sharpen the point. The receiver decides not only how a stick becomes track speed, but when the brake lights come on and when the engine note changes. Splitting that behaviour across both ends would mean editing two programs, on two boards, to change one vehicle.

So the transmitter makes no decisions. It measures and forwards; the receiver owns the interpretation. Flash a controller once and it works with every vehicle you go on to build — and when you change a vehicle, you reprogram that vehicle.

### Channel-Based Communication
- **16 Wireless Channels**: Single bytes transmitted between devices
- **Raw readings on the wire**: The transmitter sends each analog input as an unsigned `0`-`255` reading (~`128` at centre); centring, deadzone, scaling and mixing are the receiver's job
- **Flexible Routing**: Any input can map to any output through simple code
- **Real-time Performance**: 50Hz update rate matches servo refresh, minimum latency wireless

### Typical Signal Flow
```
TX6A4D Joystick → getStick() → setChannel() → Wireless Transmission
                                                              ↓
RX4M4S Reception → getChannel() → setMotor()/setServo() → Motor/Servo
```

All mappings are configurable through the MeshMass online platform at [meshmass.com](https://meshmass.com) (global access) or [meshmass.y77.cc](https://meshmass.y77.cc) (China mainland).

## Scaffold Programming Approach

### Pre-built Foundation
- **Low-level code already written**: RF communication, timing, hardware drivers
- **Safety features built-in**: Connection loss handling, failsafe values, hardware protection
- **Real-time operating system**: Manages multiple tasks without user intervention

### Focus on Application Logic
Users only write the code that matters for their specific vehicle:
- Input-to-channel mapping on transmitter
- Channel-to-output mapping on receiver
- Mixing functions for complex behaviors
- No need to understand wireless protocols or PWM timing details

### Development Workflow
**Traditional Open Hardware Approach:**
1. Research components (2-4 hours)
2. Order parts, wait for delivery (3-7 days)
3. Assemble hardware, debug connections (4-8 hours)
4. Write firmware, debug RF communication (6-12 hours)
5. Test and refine (2-4 hours)
**Total: 15-35 hours over 3-7 days**

**MeshMass Approach:**
1. Plug in module and USB dongle (2 minutes)
2. Select from pre-built examples or modify code in web editor (5-15 minutes)
3. Flash and test (1 minute)
4. Refine code as needed (5-15 minutes)
**Total: 10-30 minutes**

*With comprehensive examples and tutorials available on meshmass.com, most users can find working code for their specific use case in minutes. Beginners from the 3D printing community often find ready-to-use templates matching their vehicle designs.*

## Educational Value

### Math Comes Alive
- **Variables & Functions**: Students see how `getChannel(0)` reads the joystick position the transmitter sent
- **Number Ranges & Signs**: A stick arrives as an unsigned `0`-`255` reading; subtracting the centre turns it into a signed `-127`-`127` value where the sign *is* the direction
- **Coordinate Systems**: X and Y axes of a stick become two independent numbers to combine
- **Algebraic Operations**: Arcade steering falls out of two lines — `left = Y - X`, `right = Y + X` — and students can reason about why one track speeds up as the other slows
- **Conditional Logic**: Implement safety features with `if (getChannel(6)) { setMotor(0, 0); }`
- **Scaling & Transformation**: Divide to cap top speed, or normalise a mixed result so full stick throw doesn't clip

### Immediate Physical Feedback
- Code changes → Immediate vehicle response
- Debug by watching the vehicle move
- **Visual debugging**: Watch input and channel values update on OLED displays in real-time
- Learn programming through cause-and-effect
- No abstraction layers between code and physical motion

### Progressive Learning Path
1. **Start with pre-flashed kits**: Kit designers provide ready-to-use firmware
2. **Modify existing examples**: Adjust parameters and mixing behaviors
3. **Create custom mappings**: Write original code for unique vehicle designs
4. **Advanced programming**: Implement complex logic and state machines

## Target Audiences

### For RC Enthusiasts
- Create professional-grade mixing that expensive transmitters can't match
- Implement custom behaviors for unique vehicles (tank steering, excavator controls)
- No more menu diving - just write the logic you need

### For STEM Education
- Teach real programming concepts with immediate physical feedback
- Students see their code control real hardware in minutes
- Perfect balance: simple enough for beginners, powerful enough for projects

### For 3D Printing Community
- Customize controls for your unique printed creations
- No electronics expertise needed - focus on your design
- Affordable way to bring custom vehicles to life

## Ecosystem Strategy

### Kit Designer Support
- Designers like CDHCHAOREN pre-flash firmware for specific models
- Community integration: Designers get columns on meshmass.com linking to their stores, Makerworld pages, video channels
- Business model: Grow together with 3D printing community creators

### Future Expansion
1. **Additional board configurations** for specialized applications
2. **Expanded accessory ecosystem** (audio modules, LED effects)
3. **Educational partnerships** with STEM programs
4. **Integration with 3D modeling software** for automatic firmware generation
5. **Advanced mixing libraries** for complex vehicle behaviors

## Pairing System

MeshMass uses a secure one-to-one pairing system to establish exclusive wireless connections between transmitter and receiver modules. The pairing system ensures reliable communication and prevents interference from other nearby devices.

### EEPROM Storage

Pairing information is stored in **EEPROM** (Electrically Erasable Programmable Read-Only Memory), a non-volatile memory that retains data even when power is removed. Once a transmitter and receiver are paired, their connection information persists across power cycles and reboots. This means you don't need to re-pair devices every time you use them—the established connection is automatically restored when both devices are powered on.

### One-to-One Exclusive Pairing

MeshMass pairing is **bi-directional and exclusive**:
- When a transmitter pairs with a new receiver, it loses access to any previously paired receiver
- When a receiver pairs with a new transmitter, its previous transmitter can no longer control it

This one-to-one relationship ensures that each transmitter controls exactly one receiver at a time, and each receiver responds to exactly one transmitter. If you need to control multiple receivers simultaneously, you'll need multiple transmitter modules.

### Pairing Process

To pair a MeshMass transmitter with a receiver:

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

**Aborting Pairing:** If a device is in pairing mode, pressing the Pair button again will abort the pairing process. Since no new pairing information gets stored, the previous pairing record remains intact and will continue to be used when the device returns to normal mode.

*See individual product pages for device-specific pairing button locations and details. The pairing button is labeled "PAIR" on the PCB and is controlled by firmware—it cannot be reprogrammed for other functions.*

## Getting Started

1. **Choose your modules**: [TX6A4D Transmitter](/MeshMass-TX6A4D) and [RX4M4S Receiver](/MeshMass-RX4M4S)
2. **Visit the MeshMass online platform** at [meshmass.com](https://meshmass.com) (global access) or [meshmass.y77.cc](https://meshmass.y77.cc) (China mainland): Access the web-based programming platform
3. **Get the USB flashing dongle**: Required for programming (sold separately)
4. **Explore examples**: Start with pre-built code for common vehicle types
5. **Join the community**: [Forum discussions](https://github.com/aguegu/sourcekit.cc/discussions) and [show cases](https://space.bilibili.com/24674093/lists/6826437)

## Upgrading the Firmware

We recommend running **TX6AX** on the transmitter and **RX4MX** on the receiver. These are the current firmwares, and every lesson and example is written for them.

Flash both ends to the same generation. An earlier firmware carried a *signed* `-127`-`127` channel value and did its centring and mixing on the transmitter; mixing generations gives you a link that connects but behaves wrongly. That earlier firmware is still supported for boards already running it, but it is deprecated — new lessons and examples target TX6AX and RX4MX only.

**Pairing survives the upgrade.** The pairing is held in EEPROM and stays valid across a re-flash, so a paired set keeps working — there is no need to pair the boards again.

If you wrote your own code against the earlier API, port it as follows.

**Porting a receiver program:**

| Then | Now |
|---|---|
| Pick a firmware build per accessory combination (`RX4M3S1N`, `RX4M1S1N1A`, …) | One firmware; set `AUDIO_ON_SM1_SM2` and `NEO_ON_SM3` at the top of `app.h` |
| `getChannel()` returned a centred, signed `-127`-`127` | Returns a raw unsigned `0`-`255`; wrap stick reads in [`centered()`](/MeshMass-RX4M4S#centring-a-stick-channel) |
| `setServo()` indexed the servos that existed in that build | Indexes the **SM header label**, so a config with audio fitted has servos `0` and `3` |
| `neoInit(count)` | `neoSetup(count)` |

**Porting a transmitter program:** in most cases, don't. Mixing, deadzone and scaling now belong on the receiver, so the stock TX6AX program is usually all you need — the logic you wrote on the transmitter moves to the vehicle instead.

---

*MeshMass brings professional RC control within reach of hobbyists, educators, and makers through accessible programming.*