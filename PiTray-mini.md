# Sourcekit® PiTray mini

Version: 1.1.0

Language: English, [简体中文](PiTray-mini_cn)

Designer: Shengyuan Fang (方圣源), Weihong Guan [<span class="mdi mdi-github" style="color: #000;"></span>](https://github.com/aguegu/) [<span class="mdi mdi-twitter" style="color: #1da1f2;"></span>](https://twitter.com/BG5USN)

# Overview

Sourcekit® PiTray mini is a companion IO board for Raspberry Pi Compute Module 4 (sold separately). It is designed for use both as a development system for Compute Module 4 (CM4) and as an embedded board integrated into end products.

It provides an excellent way to bring similar development experience of Raspberry Pi 4B to CM4. So users could upgrade their system or setup from the standard Raspberry Pi 4B to CM4 seamlessly. With capability to flash OS image to eMMC on CM4, PiTray mini serves as a budget alternative to [Raspberry Pi Compute Module 4 IO Board](https://www.raspberrypi.org/products/compute-module-4-io-board/).

# Layout

![PiTray mini Layout](images/PiTray-mini-layout.jpg)

# Features

-   Compatible with all variants of CM4, no matter whether it uses onboard eMMC or micro SD card
-   Capable to flash operation system image to eMMC on CM4 with regular approaches as same as the official CMIO board, no extra tools required
-   Same dimensions and mounting holes compared to Model B Raspberry Pi, such as 3B/3B+/4B

# Specification

-   1 CM4 socket
-   1 set of standard Raspberry Pi HAT conne
-   1 Standard HDMI 2.0 connector
-   1 Gigabit Ethernet RJ45 socket
-   1 native USB 2.0 connector
-   1 SD card socket for CM4 variants without eMMC
-   1 USB Type-C connector for powering and also programming eMMC variants of CM4
-   1 Boot Mode Switch for programming mode and normal mode
-   1 RUN button for easy reset
-   1 Red Power LED
-   1 Green Activity LED
-   2 mounting holes for CM4
-   4 CM4 corner marks for CM4 position guidance

-   Input power: +5V
-   Dimensions: 85 mm x 56 mm
-   [PiTray mini Mechanical Drawings](PiTray-mini-mech.pdf ":ignore")

# Compliance

- [RoHS (issued by SGS)](https://rsts.cn.sgs.com/zh-cn/CheckMarkView_cn.asp?id=XMNEC2101876101&key=91CAE44E7642198F5393412DF730D813)

# Get started

## CM4 without eMMC (Lite)

1.  Got a micro SD card ready with operating system compatiable with raspberry pi, like NOOB, Raspbian or Ubuntu. (See also [1](https://www.raspberrypi.org/software/) [2](https://www.raspberrypi.org/software/operating-systems/) [3](https://www.raspberrypi.org/documentation/installation/installing-images/) [4](https://projects.raspberrypi.org/en/projects/raspberry-pi-setting-up))

2.  Insert the Micro SD card into the micro SD socket on PiTray mini.

3.  Make sure the `eMMC Boot` switch is at the `ON` position.

4.  Mount the CM4 without eMMC on PiTray mini. _CAUTION: be careful of the CM4 position, align the CM4 layout corner marks and holes, otherwise CM4 or PiTray would get damaged_

5.  Plug Other devices you may needed such as HDMI, Ethernet, USB (**_see below_**) Keyboard.

6.  Power PiTray with a 15W USB-C power supply. With the power led on, you are good to go. Enjoy & have fun.

## CM4 with eMMC (Flashing Guide)

1.  Power Off. Unplug micro SD card from PiTray if any.

2.  Mount the CM4 (with eMMC) on PiTray. _CAUTION: be careful of the CM4 position, align the CM4 layout corner marks and holes, otherwise CM4 or PiTray would get damaged_

3.  Make sure the `eMMC Boot` switch is at the `OFF` position.

4.  On PC, install and launch [raspberry pi usbboot](https://github.com/raspberrypi/usbboot). (See also: [5](https://www.raspberrypi.org/documentation/hardware/computemodule/cm-emmc-flashing.md))

5.  Connect PiTray mini with a USB-A to USB-C cable to the PC. (a USB-C to USB-C cable may not work)

6.  Then an external disk like flash drive, aka USB mass storage, would show up on the PC, write this disk with OS image with Raspberry Pi Imager, Etcher or dd as the step 1 above.

7.  After the image is written and the external drive is umounted from PC, disconnect PiTray mini from the PC.

8.  Turn the `eMMC Boot` switch to `ON`.

9.  Plug Other devices you may needed such as HDMI, Ethernet, USB (**_see below_**) Keyboard.

10. Power PiTray with a 15W USB-C power supply. With the red led on, you are good to go. Enjoy & have fun.

* For CM4 with eMMC that already filled with OS image, just start from Step 8 for regular usage.

# Guides

* [Hidden Feautre: Connect RTC on i2c0](https://github.com/aguegu/sourcekit.cc/discussions/18)

# Troubleshooting

-   USB devices not working

> The USB interface is disabled to save power by default on the CM4. To enable it you need to add `dtoverlay=dwc2,dr_mode=host` to the config.txt file

As described in Section 4.2 on [Compute Module 4 datasheet](https://datasheets.raspberrypi.org/cm4/cm4-datasheet.pdf).

This `feature` could confuse whoever new to Raspberry Pi Compute Module 4, when the exact same behavior as regular Raspberry Pi Model A/B/Zero is expected, especially in case that a USB keyboard is the only approach to interact with the operating system.

To fix that, for CM4 without eMMc, power off CM4, unplug the micro SD card and mounted on a PC with Micro SD card Reader/Writer. Find `config.txt` file in the boot partition of the micro SD card, which looks like a flash drive. Append `config.txt` with the line

    dtoverlay=dwc2,dr_mode=host

Save it, close the file, umount the micro SD card and mount it back to PiTray mini and try again.

For CM4 with eMMC, similar to the process to flash the operating system image, power off PiTray, switch off `eMMC Boot`, and connect PiTray to a PC with `usbboot` preloaded, then do the editing as above. Finally disconnect PiTray from PC then switch on `eMMC Boot` and try again.

For experienced raspberry pi users, this step could be done right after the OS image is written.

For CM4 without eMMC, the OS would launch fine even with `eMMC Boot` switch at `OFF`. But in this case USB devices on this USB 2.0 port would not work because the USB interface is running at the guest mode. `eMMC Boot` switch has to be at position `ON` to enable USB function in host mode.

# Discussion and Show Cases

-   [Forum (Powered by GitHub Discussion)](https://github.com/aguegu/sourcekit.cc/discussions)
-   [Prototype release on @BG5USN](https://twitter.com/BG5USN/status/1328331941536477189)
-   [neat CM4 projects/accessories - Jeff Geering](https://github.com/geerlingguy/raspberry-pi-pcie-devices/issues/25)
-   [Raspberry Pi CM4 Boards arrive! Waveshare PoE and PiTray mini - Jeff Geering](https://www.youtube.com/watch?v=DKV7wv7NaCY)
-   [Alternative Raspberry Pi Compute Module 4 Carrier Board Offers Familiar Layout - tom's Hardware](https://www.tomshardware.com/news/alternative-raspberry-pi-compute-module-4-carrier-board-offers-familiar-layout)
-   [PiTray Mini Is a CM4 Companion IO Board for Industrial Applications - Hackster.io](https://www.hackster.io/news/pitray-mini-is-a-cm4-companion-io-board-for-industrial-applications-c4ba79f90e18)
-   [RPi CM4 powered PiTray opens at $14.50 as more carriers prep for launch - LinuxGizmos.com](http://linuxgizmos.com/rpi-cm4-powered-pitray-opens-at-14-50-as-more-carriers-prep-for-launch/)
-   [Sourcekit PiTray Mini Review: Brings Ports to Raspberry Pi CM4 - tom's Hardware](https://www.tomshardware.com/reviews/sourcekit-pitray-mini)
-   [The Ultimate Raspberry Pi Compute Module Carrier Board Comparison - upswift](https://www.upswift.io/post/the-ultimate-raspberry-pi-compute-module-carrier-board-comparison)
-   [Sourcekit PiTray Mini Review -  Your Exclusive Cart](https://www.youtube.com/watch?v=_Fp6vhw5LOo)
-   [@LR_68](https://twitter.com/LR68_) - [Case for 3D Printing](https://www.thingiverse.com/thing:4946826) / [With Fan](https://www.thingiverse.com/thing:4948438)
-   [ ElectricBrain - Compute Module 4 based cluster node](https://www.electricbrain.com.au/pages/desktop-blade-center/cm4-cluster-node.php)

# Where to buy ?

<a href="https://www.dfrobot.com/product-2196.html" target="_blank"><img src="images/dfrobot.jpg" alt="Buy from DFRobot" title="DFRobot"></a>
<a href="https://www.maker-shop.ch/pitray-mini-for-raspberry-pi-compute-module-4" target="_blank"><img src="images/makershop-ch.jpg" alt="Buy from maker-shop.ch" title="MakerShop.ch"></a>
<a href="https://thepihut.com/collections/latest-raspberry-pi-products/products/pitray-mini-for-raspberry-pi-compute-module-4" target="_blank"><img src="images/thepihub.jpg" alt="Buy from the PiHub" title="thePiHub"></a>
<a href="https://www.mouser.com/ProductDetail/DFRobot/DFR0827?qs=DRkmTr78QAQr9inYZfhAoA%3D%3D" target="_blank"><img src="images/mouser.jpg" alt="Buy from Mouser" title="Mouser"></a>

<a href="https://www.digikey.com/en/products/detail/dfrobot/DFR0827/13978517" target="_blank"><img src="images/logo_dk.webp" alt="Buy from digikey.com" title="digikey.com"></a>

<a href="https://raspberrypi.dk/en/product/pitray-mini-carrier-board-for-raspberry-pi-cm4/" target="_blank"><img src="images/Jkollerup.jpg" alt="Buy from raspberrypi.dk" title="raspberrypi.dk"></a>
<a href="https://core-electronics.com.au/pitray-mini-for-raspberry-pi-compute-module-4.html" target="_blank"><img src="images/CoreEletronics.jpg" alt="Buy from Core Electronics" title="Core Electronics"></a>

![PiTray mini with Raspberry Compute Module 4 Lite](images/PiTray-mini-with-cm4-lite.jpg)

<a href="https://www.raspberrypi.org/trademark-rules/" target="_blank"><img src="images/Powered-by-Raspberry-Pi.png" alt="Powered by Raspberry Pi" title="Powered By Rasyberry Pi" width="320px"></a>

# See also

<a href="#/PiTray-clip"><img src="images/clip/step00.jpg" alt="PiTray Clip" style="width: 20%;"></a>

[Sourcekit PiTray Clip](#/PiTray-clip)

*Raspberry Pi is a trademark of the Raspberry Pi Foundation*
