#ifndef APP_H
#define APP_H

#include <stdint.h>

/**
 * Read current wireless channel value received from transmitter.
 *
 * @param index Channel index (0-15)
 * @return Signed 8-bit value (-128 to 127) representing the current
 *         channel value received from the paired transmitter.
 */
int8_t getChannel(uint8_t index);

/**
 * Set motor output value.
 *
 * @param index Motor index (0-3 for RX4M4S)
 * @param value Signed 8-bit value (-128 to 127) representing motor
 *              speed and direction. The value represents PWM duty cycle
 *              percentage: 127 means 100% forward, -127 means 100% reverse,
 *              and 0 means stop (no power). Value -128 activates braking
 *              (short circuit). Actual rotation direction depends on motor
 *              wiring and can be reversed by swapping motor connections.
 */
void setMotor(uint8_t index, int8_t value);

/**
 * Set servo output value.
 *
 * @param index Servo index (0-3 for RX4M4S)
 * @param value Unsigned 8-bit value (0-255) representing servo position.
 *              The value corresponds to PWM high-level pulse width in
 *              0.01ms units within a 20ms period. For typical analog servos:
 *              - 100 = 1.0ms pulse (minimum position)
 *              - 150 = 1.5ms pulse (center position)
 *              - 200 = 2.0ms pulse (maximum position)
 */
void setServo(uint8_t index, uint8_t value);

/**
 * Get current motor output value.
 *
 * @param index Motor index (0-3 for RX4M4S)
 * @return Signed 8-bit value (-128 to 127) representing the current
 *         motor output value set by setMotor().
 */
int8_t getMotor(uint8_t index);

/**
 * Get current servo output value.
 *
 * @param index Servo index (0-3 for RX4M4S)
 * @return Unsigned 8-bit value (0-255) representing the current
 *         servo output value set by setServo().
 */
uint8_t getServo(uint8_t index);

/**
 * Initialization function called once at system startup.
 *
 * Implement this function to perform one-time setup tasks such as
 * initializing variables, configuring hardware peripherals, or
 * setting default motor/servo positions.
 */
void setup();

/**
 * Main application loop function called when a valid wireless packet
 * is received from the paired transmitter, typically at 50Hz frequency.
 *
 * Implement this function to map received channel values (via getChannel())
 * to motor and servo outputs (using setMotor() and setServo()).
 *
 * The function is called automatically by the firmware scaffold each time
 * a complete set of 16 channel values is received from the transmitter.
 * After loop() completes, the firmware updates all motor and servo outputs
 * based on the values set during this execution.
 */
void loop();

#endif
