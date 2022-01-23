#include <string.h>
#include <stdio.h>
#include "display_7seg.h"
#include "main.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"


#include "usart.h"

//anode bit positions
#define SEG_A  11
#define SEG_B  0
#define SEG_C  5
#define SEG_D  7
#define SEG_E  13
#define SEG_F  10
#define SEG_G  4
#define SEG_DP 6
//catiode bit positions
#define DIG1_IRON_CA  8
#define DIG2_IRON_CA  9
#define DIG3_IRON_CA  12
#define DIG1_HOTAIR_CA  3
#define DIG2_HOTAIR_CA  2
#define DIG3_HOTAIR_CA  1


#define DIGIT1 1
#define DIGIT2 2
#define DIGIT3 3
#define DIGIT4 4
#define DIGIT5 5
#define DIGIT6 6

#define DECIMAL_POINT_ON  1
#define DECIMAL_POINT_OFF 0

void Set_Anode_Outputs(unsigned char sign, unsigned char decimal_point, unsigned int *display_data);
void One_Digit_Handler(unsigned char sign, unsigned char digit_number, unsigned char decimal_point);
void Display_7Seg(unsigned char *text, unsigned char decimal_point);
void Disable_All_Digits(void);


void Test_Display(void)
{
	unsigned char text[7] = "000000";
	uint32_t counter=0,
			 digits_to_display=0;

	while(1)
	{

		Display_7Seg(&text[0],0xFF);

		HAL_Delay(2);	//5ms multiplex time

		counter++;

		if(counter>500)
		{
			if(digits_to_display>=999999)
			{
				Disable_All_Digits();

				printf("Test 7 seg display done! \n\r");
				HAL_Delay(2000);
				break;
			}

			digits_to_display=digits_to_display+111111;
			printf(text, "%ld", digits_to_display);

			counter=0;
		}
	}
}


/*
*
*	Write data into 74HC595D via hardware SPI
*
*/
void Write_Display_Data(unsigned int *display_data)
{
	unsigned char display_data_table[2];

	display_data_table[1] = (unsigned char) *display_data;
	display_data_table[0] = (unsigned char) ((*display_data)>>8);

	HAL_GPIO_WritePin(DISP_LATCH_GPIO_Port, DISP_LATCH_Pin, GPIO_PIN_RESET);

	HAL_SPI_Transmit(&hspi1,&display_data_table[0], 2, 1000);
	while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY){};

	HAL_GPIO_WritePin(DISP_LATCH_GPIO_Port, DISP_LATCH_Pin, GPIO_PIN_SET);
}


/*
*
*	Letters and digits definitions
*
*/


unsigned char Sign_Anode_Data(unsigned char sign)
{
    switch (sign)
    {
        case 0 : return 0b11111100;
        case 1 : return 0b01100000;
        case 2 : return 0b11011010;
        case 3 : return 0b11110010;
        case 4 : return 0b01100110;
        case 5 : return 0b10110110;
        case 6 : return 0b10111110;
        case 7 : return 0b11100100;
        case 8 : return 0b11111110;
        case 9 : return 0b11110110;
        case '0': return 0b11111100;
        case '1': return 0b01100000;
        case '2': return 0b11011010;
        case '3': return 0b11110010;
        case '4': return 0b01100110;
        case '5': return 0b10110110;
        case '6': return 0b10111110;
        case '7': return 0b11100100;
        case '8': return 0b11111110;
        case '9': return 0b11110110;
        case 'a': return 0b11101110;
        case 'b': return 0b00111110;
        case 'c': return 0b10011100;
        case 'd': return 0b01111010;
        case 'e': return 0b10011110;
        case 'f': return 0b10001110;
        case 'g': return 0b10111100;
        case 'h': return 0b01101110;
        case 'i': return 0b01100000;
        case 'j': return 0b01110000;
        case 'k': return 0b01101110;   //same as H
        case 'l': return 0b00011100;
        case 'm': return 0b11101100;   //display as N
        case 'n': return 0b00101010;
        case 'o': return 0b11111100;
        case 'p': return 0b01110011;
        case 'r': return 0b00001010;
        case 's': return 0b10110110;
        case 't': return 0b00011110;
        case 'u': return 0b01111100;
        case 'v': return 0b01111100;   //same as U
        case 'w': return 0b01111100;   //same as U
        case 'x': return 0b01101110;   //same as H
        case 'y': return 0b01110110;
        case 'z': return 0b11011010;   //same as 2
        case '*': return 0b00000000;   //disable digit

     }

    return 0;
}

