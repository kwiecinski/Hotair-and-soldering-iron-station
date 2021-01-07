/*
 * fan_regulator.h
 *
 *  Created on: 6 sty 2021
 *      Author: LPCusr
 */

#ifndef INC_FAN_REGULATOR_H_
#define INC_FAN_REGULATOR_H_

void ADC_Init(void);
uint16_t ADC_Read_Ref(void);

uint16_t ADC_Read_Fan_Voltage(void);

#endif /* INC_FAN_REGULATOR_H_ */
