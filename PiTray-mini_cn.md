# Sourcekit® PiTray mini

版本：1.1.0

Language: [English](PiTray-mini), 简体中文

设计人：方圣源，官微宏

Sourcekit® PiTray mini是专为搭建搭建树莓派（Raspberry Pi, RPi）第4代计算模块（CM4）而开发的类 B型 (2B/3B/3B+/4B) 树莓派IO载板。PiTray mini旨在为构建 CM4 应用开发提供精巧且经济的解决方案。它具备和标准树莓派4B一样的轮廓和安装孔，可以直接叠加在已有的B型树莓派集群上。

相较于4B，CM4 在产品开发方面更具优势。它发布了板载eMMC存储的版本，抛弃了 SD 卡，这样无论是单独应用还是集群应用，磁盘读写的可靠性和速度都能得到显著提升。于此同时，CM4 也提供了不含 WiFi 蓝牙芯片的系列，这就使得集群的功耗得到进一步的降低，更加节能环保，操作系统也能完全禁用相关服务节省算力。

PiTray mini 提供了接近原生树莓派 4B 的开发体验，希望用户能实现从 4B 到 CM4 平台无缝升级。它提供直接对 CM4 板载 eMMC 烧录的支持，所以也能作为经济简易的[官方 CMIO 板](https://www.raspberrypi.org/products/compute-module-4-io-board/)的替代选择。

# 平面图

![PiTray mini Layout](images/PiTray-mini-layout.jpg)

# 特点

-   兼容所有类型的 CM4，无论其是否使用板载 eMMC 或是外置 Micro SD 卡作为主存储设备；
-   支持对 CM4 板载 eMMC 的烧录（方法和官方教程相同），而且可以一键切换，更加方便易用；
-   具备和 B 型树莓派（3B/3B+/4B）同样的外形轮廓和定位孔；

# 接口及规格

- 1个 CM4 接口
- 1个树莓派标准 HAT 接口
- 1个标准 HDMI2.0 接口
- 1个千兆以太网 RJ45 接口
- 1个 USB2.0 接口
- 1个 SD 卡槽
- 1个 USB Type-C 接口，用于供电和对CM4板载的eMMC存储器烧写操作系统镜像
- 1个 eMMC 启动切换开关，用来控制系统引导时是编程（烧写）模式或是正常模式
- 1个运行按键，可用于硬复位
- 1个红色LED电源指示灯
- 1个绿色LED运行指示灯
- 2个 CM4 安装孔
- 4个 CM4 角标用于CM4定位标识

- 尺寸: 85毫米× 56毫米
- 输入电源: +5V
- [外形尺寸](PiTray-mini-mech.pdf ":ignore")

# 入门教程

## CM4 without eMMC (Lite)

1.  Got a micro SD card ready with operating system compatiable with raspberry pi, like NOOB, Raspbian or Ubuntu. (See also [1](https://www.raspberrypi.org/software/) [2](https://www.raspberrypi.org/software/operating-systems/) [3](https://www.raspberrypi.org/documentation/installation/installing-images/) [4](https://projects.raspberrypi.org/en/projects/raspberry-pi-setting-up))

2.  Insert the Micro SD card into the micro SD socket on PiTray.

3.  Make sure the `eMMC Boot` switch is at the `ON` position.

4.  Mount the CM4 without eMMC on PiTray. _CAUTION: be careful of the CM4 position, align the CM4 layout corner marks and holes, otherwise CM4 or PiTray would get damaged_

5.  Plug Other devices you may needed such as HDMI, Ethernet, USB (**_see below_**) Keyboard.

6.  Power PiTray with a 15W USB-C power supply. With the power led on, you are good to go. Enjoy & have fun.

## CM4 with eMMC (Flashing Guide)

1.  Unplug micro SD card from PiTray if any.

2.  Mount the CM4 (with eMMC) on PiTray. _CAUTION: be careful of the CM4 position, align the CM4 layout corner marks and holes, otherwise CM4 or PiTray would get damaged_

3.  Make sure the `eMMC Boot` switch is at the `OFF` position.

4.  On PC, install and launch [raspberry pi usbboot](https://github.com/raspberrypi/usbboot). (See also: [5](https://www.raspberrypi.org/documentation/hardware/computemodule/cm-emmc-flashing.md))

5.  Connect PiTray with a USB-A to USB-C cable to the PC. (a USB-C to USB-C cable may not work)

6.  Then an external disk like flash drive, aka USB mass storage, would show up on the PC, write this disk with OS image with Raspberry Pi Imager, Etcher or dd as the step 1 above.

7.  After the image is written and the external drive is umounted from PC, disconnect PiTray from the PC.

8.  Turn the `eMMC Boot` switch to `ON`.

9.  Plug Other devices you may needed such as HDMI, Ethernet, USB (**_see below_**) Keyboard.

10. Power PiTray with a 15W USB-C power supply. With the red led on, you are good to go. Enjoy & have fun.

For CM4 with eMMC that already filled with OS image, just start from Step 8 for regular usage.

# 故障排查

-   USB devices not working

> The USB interface is disabled to save power by default on the CM4. To enable it you need to add `dtoverlay=dwc2,dr_mode=host` to the config.txt file

As described in Section 4.2 on [Compute Module 4 datasheet](https://datasheets.raspberrypi.org/cm4/cm4-datasheet.pdf).

This `feature` could confuse whoever new to Raspberry Pi Compute Module 4, when the exact same behavior as regular Raspberry Pi Model A/B/Zero is expected, especially in case that a USB keyboard is the only approach to interact with the operating system.

To fix that, for CM4 without eMMc, power off CM4, unplug the micro SD card and mounted on a PC with Micro SD card Reader/Writer. Find `config.txt` file in the boot partition of the micro SD card, which looks like a flash drive. Append `config.txt` with the line

    dtoverlay=dwc2,dr_mode=host

Save it, close the file, umount the micro SD card and mount it back to PiTray and try again.

For CM4 with eMMC, similar to the process to flash the operating system image, power off PiTray, switch off `eMMC Boot`, and connect PiTray to a PC with `usbboot` preloaded, then do the editing as above. Finally disconnect PiTray from PC then switch on `eMMC Boot` and try again.

For experienced raspberry pi users, this step could be done right after the OS image is written.

For CM4 without eMMC, the OS would launch fine even with `eMMC Boot` switch at `OFF`. But in this case USB devices on this USB 2.0 port would not work because the USB interface is running at the guest mode. `eMMC Boot` switch has to be at position `ON` to enable USB function in host mode.


# 讨论与展示

-   [论坛 (Powered by GitHub Discussion)](https://github.com/aguegu/sourcekit.cc/discussions)
-   [Prototype release on @BG5USN](https://twitter.com/BG5USN/status/1328331941536477189)
-   [neat CM4 projects/accessories - Jeff Geering](https://github.com/geerlingguy/raspberry-pi-pcie-devices/issues/25)
-   [Raspberry Pi CM4 Boards arrive! Waveshare PoE and PiTray mini - Jeff Geering](https://www.youtube.com/watch?v=DKV7wv7NaCY)
-   [Alternative Raspberry Pi Compute Module 4 Carrier Board Offers Familiar Layout - tom's Hardware](https://www.tomshardware.com/news/alternative-raspberry-pi-compute-module-4-carrier-board-offers-familiar-layout)
-   [PiTray Mini Is a CM4 Companion IO Board for Industrial Applications - Hackster.io](https://www.hackster.io/news/pitray-mini-is-a-cm4-companion-io-board-for-industrial-applications-c4ba79f90e18)
-   [RPi CM4 powered PiTray opens at $14.50 as more carriers prep for launch - LinuxGizmos.com](http://linuxgizmos.com/rpi-cm4-powered-pitray-opens-at-14-50-as-more-carriers-prep-for-launch/)
-   [Sourcekit PiTray Mini Review: Brings Ports to Raspberry Pi CM4](https://www.tomshardware.com/reviews/sourcekit-pitray-mini)

# 购买通道

<a href="https://www.dfrobot.com/product-2196.html" target="_blank"><img src="images/dfrobot.jpg" alt="Buy from DFRobot" title="DFRobot" /></a>
<a href="https://www.maker-shop.ch/pitray-mini-for-raspberry-pi-compute-module-4" target="_blank"><img src="images/makershop-ch.jpg" alt="Buy from maker-shop.ch" title="MakerShop.ch" /></a>
<a href="https://thepihut.com/collections/latest-raspberry-pi-products/products/pitray-mini-for-raspberry-pi-compute-module-4" target="_blank"><img src="images/thepihub.jpg" alt="Buy from the PiHub" title="thePiHub" /></a>
<a href="https://www.mouser.com/ProductDetail/DFRobot/DFR0827?qs=DRkmTr78QAQr9inYZfhAoA%3D%3D" target="_blank"><img src="images/mouser.jpg" alt="Buy from Mouser" title="Mouser" /></a>

![PiTray mini with Raspberry Compute Module 4 Lite](images/PiTray-mini-with-cm4-lite.jpg)

*Raspberry Pi 是属于树莓派基金会的商标*
