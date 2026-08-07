#ifndef APP_H
#define APP_H

#include <stdint.h>
#include <stdbool.h>

/**
 * Read digital button state.
 *
 * @param index Button index (0-3):
 * • 0: Button 0 (left edge) / Left joystick press
 * • 1: Button 1 (left middle)
 * • 2: Button 2 (right middle)
 * • 3: Button 3 (right edge) / Right joystick press
 * @return true if button is pressed, false otherwise
 */
bool getButton(uint8_t index);

/**
 * Read analog input value.
 *
 * @param index Analog input index (0-5):
 * • 0: Right joystick X-axis (STK0)
 * • 1: Right joystick Y-axis (STK1)
 * • 2: Left joystick Y-axis (STK2)
 * • 3: Left joystick X-axis (STK3)
 * • 4: Left knob (STK4)
 * • 5: Right knob (STK5)
 * @return Raw unsigned 8-bit reading (0 to 255) from the input's own ADC
 * channel, VBat-compensated for battery droop. ~128 is the center/neutral
 * position; 0 and 255 are the travel extremes.
 */
uint8_t getStick(uint8_t index);

/**
 * Set wireless channel value.
 *
 * @param index Channel index (0-15)
 * @param value Signed 8-bit value (-128 to 127) to assign to channel.
 * While getStick() avoids -128, setChannel() can use it for
 * special purposes (e.g., braking in motor control).
 */
void setChannel(uint8_t index, int8_t value);

/**
 * Get current wireless channel value.
 *
 * @param index Channel index (0-15)
 * @return Current signed 8-bit value (-128 to 127) of the channel
 */
int8_t getChannel(uint8_t index);

/**
 * Application main loop function.
 *
 * Called every 20ms (50Hz) by the firmware scaffold. Implement this function
 * to define your control logic mapping inputs to wireless channels.
 *
 * Important: Avoid busy-waiting or delay functions. The firmware runs a
 * Real-Time Operating System (RTOS) in the background.
 *
 * After loop() completes, the firmware broadcasts all 16 channel values
 * wirelessly to paired receivers. Channels not explicitly set in loop()
 * retain their previous values.
 */
void loop();

#endif
