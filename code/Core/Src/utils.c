/*
 * utils.c
 *
 *  Created on: Mar 18, 2022
 *      Author: LPCusr
 */

#include "main.h"
#include "tim.h"

void Start_generic_timer(void)
{
	HAL_TIM_Base_Init(&htim3);
	HAL_TIM_Base_Start(&htim3);
}


void Delay_us(uint16_t us)
{
	htim3.Instance->CNT = 0;
	while(htim3.Instance->CNT <= us);
}
