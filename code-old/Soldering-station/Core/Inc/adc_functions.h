/*
 * fan_regulator.h
 *
 *  Created on: 6 sty 2021
 *      Author: LPCusr
 */

#ifndef INC_ADC_FUNCTIONS_H_
#define INC_ADC_FUNCTIONS_H_

#define FAN_ADC_INPUT		1
#define HOTAIR_ADC_INPUT	2
#define SOLDER_ADC_INPUT	3
#define TEMP_SNS_ADC_INPUT	4


void Init_ADC(void);
uint16_t ADC_Read_Voltage(uint8_t adc_input);

#endif /* INC_ADC_FUNCTIONS_H_ */
