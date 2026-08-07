#ifndef APP_H
#define APP_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

// ===========================================================================
// 第 1 层 —— 板型申报
// ---------------------------------------------------------------------------
// 回答关于你的板子的两个问题；其余全部由下面推导。
//
// PCB 上有四个舵机排针：SM0 SM1 SM2 SM3。可选模块会占用排针——MP3 模块占用
// SM1 + SM2，灯带占用 SM3。剩下的排针就是你的舵机通道。
// ===========================================================================

#define AUDIO_ON_SM1_SM2 0   // 1 = SM1+SM2 接 MP3 模块；0 = SM1、SM2 为舵机
#define NEO_ON_SM3       0   // 1 = SM3 接灯带；       0 = SM3 为舵机

// ===========================================================================
// 第 2 层 —— 推导出的配置（由上面的申报生成，请勿修改）
// ---------------------------------------------------------------------------
//   音频  灯带  舵机
//    无    无   SM0 SM1 SM2 SM3 (4)
//    无    有   SM0 SM1 SM2     (3)
//    有    有   SM0             (1)
//    有    无   SM0 SM3         (2*)   (*不连续：序号 0 和 3)
// ===========================================================================

// 四个排针减去已装模块占用的部分（音频占 2 个，灯带占 1 个）。
#define SERVO_COUNT (4 - AUDIO_ON_SM1_SM2 * 2 - NEO_ON_SM3)

// 哪些 SM 排针是舵机：每一项存放它自己的 SM 编号，若该排针被模块占用则为
// 0xFF。main.c 会把它压缩成 servoTargets 的槽位（该排针在舵机中的排位）。
#define SM_SLOTS {0,                            \
                  AUDIO_ON_SM1_SM2 ? 0xFF : 1,  \
                  AUDIO_ON_SM1_SM2 ? 0xFF : 2,  \
                  NEO_ON_SM3 ? 0xFF : 3}

// ===========================================================================
// 公开 API
// ===========================================================================

/**
 * 读取从发射器接收的当前无线通道值。
 *
 * @param index 通道索引 (0-15)
 * @return 无符号8位值 (0-255)——发射器转发过来的原始读数。摇杆通道装的是
 * 原始 ADC 位置 (0-255，约 128 居中)；按键通道装的是 0 或 1。居中、死区、
 * 缩放、混控全部由接收机负责（例如用 getChannel(i) - 128 把摇杆居中）。
 */
uint8_t getChannel(uint8_t index);

/**
 * 设置电机输出值。
 *
 * @param index 电机索引 (0-3)
 * @param value 有符号8位值 (-128 到 127)，表示电机速度和方向。
 *              该值表示PWM占空比百分比：
 *              - 127: 100% PWM占空比，一个方向
 *              - 0: 停止（无动力）
 *              - -127: 100% PWM占空比，相反方向
 *              - -128: 激活刹车（短路）
 *              实际旋转方向取决于电机接线。
 *              如果需要反转方向，可以对调电机电极接线。
 */
void setMotor(uint8_t index, int8_t value);

/**
 * 设置舵机输出值。
 *
 * @param index 舵机索引——即 PCB 上的 SM 排针编号。可用的排针取决于板型申报
 *              （例如装了音频模块时为 0 和 3）。在本配置下并非舵机排针的序号
 *              会被忽略。
 * @param value 无符号8位值 (0-255)，表示舵机位置。
 *              该值对应于20ms周期内PWM高电平脉冲宽度，单位为0.01ms，
 *              提供0ms到2.55ms的范围，分辨率为0.01ms。
 *              典型的模拟舵机使用1.0ms到2.0ms之间的脉冲宽度：
 *              - 100 = 1.0ms脉冲
 *              - 150 = 1.5ms脉冲（常规模拟舵机的中心位置）
 *              - 200 = 2.0ms脉冲
 *              高级舵机可能支持扩展范围（0.5ms到2.5ms）。
 *              脉冲宽度与物理角度之间的映射因舵机型号而异，
 *              应在每个应用中进行校准。
 */
void setServo(uint8_t index, uint8_t value);

/**
 * 获取当前电机输出值。
 *
 * @param index 电机索引 (0-3)
 * @return 有符号8位值 (-128 到 127)，表示由 setMotor() 设置的当前电机输出值。
 */
int8_t getMotor(uint8_t index);

/**
 * 获取当前舵机输出值。
 *
 * @param index 舵机索引——即 PCB 上的 SM 排针编号（参见 setServo()）。
 * @return 无符号8位值 (0-255)，表示由 setServo() 设置的当前舵机输出值。
 */
uint8_t getServo(uint8_t index);

/**
 * 系统启动时调用一次的初始化函数。
 *
 * 实现此函数以执行一次性设置任务，例如初始化变量、
 * 配置硬件外设或设置电机/舵机的默认位置。
 */
void setup();

