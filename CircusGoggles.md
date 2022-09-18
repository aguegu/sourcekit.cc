Sourcekit&reg; Circus Goggles
===

Version: 1.0.0 (3842)

Designer: Weihong Guan [<span class="mdi mdi-github" style="color: #000;"></span>](https://github.com/aguegu/) [<span class="mdi mdi-twitter" style="color: #1da1f2;"></span>](https://twitter.com/BG5USN), Shengyuan Fang (方圣源)

# Overview

Sourcekit&reg; Circus Goggles are RGB LED goggles with 32 Pixels. It brings splendid animation effects simply by turing the 5 Knobs onboards.

# Safety Precautions

* Keep away from children. Adult guidance is necessary for children using Circus Goggles.

* Do not stare at LEDs when the light is on. It may hurt your eye sight.

* Store or play Circus Goggles in dry location and do not allow it to come in contact with water, rain or snow.

* If Circus Goggles come into contact with water, place in a dry location at room temperature, on a soft absorbent towel and allow to dry thoroughly. Do not operate the unit until it is completely free of moisture.

* Use only an appropriate USB power outlet or PC USB panel to charge the Circus Goggles.

# Features

* 32 WS2812 RGB LED shaped in 2 full circles
* 5 knobs to adjust animations
* Main Controlled by a [STC](http://stcmcudata.com/)8H8K64U microcontroller
* Powered By rechargeable 3.7v/180mAh Li-Ion Battery with Short-Circuit / Overload / Over-Charge / Over-Discharge Protection
* Recharged or Firmware upgraded with a standard 5V 1A micro USB socket
* Battery Voltage Indicator
* Battery life 1 - 6 hour depending on the effects
* Route Switch
* Microphone input as variant
* Battery Charge Indicator LED
* Firmeware upgradable online

# Instructions

* Turn on the power switch. If no LED is light up, the battery could be dead, please charge it with a micro USB cable for a while. Some LED should light up when it is powered by USB cable. The battery is being charged at the same time.

* Tune the 5 Knobs: Division / Color / Brightness / Speed / Pattern or Press the Route Switch Button to the effects you like.

# Tuning Guideline

With all these combination from Knobs and routes, Sourcekit&reg; provides thousands of effects without help from 3rd parties, like an remote control, PC or Mobile Application. Inspired by electronic musical instruments, Sourcekit Designers want Circus Goggles to be a standalone product with simple and budget design. With the entry barriers lowered, kids could have fun with easily and explore the led movement or color pattern on their own.

Just remember to dim the LED when it gets too bright to look into or slow down the speed when it got too flashing.

# Power Consumption

By pressing the Battery Check button down, Circus Goggles would show up a 3 digits voltage meter (about right) of the battery, with which we could calculate how much battery life left.

Battery Voltage = ( RED LED count ) * 1 + ( Green LED Count ) * 0.1 + ( Blue LED Count ) * 0.01 （volt）

The voltage is about 4.20v when fully charged and 3.40v when stop discharging.

With the battery capacity const, the battery life depends on how the LEDs effects arranged. So the less led is on, the closer the color is to primary Color (Red, Green, Blue), the less current it required.
