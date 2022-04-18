/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "main.h"
#include "adc.h"
#include "adc_functions.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "MAX31855/MAX31855.h"
#include "LCD16x2/LCD.h"
#include "utils.h"


#define OPAMP_GAIN 					123			// read from schematic - non-inverting opamp gain
#define THERMOCOUPLE_COEFFICIENT 	0.040		// mv/C
#define AMBIENT_TEMP				20			// TODO - need to read this from MAX31855 or uC internat temp sensor


void Show_HOTAIR_data(int16_t compensaded_temp, float temp_voltage, float fan_voltage)
{

	// show on LCD
	char lcd[10];
	sprintf(lcd,"T%-3d",compensaded_temp);			// Conversation to Char
	LCD_Clear();
	LCD_Puts(0,0,"TEST HOTAIR");
	LCD_Puts(12, 0, lcd);							// show temp
	sprintf(lcd,"V%-.1f",temp_voltage);
	LCD_Puts(0, 1, lcd);							// show ADC temp voltage
	sprintf(lcd,"F%-.1f",fan_voltage/1000);
	LCD_Puts(8, 1, lcd);							// show ADC fan  voltage

	// send via UART
	printf("HOTAIR tip temp:%u[C]\r\n",compensaded_temp);
	printf("Thermocouple voltage: %.1f[mV] \r\n",temp_voltage);
	printf("Fan voltage: %.1f[V] \r\n\r\n",fan_voltage/1000);
}


// Set fan PWM using HW PWM, ducy cycle from 0-100
void Set_Fan_PWM(uint8_t ducy_cycle)
{

	TIM_OC_InitTypeDef sConfigOC = {0};
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
	sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;


	HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_1);
	sConfigOC.Pulse = htim1.Init.Period*ducy_cycle/100;
	HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
}

// time in ms - minimum time 25ms
void Set_HOTAIR_Time(uint16_t time)
{
	HAL_GPIO_WritePin(HOTAIR_HEATER_CTRL_GPIO_Port, HOTAIR_HEATER_CTRL_Pin , GPIO_PIN_SET);
	HAL_Delay(time);
	HAL_GPIO_WritePin(HOTAIR_HEATER_CTRL_GPIO_Port, HOTAIR_HEATER_CTRL_Pin , GPIO_PIN_RESET);
}

// Test heater and temp sensor for hotair
void Test_HOTAIR(void)
{
	const uint16_t set_temp=320;		// target  TIP temp
	int16_t compensaded_temp,compensaded_temp_old;
	float temp, temp_voltage, fan_voltage;

	printf("Testing HOTAIR, heating to %d[C] \r\n",set_temp);

	Set_Fan_PWM(50);

	while(1)
	{
		HAL_Delay(10);					// wait to all transients settle down

		temp_voltage=ADC_Read_Voltage(HOTAIR_ADC_INPUT);
		fan_voltage=ADC_Read_Voltage(FAN_ADC_INPUT);
		temp=((temp_voltage/OPAMP_GAIN) + AMBIENT_TEMP*THERMOCOUPLE_COEFFICIENT)/THERMOCOUPLE_COEFFICIENT;

		HAL_Delay(10);

		compensaded_temp=(int16_t)temp;

		// show on LCD and send to UART only if temp change
		if(compensaded_temp!=compensaded_temp_old)
		{
			Show_HOTAIR_data(compensaded_temp, temp_voltage, fan_voltage);
		}
		compensaded_temp_old=compensaded_temp;

		// simple temp regulator
		if(compensaded_temp<set_temp)
		{
			if(compensaded_temp<set_temp/4)
			{
				Set_HOTAIR_Time(500);

			}else if(compensaded_temp>=set_temp/4 && compensaded_temp<set_temp/2)
			{

				Set_HOTAIR_Time(400);

			}else if(compensaded_temp>=set_temp/2 && compensaded_temp<set_temp)
			{
				Set_HOTAIR_Time(200);
			}

		}else
		{
			printf("HEATED");
			LCD_Puts(13, 1,"HTD");
		}

		HAL_Delay(500);

	} // while end

}
