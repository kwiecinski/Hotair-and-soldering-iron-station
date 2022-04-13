#include <string.h>
#include <stdio.h>

#include"MAX31855.h"
#include "spi.h"

/**
  * Reads data from MAX31855 chip.
  * Inputs: pointer to MAX_TEMP_DATA struct, selected chip
  * Outputs: thermocuple temp, cold junction temp, errors
  */
void Max31855_Read_Temp(MAX_TEMP_DATA *max_data, uint8_t chip_select)
{
	uint8_t SPI_BUFF[4],DATARX[4]; 						 // Raw Data from MAX6675

	max_data->get_temperature=0;
	max_data->get_cold_junction_temperature=0;
	max_data->error=0;


	if(chip_select==READ_HOTAIR)
	{
		HAL_GPIO_WritePin(SSPORT_HOTAIR,SSPIN_HOTAIR,GPIO_PIN_RESET);      // Low State for SPI Communication
		HAL_SPI_Receive(&hspi1,SPI_BUFF,4,2);                // DATA Transfer
		HAL_Delay(1);
		HAL_GPIO_WritePin(SSPORT_HOTAIR,SSPIN_HOTAIR,GPIO_PIN_SET);        // High State for SPI Communication
	}else if(chip_select==READ_IRON)
	{

		HAL_GPIO_WritePin(SSPORT_IRON,SSPIN_IRON,GPIO_PIN_RESET);      // Low State for SPI Communication
		HAL_SPI_Receive(&hspi1,SPI_BUFF,4,2);                // DATA Transfer
		HAL_Delay(1);
		HAL_GPIO_WritePin(SSPORT_IRON,SSPIN_IRON,GPIO_PIN_SET);        // High State for SPI Communication
	}


	// There is some weird problem in HAL_SPI_Receive, it write data not in correct order.
	// The last byte is first. For clarity i switched bytes in correct order.
	DATARX[3]=SPI_BUFF[0];
	DATARX[0]=SPI_BUFF[1];
	DATARX[1]=SPI_BUFF[2];
	DATARX[2]=SPI_BUFF[3];

	//printf("%d %d %d %d \n\r", DATARX[0],DATARX[1],DATARX[2],DATARX[3] );
	max_data->error=DATARX[3]&0x07;								  // Error Detection
    uint8_t sign=(DATARX[0]&(0x80))>>7;							  // Sign Bit for thermocouple



	if(DATARX[3] & 0x07)
	{
		max_data->error= DATARX[3] & 0x07;
		// error, no temperature can be measured
		return;
	}else if(sign==1)
	{
		// Negative Temperature
		//14-Bit Thermocouple Temperature Data - DATARX[0] all 8 bit and DATARX[1] first 6 bits
		max_data->get_temperature = ((DATARX[0] << 8) | DATARX[1])>>2;
		max_data->get_temperature &= 0b01111111111111;
		max_data->get_temperature ^= 0b01111111111111;
		// I subtract -0.25 because -0.25= 0b1111 1111 1111 11 (from datasheet example)
		max_data->get_temperature = (float)-max_data->get_temperature/4-0.25;

	}else								 // Positive Temperature
	{
		max_data->get_temperature = ((DATARX[0] << 8) | DATARX[1])>>2;
		max_data->get_temperature = (float)max_data->get_temperature/4;

	}

	max_data->error=0;
	sign=(DATARX[2]&(0x80))>>7;	// Sign Bit for reference junction

	if(sign==1)
		{
			// Negative Temperature
			//12-Bit reference junction temperature data - DATARX[2] all 8 bit and DATARX[3] first 4 bits
			max_data->get_cold_junction_temperature = ((DATARX[2] << 8) | DATARX[3])>>4;
			max_data->get_cold_junction_temperature &= 0b01111111111111;
			max_data->get_cold_junction_temperature ^= 0b01111111111111;
			// I subtract -0.25 because -0.25= 0b1111 1111 1111 11 (from datasheet example)
			max_data->get_cold_junction_temperature = (float)-max_data->get_cold_junction_temperature/16-0.0625;
			return;

	}else								 // Positive Temperature
		{
			max_data->get_cold_junction_temperature = ((DATARX[2] << 8) | DATARX[3])>>4;
			max_data->get_cold_junction_temperature = (float)max_data->get_cold_junction_temperature/16;
			return;
		}
}
