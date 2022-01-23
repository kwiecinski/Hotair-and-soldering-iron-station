#include <stdio.h>
#include "adc.h"
#include "main.h"
#include "usart.h"
#include "gpio.h"
#include "adc_functions.h"
#include "tim.h"


void Init_Fan(void)
{

	  HAL_TIM_Base_MspInit(&htim3);
	  HAL_TIM_MspPostInit(&htim3);
	  HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);

	  TIM3->CCR2=0;	//Initial voltage is 0V
}

void Denit_Fan(void)
{

	/* Attention:
	 * After stopping a PWM Output (HAL_TIM_PWM_Stop) the PWM does not go LOW it gets HIGH IMPEDANCE.

	 * Need to do some other things to get LOW output and disable PWM timer or just write CCR2=0
	 * more info:
	 * https://community.st.com/s/question/0D50X00009kLFLzSAO/after-stopping-a-pwm-output-haltimpwmstop-the-signal-is-slowly-decreasing-instead-of-switching-instantly-to-low-0-volt
	 */

     TIM3->CCR2=0;
	// HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_2);
	// HAL_TIM_Base_MspDeInit(&htim3);
	// HAL_GPIO_WritePin(FAN_PWM_GPIO_Port, FAN_PWM_Pin, GPIO_PIN_RESET);
}


void Test_Fan(void)
{

	static int16_t 	duty=0,
					fan_voltage_set=24000,
					fan_voltage;


	static uint8_t dir=0, reg_counter=0;

	Init_Fan();

	while(1)
	{

		fan_voltage = ADC_Read_Voltage(FAN_ADC_INPUT);

		//descending direction
		if(dir==1)
		{
			if(fan_voltage > fan_voltage_set )
			{
				duty--;


				//if sth go wrong propably never used
				if(duty<=0)
				{
					printf("Reg min lvl: %d \n\r", fan_voltage);
					dir=1;
					fan_voltage_set=fan_voltage_set+1000;
					duty++;

				}

			}else if(fan_voltage < fan_voltage_set-500)
			{
				duty++;


			//voltage regulation done
			}else
			{

				printf("Reg done!: %d \n\r", fan_voltage_set);
				fan_voltage_set=fan_voltage_set-1000;

				if((fan_voltage_set<=7000))
				{

					dir=0;
					fan_voltage_set=fan_voltage_set+1000;
					printf("Min voltage reached!: %d \n\r", fan_voltage);
					HAL_Delay(2000);
					reg_counter++;
				}
			}

		//descending direction
		}else
		{
			if(fan_voltage > fan_voltage_set)
			{
				duty--;

			}else if((fan_voltage < fan_voltage_set-500) | (duty>=htim3.Init.Period))
			{
				duty++;


				/*
				*this situation may occur when the supply voltage for some reason does
				*not reach fan_voltage_set (i.e. always if we set 24V due to voltage drop
				*on the power transistor)
				*/
				if(duty>=htim3.Init.Period)
				{
					dir=1;
					fan_voltage_set=fan_voltage_set-1000;
					printf("Reg max lvl: %d \n\r", fan_voltage);
					printf("Max voltage reached!: %d \n\r", fan_voltage);
					HAL_Delay(2000);
				}
			}else
			{
				printf("Reg done!: %d \n\r", fan_voltage_set);
				fan_voltage_set=fan_voltage_set+1000;

				if(duty>=(htim3.Init.Period+1))
				{
					dir=1;
					fan_voltage_set=fan_voltage_set-1000;
					printf("Max voltage reached!: %d \n\r", fan_voltage);
					HAL_Delay(2000);

				}
			}
		}
		//Maximum value of CCR2 register (100% duty cycle) is equal AutoReaload Register value + 1
		TIM3->CCR2=duty;

		//a delay is necessary: too fast response results in a lack of regulation, time selected empirically
		HAL_Delay(20);

		//printf("Duty: %d \n\r", duty);

		if(reg_counter>=2)
		{
			printf("Test FAN done! \n\r");
			HAL_Delay(2000);
			reg_counter=0;
			Denit_Fan();
			break;

		}
	}	//while end

}
