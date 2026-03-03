#ifndef APP_H
#define APP_H

#include <stdint.h>
#include <stdbool.h>

/**
 * 读取数字按钮状态。
 *
 * @param index 按钮索引 (0-3):
 *              - 0: 按钮0（左侧边缘）/ 左摇杆按压
 *              - 1: 按钮1（左侧中间）
 *              - 2: 按钮2（右侧中间）
 *              - 3: 按钮3（右侧边缘）/ 右摇杆按压
 * @return true 如果按钮按下，否则 false
 */
bool getButton(uint8_t index);

/**
 * 读取模拟输入值。
 *
 * @param index 模拟输入索引 (0-5):
 *              - 0: 右摇杆 X轴 (STK0)
 *              - 1: 右摇杆 Y轴 (STK1)
 *              - 2: 左摇杆 Y轴 (STK2)
 *              - 3: 左摇杆 X轴 (STK3)
 *              - 4: 左旋钮 (STK4)
 *              - 5: 右旋钮 (STK5)
 * @return 有符号8位值 (-127 到 127)。固件避免使用-128值以支持方向反转。
 *         值0表示中心/中立位置。
 */
int8_t getStick(uint8_t index);

/**
 * 设置无线通道值。
 *
 * @param index 通道索引 (0-15)
 * @param value 有符号8位值 (-128 到 127) 分配给通道。
 *              虽然 getStick() 避免使用-128，但 setChannel() 可以将其用于特殊用途
 *              （例如，电机控制中的刹车）。
 */
void setChannel(uint8_t index, int8_t value);

/**
 * 获取当前无线通道值。
 *
 * @param index 通道索引 (0-15)
 * @return 通道当前的有符号8位值 (-128 到 127)
 */
int8_t getChannel(uint8_t index);

/**
 * 应用程序主循环函数。
 *
 * 由固件框架每20ms（50Hz）调用一次。实现此函数以定义将输入映射到无线通道的控制逻辑。
 *
 * 重要：避免忙等待或延时函数。固件在后台运行实时操作系统（RTOS）。
 *
 * loop() 完成后，固件将所有16个通道值无线广播到配对的接收器。
 * 在 loop() 中未显式设置的通道保留其先前值。
 */
void loop();

#endif