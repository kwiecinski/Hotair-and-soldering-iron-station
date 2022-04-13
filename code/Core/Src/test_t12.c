#include <stdio.h>
#include "main.h"
#include "adc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "MAX31855/MAX31855.h"
#include "LCD16x2/LCD.h"
#include "utils.h"
#include "adc_functions.h"


typedef struct
{
  int16_t temperature;
  int16_t cold_junction_temperature;
  uint8_t error;

}T12_TEMP_DATA;


#define OPAMP_GAIN 200
#define THERMOCOUPLE_COEFFICIENT 	0.021		// mv/C
#define AMBIENT_TEMP		20					// TODO - need to read this from MAX31855 or uC internat temp sensor


void Show_T12_data(int16_t compensaded_temp)
{

		char lcd[10];
		sprintf(lcd,"T%-3d",compensaded_temp);			// Conversation to Char
		LCD_Clear();
		LCD_Puts(0,0,"TEST T12");
		//LCD_Puts(9, 0, lcd);
		//sprintf(lcd,"%-2d",data->get_cold_junction_temperature);
		//LCD_Puts(14, 0, lcd);

		printf("T12 tip temp:%u[C]\r\n",compensaded_temp);

}


void Test_T12(void)
{

	const uint16_t set_temp=320;		// target  TIP temp
	const uint16_t frequency=1000;		// switch frequency in Hz
	TIM_OC_InitTypeDef sConfigOC = {0};
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;

	int16_t compensaded_temp,compensaded_temp_old;
	float temp;

	printf("Testing T12 soldering iron, heating to %d \r\n",set_temp);

	while(1)
	{

			//printf("%f [mV]\r\n",temp);
			//printf("temp: %f\r\n",(temp/200)/0.021);

			// Reading soldering iron voltage from thermocouple + converting ambient temp to voltage and then dividing
			// by thermocouple coefficient to get relative temp

			HAL_TIM_PWM_Stop(&htim4,TIM_CHANNEL_1);
			HAL_Delay(20);
			temp=((ADC_Read_Voltage(T12_ADC_INPUT)/OPAMP_GAIN) + AMBIENT_TEMP*THERMOCOUPLE_COEFFICIENT)/THERMOCOUPLE_COEFFICIENT;



		// Compensation equation calculated from excel

		//compensaded_temp=(data.get_temperature*69+500)/100;

		compensaded_temp=(uint16_t)temp;

		if(compensaded_temp!=compensaded_temp_old)
		{
			Show_T12_data(compensaded_temp);
		}

		compensaded_temp_old=compensaded_temp;

		if(compensaded_temp<set_temp)
		{
			if(compensaded_temp<set_temp/4)
			{
				  sConfigOC.Pulse = htim4.Init.Period/2;
				  HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1);

			}else if(compensaded_temp>=set_temp/4 && compensaded_temp<set_temp/2)
			{

				  sConfigOC.Pulse = htim4.Init.Period/3;
				  HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1);

			}else if(compensaded_temp>=set_temp/2 && compensaded_temp<set_temp)
			{
				  sConfigOC.Pulse = htim4.Init.Period/6;
				  HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1);
			}

			HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);
			HAL_Delay(frequency);

		}else
		{

			/*
			sConfigOC.Pulse = htim4.Init.Period/2;
			HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1);
			HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);
			while(1){}
			*/
			HAL_TIM_PWM_Stop(&htim4,TIM_CHANNEL_1);
			LCD_Puts(10, 1,"      ");
			LCD_Puts(10, 1,"HEATED");
		}

	} //while end
}
