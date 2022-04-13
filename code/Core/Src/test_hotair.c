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

void Show_HOTAIR_data(MAX_TEMP_DATA *data, int16_t compensaded_temp)
{

		char lcd[10];
		sprintf(lcd,"T%-3d",compensaded_temp);			// Conversation to Char
		LCD_Clear();
		LCD_Puts(0,0,"TEST HAR");
		LCD_Puts(9, 0, lcd);
		sprintf(lcd,"%-2d",data->get_cold_junction_temperature);
		LCD_Puts(14, 0, lcd);

    // Send to LCD
	switch(data->error)
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
	 // Send to debug uart
	switch(data->error)
	{
		case MAX31855_THERMOCOUPLE_OK:				printf("Iron compensated temp: %d%cC\r\n",compensaded_temp,'\xF8');
													printf("Iron temp: %d%cC\r\n",data->get_temperature,'\xF8');
		break;
		case MAX31855_THERMOCOUPLE_OPEN_CIRCUIT:    printf("MAX ERROR: Open circuit \r\n");
		break;
		case MAX31855_THERMOCOUPLE_SHORT_TO_GND:    printf("MAX ERROR: Short to GND \r\n");
		break;
		case MAX31855_THERMOCOUPLE_SHORT_TO_VCC:    printf("MAX ERROR: Short to VCC \r\n");
		break;
		default:
		break;
	}
}


/* Generate software PWM
 * frequency in Hz - minimum 16Hz, maximum 6553Hz
 * duration time in ms
 */

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

//time in ms - minimu time 25ms
void Set_HOTAIR_Time(uint16_t time)
{
	HAL_GPIO_WritePin(HOTAIR_HEATER_CTRL_GPIO_Port, HOTAIR_HEATER_CTRL_Pin , GPIO_PIN_SET);
	HAL_Delay(time);
	HAL_GPIO_WritePin(HOTAIR_HEATER_CTRL_GPIO_Port, HOTAIR_HEATER_CTRL_Pin , GPIO_PIN_RESET);
}

void Test_HOTAIR(void)
{
	MAX_TEMP_DATA data;
	MAX_TEMP_DATA data_old;
	const uint16_t set_temp=320;		// target  TIP temp
	int16_t compensaded_temp;



	printf("Testing HOTAIR, heating to %d \r\n",set_temp);

	while(1)
	{
		// Important delay, without it MAX won't correctly measure.
		// Noise occurs because the thermocouple test leads run parallel to the heating leads.
		// Even that the transistor is turned off due to the self-induction voltage (the heater has a slight inductance)
		// It inject some noise to de thermocouple system.
		// Need to experiment to achieve optimal time

		 Set_Fan_PWM(30);

		HAL_Delay(10);
		Max31855_Read_Temp(&data,READ_HOTAIR);
		HAL_Delay(10);

		// Compensation equation calculated from excel
		//compensaded_temp=(data.get_temperature*69+500)/100;
		compensaded_temp=data.get_temperature;

		if((data_old.get_temperature != data.get_temperature) |
		   (data_old.get_cold_junction_temperature != data.get_cold_junction_temperature) |
		   (data_old.get_temperature != data.get_temperature) |
		   (data_old.error != data.error))
		{

			Show_HOTAIR_data(&data,compensaded_temp);
		}

		if(compensaded_temp<set_temp)
		{
			if(compensaded_temp<set_temp/4)
			{
				Set_HOTAIR_Time(400);

			}else if(compensaded_temp>=set_temp/4 && compensaded_temp<set_temp/2)
			{

				Set_HOTAIR_Time(200);

			}else if(compensaded_temp>=set_temp/2 && compensaded_temp<set_temp)
			{
				Set_HOTAIR_Time(100);
			}

		}else
		{
			printf("HEATED");
			LCD_Puts(10, 1,"      ");
			LCD_Puts(10, 1,"HEATED");
		}

		HAL_Delay(500);
	} //while end

}
