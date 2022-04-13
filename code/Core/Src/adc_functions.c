/*
 * fan_regulator.c
 *
 *  Created on: 6 sty 2021
 *      Author: LPCusr
 */


#include <stdio.h>
#include "adc.h"
#include "main.h"
#include "usart.h"
#include "gpio.h"
#include "adc_functions.h"


#define FULL_SCALE_ADC          4095
#define ADC_FAN_DIVIDER_TOP    	33000
#define ADC_FAN_DIVIDER_BOTTOM 	2200

#define VREFINT		(uint16_t) 1200
// #define VREFINT_CAL_ADDR ((uint16_t*)((uint32_t)0x1FFFF7BA))  // In STM32F103 no such register

#define ADC_FAN_CHANNEL 		ADC_CHANNEL_1
#define ADC_HOTAIR_CHANNEL 		ADC_CHANNEL_9
#define ADC_T12_CHANNEL 		ADC_CHANNEL_8
// ADC_CHANNEL_VREFINT - library define



void Init_ADC(void)
{
	HAL_ADC_Init(&hadc1);
	// Before starting a calibration, the ADC must have been in power-on state (ADON bit = ‘1’) for
	// at least two ADC clock cycles.
	HAL_Delay(1);
	HAL_ADCEx_Calibration_Start(&hadc1);
}


uint16_t ADC_Read_Raw(uint32_t channel)
{
	uint16_t adc_value;

	//channel selection
	ADC_ChannelConfTypeDef adc_ch;
	adc_ch.Rank = ADC_REGULAR_RANK_1;
	adc_ch.SamplingTime = ADC_SAMPLETIME_13CYCLES_5;
	adc_ch.Channel = channel;

	HAL_ADC_ConfigChannel(&hadc1, &adc_ch);
	//end channel selection
	HAL_Delay(1);
	HAL_ADC_Start(&hadc1);
	HAL_Delay(1);

	while(HAL_ADC_PollForConversion(&hadc1, 1000)!=HAL_OK)
	{
	}

	HAL_Delay(1);
	adc_value = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);

	return adc_value;
}



// return VREF voltages in mV eg. 1202[mv]
uint16_t ADC_Read_Refrence(void)
{
	uint32_t ref_value;
/*

	VREFINT is measured like any other channel on ADC1.
	Because we know that VREFINT = 1.20V, we can calculate VDDA= FULL_SCALE_ADC * VREFINT / VREFINT_raw_value
 */
	ref_value = ADC_Read_Raw(ADC_CHANNEL_VREFINT);
	ref_value = FULL_SCALE_ADC*VREFINT/ref_value;

	return (uint16_t)ref_value;
}

/*
 *
 * return voltage value in mV
 * eg. returns 15987 -> 15,987V
 *
 */


float ADC_Read_Voltage(uint8_t adc_input)
{

	const uint8_t number_of_samples=50;
	uint16_t value;
	float sum;


/*
	printf("VREF:%d  \r\n",ADC_Read_Refrence());
	HAL_Delay(100);
	printf("T12:%d  \r\n",ADC_Read_Raw(ADC_T12_CHANNEL));
	//printf("VREF CAL:%d  \r\n",(*VREFINT_CAL_ADDR));

*/
		sum=0;

		if(adc_input == FAN_ADC_INPUT)
		{

			for(uint8_t i=0;i<number_of_samples;i++)
			{
				sum = sum + ADC_Read_Raw(ADC_FAN_CHANNEL);
			}

			sum = sum / (uint32_t) number_of_samples;

			sum = ADC_Read_Refrence() * sum / FULL_SCALE_ADC;
			return (sum * (ADC_FAN_DIVIDER_BOTTOM + ADC_FAN_DIVIDER_TOP) / ADC_FAN_DIVIDER_BOTTOM);

		}else if(adc_input == HOTAIR_ADC_INPUT)
		{

			for(uint8_t i=0;i<number_of_samples;i++)
			{
				sum = sum + ADC_Read_Raw(ADC_HOTAIR_CHANNEL);
			}

			sum = sum / (uint32_t) number_of_samples;

			sum = ADC_Read_Refrence() *  sum / FULL_SCALE_ADC;
			return sum;

		}else if(adc_input == T12_ADC_INPUT)
		{

			for(uint8_t i=0;i<number_of_samples;i++)
			{
				sum = sum + ADC_Read_Raw(ADC_T12_CHANNEL);
			}
			sum = sum / (float) number_of_samples;

			sum = (ADC_Read_Refrence() * sum) / FULL_SCALE_ADC;

			return sum ;
		}
	return 0;
}