/*
*
*	Disable all digits
*
*/


void Disable_All_Digits(void)
{

	unsigned int turn_off_display_val=0xFFFF;
	Write_Display_Data(&turn_off_display_val);

}

/*
*
*	Main function handling display
*	inputs:
*	*text - pointer to first element of char array
*	decimal_point - determines which decimal points have to be enabled
*	eg.
*	0b0001	- only first display
*	0b0101  - first and third display
*
*/


void Display_7Seg(unsigned char *text, unsigned char decimal_point)
{
    static unsigned char enable_digit=DIGIT1;

    if(enable_digit<=DIGIT1)
    {
        if(decimal_point & 0b100000)
        {
            One_Digit_Handler(*(text+5),DIGIT1,DECIMAL_POINT_ON);
        }else
        {
            One_Digit_Handler(*(text+5),DIGIT1,DECIMAL_POINT_OFF);
        }
        enable_digit=DIGIT2;

    }else if(enable_digit==DIGIT2)
    {
        if(decimal_point & 0b010000)
        {
            One_Digit_Handler(*(text+4),DIGIT2,DECIMAL_POINT_ON);
        }else
        {
            One_Digit_Handler(*(text+4),DIGIT2,DECIMAL_POINT_OFF);
        }
        enable_digit=DIGIT3;

    }else if(enable_digit==DIGIT3)
    {
        if(decimal_point & 0b001000)
        {
           One_Digit_Handler(*(text+3),DIGIT3,DECIMAL_POINT_ON);
        }else
        {
           One_Digit_Handler(*(text+3),DIGIT3,DECIMAL_POINT_OFF);
        }
        enable_digit=DIGIT4;

    }else if(enable_digit==DIGIT4)
    {
        if(decimal_point & 0b000100)
        {
           One_Digit_Handler(*(text+0),DIGIT4,DECIMAL_POINT_ON);
        }else
        {
           One_Digit_Handler(*(text+0),DIGIT4,DECIMAL_POINT_OFF);
        }
        enable_digit=DIGIT5;

    }else if(enable_digit==DIGIT5)
    {
        if(decimal_point & 0b000010)
        {
           One_Digit_Handler(*(text+1),DIGIT5,DECIMAL_POINT_ON);
        }else
        {
           One_Digit_Handler(*(text+1),DIGIT5,DECIMAL_POINT_OFF);
        }
        enable_digit=DIGIT6;

    }else if(enable_digit>=DIGIT6)
    {
        if(decimal_point & 0b000001)
        {
            One_Digit_Handler(*(text+2),DIGIT6,DECIMAL_POINT_ON);
        }else
        {
            One_Digit_Handler(*(text+2),DIGIT6,DECIMAL_POINT_OFF);
        }
        enable_digit=DIGIT1;
    }

}

/*
*
*	Turn on and turn off single digit
*
*/

