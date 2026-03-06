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
 * @param index 电机索引 (0-3 对应 RX4M1S1N1A)
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
 * @param index 舵机索引 (0 对应 RX4M1S1N1A)
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
 * @param index 电机索引 (0-3 对应 RX4M1S1N1A)
 * @return 有符号8位值 (-128 到 127)，表示由 setMotor() 设置的当前电机输出值。
 */
int8_t getMotor(uint8_t index);

/**
 * 获取当前舵机输出值。
 *
 * @param index 舵机索引 (0 对应 RX4M1S1N1A)
 * @return 无符号8位值 (0-255)，表示由 setServo() 设置的当前舵机输出值。
 */
uint8_t getServo(uint8_t index);

/**
 * 系统启动时调用一次的初始化函数。
 *
 * 实现此函数以执行一次性设置任务，例如初始化变量、配置硬件外设或
 * 设置默认的电机/舵机位置。对于Neopixel初始化，
 * 在 setup() 内调用 neoInit() 以配置LED数量。
 *
 * 注意：MY1690音频模块在 setup() 完成后自动初始化。
 * 使用 onPlayerReady() 回调进行音频相关的初始化。
 */
void setup();

/**
 * 当从配对发射器接收到有效的无线数据包时调用的主应用程序循环函数，
 * 通常以50Hz频率调用。
 *
 * 实现此函数以将接收到的通道值（通过 getChannel()）映射到电机和舵机输出
 * （使用 setMotor() 和 setServo()）。
 * 对于音频控制，使用 mpPlay() 和 mpVolume() 函数。
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


/**
 * 从 MY1690 音频模块 SD 卡存储播放音频文件。
 *
 * 文件必须存储在 FAT16/FAT32 格式的 SD 卡根目录中（最大 32GB），
 * 文件名需为4位数字 (0001-9999)。支持格式：MP3 或 WAV。
 * 用户友好的名称可以附加在序列号后面（例如：0001_EngineStart.mp3, 0002_EngineRunning.wav）。
 *
 * 该函数通常从 loop() 调用（每20ms）。音频文件通常持续时间超过20ms，
 * 因此需要仔细选择 force 参数。
 *
 * @param filesn 音频文件的序列号 (1-9999)
 * @param force 强制播放行为：
 *              - false: 如果播放器正忙（正在播放任何文件），命令将被跳过。
 *                如果播放器空闲，filesn 开始播放。
 *              - true: 如果播放器空闲，filesn 开始播放。
 *                如果播放器正忙于播放不同的文件，当前播放将被中断，filesn 从头开始播放。
 *                如果播放器已经在播放相同的文件（filesn），命令将被跳过（不会重新启动当前播放）。
 */
void mpPlay(uint16_t filesn, bool force);

/**
 * 设置 MY1690 音频模块播放音量级别。
 *
 * @param value 音量级别 (0 = 静音，30 = 最大音量)。
 *              音量设置会持续到更改为止。
 */
void mpVolume(uint8_t value);

/**
 * MY1690 音频播放器就绪回调函数，当音频模块初始化完成时由系统调用。
 *
 * 音频模块在系统启动期间自动初始化。
 * 初始化通常在 setup() 返回后完成，此时会调用此回调。
 *
 * 实现此函数以执行音频相关的初始化任务，例如设置初始音量或播放启动声音。
 *
 * 示例：
 * ```
 * void onPlayerReady() {
 *   mpVolume(20);  // 将音量设置为级别 20（0-30 范围）
 * }
 * ```
 */
void onPlayerReady();

#endif