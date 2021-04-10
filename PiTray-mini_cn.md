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

# 讨论与展示

-   [Forum (Powered by GitHub Discussion)](https://github.com/aguegu/sourcekit.cc/discussions)
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
