/*
 * buttons.c
 *
 *  Created on: Apr 27, 2022
 *      Author: luk6xff
 */

#include "Buttons.h"

#include "FreeRTOS.h"
#include "task.h"

//------------------------------------------------------------------------------
struct ButtonStatus
{
	ButtonState current_state;
	ButtonState previous_state;

	void (*button_released)(void);
	std::function<void(void)> button_pressed_short;
	std::function<void(void)> button_pressed_long;
};


//------------------------------------------------------------------------------
struct ButtonConfig
{
	uint16_t pin;
	GPIO_TypeDef *port;
	GPIO_PinState pressed_pin_state;

};

//------------------------------------------------------------------------------
const struct ButtonConfig buttons_cfg[BUTTONS_NUMBER] =
{
	{ HOTAIR_ON_SW_Pin, 		HOTAIR_ON_SW_GPIO_Port,			GPIO_PIN_RESET },
	{ HOTAIR_TEMP_UP_SW_Pin, 	HOTAIR_TEMP_UP_SW_GPIO_Port,	GPIO_PIN_RESET },
	{ HOTAIR_TEMP_DOWN_SW_Pin, 	HOTAIR_TEMP_DOWN_SW_GPIO_Port,	GPIO_PIN_RESET },
	{ HOTAIR_FAN_UP_SW_Pin, 	HOTAIR_FAN_UP_SW_GPIO_Port,		GPIO_PIN_RESET },
	{ HOTAIR_FAN_DOWN_SW_Pin, 	HOTAIR_FAN_DOWN_SW_GPIO_Port,	GPIO_PIN_RESET },
	{ SOLDER_SELECT_T12_SW_Pin, SOLDER_SELECT_T12_SW_GPIO_Port,	GPIO_PIN_RESET },
	{ SOLDER_SELECT_WEP_SW_Pin, SOLDER_SELECT_WEP_SW_GPIO_Port,	GPIO_PIN_RESET },
	{ SOLDER_TEMP_UP_SW_Pin, 	SOLDER_TEMP_UP_SW_GPIO_Port,	GPIO_PIN_RESET },
	{ SOLDER_TEMP_DOWN_SW_Pin, 	SOLDER_TEMP_DOWN_SW_GPIO_Port,	GPIO_PIN_RESET },
	{ MENU_RIGHT_SW_Pin, 		MENU_RIGHT_SW_GPIO_Port,		GPIO_PIN_RESET },
	{ MENU_OK_SW_Pin,			MENU_OK_SW_GPIO_Port,			GPIO_PIN_RESET },
	{ MENU_LEFT_SW_Pin, 		MENU_LEFT_SW_GPIO_Port,			GPIO_PIN_RESET },
	{ HOTAIR_REED_SW_Pin, 		HOTAIR_REED_SW_GPIO_Port,		GPIO_PIN_SET   },
	{ IRON_T12_MOTION_SW_Pin, 	IRON_T12_MOTION_SW_GPIO_Port,	GPIO_PIN_SET   },
};

//------------------------------------------------------------------------------
static struct ButtonStatus buttons[BUTTONS_NUMBER];

//------------------------------------------------------------------------------
void Buttons::buttons_task(void *argument)
{
	// Last wake time
	TickType_t last_wake_time = xTaskGetTickCount();
	// Sampling interval
	const TickType_t sample_interval = 50/portTICK_PERIOD_MS;
	// Setup default state
	for (int i = 0; i < BUTTONS_NUMBER; ++i)
	{
		buttons[i].current_state = BUTTON_NOT_PRESSED;
		buttons[i].previous_state = BUTTON_NOT_PRESSED;
	}

	for(;;)
	{

		// Wait for the next cycle.
		vTaskDelayUntil(&last_wake_time, sample_interval);

		// Get the level on button pin
		for (int i = 0; i < BUTTONS_NUMBER; ++i)
		{
			const GPIO_PinState pin_state  = HAL_GPIO_ReadPin(buttons_cfg[i].port, buttons_cfg[i].pin);

			if (pin_state == (buttons_cfg[i].pressed_pin_state ^ 1))
			{
				buttons[i].current_state = BUTTON_NOT_PRESSED;
			}
			else if ((pin_state == buttons_cfg[i].pressed_pin_state) && (buttons[i].previous_state == BUTTON_NOT_PRESSED))
			{
				buttons[i].current_state = BUTTON_SHORT_PRESSED;
				// Run pressed_short cb if registered
				if (buttons[i].button_pressed_short)
				{
					(buttons[i].button_pressed_short)();
				}
			}
			else if ((pin_state == buttons_cfg[i].pressed_pin_state) && \
					 (buttons[i].previous_state == BUTTON_SHORT_PRESSED || \
					  buttons[i].previous_state == BUTTON_LONG_PRESSED))
			{
				buttons[i].current_state = BUTTON_LONG_PRESSED;
				// Run pressed_long cb if registered
				if (buttons[i].button_pressed_long)
				{
					(buttons[i].button_pressed_long)();
				}
			}
			else if ((pin_state == (buttons_cfg[i].pressed_pin_state ^ 1)) && \
					 (buttons[i].previous_state == BUTTON_SHORT_PRESSED || \
					  buttons[i].previous_state == BUTTON_LONG_PRESSED))
			{
				buttons[i].current_state = BUTTON_NOT_PRESSED;
				// Run released cb if registered
				if (buttons[i].button_released)
				{
					(*buttons[i].button_released)();
				}
			}

			buttons[i].previous_state = buttons[i].current_state;
		}
	}
}

//------------------------------------------------------------------------------
void Buttons::button_released_cb(ButtonType type, void(*cb)(void))
{
	buttons[(int)type].button_released = cb;
}

//------------------------------------------------------------------------------
void Buttons::button_pressed_short_cb(ButtonType type, std::function<void(void)> cb)
{
	buttons[(int)type].button_pressed_short = cb;
}

//------------------------------------------------------------------------------
void Buttons::button_pressed_long_cb(ButtonType type, std::function<void(void)> cb)
{
	buttons[(int)type].button_pressed_long = cb;
}

//------------------------------------------------------------------------------
const ButtonState Buttons::buttons_state(ButtonType button)
{
	return buttons[(int)button].current_state;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
