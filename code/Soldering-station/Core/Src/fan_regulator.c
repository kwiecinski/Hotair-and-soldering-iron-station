/*
 * fan_regulator.c
 *
 *  Created on: 6 sty 2021
 *      Author: LPCusr
 */

#include "adc.h"
#include "main.h"
#include "usart.h"
#include "gpio.h"
#include <stdio.h>


#define VFULL                  (4095)   /* Max value with a full range of 12 bits */
#define ADC_RES_DIVIDER_TOP    (22000) 	/* Value of top resistor in a adc input divider in [ohm] */
#define ADC_RES_DIVIDER_BOTTOM (1000) 	/* Value of bottom resistor in a adc input divider in [ohm] */

#define VREFINT		(uint16_t) 3300

#define VREFINT_CAL_ADDR ((uint16_t*)((uint32_t)0x1FFFF7BA))
#define VDD (uint16_t)


#define ADC_FAN_CHANNEL ADC_CHSELR_CHSEL3
#define ADC_VREF_CHANNEL ADC_CHSELR_CHSEL17

void ADC_Init(void)
{
	HAL_ADC_MspInit(&hadc);
	HAL_ADCEx_Calibration_Start(&hadc);
}


uint16_t ADC_Read_Ref(void)
{

	//Important !!! to run single conversion in in code configurator "Overrun behaviour" must be set to "Overrun data overwirtten"

	uint16_t adc_value, voltage_value;

	ADC1->CHSELR = ADC_VREF_CHANNEL;
	HAL_ADC_Start(&hadc);
	HAL_ADC_PollForConversion(&hadc, 1000);
	adc_value = HAL_ADC_GetValue(&hadc);

	voltage_value = VREFINT * (*VREFINT_CAL_ADDR) / adc_value;

	return voltage_value;

}

uint16_t ADC_Read_Fan_Voltage(void)
{

	uint16_t adc_value, voltage_value;


	ADC1->CHSELR = ADC_FAN_CHANNEL;

	HAL_ADC_Start(&hadc);
	HAL_ADC_PollForConversion(&hadc, 1000);
	adc_value = HAL_ADC_GetValue(&hadc);
	HAL_ADC_Stop(&hadc);





	voltage_value = ADC_Read_Ref()*adc_value / VFULL;

	voltage_value = voltage_value * (ADC_RES_DIVIDER_BOTTOM + ADC_RES_DIVIDER_TOP) / ADC_RES_DIVIDER_BOTTOM;



	//printf("Fan voltage: %d \n\r", voltage_value);
	return voltage_value;
}