void One_Digit_Handler(unsigned char sign, unsigned char digit_number, unsigned char decimal_point)
{
	unsigned int display_data;

    Disable_All_Digits();
    Set_Anode_Outputs(Sign_Anode_Data(sign),decimal_point,&display_data);

    if(digit_number == DIGIT1)
    {
    	display_data &= ~(1<<DIG1_IRON_CA);
    	display_data |= 1<<DIG2_IRON_CA;
    	display_data |= 1<<DIG3_IRON_CA;
    	display_data |= 1<<DIG1_HOTAIR_CA;
    	display_data |= 1<<DIG2_HOTAIR_CA;
    	display_data |= 1<<DIG3_HOTAIR_CA;

    }else if(digit_number == DIGIT2)
    {
    	display_data |= 1<<DIG1_IRON_CA;
    	display_data &= ~(1<<DIG2_IRON_CA);
    	display_data |= 1<<DIG3_IRON_CA;
    	display_data |= 1<<DIG1_HOTAIR_CA;
    	display_data |= 1<<DIG2_HOTAIR_CA;
    	display_data |= 1<<DIG3_HOTAIR_CA;

    }else if(digit_number == DIGIT3)
    {
    	display_data |= 1<<DIG1_IRON_CA;
    	display_data |= 1<<DIG2_IRON_CA;
    	display_data &= ~(1<<DIG3_IRON_CA);
    	display_data |= 1<<DIG1_HOTAIR_CA;
    	display_data |= 1<<DIG2_HOTAIR_CA;
    	display_data |= 1<<DIG3_HOTAIR_CA;

    }else if(digit_number == DIGIT4)
    {
    	display_data |= 1<<DIG1_IRON_CA;
    	display_data |= 1<<DIG2_IRON_CA;
    	display_data |= 1<<DIG3_IRON_CA;
    	display_data &= ~(1<<DIG1_HOTAIR_CA);
    	display_data |= 1<<DIG2_HOTAIR_CA;
    	display_data |= 1<<DIG3_HOTAIR_CA;

    }else if(digit_number == DIGIT5)
    {
    	display_data |= 1<<DIG1_IRON_CA;
    	display_data |= 1<<DIG2_IRON_CA;
    	display_data |= 1<<DIG3_IRON_CA;
    	display_data |= 1<<DIG1_HOTAIR_CA;
    	display_data &= ~(1<<DIG2_HOTAIR_CA);
    	display_data |= 1<<DIG3_HOTAIR_CA;

    }else if(digit_number == DIGIT6)
    {
    	display_data |= 1<<DIG1_IRON_CA;
    	display_data |= 1<<DIG2_IRON_CA;
    	display_data |= 1<<DIG3_IRON_CA;
    	display_data |= 1<<DIG1_HOTAIR_CA;
    	display_data |= 1<<DIG2_HOTAIR_CA;
    	display_data &= ~(1<<DIG3_HOTAIR_CA);
    }

   Write_Display_Data(&display_data);
}



/*
*
*	Turns on individual anodes based on the data from the character table
*
*/


void Set_Anode_Outputs(unsigned char sign, unsigned char decimal_point, unsigned int *display_data)
{

    if(sign>>7 & 1)
    {
    	*display_data |=  1<<SEG_A;
    }else
    {
    	*display_data &= ~(1<<SEG_A);
    }

    if(sign>>6 & 1)
    {
    	*display_data |=  1<<SEG_B;
    }else
    {
    	*display_data &= ~(1<<SEG_B);
    }

    if(sign>>5 & 1)
    {
    	*display_data |=  1<<SEG_C;
    }else
    {
    	*display_data &= ~(1<<SEG_C);
    }

    if(sign>>4 & 1)
    {
    	*display_data |=  1<<SEG_D;
    }else
    {
    	*display_data &= ~(1<<SEG_D);
    }

    if(sign>>3 & 1)
    {
    	*display_data |=  1<<SEG_E;
    }else
    {
    	*display_data &= ~(1<<SEG_E);
    }

    if(sign>>2 & 1)
    {
    	*display_data |= 1<<SEG_F;
    }else
    {
    	*display_data &= ~(1<<SEG_F);
    }

    if(sign>>1 & 1)
    {
    	*display_data |=  1<<SEG_G;
    }else
    {
    	*display_data &= ~(1<<SEG_G);
    }

    if(decimal_point==1)
    {
    	*display_data |= 1<<SEG_DP;
    }else
    {
    	*display_data &= ~(1<<SEG_DP);
    }
}
