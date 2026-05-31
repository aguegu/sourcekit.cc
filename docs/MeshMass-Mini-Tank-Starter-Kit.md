# MeshMass Mini Tank Starter Kit

Author: Weihong Guan [<span class="mdi mdi-github" style="color: #000;" />](https://github.com/aguegu/) [<span class="mdi mdi-twitter" style="color: #1da1f2;" />](https://twitter.com/BG5USN)

## Overview

The **Mini Tank Starter Kit** is a beginner-friendly, 3D-printable tank chassis kit that uses the MeshMass **TX6A4D** transmitter and **RX4M4S** receiver to make a complete programmable RC tank. This page is the **teacher's guide** for delivering the kit as a structured lesson.

The lesson targets **STEM education** classrooms with native-English teachers and ~10-year-old students (~2 years of English background). It is **hands-on first** - students discover concepts by touching parts and running experiments before any programming.

## At a Glance

This page is the teacher's guide for the Mini Tank lesson, organised in two sessions:

- **Session 1: Get Running First!** - electronics, mechanics, and hardware. Five hands-on experiments take students from a single battery and motor all the way to a fully assembled, wireless-controlled tank. No programming.
- **Session 2: Code Your Tank** *(work in progress)* - programming the receiver's MCU to customise how the tank responds.

Reference sections at the back: **Learning Path**, **Bill of Materials**, **Specifications**, **Related Products**.

## Pre-class Preparation

Before delivering Session 1, the teacher should:

- **Charge both batteries** (the 1S LiPo for the TX6A4D and the 2S LiPo for the RX4M4S). New packs ship partially charged, and the kit's chargers take longer than a 3-hour class to fill them.
- **Confirm the right firmware is on each board** (the kit ships pre-flashed; re-flash from the MeshMass platform if needed):
  - **RX4M4S**: [`05-OnDisconnect`](https://meshmass.y77.cc/#/courses/3057237/lessons/05-OnDisconnect)
  - **TX6A4D**: [`20-MiniTank`](https://meshmass.y77.cc/#/courses/2979972/lessons/20-MiniTank)
- **Pair both boards once** — this also verifies the firmware. Power both on and hold each board's **PAIR** button for 5+ seconds; the OLEDs confirm the link.
  - **Recommendation:** pair one kit at a time if multiple are being set up — otherwise boards can accidentally pair with the wrong partner.
  - Pairing is sticky across power cycles, so it only needs doing once after re-flashing.
  - Full pairing details: see the [RX4M4S](/MeshMass-RX4M4S#pairing) and [TX6A4D](/MeshMass-TX6A4D#pairing) product pages.

## Session 1: Get Running First! (3 Hours)

No programming required - firmware is pre-flashed. Just assemble and play!

### Step 1: Electronics Basics

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

Voltage is the **push** that makes electricity flow through a wire.

Think of voltage like **water pressure** in pipes:

- More pressure = water pushes harder = more flow
- More voltage = electrons push harder = more power

Voltage is measured in **volts** (**V**). So "3.7V" on a LiPo battery means "3.7 volts" - the strength of that battery's push.

**Analogy Time!**
- A tiny battery (1.5V AA) = garden hose spray - gentle
- A bigger battery (3.7V LiPo) = pressure washer - much stronger!
- A car battery (12V) = fire hose - super powerful!

> **💡 Tip for Teachers:** The unit is named after **Alessandro Volta**, the Italian scientist who built the first real battery (a "voltaic pile") around the year 1800 - a nice moment to introduce a famous name behind a unit.

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

At hundreds of switches per second, each off-gap is too brief for the motor to feel (its own weight and momentum carry it through) and too brief for human eyes to see. The motor experiences only an *average* power level, and the shaft spins smoothly at whatever speed the on/off ratio sets.

### Step 2: Meet the MeshMass Boards

#### Meet the Receiver

The **RX4M4S** is the **receiver** of MeshMass - the small board you mount on the tank. Tour it by following its parts.

**Start at the motor sockets.** On one edge of the board you will see **four small connectors** - the same kind that fits the N20 motor's plug from Experiment #1. The Mini Tank kit uses two of them (one motor per track); the other two are spare outputs.

**Follow the wires inward.** Each motor socket runs through traces on the board to a small chip nearby. These chips are called **motor drivers** - four in total, one per motor output. A motor driver takes over the two jobs Step 1 taught us:

- It switches the motor on and off **hundreds of times per second** - automatic PWM, the technique from Experiment #3. The motor sees a smooth average power level.
- It can **reverse the output direction** - the same wire-swap trick from Experiment #1, but done electronically with no hands.

So each motor driver is the small, fast, automatic helper that solves the "person can't ride on the tank" problem we finished Step 1 with.

**Keep tracing inward.** Follow the wires from the **other side** of the motor drivers. They all meet at a single, even **smaller** chip. This chip is the **MCU** - *Micro Controller Unit*. The MCU is the **brain** of the receiver: tiny, but it tells every motor driver what to do (how fast, which direction, when to stop). When students write code in Session 2, that program runs on this chip.

**Keep going.** One wire from the MCU is special - it does not lead to a chip or a connector. Instead it twists across the board in a flat, zig-zag shape, like a **square snake**. That is the **antenna**. It catches the wireless signal sent by the transmitter (which we meet next), so the MCU can hear the instructions.

**Putting it all together.** With the RX4M4S on board, no human needs to ride the tank tapping wires. The **motor drivers** do the rapid tapping for us (automatic PWM, automatic direction reversal). The **MCU** receives signals from the **antenna** and tells each motor driver what to do - following the program running on it. The human just sends instructions **remotely**, with a controller in hand.

The RX4M4S also has 4 servo outputs and runs off the 2S LiPo battery from Step 1.

For full hardware details, see the [RX4M4S product page](/MeshMass-RX4M4S).

#### Meet the Transmitter

The **TX6A4D** is the **transmitter** of MeshMass - the controller students hold in their hands (this is the "controller" Step 1 ended with). Tour it by following its parts.

**Start at the inputs.** On the top of the TX6A4D you will see:
- Two **joysticks** - each tilts in any direction. The Mini Tank uses these to steer.
- Several **buttons** and **knobs** - extra controls for triggers, modes, and fine tuning.
- A small **OLED display** - shows status and current mode.

Anything a student moves or presses becomes a number that the transmitter will send to the receiver.

**Look inside.** Same **MCU-and-antenna** pair as the RX4M4S - just wired the other way around. Where the RX4M4S's MCU drives **outputs** (the motor drivers and servo sockets), the TX6A4D's MCU reads **inputs** (the joysticks, knobs, and buttons on top). The MCU packages every reading into a message, and the **antenna** (another square snake) broadcasts it wirelessly to the receiver, many times every second.

**Power.** The TX6A4D runs off the **1S LiPo battery** from Step 1 - much smaller than the receiver's 2S, because the transmitter only powers its MCU, display, and radio. No motors here.

For full hardware details, see the [TX6A4D product page](/MeshMass-TX6A4D).

::: info Experiment #4: Prove All the Electronics Work

> **Before you start:** Both MCUs come pre-flashed with the right firmware and pre-paired at the factory. No flashing or pairing is needed here - just power and connect.

**Power the transmitter:** plug the **1S LiPo** battery into the TX6A4D and switch it on.

**Power the receiver:** plug a motor into the **DM0** socket on the RX4M4S (the first of the four DC motor sockets), and a second motor into **DM1**. Then plug in the **2S LiPo** battery.

Now move the joysticks on the transmitter.

The motors on the receiver spin in response - faster with more stick deflection, reverse when the stick crosses centre, stop when the stick is centred. No wires running between the two boards. No human tapping anything.

This is everything from Step 1 happening **automatically**:

- The **PWM** the student did by hand in Experiment #3 is now generated by the motor drivers, hundreds of times per second.
- The **direction reversal** from Experiment #1 happens whenever the stick crosses centre.
- The **wireless link** between the two antennas closes the loop between the inputs in the student's hand and the outputs spinning on the table.

The full path is now traceable: fingers → joystick → TX's MCU → antenna → air → RX's antenna → RX's MCU → motor drivers → motors → spinning shaft.

> **💡 Tip for Teachers:** This is the payoff of Session 1. Spend time here. Let students push the sticks in different directions, watch the motors respond, and notice the invisibility of the wireless link. Saying it explicitly helps: "There is nothing between these two boards but air."

> **💡 After the experiment:** Use the **Socket Separator** in the kit to unplug each 2S LiPo from the receiver - LiPo connectors are tight by design.

:::

### Step 3: Assemble the Transmitter

Build the controller students will hold.

**Materials:**
- TX6A4D × 1
- PB2×5 screws × 4
- 1S LiPo battery × 1
- Transmitter Chassis × 1

**Tool:** Phillips Screwdriver

**Instructions:**
1. Place the **1S LiPo** battery inside the Transmitter Chassis.
2. Place the **TX6A4D** on top of the battery and chassis, aligning its 4 screw holes with the chassis.
3. Fasten the 4 **PB2×5 screws** through the TX6A4D into the chassis with the Phillips screwdriver.
4. Arrange the battery cables so they stay inside the chassis (no loose wires hanging out).

> **💡 Tip for Teachers:** Once a controller is assembled, have students add a **name tag or sticker** to their transmitter chassis so each pair gets their own back next session.

### Step 4: Assemble the Tank

Build the mini tank chassis.

#### 4.1 Mount the Motors

Wheels stay off until 4.5–4.6 - that way the chassis sits flat on the table during the screw-heavy steps in between.

**Materials:**
- N20 DC Motors × 2
- PB2×5 screws × 8
- Tank Chassis × 1
- Motor Covers × 2

**Tools:** Phillips Screwdriver, Socket Separator

**Instructions:**
1. Use the **Socket Separator** to gently unplug both N20 motors from the receiver.
2. Place one N20 motor into its slot on one side of the chassis. The output shaft should point outward (where the wheel will mount); route the motor wires into the chassis interior.
3. Set a Motor Cover over the motor and fasten it to the chassis with 4 PB2×5 screws.
4. Repeat for the second motor on the other side.

#### 4.2 Mount the OLED Screen on the Screen Stand

**Materials:**
- 128×64 OLED Display × 1
- PB2×5 screws × 2
- Screen Stand × 1

**Tool:** Phillips Screwdriver

**Instructions:**
1. Place the OLED display on the Screen Stand, aligning its two screw holes.
2. Fasten with 2 PB2×5 screws.
3. Plug the OLED's cable into the screen socket on the RX4M4S.

#### 4.3 Place the 2S LiPo on the Chassis

**Materials:**
- 2S LiPo battery × 1

**Instructions:**
1. Place the 2S LiPo battery into the battery well on the chassis - between the four receiver mounting poles, so the receiver will sit on top of it.
2. Route the battery's connector cable so it can reach the receiver's power socket from above once the receiver is mounted.

#### 4.4 Mount the RX4M4S on the Chassis

The receiver mounts onto four poles on the chassis. Two of those poles will also hold the Screen Stand on top of the receiver.

**Materials:**
- PB2×5 screws × 2
- PB2×8 screws × 2

**Tool:** Phillips Screwdriver

**Instructions:**
1. Place the RX4M4S onto the four mounting poles of the chassis.
2. Set the Screen Stand (with the OLED display from 4.2) on top of the RX4M4S, aligning its two screw holes with two of the receiver's four mounting holes.
3. Fasten the two stacked holes (Screen Stand → RX4M4S → chassis pole) using the **long PB2×8 screws** - they need the extra length.
4. Fasten the other two holes (RX4M4S → chassis pole, no Screen Stand) using the **short PB2×5 screws**.
5. Plug both N20 motor cables back into the RX4M4S - **DM0** for the **left** motor, **DM1** for the **right** motor.

::: warning No Power Switch

The RX4M4S has **no power switch**. This kit treats the tank like a classic RC vehicle: connect the **2S LiPo** to power on, **disconnect** it to power off. Use the **Socket Separator** in the kit for disconnection - the LiPo plug is intentionally tight.

**Always disconnect the battery when done playing.** A LiPo left plugged in keeps draining itself, which shortens the battery's useful life and can cause damage over time.

:::

#### 4.5 Mount the Rear Wheels

**Materials:**
- Rear Wheels × 2

**Instructions:**
1. Press a Rear Wheel firmly onto each motor's output shaft. The hole in the wheel is sized for a snug press fit - no glue or screws needed.

#### 4.6 Mount the Front Wheels

**Materials:**
- Front Wheels × 2
- PB2×8 screws × 2

**Tool:** Phillips Screwdriver

**Instructions:**
1. Place a Front Wheel against its mounting point on the chassis.
2. Pass a PB2×8 screw through the wheel and into the chassis. **Fasten it tight.** The Front Wheel is essentially two rings stacked together with a groove between them, 3D-printed as a single piece — the rings cannot be separated but they can still spin relative to each other. So the screw clamps the inner ring to the chassis while the outer ring continues to spin freely.
3. Repeat for the second front wheel.

> **💡 Tip for Teachers:** This is a great example of a 3D-printing technique called **print-in-place** — two (or more) parts are printed at the same time with a tiny gap between them, so they come off the printer pre-assembled. They fit together perfectly, can't be separated, but can move relative to each other. The same technique can print fully-functional hinges, joints, chains, and bearings without any post-assembly work.

The chassis can already roll on its bare wheels - let's see what tracks add.

::: info Experiment #5: Why Tracks Matter

The Mini Tank's track system is the simplest possible - just two wheels per side. Without the tracks, those wheels still touch the ground. So why bother with tracks at all? Let's find out.

**Setup:** With the chassis assembled to this point, connect the **2S LiPo** battery to the receiver's power socket. Switch on the TX6A4D.

**Drive without tracks first.** With the bare wheels on the ground, drive the tank around using the joysticks. Watch closely:
- The wheels touch the ground at only a few small points.
- Bumps, slopes, or carpet make the tank slip or get stuck.

**Now put the tracks on.**

Materials: Continuous Tracks × 2

1. Wrap one Continuous Track around the rear and front wheels on one side. Fit the track around both wheels.
2. Make sure the track is taut but not stretched.
3. Repeat on the other side.

**Drive with tracks.** The differences:
- The track makes a long, flat contact patch instead of two small wheel-points.
- The tank now climbs small bumps and grips carpet and slopes.

This is why every real tank, bulldozer, and crawler uses **continuous tracks**: more ground contact means more traction. Two wheels alone can roll; tracks turn rolling into crawling.

> **💡 Tip for Teachers:** A folded sheet of paper, a thin book, or a small ramp makes a great mini obstacle course. The "with tracks" advantage gets obvious fast when the tracked tank climbs what the bare-wheel tank can't.

> **💡 Tip for Teachers:** A small 3D-printing design lesson lives here. If the rear wheels were wrapped in a soft (TPU/rubber) tire, grip on a hard floor would already be decent — no tracks needed. But this starter kit is designed so **every 3D-printed part prints fast, on one plate, in a single common material like PLA or PETG**. The result: hard plastic rear wheels, which don't grip much on a hard floor. The continuous track is the part that restores the grip — turning rolling into crawling.

> **💡 Tip for Teachers:** Another design choice: a tank with **two motors driving two tracks** can turn just by running the motors at different speeds (or in opposite directions). That is **differential steering**. Cars need a separate steering servo to angle their front wheels; tank tracks don't. This is why the starter kit's electronics and mechanics stay simple — no extra steering servo, no steering linkage, no pivots.

:::

> **💡 Tip for Teachers:** Once the tank is powered, the **OLED screen** on the receiver displays the **incoming signals** from the transmitter and the **outgoing values** to the motor drivers - all as numbers. This is a perfect chance to connect figures to motor actions: push the left stick → a number on the screen changes → the left motor responds. A useful warm-up for Session 2's programming.
>
> Realistically, by this point students are itching to drive. Spend a moment on screen-watching if the energy allows; otherwise save it for Session 2.

### Step 5: Game Time

The tank is ready to drive as-is. The **Horn** is an optional accessory that turns the tank into a football pusher - mount it if you plan to play the default football game; otherwise skip ahead to Game Time.

**Mount the Horn**

**Materials:**
- Horn × 1
- PB2×5 screws × 2

**Tool:** Phillips Screwdriver

**Instructions:**
1. Place the Horn against the head of the tank chassis, aligning its two screw holes.
2. Fasten with 2 PB2×5 screws.

The Horn sticks out at the front like a pair of arms - useful for pushing objects.

**Game Time!**

Drive freely. A few ideas:

- **Robot football duels** - push a light ball (paper wad, ping-pong ball) into the opponent's goal. Books mark the goals; the Horn makes contact.
- **Racing** - mark a start line and a finish line. First tank home wins.
- **Maze** - lay out walls with books or tape. Drive from one end to the other.
- **Sumo** - draw a circle; two tanks inside; first one pushed out loses.
- **Obstacle course** - ramps, gates, small bumps to drive over.

Or invent new games entirely.

> **💡 Tip for Teachers:** Mark a clear **boundary** for the play area (tape on the floor, a ring of books). The tank moves fast and is small enough to slip under furniture. A tank that ends up under someone's foot gets smashed.

> **💡 Tip for Teachers:** The tank ships **without body covers** - the motor and battery cables sit exposed on the chassis. In rough play (sumo, football collisions), a stray Horn or a flip onto its side can yank a wire loose or snap one. Either **bind the cables** neatly along the chassis with a small piece of tape, or be ready to **repair** (re-crimp the JST, swap a connector). A future 3D-modelling session in this kit's roadmap will let students design their own protective covers.

Enjoy.

### Summary

By the end of Session 1, students have:

**Electronics (Step 1):**
- **Circuit**, **switch**, and **polarity** - discovered through the 1S battery + motor experiments.
- **Voltage** as the push behind electricity; measured in volts (V), named after Volta.
- **Series stacking** of cells (1S + 1S = 2S, 3.7V + 3.7V = 7.4V).
- **PWM** (Pulse Width Modulation) - speed control by rapid on/off switching.

**Mechanics:**
- **Gearbox** - slows the motor down to make it stronger, like a low bicycle gear (Step 1).
- **Continuous tracks** - more ground contact than bare wheels means more grip and climbing ability (Experiment #5).

**Hardware (Step 2):**
- **RX4M4S** receiver - motor drivers, MCU, antenna.
- **TX6A4D** transmitter - inputs, MCU, antenna; same architecture mirrored.
- The **wireless link** between the two antennas.

**Built and drove (Steps 3-5):**
- A handheld controller (TX6A4D + 1S LiPo) and a tracked mini tank (RX4M4S + 2S LiPo + N20 motors + OLED).
- Free driving with the Horn - football, racing, maze, sumo, obstacle course.

In Session 2, students go inside the MCU's program and change how the tank responds to the controller.

## Session 2: Code Your Tank *(work in progress)*

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

## About the Kit

This is a starter kit with a minimum setup:
- 2 motors, one for each track.
- No turret - tracks and forward/reverse only.
- Expansion paths for adding servos and more in [Beyond This Kit](#beyond-this-kit).

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

The 3D model files for all printable parts in this kit are available on [MakerWorld](https://makerworld.com.cn/zh/models/2550208-ke-bian-cheng-yao-kong-zu-qiu-xiao-che-lu-dai-che).

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

## Beyond This Kit

Once students have driven their Mini Tank, several branches open up.

**1. Print a finished transmitter case.** CDHCHAOREN has designed a complete 3D-printable case for the TX6A4D, [available on MakerWorld](https://makerworld.com.cn/zh/models/2193372-16tong-dao-ke-bian-cheng-zi-ding-yi-shua-ji-yao-ko). It replaces the basic Transmitter Chassis from this kit with a finished, comfortable-to-hold enclosure.

**2. Customise this Mini Tank.** Keep working on the Mini Tank itself - design custom turrets, body covers, and other add-ons in CAD, then 3D-print them in your favourite colour combinations. The kit uses only 2 of the receiver's 4 motor sockets and none of its 4 servo sockets, so there is room to add motorised arms, grippers, lights, or other moving parts. You can also reprogram the receiver to try different control schemes - that is what Session 2 covers.

**3. Build a bigger or different vehicle.** Reuse the same TX6A4D and RX4M4S electronics to drive completely different builds, usually larger - construction equipment (forklift, dump truck, excavator), RC cars and trucks, cranes, manipulators. The receiver supports up to 4 DC motors and 4 servos per build.

**4. Migrate MeshMass to LEGO Technic.** Bring wireless remote control to existing LEGO Technic builds using hobby motors that mount onto Technic systems. A static LEGO excavator or truck can become a fully RC version.

**5. Add MeshMass accessories.** The RX4M4S has hardware support for **WS2812 RGB LED strips** (head/turning/tail lights, ambient glow) and an **MP3 audio module** (engine sounds, horns, custom effects). These require alternate firmware variants - see the [RX4M4S product page](/MeshMass-RX4M4S) for details on the RX4M3S1N and RX4M1S1N1A variants.

## Discussion

- [Forum (Powered by GitHub Discussion)](https://github.com/aguegu/sourcekit.cc/discussions)

## Related Products

- [TX6A4D Transmitter](/MeshMass-TX6A4D) - Dual joystick transmitter module
- [RX4M4S Receiver](/MeshMass-RX4M4S) - 4 DC motor + 4 servo receiver