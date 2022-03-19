#ifndef MAX31855_H_
#define MAX31855_H_
#include "main.h"

// ------------------------- Defines -------------------------

#define SSPORT_HOTAIR MAX31855_HOTAIR_CS_GPIO_Port       // GPIO Port of Chip Select(Slave Select)
#define SSPIN_HOTAIR  MAX31855_HOTAIR_CS_Pin			  // GPIO PIN of Chip Select(Slave Select)

#define SSPORT_IRON MAX31855_IRON_CS_GPIO_Port       // GPIO Port of Chip Select(Slave Select)
#define SSPIN_IRON  MAX31855_IRON_CS_Pin			  // GPIO PIN of Chip Select(Slave Select)

#define READ_IRON		0
#define READ_HOTAIR	    1


#define MAX31855_THERMOCOUPLE_OK            0
#define MAX31855_THERMOCOUPLE_OPEN_CIRCUIT  0b00000001  //1
#define MAX31855_THERMOCOUPLE_SHORT_TO_GND  0b00000010  //2
#define MAX31855_THERMOCOUPLE_SHORT_TO_VCC  0b00000100  //4
#define MAX31855_THERMOCOUPLE_READ_FAIL     5

typedef struct
{
  int16_t get_temperature;
  int16_t get_cold_junction_temperature;
  uint8_t error;

}MAX_TEMP_DATA;


// ------------------------- Functions  ----------------------

void Max31855_Read_Temp(MAX_TEMP_DATA *max_data,uint8_t chip_select);


#endif
