/*
 * buttons.h
 *
 *  Created on: Apr 27, 2022
 *      Author: luk6xff
 */

#ifndef BUTTONS_BUTTONS_H_
#define BUTTONS_BUTTONS_H_

#include "gpio.h"
#include <functional>
#include "ButtonTypes.h"

namespace button
{

// Last time of button pressed
extern uint32_t last_button_time;

/**
 * @brief Button status structure
 */
struct ButtonStatus
{
	ButtonState current_state;
	ButtonState previous_state;

	std::function<void(void)> button_released;
	std::function<void(void)> button_pressed_short;
	std::function<void(void)> button_pressed_long;
};

class Buttons
{
public:
	/**
	 * @brief Buttons polling task
	 */
	static void buttons_task(void *argument);

	/**
	 * @brief Set button released callback
	 */
	void button_released_cb(ButtonType type, std::function<void(void)> cb);

	/**
	 * @brief Set button pressed_short callback
	 */
	void button_pressed_short_cb(ButtonType type, std::function<void(void)>);

	/**
	 * @brief Set button pressed_long callback
	 */
	void button_pressed_long_cb(ButtonType type, std::function<void(void)>);

	/**
	 * @brief Returns what buttons are pressed.
	 */
	const ButtonState buttons_state(ButtonType button);

protected:
	ButtonStatus buttons[BUTTONS_NUMBER];
};

}

#endif /* BUTTONS_BUTTONS_H_ */
