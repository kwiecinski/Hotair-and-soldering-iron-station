/*
 * test_buttons.c
 *
 *  Created on: 15 kwi 2022
 *      Author: kwiecinski
 */

/*
 * BUTTON MAP
 *
 * 	-----HOTAIR BUTTONS------------------
 * HOTAIR_FAN_DOWN
 * HOTAIR_FAN_UP
 * HOTAIR_DOWN_SW
 * HOTAIR_UP_SW
 * HOTAIR_ON
 *
 * ----SOLDERING IRON BUTTONS-----------------
 * SOLDER_ON_SW
 * SOLDER_DOWN_SW
 * SOLDER_UP_SW
 * SOODER_SELECT_T12_SW
 * SOLDER_SELECT_WEP_SW
 *
 * ----MENU BUTTONS-------------------------
 * MENU_UP_SW
 * MENU_OK_SW
 * MENU_DOWN_SW
 *
 * ----SENSING SW----------------------------
 * HOTAIR_REED_SW
 * IRON_T12_MOTION_SW
 *
 */


#include <stdio.h>
#include "main.h"
#include "usart.h"
#include "gpio.h"
#include "LCD16x2/LCD.h"
#include "utils.h"
#include "stm32f103xb.h"

#define SWITCH_NUMBER 14


char *text[SWITCH_NUMBER]=
{
	"HOTAIR_ON",
	"HOTAIR_TEMP_Up",
	"HOTAIR_TEMP_DOWN",
	"HOTAIR_FAN_UP",
	"HOTAIR_FAN_DOWN",

	"SELECT_T12",
	"SELECT_WEP",
	"SOLDER_TEMP_UP",
	"SOLDER_TEMP_DOWN",

	"MENU_RIGHT",
	"MENU_OK",
	"MENU_LEFT",

	"HOTAIR_REED",
	"IRON_T12_MOTION",
};


uint16_t buttons_pin[SWITCH_NUMBER]=
{
	HOTAIR_ON_SW_Pin,
	HOTAIR_TEMP_UP_SW_Pin,
	HOTAIR_TEMP_DOWN_SW_Pin,
	HOTAIR_FAN_UP_SW_Pin,
	HOTAIR_FAN_DOWN_SW_Pin,

	SOLDER_SELECT_T12_SW_Pin,
	SOLDER_SELECT_WEP_SW_Pin,
	SOLDER_TEMP_UP_SW_Pin,
	SOLDER_TEMP_DOWN_SW_Pin,

	MENU_RIGHT_SW_Pin,
	MENU_OK_SW_Pin,
	MENU_LEFT_SW_Pin,

	HOTAIR_REED_SW_Pin,
	IRON_T12_MOTION_SW_Pin
};

GPIO_TypeDef *buttons_port[SWITCH_NUMBER]=
{
	HOTAIR_ON_SW_GPIO_Port,
	HOTAIR_TEMP_UP_SW_GPIO_Port,
	HOTAIR_TEMP_DOWN_SW_GPIO_Port,
	HOTAIR_FAN_UP_SW_GPIO_Port,
	HOTAIR_FAN_DOWN_SW_GPIO_Port,

	SOLDER_SELECT_T12_SW_GPIO_Port,
	SOLDER_SELECT_WEP_SW_GPIO_Port,

	SOLDER_TEMP_UP_SW_GPIO_Port,
	SOLDER_TEMP_DOWN_SW_GPIO_Port,

	MENU_RIGHT_SW_GPIO_Port,
	MENU_OK_SW_GPIO_Port,
	MENU_LEFT_SW_GPIO_Port,

	HOTAIR_REED_SW_GPIO_Port,
	IRON_T12_MOTION_SW_GPIO_Port,
};


void Test_Buttons(void)
{
	uint8_t i=0;

	printf("Button test. Press button... /n/r");
    LCD_Clear();
	LCD_Puts(0,0, "BUTTON TEST");
	LCD_Puts(0,1, "PRESS BUTTON....");

	while(1)
	{
		if(buttons_pin[i]==IRON_T12_MOTION_SW_Pin || buttons_pin[i]==HOTAIR_REED_SW_Pin)
		{
			if (HAL_GPIO_ReadPin(buttons_port[i],buttons_pin[i]) == 1)
			{
				  LCD_Clear();
				  LCD_Puts(0,0, "BUTTON TEST");
				  LCD_Puts(0,1, text[i]);
				  printf("%s \n\r ", text[i]);
				  Buzzer(500);

				  HAL_Delay(1000);
				  LCD_Clear();
				  LCD_Puts(0,0, "BUTTON TEST");
				  LCD_Puts(0,1, "PRESS BUTTON....");

			}
		}else
		{

			if (HAL_GPIO_ReadPin(buttons_port[i],buttons_pin[i]) == 0)
			{
				  LCD_Clear();
				  LCD_Puts(0,0, "BUTTON TEST");
				  LCD_Puts(0,1, text[i]);
				  printf("%s \n\r ", text[i]);
				  Buzzer(500);

				  HAL_Delay(1000);
				  LCD_Clear();
				  LCD_Puts(0,0, "BUTTON TEST");
				  LCD_Puts(0,1, "PRESS BUTTON....");
			}
		}

		i++;
		if(i>(SWITCH_NUMBER-1))
		{
			i=0;
		}
	}
}
