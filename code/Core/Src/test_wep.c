/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "main.h"
#include "adc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "MAX31855/MAX31855.h"
#include "LCD16x2/LCD.h"


void Test_WEP(void)
{


	MAX_TEMP_DATA data;
	char lcd[16];


	Max31855_Read_Temp(&data,READ_IRON); 			// Gets Temperature from MAX31855
	sprintf(lcd,"T%-3d",data.get_temperature);		// Conversation to Char
	LCD_Clear();
	LCD_Puts(0,0,"TEST WEP");
	LCD_Puts(9, 0, lcd); 			// LCD Show
	sprintf(lcd,"J%-2d",data.get_cold_junction_temperature);		// Conversation to Char
	LCD_Puts(14, 0, lcd); 			// LCD Show

	switch(data.error)
	{
		case MAX31855_THERMOCOUPLE_OK: 				LCD_Puts(0, 1,"NORMAL");
		break;
		case MAX31855_THERMOCOUPLE_OPEN_CIRCUIT:    LCD_Puts(0, 1,"OPEN ");
		break;
		case MAX31855_THERMOCOUPLE_SHORT_TO_GND:    LCD_Puts(0, 1,"SHORT GND");
		break;
		case MAX31855_THERMOCOUPLE_SHORT_TO_VCC:    LCD_Puts(0, 1,"SHORT VCC");
		break;
		default:
		break;
	}


	HAL_Delay(1000);

}