/**
 * 主应用程序循环函数，在收到来自配对发射器的有效无线数据包时调用，
 * 通常频率为 50Hz。
 *
 * 实现此函数，把收到的通道值（通过 getChannel()）映射到电机和舵机输出
 * （使用 setMotor() 和 setServo()）。
 *
 * 每当从发射器收到完整的 16 个通道值，固件框架就会自动调用一次此函数。
 * loop() 执行完毕后，固件会根据本次执行中设置的值更新所有电机和舵机输出。
 */
void loop();

/**
 * 当无线链路中断时间超过消抖窗口时调用
 * （无数据包达 400ms 后触发 MAIN_DISCONNECT_EVT）。
 * 实现此函数以让执行机构进入安全状态（例如电机归零、舵机回中位）。
 * 若链路在定时器到期前恢复，本次调用会被自动取消。
 */
void onDisconnect();

#if AUDIO_ON_SM1_SM2
/**
 * 在外接的 MP3 模块上播放音频文件。
 *
 * @param filesn 文件编号 (1-65535)，即模块 SD 卡/闪存中存放的编号。
 * @param force  为 true 时，即使同一文件正在播放也会重新触发——当你希望
 *               每次输入边沿都让音效重新开始时很有用。为 false 时，只在
 *               模块空闲（BUSY 线为低）时才开始播放。无论 `force` 取值，
 *               内部都限速为每 80ms 最多一次。
 */
void mpPlay(uint16_t filesn, bool force);

/**
 * 停止 MP3 模块的播放。
 *
 * 立即中止当前曲目（BUSY 线回到低电平）。停止之后，下一次 mpPlay()
 * ——无论是否带 `force`——都会从空闲状态干净地开始。
 */
void mpStop(void);

/**
 * 设置音频模块的播放音量。
 *
 * @param value 音量等级 0-30（模块共 31 级，含静音）。
 *              大于等于 31 的值按模 31 处理。
 */
void mpVolume(uint8_t value);

/**
 * 设置音频模块的循环模式。
 *
 * @param isLoop true = 循环播放当前文件；false = 播放一次后停止。
 */
void mpLoop(bool isLoop);

/**
 * 在音频模块完成上电流程后（开机约 1 秒）调用一次。
 * 典型用途是发送初始音量并播放开机提示音。
 * 默认是一个弱符号空实现——可以覆盖它以自定义行为。
 */
void onPlayerReady();
#endif // AUDIO_ON_SM1_SM2

#if NEO_ON_SM3
/*
 * 用于 neoSetHSL() 和 neoSetColor() 函数的常用颜色色调值。
 * 色调值范围是色轮上的 0-359 度。
 */
#define COLOR_RED        0
#define COLOR_ORANGE     25
#define COLOR_YELLOW     55
#define COLOR_GREEN      120
#define COLOR_TEAL       170
#define COLOR_BLUE       210
#define COLOR_INDIGO     240
#define COLOR_PURPLE     275
#define COLOR_PINK       330
#define COLOR_WHITE      360

/**
 * Neopixel 动画函数，由操作系统定期调用，
 * 每 125ms 一次（每秒 8 次）。
 *
 * 实现此函数以创建动态 LED 动画、颜色图案或视觉反馈。
 * 此函数独立于主控制循环被调用，因此即使控制更新不频繁，
 * 动画也能保持流畅。
 */
void neo();

/**
 * 初始化 Neopixel LED 灯带配置。
 *
 * 在 setup() 内调用此函数以配置所连接灯带的 LED 数量。
 * 必须在使用任何其他 Neopixel 函数之前调用。
 *
 * @param pixelCount Neopixel 灯带中的 LED 数量 (1-32)。
 */
void neoSetup(uint8_t pixelCount);

/**
 * 使用 HSL（色调、饱和度、亮度）颜色模型设置 Neopixel LED 颜色。
 *
 * @param n LED 索引 (0 到 pixelCount-1，由 neoSetup() 配置)
 * @param hue 色调值 (0-359，色轮上的角度)
 * @param saturation 饱和度值 (0-255，0 = 灰度，255 = 全彩)
 * @param lightness 亮度值 (0-255，0 = 关闭，255 = 最大亮度)
 */
void neoSetHSL(uint8_t n, uint16_t hue, uint8_t saturation, uint8_t lightness);

/**
 * 使用简化的颜色值设置 Neopixel LED 颜色。
 *
 * 这是一个便捷函数，内部调用 neoSetHSL() 并简化参数。
 * 当 color 在 0-359 范围内时，等价于
 * neoSetHSL(index, color, 255, lightness)（全饱和度）。
 * 当 color 等于 360 时，等价于 neoSetHSL(index, 0, 0, lightness)
 * （白色，饱和度为零）。
 *
 * @param index LED 索引 (0 到 pixelCount-1，由 neoSetup() 配置)
 * @param color 颜色值 (0-359 为色调，360 为白色)
 * @param lightness 亮度值 (0-255，0 = 关闭，255 = 最大亮度)
 */
void neoSetColor(uint8_t index, uint16_t color, uint8_t lightness);
#endif // NEO_ON_SM3

#endif
