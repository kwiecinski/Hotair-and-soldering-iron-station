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
#define ADC_FAN_DIVIDER_TOP    	22000
#define ADC_FAN_DIVIDER_BOTTOM 	1000

#define VREFINT		(uint16_t) 3300
#define VREFINT_CAL_ADDR ((uint16_t*)((uint32_t)0x1FFFF7BA))

#define ADC_IRON_CHANNEL 	ADC_CHSELR_CHSEL0
#define ADC_HOTAIR_CHANNEL 	ADC_CHSELR_CHSEL1
#define ADC_FAN_CHANNEL 	ADC_CHSELR_CHSEL3
#define ADC_VREF_CHANNEL 	ADC_CHSELR_CHSEL17
#define ADC_TEMP_CHANNEL 	ADC_CHSELR_CHSEL16


void Init_ADC(void)
{
	HAL_ADC_MspInit(&hadc);
	HAL_ADCEx_Calibration_Start(&hadc);
}


uint16_t ADC_Read_Raw(uint32_t channel)
{
	uint16_t adc_value;
	ADC1->CHSELR = channel;
	HAL_ADC_Start(&hadc);
	HAL_ADC_PollForConversion(&hadc, 1000);
	adc_value = HAL_ADC_GetValue(&hadc);
	HAL_ADC_Stop(&hadc);

	return adc_value;
}


uint16_t ADC_Read_Refrence(void)
{

	uint16_t ref_value;

	ref_value = ADC_Read_Raw(ADC_VREF_CHANNEL);
	ref_value = VREFINT * (*VREFINT_CAL_ADDR) / ref_value;
	return ref_value;

}

/*
 *
 * return voltage value in mV
 * eg. returns 15987 -> 15,987V
 *
 */


uint16_t ADC_Read_Voltage(uint8_t adc_input)
{

	const uint8_t number_of_samples=100;
	uint16_t value;
	uint32_t sum;


		sum=0;

		if(adc_input == FAN_ADC_INPUT)
		{

			for(uint8_t i=0;i<number_of_samples;i++)
			{
				sum = sum + ADC_Read_Raw(ADC_FAN_CHANNEL);
			}

			sum = sum / (uint32_t) number_of_samples;

			value = ADC_Read_Refrence() * sum / FULL_SCALE_ADC;
			return (value * (ADC_FAN_DIVIDER_BOTTOM + ADC_FAN_DIVIDER_TOP) / ADC_FAN_DIVIDER_BOTTOM);

		}else if(adc_input == HOTAIR_ADC_INPUT)
		{

			for(uint8_t i=0;i<number_of_samples;i++)
			{
				sum = sum + ADC_Read_Raw(ADC_HOTAIR_CHANNEL);
			}

			sum = sum / (uint32_t) number_of_samples;

			value = ADC_Read_Refrence() *  sum / FULL_SCALE_ADC;
			return (value * (ADC_FAN_DIVIDER_BOTTOM + ADC_FAN_DIVIDER_TOP) / ADC_FAN_DIVIDER_BOTTOM);

		}else if(adc_input == SOLDER_ADC_INPUT)
		{

			for(uint8_t i=0;i<number_of_samples;i++)
			{
				sum = sum + ADC_Read_Raw(ADC_IRON_CHANNEL);
			}

			sum = sum / (uint32_t) number_of_samples;

			value = ADC_Read_Refrence() *  sum / FULL_SCALE_ADC;
			return (value * (ADC_FAN_DIVIDER_BOTTOM + ADC_FAN_DIVIDER_TOP) / ADC_FAN_DIVIDER_BOTTOM);

		}else if(adc_input == TEMP_SNS_ADC_INPUT)
		{

			for(uint8_t i=0;i<number_of_samples;i++)
			{
				sum = sum + ADC_Read_Raw(ADC_TEMP_CHANNEL);
			}

			sum = sum / (uint32_t) number_of_samples;

			value = ADC_Read_Refrence() *  sum / FULL_SCALE_ADC;
			return value;

		}

	return 0;
}





