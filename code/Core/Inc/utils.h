/*
 * utils.h
 *
 *  Created on: Mar 18, 2022
 *      Author: kwiecinski
 */

#ifndef INC_UTILS_H_
#define INC_UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif

void Start_generic_timer(void);
void Delay_us(uint16_t us);
void Buzzer(uint16_t ms);

#ifdef __cplusplus
}
#endif

#endif /* INC_UTILS_H_ */
