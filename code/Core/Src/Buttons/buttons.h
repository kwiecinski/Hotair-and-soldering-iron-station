/*
 * buttons.h
 *
 *  Created on: Apr 27, 2022
 *      Author: luk6xff
 */

#ifndef SRC_BUTTONS_BUTTONS_H_
#define SRC_BUTTONS_BUTTONS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "gpio.h"



// Last time of button pressed
extern uint32_t last_button_time;


/**
 * @brief Button types
 */
typedef enum
{
	// HOTAIR BUTTONS
	BUTTON_HOTAIR_ON = 0,
	BUTTON_HOTAIR_TEMP_UP,
	BUTTON_HOTAIR_TEMP_DOWN,
	BUTTON_HOTAIR_FAN_UP,
	BUTTON_HOTAIR_FAN_DOWN,

	// SOLDERING IRON BUTTONS
	//BUTTON_SOLDER_ON, - NOT USED
	BUTTON_SOLDER_TEMP_DOWN,
	BUTTON_SOLDER_TEMP_UP,
	BUTTON_SOLDER_SELECT_T12,
	BUTTON_SOLDER_SELECT_WEP,

	// MENU BUTTONS
	BUTTON_MENU_RIGHT,
	BUTTON_MENU_OK,
	BUTTON_MENU_LEFT,

	// SENSING SW
	BUTTON_HOTAIR_REED,
	BUTTON_IRON_T12_MOTION,

	// Number of all supported buttons
	// Keep it always as last
	BUTTONS_NUMBER,
} ButtonType;

/**
 * @brief Button state
 */
typedef enum
{
	BUTTON_NOT_PRESSED = 0,
	BUTTON_SHORT_PRESSED,
	BUTTON_LONG_PRESSED,
} ButtonState;

/**
 * @brief Buttons polling task
 */
void buttons_task(void *argument);

/**
 * @brief Set button released callback
 */
void button_released_cb(ButtonType type, void(*cb)(void));

/**
 * @brief Set button pressed_short callback
 */
void button_pressed_short_cb(ButtonType type, void(*cb)(void));

/**
 * @brief Set button pressed_long callback
 */
void button_pressed_long_cb(ButtonType type, void(*cb)(void));

/**
 * @brief Returns what buttons are pressed.
 */
const ButtonState buttons_state();

#ifdef __cplusplus
}
#endif

#endif /* SRC_BUTTONS_BUTTONS_H_ */
