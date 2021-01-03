/*
 * d_led.h
 *
 *  Created on: Jan 2, 2021
 *      Author: LPCusr
 */

#ifndef INC_D_LED_H_
#define INC_D_LED_H_

#define DECIMAL_POINT_ON  1
#define DECIMAL_POINT_OFF 0

void Display_7Seg(unsigned char *text, unsigned char decimal_point);
void Test_Display (void);

#endif /* INC_D_LED_H_ */
