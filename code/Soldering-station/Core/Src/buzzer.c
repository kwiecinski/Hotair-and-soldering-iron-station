/*
 * buzzer.c
 *
 *  Created on: 15 sty 2021
 *      Author: LPCusr
 */

#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"


void Init_Buzzer(void)
{

	__HAL_TIM_ENABLE(&htim14);
	  HAL_TIM_Base_MspInit(&htim14);
	  HAL_TIM_MspPostInit(&htim14);
}


void Deinit_Buzzer(void)
{
	__HAL_TIM_DISABLE(&htim14);
}

void Buzzer_Start(void)
{

	HAL_TIM_OC_Start(&htim14,TIM_CHANNEL_1);
}

void Buzzer_Stop(void)
{
	HAL_TIM_OC_Stop(&htim14,TIM_CHANNEL_1);
}


void Test_Buzzer(void)
{
	Init_Buzzer();
	Buzzer_Start();
	HAL_Delay(3000);
	Buzzer_Stop();
	Deinit_Buzzer();
	printf("Test buzzer done! \n\r");
	HAL_Delay(2000);
}
