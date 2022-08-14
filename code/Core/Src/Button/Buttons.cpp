/*
 * buttons.c
 *
 *  Created on: Apr 27, 2022
 *      Author: luk6xff
 */

#include "Buttons.h"

#include "FreeRTOS.h"
#include "task.h"

using namespace button;


//------------------------------------------------------------------------------
struct ButtonConfig
{
	uint16_t pin;
	GPIO_TypeDef *port;
	GPIO_PinState pressedPinState;

};

//------------------------------------------------------------------------------
const struct ButtonConfig buttonsCfg[BUTTONS_NUMBER] =
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


//------------------------------------------------------------------------------
void Buttons::buttonsTask(void *argument)
{
	Buttons *obj = reinterpret_cast<Buttons*>(argument);

	// Last wake time
	TickType_t last_wake_time = xTaskGetTickCount();

	// Sampling interval
	const TickType_t sample_interval = 50/portTICK_PERIOD_MS;

	// Setup default state
	for (int i = 0; i < BUTTONS_NUMBER; ++i)
	{
		obj->buttons[i].currentState = BUTTON_NOT_PRESSED;
		obj->buttons[i].previousState = BUTTON_NOT_PRESSED;
	}

	for(;;)
	{

		// Wait for the next cycle.
		vTaskDelayUntil(&last_wake_time, sample_interval);

		// Get the level on button pin
		for (int i = 0; i < BUTTONS_NUMBER; ++i)
		{
			const GPIO_PinState pin_state  = HAL_GPIO_ReadPin(buttonsCfg[i].port, buttonsCfg[i].pin);

			if (pin_state == (buttonsCfg[i].pressedPinState ^ 1))
			{
				obj->buttons[i].currentState = BUTTON_NOT_PRESSED;
			}
			else if ((pin_state == buttonsCfg[i].pressedPinState) && (obj->buttons[i].previousState == BUTTON_NOT_PRESSED))
			{
				obj->buttons[i].currentState = BUTTON_SHORT_PRESSED;
				// Run pressed_short cb if registered
				if (obj->buttons[i].buttonPressedShort != nullptr)
				{
					obj->buttons[i].buttonPressedShort();
				}
			}
			else if ((pin_state == buttonsCfg[i].pressedPinState) && \
					 (obj->buttons[i].previousState == BUTTON_SHORT_PRESSED || \
					  obj->buttons[i].previousState == BUTTON_LONG_PRESSED))
			{
				obj->buttons[i].currentState = BUTTON_LONG_PRESSED;
				// Run pressed_long cb if registered
				if (obj->buttons[i].buttonPressedLong != nullptr)
				{
					obj->buttons[i].buttonPressedLong();
				}
			}
			else if ((pin_state == (buttonsCfg[i].pressedPinState ^ 1)) && \
					 (obj->buttons[i].previousState == BUTTON_SHORT_PRESSED || \
					  obj->buttons[i].previousState == BUTTON_LONG_PRESSED))
			{
				obj->buttons[i].currentState = BUTTON_NOT_PRESSED;
				// Run released cb if registered
				if (obj->buttons[i].buttonReleased != nullptr)
				{
					obj->buttons[i].buttonReleased();
				}
			}

			obj->buttons[i].previousState = obj->buttons[i].currentState;
		}
	}
}

//------------------------------------------------------------------------------
void Buttons::buttonReleasedCb(ButtonType type, std::function<void(void)> cb)
{
	buttons[(int)type].buttonReleased = cb;
}

//------------------------------------------------------------------------------
void Buttons::buttonPressedShortCb(ButtonType type, std::function<void(void)> cb)
{
	buttons[(int)type].buttonPressedShort = cb;
}

//------------------------------------------------------------------------------
void Buttons::buttonPressedLongCb(ButtonType type, std::function<void(void)> cb)
{
	buttons[(int)type].buttonPressedLong = cb;
}

//------------------------------------------------------------------------------
const ButtonState Buttons::buttonsState(ButtonType button)
{
	return buttons[(int)button].currentState;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
