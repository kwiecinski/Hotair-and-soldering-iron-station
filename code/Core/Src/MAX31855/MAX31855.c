/*************************************************************************************
 Title	 :  MAXIM Integrated MAX31855 Library for STM32 Using HAL Libraries
 Author  :  Bardia Alikhan Afshar <bardia.a.afshar@gmail.com>
 Software:  STM32CubeIDE
 Hardware:  Any STM32 device
*************************************************************************************/
#include <string.h>
#include <stdio.h>

#include"MAX31855.h"
#include "spi.h"
// ------------------- Variables ----------------

uint8_t Error=0;                                      // Thermocouple Connection acknowledge Flag
uint32_t sign=0;									  // Sign bit
uint8_t SPI_BUFF[4],DATARX[4];                                    // Raw Data from MAX6675
// ------------------- Functions ----------------
float Max31855_Read_Temp(void)
{
	int Temp=0;                                           // Temperature Variable

	HAL_GPIO_WritePin(SSPORT,SSPIN,GPIO_PIN_RESET);       // Low State for SPI Communication
	HAL_SPI_Receive(&hspi1,SPI_BUFF,4,1);                // DATA Transfer
	HAL_GPIO_WritePin(SSPORT,SSPIN,GPIO_PIN_SET);         // High State for SPI Communication

	DATARX[3]=SPI_BUFF[0];
	DATARX[0]=SPI_BUFF[1];
	DATARX[1]=SPI_BUFF[2];
	DATARX[2]=SPI_BUFF[3];

	for(uint8_t i=0;i<4;i++)
	{
	  printf("%d:%X ",i,DATARX[i]);
	}
	printf("\n\r");

	Error=DATARX[3]&0x07;								  // Error Detection
	sign=(DATARX[0]&(0x80))>>7;							  // Sign Bit calculation



	if(DATARX[3] & 0x07)
	{
		// Returns Error Number
		return(-1*(DATARX[3] & 0x07));
	}
		else if(sign==1)
		{									  // Negative Temperature
			Temp = (DATARX[0] << 6) | (DATARX[1] >> 2);
			Temp&=0b01111111111111;
			Temp^=0b01111111111111;
			return((double)-Temp/4);
		}

		else												  // Positive Temperature
		{
			Temp = (DATARX[0] << 6) | (DATARX[1] >> 2);
			return((double)Temp / 4);
		}
}
