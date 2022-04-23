/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "main.h"
#include "adc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "MAX31855/MAX31855.h"
#include "LCD16x2/LCD.h"
#include "utils.h"

void Show_MAX_data_LCD(MAX_TEMP_DATA *data, int16_t compensaded_temp)
{

		char lcd[10];
		sprintf(lcd,"T%-3d",compensaded_temp);			// Conversation to Char
		LCD_Clear();
		LCD_Puts(0,0,"TEST WEP");
		LCD_Puts(9, 0, lcd);
		sprintf(lcd,"%-2d",data->get_cold_junction_temperature);
		LCD_Puts(14, 0, lcd);

    // Send to LCD
	switch(data->error)
	{
		case MAX31855_THERMOCOUPLE_OK: 				LCD_Puts(0, 1,"NORMAL");
		break;
		case MAX31855_THERMOCOUPLE_OPEN_CIRCUIT:    LCD_Puts(0, 1,"OPEN ");
		break;
		case MAX31855_THERMOCOUPLE_SHORT_TO_GND:    LCD_Puts(0, 1,"SHORT GND");
		break;
		case MAX31855_THERMOCOUPLE_SHORT_TO_VCC:    LCD_Puts(0, 1,"SHORT VCC");
		break;
		default:
		break;
	}
	 // Send to debug uart
	switch(data->error)
	{
		case MAX31855_THERMOCOUPLE_OK:				printf("Iron compensated temp: %d%cC\r\n",compensaded_temp,'\xF8');
													printf("Iron temp: %d%cC\r\n",data->get_temperature,'\xF8');
		break;
		case MAX31855_THERMOCOUPLE_OPEN_CIRCUIT:    printf("MAX ERROR: Open circuit \r\n");
		break;
		case MAX31855_THERMOCOUPLE_SHORT_TO_GND:    printf("MAX ERROR: Short to GND \r\n");
		break;
		case MAX31855_THERMOCOUPLE_SHORT_TO_VCC:    printf("MAX ERROR: Short to VCC \r\n");
		break;
		default:
		break;
	}
}


/* Generate software PWM
 * frequency in Hz - minimum 16Hz, maximum 6553Hz
 * duration time in ms
 */

void Set_WEP_PWM(uint32_t duty_cycle, uint32_t frequency)
{
	HAL_GPIO_WritePin(IRON_WEP_HEATER_CTRL_GPIO_Port, IRON_WEP_HEATER_CTRL_Pin, GPIO_PIN_SET);
	Delay_us(1000000/frequency*(duty_cycle)/100);
	HAL_GPIO_WritePin(IRON_WEP_HEATER_CTRL_GPIO_Port, IRON_WEP_HEATER_CTRL_Pin, GPIO_PIN_RESET);
	Delay_us(1000000/frequency*(100-(duty_cycle))/100);
}


void Test_WEP(void)
{
	MAX_TEMP_DATA data;
	MAX_TEMP_DATA data_old;
	const uint16_t set_temp=320;		// target  TIP temp
	const uint16_t frequency=25000;		// switch frequency in Hz
	int16_t cnt, htd_cnt=0;
	int16_t compensaded_temp;


	printf("Testing WEP soldering iron, heating to %d \r\n",set_temp);

	while(1)
	{
		// Important delay, without it MAX won't correctly measure.
		// Noise occurs because the thermocouple test leads run parallel to the heating leads.
		// Even that the transistor is turned off due to the self-induction voltage (the heater has a slight inductance)
		// It inject some noise to de thermocouple system.
		// Need to experiment to achieve optimal time
		HAL_GPIO_WritePin(IRON_WEP_HEATER_CTRL_GPIO_Port, IRON_WEP_HEATER_CTRL_Pin, GPIO_PIN_RESET);
		HAL_Delay(10);
		Max31855_Read_Temp(&data,READ_IRON);
		HAL_Delay(10);

		// Compensation equation calculated from excel
		compensaded_temp=(data.get_temperature*69+500)/100;

		// Update LCD and send to debug uart if temp values or error status change
		if((data_old.get_temperature != data.get_temperature) |
		   (data_old.get_cold_junction_temperature != data.get_cold_junction_temperature) |
		   (data_old.get_temperature != data.get_temperature) |
		   (data_old.error != data.error))
		{

			Show_MAX_data_LCD(&data,compensaded_temp);
		}

		data_old.error=data.error;
		data_old.get_cold_junction_temperature=data.get_cold_junction_temperature;
		data_old.get_temperature=data.get_temperature;

		if(data.error != MAX31855_THERMOCOUPLE_OK)
		{
			HAL_GPIO_WritePin(IRON_WEP_HEATER_CTRL_GPIO_Port, IRON_WEP_HEATER_CTRL_Pin, GPIO_PIN_RESET);

		}else
		{
			if(compensaded_temp<set_temp/4)
			{
				cnt=frequency;
				while(cnt)
				{
					Set_WEP_PWM(100,frequency);
					cnt--;
				}
			}else if(compensaded_temp>=set_temp/4 && compensaded_temp<set_temp/2)
			{
				cnt=frequency;
				while(cnt)
				{
					Set_WEP_PWM(75,frequency);
					cnt--;
				}

			}else if(compensaded_temp>=set_temp/2 && compensaded_temp<set_temp)
			{
				cnt=frequency;
				while(cnt)
				{
					Set_WEP_PWM(60,frequency);
					cnt--;
				}

			}else if(compensaded_temp>=set_temp)
			{

				Set_WEP_PWM(0,frequency);
				printf("HEATED \n\r");
				LCD_Puts(13, 1,"HTD");
				Buzzer(1000);
				HAL_Delay(3000);
				htd_cnt++;
				if(htd_cnt>2)
				{
					break;
				}


			}
		} // else end
	} // while end
}
