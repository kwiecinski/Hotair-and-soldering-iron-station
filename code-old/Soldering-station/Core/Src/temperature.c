/*
 * temperature.c
 *
 *  Created on: Jan 17, 2021
 *      Author: LPCusr
 */


#include <stdio.h>
#include "adc.h"
#include "main.h"
#include "usart.h"
#include "gpio.h"
#include "adc_functions.h"


#define TEMP30_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FFFF7B8))
#define TEMP110_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FFFF7C2))

//AVG_SLOPE in ADC conversion step
//from datasheet (p.71) min 4.0mV/C max 4.6mV/C so take average 4.3mV/C
#define AVG_SLOPE ((int32_t) (4300))
#define ADD_30	  ((int32_t) (30))		//from datasheet p.204 ref. man


/*
 *
 * The sampling time for the temperature sensor analog pin must be greater
 * than the minimum TS_temp value specified in the datasheet.
 *
 * In our uC: ts_min = 4us
 *
 * I choose for entire ADC : ADC_SAMPLETIME_71CYCLES_5 to for 14MHz clk is > 5us so its enough
 *
 */
void Read_Temperature(void)
{
	int32_t temp; //will contain the temperature in degrees Celsius

	temp=ADC_Read_Voltage(TEMP_SNS_ADC_INPUT);

	//from datasheet
	/*
	temp=((int32_t) *TEMP30_CAL_ADDR) - temp;
	temp= temp/AVG_SLOPE+ADD_30;
	*/

	//from stack
	temp = temp - (int32_t) *TEMP30_CAL_ADDR;
	temp *= (int32_t)(11000 - 3000);
	temp = temp / (int32_t)(*TEMP110_CAL_ADDR - *TEMP30_CAL_ADDR);
	temp = temp + 3000;

	printf("Temp : %ld\n\r",temp);

}
