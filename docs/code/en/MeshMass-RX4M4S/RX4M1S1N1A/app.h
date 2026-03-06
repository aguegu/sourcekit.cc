#ifndef APP_H
#define APP_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Common color hue values for use with neoSetHSL() and neoSetColor() functions.
 * Hue values range from 0-359 degrees on the color wheel.
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
 * @param index Motor index (0-3 for RX4M1S1N1A)
 * @param value Signed 8-bit value (-128 to 127) representing motor speed and direction.
 *              The value represents PWM duty cycle percentage:
 *              - 127: 100% PWM duty cycle in one direction
 *              - 0: stop (no power)
 *              - -127: 100% PWM duty cycle in opposite direction
 *              - -128: activates braking (short circuit)
 *              Actual rotation direction depends on motor wiring.
 *              Swap motor terminals to reverse direction if needed.
 */
void setMotor(uint8_t index, int8_t value);

/**
 * Set servo output value.
 *
 * @param index Servo index (0 for RX4M1S1N1A)
 * @param value Unsigned 8-bit value (0-255) representing servo position.
 *              The value corresponds to PWM high-level pulse width in
 *              0.01ms units within a 20ms period, providing a range of
 *              0ms to 2.55ms with 0.01ms resolution.
 *              Typical analog servos use pulse widths between 1.0ms and 2.0ms:
 *              - 100 = 1.0ms pulse
 *              - 150 = 1.5ms pulse (center position for regular analog servos)
 *              - 200 = 2.0ms pulse
 *              Advanced servos may support extended ranges (0.5ms to 2.5ms).
 *              The mapping between pulse width and physical angle varies
 *              by servo model and should be calibrated for each application.
 */
void setServo(uint8_t index, uint8_t value);

/**
 * Get current motor output value.
 *
 * @param index Motor index (0-3 for RX4M1S1N1A)
 * @return Signed 8-bit value (-128 to 127) representing the current
 *         motor output value set by setMotor().
 */
int8_t getMotor(uint8_t index);

/**
 * Get current servo output value.
 *
 * @param index Servo index (0 for RX4M1S1N1A)
 * @return Unsigned 8-bit value (0-255) representing the current
 *         servo output value set by setServo().
 */
uint8_t getServo(uint8_t index);

/**
 * Initialization function called once at system startup.
 *
 * Implement this function to perform one-time setup tasks such as
 * initializing variables, configuring hardware peripherals, or
 * setting default motor/servo positions. For Neopixel initialization,
 * call neoInit() within setup() to configure the LED count.
 *
 * Note: The MY1690 audio module initializes automatically after setup()
 * completes. Use onPlayerReady() callback for audio-specific initialization.
 */
void setup();

/**
 * Main application loop function called when a valid wireless packet
 * is received from the paired transmitter, typically at 50Hz frequency.
 *
 * Implement this function to map received channel values (via getChannel())
 * to motor and servo outputs (using setMotor() and setServo()).
 * For audio control, use mpPlay() and mpVolume() functions.
 *
 * The function is called automatically by the firmware scaffold each time
 * a complete set of 16 channel values is received from the transmitter.
 * After loop() completes, the firmware updates all motor and servo outputs
 * based on the values set during this execution.
 */
void loop();

/**
 * Neopixel animation function called regularly by the operating system,
 * every 125ms (8 times per second).
 *
 * Implement this function to create dynamic LED animations, color patterns,
 * or visual feedback. This function is called independently of the main
 * control loop, allowing smooth animations even when control updates are
 * infrequent.
 */
void neo();

/**
 * Initialize Neopixel LED strip configuration.
 *
 * Call this function within setup() to configure the number of LEDs
 * in the connected Neopixel strip. Must be called before using any
 * other Neopixel functions.
 *
 * @param pixelCount Number of LEDs in the Neopixel strip (1-16).
 *                   Limited by available memory.
 */
void neoInit(uint8_t pixelCount);

/**
 * Set Neopixel LED color using HSL (Hue, Saturation, Lightness) color model.
 *
 * @param n LED index (0 to pixelCount-1, as configured by neoInit())
 * @param hue Hue value (0-359 degrees on color wheel)
 * @param saturation Saturation value (0-255, 0 = grayscale, 255 = full color)
 * @param lightness Lightness value (0-255, 0 = off, 255 = maximum brightness)
 */
void neoSetHSL(uint8_t n, uint16_t hue, uint8_t saturation, uint8_t lightness);

/**
 * Set Neopixel LED color using simplified color value.
 *
 * This is a convenience function that calls neoSetHSL() with simplified
 * parameters. When color is in range 0-359, it's equivalent to
 * neoSetHSL(index, color, 255, lightness) (full saturation). When color
 * equals 360, it's equivalent to neoSetHSL(index, 0, 0, lightness) (white,
 * saturation zero).
 *
 * @param index LED index (0 to pixelCount-1, as configured by neoInit())
 * @param color Color value (0-359 for hue, 360 for white)
 * @param lightness Lightness value (0-255, 0 = off, 255 = maximum brightness)
 */
void neoSetColor(uint8_t index, uint16_t color, uint8_t lightness);


/**
 * Play audio file from MY1690 audio module SD card storage.
 *
 * Files must be stored in the root directory of a FAT16/FAT32 formatted
 * SD card (max 32GB) with 4-digit numeric filenames (0001-9999). Supported
 * formats: MP3 or WAV. User-friendly names can be appended after the
 * serial number (e.g., 0001_EngineStart.mp3, 0002_EngineRunning.wav).
 *
 * The function is typically called from loop() (every 20ms). Audio files
 * often last longer than 20ms, requiring careful force parameter selection.
 *
 * @param filesn Serial number of audio file (1-9999)
 * @param force Force playback behavior:
 *              - false: If player is busy (playing any file), command is skipped.
 *                If player is idle, filesn starts playing.
 *              - true: If player is idle, filesn starts playing.
 *                If player is busy playing a different file, current playback
 *                is interrupted and filesn starts from beginning.
 *                If player is already playing the same file (filesn), command
 *                is skipped (does not restart current playback).
 */
void mpPlay(uint16_t filesn, bool force);

/**
 * Set MY1690 audio module playback volume level.
 *
 * @param value Volume level (0 = silent, 30 = maximum volume).
 *              Volume setting persists until changed.
 */
void mpVolume(uint8_t value);

/**
 * MY1690 audio player ready callback function called by the system when
 * audio module initialization is complete.
 *
 * The audio module automatically initializes during system startup.
 * Initialization typically completes after setup() returns, at which
 * point this callback is invoked.
 *
 * Implement this function to perform audio-related initialization
 * tasks such as setting initial volume or playing startup sounds.
 *
 * Example:
 * ```
 * void onPlayerReady() {
 *   mpVolume(20);  // Set volume to level 20 (0-30 range)
 * }
 * ```
 */
void onPlayerReady();

#endif
