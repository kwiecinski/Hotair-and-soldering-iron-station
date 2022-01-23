#include <string.h>
#include <stdio.h>
#include "main.h"
#include "tim.h"
#include "gpio.h"


void Init_Delay_Timer(void)
{
	HAL_TIM_Base_Start(&htim1);
}

void delay_us (uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&htim1,0);  // set the counter value a 0
	while (__HAL_TIM_GET_COUNTER(&htim1) < (us));  // wait for the counter to reach the us input in the parameter
}

uint16_t make16(uint8_t b1, uint8_t b2)
{
	uint16_t combined = b1 << 8 | b2;
    return combined;
}

/*******************1-wire communication functions********************/

/************onewire_reset*************************************************/
/*This function initiates the 1wire bus */
/* */
/*PARAMETERS: */
/*RETURNS: */
/*********************************************************************/

void Set_Pin_Input(void)
{
	DS18B20_DATA_GPIO_Port->MODER &= ~(GPIO_MODER_MODER15);
}

void Set_Pin_Output(void)
{
	DS18B20_DATA_GPIO_Port->MODER |= GPIO_MODER_MODER15_0;
}

void onewire_reset()  // OK if just using a single permanently connected device
{
	Set_Pin_Output();   // set the pin as output
	HAL_GPIO_WritePin(DS18B20_DATA_GPIO_Port, DS18B20_DATA_Pin, 0);  // pull the pin low
	delay_us(480);   // delay according to datasheet
	Set_Pin_Input();    // set the pin as input
	delay_us(80);    // delay according to datasheet
	while(HAL_GPIO_ReadPin (DS18B20_DATA_GPIO_Port, DS18B20_DATA_Pin)==1);   // if the pin is low i.e the presence pulse is detected
	delay_us(400);
}

/*********************** onewire_write() ********************************/
/*This function writes a byte to the sensor.*/
/* */
/*Parameters: byte - the byte to be written to the 1-wire */
/*Returns: */
/*********************************************************************/

void onewire_write(uint8_t data)
{

	for (uint8_t i=0; i<8; i++)
	{
		if ((data & (1<<i))!=0)  // if the bit is high
		{
			// write 1

			Set_Pin_Output();
			HAL_GPIO_WritePin (DS18B20_DATA_GPIO_Port, DS18B20_DATA_Pin, 0);
			delay_us(2);
			Set_Pin_Input();
			delay_us(50);

		}else  // if the bit is low
		{
			Set_Pin_Output();
			HAL_GPIO_WritePin (DS18B20_DATA_GPIO_Port, DS18B20_DATA_Pin, 0);
			delay_us(50);
			Set_Pin_Input();
		}
	}
}

/*********************** read1wire() *********************************/
/*This function reads the 8 -bit data via the 1-wire sensor. */
/* */
/*Parameters: */
/*Returns: 8-bit (1-byte) data from sensor */
/*********************************************************************/

uint8_t onewire_read(void)
{
	uint8_t value=0;
	for (uint8_t i=0;i<8;i++)
	{
		Set_Pin_Output();    // set as output

		HAL_GPIO_WritePin (DS18B20_DATA_GPIO_Port, DS18B20_DATA_Pin, 0);  // pull the data pin LOW
		delay_us(2);  // wait for 2 us

		Set_Pin_Input();
		if (HAL_GPIO_ReadPin (DS18B20_DATA_GPIO_Port, DS18B20_DATA_Pin))  // if the pin is HIGH
		{
			value |= 1<<i;  // read = 1
		}
		delay_us(60);  // wait for 60 us
	}
	return value;
}

uint8_t CRC8(uint8_t *inData, uint8_t len)
{
   uint8_t crc;
   crc = 0;
   for(; len; len--)
   {
      crc ^= *inData++;
      crc ^= (crc << 3) ^ (crc << 4) ^ (crc << 6);
      crc ^= (crc >> 4) ^ (crc >> 5);
   }
   return crc;
}


void ds1820_read(void)
{

	uint8_t frametab[9],i, busy;
	int16_t temp;
	float result;

	onewire_reset();
	onewire_write(0xCC);
	onewire_write(0x44);
	while (busy==0)
		{
			busy=onewire_read();
		}

	onewire_reset();
	onewire_write(0xCC);
	onewire_write(0xBE);

	for(i=0;i<=8;i++)
	{
		frametab[i]=onewire_read();
	}

/*
	for(i=0;i<=8;i++)
	{
		printf("%d: %d \r\n",i,frametab[i]);
	}

*/
	if(frametab[8]==CRC8(&frametab[0],8))
	{

		temp = make16(frametab[1], frametab[0]);
		result= ((float)temp/16.0)*10;
		printf("DS18B20 temp: %d.%d\r\n",(int16_t)result/10, abs((int16_t)result%10));

	}else
	{
		printf("DS18B20 CRC bad \r\n");
	}

	HAL_Delay(2000);


}
