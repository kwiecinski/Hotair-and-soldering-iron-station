/*
 * ds18b20.c
 *
 *  Created on: Jan 17, 2021
 *      Author: LPCusr
 */



void onewire_reset()  // OK if just using a single permanently connected device
{
	output_low(one_wire_pin);
	HAL_Delay(500); // pull 1-wire low for reset pulse
	output_float(one_wire_pin); // float 1-wire high
	HAL_Delay(500); // wait-out remaining initialisation window.
	output_float(one_wire_pin);
}

/*********************** onewire_write() ********************************/
/*This function writes a byte to the sensor.*/
/* */
/*Parameters: byte - the byte to be written to the 1-wire */
/*Returns: */
/*********************************************************************/

void onewire_write(int data)
{
	int count;

	for (count=0; count<8; ++count)
	{

		output_low(one_wire_pin);
		delay_us( 2 ); // pull 1-wire low to initiate write time-slot.
		output_bit(one_wire_pin, shift_right(&data,1,0)); // set output bit on 1-wire
		delay_us( 60 ); // wait until end of write slot.
		output_float(one_wire_pin); // set 1-wire high again,
		delay_us( 2 ); // for more than 1us minimum.

	}

}

/*********************** read1wire() *********************************/
/*This function reads the 8 -bit data via the 1-wire sensor. */
/* */
/*Parameters: */
/*Returns: 8-bit (1-byte) data from sensor */
/*********************************************************************/

int onewire_read()
{
 int count, data;

	for (count=0; count<8; ++count)
	{
		output_low(one_wire_pin);
		delay_us( 2 ); // pull 1-wire low to initiate read time-slot.
		output_float(one_wire_pin); // now let 1-wire float high,
		delay_us( 8 ); // let device state stabilise,
		shift_right(&data,1,input(one_wire_pin)); // and load result.
		delay_us( 120 ); // wait until end of read slot.
	}


 return( data );
}


#define error 0xFFFF

volatile int8 temp_counter;

int8 CRC8(int8 *inData, int8 len)
{
   int8 crc;
   crc = 0;
   for(; len; len--)
   {
      crc ^= *inData++;
      crc ^= (crc << 3) ^ (crc << 4) ^ (crc << 6);
      crc ^= (crc >> 4) ^ (crc >> 5);
   }
   return crc;
}


float ds1820_read()
{
 	int1 conv_ok;
	int8 busy=0, frametab[9],i,fail_counter;
	signed int16 temp;
	float result;


	conv_ok=true;
	fail_counter=0;
	while(conv_ok==true)
	{
		onewire_reset();
		onewire_write(0xCC);
		onewire_write(0x44);
		HAL_Delay(1000);	//wait for conv ~1s
		while (busy == 0)
		{
			restart_wdt();
			busy = onewire_read();
			if (temp_counter==0)
			{
				return error;
			}
		}
		onewire_reset();
		onewire_write(0xCC);
		onewire_write(0xBE);

		for(i=0;i<=8;i++)
		{
			frametab[i]=onewire_read();
		}

		if(frametab[8]==CRC8(&frametab,8))
		{
			conv_ok=false;
			temp = make16(frametab[1], frametab[0]);
			result= ((float)temp/16.0)*10;
			return(result);
		}

		delay_ms(50);

		fail_counter++;
		if(fail_counter>10)
		{
			return error;
		}
	}


}
