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

/**
 * @brief Button status structure
 */
struct ButtonStatus
{
	ButtonState currentState;
	ButtonState previousState;

	std::function<void(void)> buttonReleased;
	std::function<void(void)> buttonPressedShort;
	std::function<void(void)> buttonPressedLong;
};

class Buttons
{
public:
	/**
	 * @brief Buttons polling task
	 */
	static void buttonsTask(void *argument);

	/**
	 * @brief Set button released callback
	 */
	void buttonReleasedCb(ButtonType type, std::function<void(void)> cb);

	/**
	 * @brief Set button pressed_short callback
	 */
	void buttonPressedShortCb(ButtonType type, std::function<void(void)>);

	/**
	 * @brief Set button pressed_long callback
	 */
	void buttonPressedLongCb(ButtonType type, std::function<void(void)>);

	/**
	 * @brief Returns what buttons are pressed.
	 */
	const ButtonState buttonsState(ButtonType button);

protected:
	ButtonStatus buttons[BUTTONS_NUMBER];
};

}

#endif /* BUTTONS_BUTTONS_H_ */
