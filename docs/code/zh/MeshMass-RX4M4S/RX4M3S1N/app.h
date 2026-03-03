#ifndef APP_H
#define APP_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

/**
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
 * 读取从发射器接收的当前无线通道值。
 *
 * @param index 通道索引 (0-15)
 * @return 有符号8位值 (-128 到 127)，表示从配对发射器接收的当前通道值。
 */
int8_t getChannel(uint8_t index);

/**
 * 设置电机输出值。
 *
 * @param index 电机索引 (0-3 对应 RX4M3S1N)
 * @param value 有符号8位值 (-128 到 127)，表示电机速度和方向。
 *              该值表示PWM占空比百分比：127表示100%前进，-127表示100%后退，
 *              0表示停止（无动力）。值-128激活刹车（短路）。
 *              实际旋转方向取决于电机接线，可以通过交换电机连接来反转。
 */
void setMotor(uint8_t index, int8_t value);

/**
 * 设置舵机输出值。
 *
 * @param index 舵机索引 (0-2 对应 RX4M3S1N)
 * @param value 无符号8位值 (0-255)，表示舵机位置。
 *              该值对应于20ms周期内PWM高电平脉冲宽度，单位为0.01ms。
 *              对于典型的模拟舵机：
 *              - 100 = 1.0ms脉冲（最小位置）
 *              - 150 = 1.5ms脉冲（中心位置）
 *              - 200 = 2.0ms脉冲（最大位置）
 */
void setServo(uint8_t index, uint8_t value);

/**
 * 获取当前电机输出值。
 *
 * @param index 电机索引 (0-3 对应 RX4M3S1N)
 * @return 有符号8位值 (-128 到 127)，表示由 setMotor() 设置的当前电机输出值。
 */
int8_t getMotor(uint8_t index);

/**
 * 获取当前舵机输出值。
 *
 * @param index 舵机索引 (0-2 对应 RX4M3S1N)
 * @return 无符号8位值 (0-255)，表示由 setServo() 设置的当前舵机输出值。
 */
uint8_t getServo(uint8_t index);

/**
 * 系统启动时调用一次的初始化函数。
 *
 * 实现此函数以执行一次性设置任务，例如初始化变量、配置硬件外设或
 * 设置默认的电机/舵机位置。对于Neopixel初始化，
 * 在 setup() 内调用 neoInit() 以配置LED数量。
 */
void setup();

/**
 * 当从配对发射器接收到有效的无线数据包时调用的主应用程序循环函数，
 * 通常以50Hz频率调用。
 *
 * 实现此函数以将接收到的通道值（通过 getChannel()）映射到电机和舵机输出
 * （使用 setMotor() 和 setServo()）。
 *
 * 该函数由固件框架在每次从发射器接收到完整的16个通道值时自动调用。
 * loop() 完成后，固件根据此执行期间设置的值更新所有电机和舵机输出。
 */
void loop();

/**
 * 由操作系统定期调用的Neopixel动画函数，每125ms（每秒8次）调用一次。
 *
 * 实现此函数以创建动态LED动画、颜色模式或视觉反馈。
 * 该函数独立于主控制循环调用，即使控制更新不频繁也能实现流畅的动画。
 */
void neo();

/**
 * 初始化Neopixel LED灯带配置。
 *
 * 在 setup() 内调用此函数以配置连接的Neopixel灯带中的LED数量。
 * 在使用任何其他Neopixel函数之前必须调用此函数。
 *
 * @param pixelCount Neopixel灯带中的LED数量 (1-16)。
 *                   受可用内存限制。
 */
void neoInit(uint8_t pixelCount);

/**
 * 使用HSL（色调、饱和度、亮度）颜色模型设置Neopixel LED颜色。
 *
 * @param n LED索引 (0 到 pixelCount-1，由 neoInit() 配置)
 * @param hue 色调值 (0-359 度，色轮)
 * @param saturation 饱和度值 (0-255，0 = 灰度，255 = 全彩)
 * @param lightness 亮度值 (0-255，0 = 关闭，255 = 最大亮度)
 */
void neoSetHSL(uint8_t n, uint16_t hue, uint8_t saturation, uint8_t lightness);

/**
 * 使用简化的颜色值设置Neopixel LED颜色。
 *
 * 这是一个调用 neoSetHSL() 并带有简化参数的便捷函数。
 * 当颜色值在 0-359 范围内时，等效于 neoSetHSL(index, color, 255, lightness)（全饱和度）。
 * 当颜色值等于 360 时，等效于 neoSetHSL(index, 0, 0, lightness)（白色，饱和度为零）。
 *
 * @param index LED索引 (0 到 pixelCount-1，由 neoInit() 配置)
 * @param color 颜色值 (0-359 表示色调，360 表示白色)
 * @param lightness 亮度值 (0-255，0 = 关闭，255 = 最大亮度)
 */
void neoSetColor(uint8_t index, uint16_t color, uint8_t lightness);

#endif