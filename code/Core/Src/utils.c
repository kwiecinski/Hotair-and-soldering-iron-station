/*
 * utils.c
 *
 *  Created on: Mar 18, 2022
 *      Author: kwiecinski
 */

#include "main.h"
#include "tim.h"


void Buzzer(uint16_t ms)
{
	  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
	  HAL_Delay(ms);
	  HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_1);
}


void Start_generic_timer(void)
{
	HAL_TIM_Base_Init(&htim3);
	HAL_TIM_Base_Start(&htim3);
}


void Delay_us(uint16_t us)
{
	htim3.Instance->CNT = 0;
	while(htim3.Instance->CNT <= us*2);
}
