#include "app_test.h"

#include <main.h>
#include <stdio.h>
#include <string.h>
#include "retarget.h"
#include "utils.h"
#include "adc_functions.h"
#include "adc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "MAX31855/MAX31855.h"



// TEST BUTTONS
void button_short_pressed_test()
{
	 static int i = 0;
	 printf("BUTTON SHORT:%d\r\n", i);
	 i++;
}

void button_long_pressed_test()
{
	 static int i = 0;
	 printf("BUTTON LONG:%d\r\n", i);
	 i++;
}


AppTest::AppTest()
    : display()
{

}

//------------------------------------------------------------------------------
void AppTest::run()
{
    //Init printf retarget
    RetargetInit(&huart2);
    printf("Hello! \r\n");

    // Start Timer
    Start_generic_timer();
    // Init ADC
    Init_ADC();

    // Init Display
    display.init();

    // BUTTONS
	//button_pressed_short_cb(BUTTON_HOTAIR_FAN_UP, button_short_pressed_test);
	//button_pressed_long_cb(BUTTON_HOTAIR_FAN_DOWN, button_long_pressed_test);

//    // LCD
//    testLcd();

//    // WEP
//    testWEP();
//
//    // T12
//    testT12();
//
//    // HotAir
//    testHOTAIR();
}

Display& AppTest::getDisplayHandle()
{
	return display;
}



//------------------------------------------------------------------------------
void AppTest::testLcd()
{
//    // Init LCD display
//    lcd.begin(16, 2);
//    // Print demo message
//    lcd.setCursor(0, 0);
//    lcd.print("111TEST111");
//    lcd.blink();
//    lcd.setCursor(0, 1);
//    lcd.print("222TEST222");
//    lcd.cursor();
//
//    // create a new character
//    lcd.createChar(0, glyphs::heart);
//    // create a new character
//    lcd.createChar(1, glyphs::smiley);
//    // create a new character
//    lcd.createChar(2, glyphs::frownie);
//    // create a new character
//    lcd.createChar(3, glyphs::armsDown);
//    // create a new character
//    lcd.createChar(4, glyphs::armsUp);
//
//    // set the cursor to the top left
//    lcd.setCursor(0, 0);
//
//    // Print a message to the LCD.
//    lcd.write(uint8_t(0)); // when calling lcd.write() '0' must be cast as a uint8_t
//    lcd.print(" SolderTest ");
//    lcd.write((uint8_t)1);
//
//    lcd.setCursor(4, 1);
//    // draw the little man, arms down:
//    lcd.write(3);
//    HAL_Delay(2000);
//    lcd.setCursor(4, 1);
//    // draw him arms up:
//    lcd.write(4);


//    // MENU
//    uint8_t fan_glyphIndex = 0;
//    uint8_t thermometer_glyphIndex = 2;
//    uint8_t celsiusSymbol_glyphIndex = 3;
//
//    LiquidLine welcome_line1(1, 0, "LiquidMenu ", LIQUIDMENU_VERSION);
//    LiquidLine welcome_line2(1, 1, "Glyphs example");
//    LiquidScreen welcome_screen(welcome_line1, welcome_line2);
//
//    LiquidLine line1(1, 1, fan_glyphIndex);
//    LiquidLine line2(7, 1, thermometer_glyphIndex);
//    LiquidLine line3(13, 1, celsiusSymbol_glyphIndex, "C");
//    LiquidScreen screen1(line1, line2, line3);
//
//    LiquidMenu menu(lcd, welcome_screen, screen1);
//
//    lcd.createChar(fan_glyphIndex, glyphs::fan1);
//    // This is the second glyph, indexed after the first.
//    lcd.createChar(fan_glyphIndex + 1, glyphs::fan2);
//    lcd.createChar(thermometer_glyphIndex, glyphs::thermometer);
//    lcd.createChar(celsiusSymbol_glyphIndex, glyphs::celsiusSymbol);
//
//    // This functions tells the LiquidLine objects that their first
//    // variable is not an integer value but an index to a glyph.
//    line1.set_asGlyph(1);
//    line2.set_asGlyph(1);
//    line3.set_asGlyph(1);
//
//    // Init LCD
//    lcd.begin(16, 2);
//    menu.softUpdate();
    //menu.next_screen();
}

//------------------------------------------------------------------------------
// TEST WEP
void Show_MAX_data_LCD(LiquidCrystal& lcd, MAX_TEMP_DATA *data, int16_t compensaded_temp)
{

    char buf[10];
    sprintf(buf,"T%-3d",compensaded_temp);			// Conversation to Char
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("TEST WEP");
    lcd.setCursor(9,0);
    lcd.print(buf);
    sprintf(buf,"%-2d",data->get_cold_junction_temperature);
    lcd.setCursor(14,0);
    lcd.print(buf);

    // Send to LCD
	switch(data->error)
	{
		case MAX31855_THERMOCOUPLE_OK: 				lcd.setCursor(0,1); lcd.print("NORMAL");
		break;
		case MAX31855_THERMOCOUPLE_OPEN_CIRCUIT:    lcd.setCursor(0,1); lcd.print("OPEN ");
		break;
		case MAX31855_THERMOCOUPLE_SHORT_TO_GND:    lcd.setCursor(0,1); lcd.print("SHORT GND");
		break;
		case MAX31855_THERMOCOUPLE_SHORT_TO_VCC:    lcd.setCursor(0,1); lcd.print("SHORT VCC");
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



void AppTest::testWEP()
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

			Show_MAX_data_LCD(display.handle(), &data,compensaded_temp);
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
				display.handle().setCursor(13,1);
				display.handle().print("HTD");
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

//------------------------------------------------------------------------------
// TEST T12
typedef struct
{
    int16_t temperature;
    int16_t cold_junction_temperature;
    uint8_t error;

} T12_TEMP_DATA;

void AppTest::testT12()
{
    #define OPAMP_GAIN 					200
    #define THERMOCOUPLE_COEFFICIENT 	0.021		// mv/C
    #define AMBIENT_TEMP				20			// TODO - need to read this from MAX31855 or uC internat temp sensor


	const uint16_t set_temp=320;		// target  TIP temp
	const uint16_t frequency=1000;		// switch frequency in Hz
	int16_t compensaded_temp,compensaded_temp_old;
	float temp,temp_voltage;
	uint8_t htd_cnt=0;

	// PWM channel config
	TIM_OC_InitTypeDef sConfigOC = {0};
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;


    while(1)
    {


	printf("Testing T12 soldering iron, heating to %d \r\n",set_temp);
			//printf("%f [mV]\r\n",temp);
			//printf("temp: %f\r\n",(temp/200)/0.021);

			// Reading soldering iron voltage from thermocouple + converting ambient temp to voltage and then dividing
			// by thermocouple coefficient to get relative temp

			HAL_TIM_PWM_Stop(&htim4,TIM_CHANNEL_1);
			HAL_Delay(20);

			temp_voltage=ADC_Read_Voltage(T12_ADC_INPUT);
			temp=((temp_voltage/OPAMP_GAIN) + AMBIENT_TEMP*THERMOCOUPLE_COEFFICIENT)/THERMOCOUPLE_COEFFICIENT;



		// Compensation equation calculated from excel

		//compensaded_temp=(data.get_temperature*69+500)/100;

		compensaded_temp=(uint16_t)temp;

		if(compensaded_temp!=compensaded_temp_old)
		{

            // Show_T12_data
            // show on LCD
            char buf[10];
            sprintf(buf,"T%-3d",compensaded_temp);			// Conversation to Char
            display.handle().clear();
            display.handle().print("TEST T12");
            display.handle().setCursor(12,0);
            display.handle().print(buf);							// show temp
            sprintf(buf,"V%-.1f",temp_voltage);
            display.handle().setCursor(0,1);
            display.handle().print(buf);							// show ADC temp voltage


            // send via UART
            printf("T12 tip temp:%u[C]\r\n",compensaded_temp);
            printf("Thermocouple voltage: %.1f[mV] \r\n",temp_voltage);
		}

		compensaded_temp_old=compensaded_temp;

		if(compensaded_temp<set_temp)
		{
			if(compensaded_temp<set_temp/4)
			{
				  sConfigOC.Pulse = htim4.Init.Period/2;
				  HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1);

			}else if(compensaded_temp>=set_temp/4 && compensaded_temp<set_temp/2)
			{

				  sConfigOC.Pulse = htim4.Init.Period/3;
				  HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1);

			}else if(compensaded_temp>=set_temp/2 && compensaded_temp<set_temp)
			{
				  sConfigOC.Pulse = htim4.Init.Period/6;
				  HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1);
			}

			HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);
			HAL_Delay(frequency);

		}else
		{
			HAL_TIM_PWM_Stop(&htim4,TIM_CHANNEL_1);
			display.handle().setCursor(10,1);
			display.handle().print("      ");
			display.handle().print("HEATED");
			Buzzer(1000);
			HAL_Delay(3000);
			htd_cnt++;
			if(htd_cnt>2)
			{
				break;
			}
		}
    }
}

//------------------------------------------------------------------------------
// TEST HOTAIR
void Show_HOTAIR_data(LiquidCrystal& lcd, int16_t compensaded_temp, float temp_voltage, float fan_voltage)
{

	// show on LCD
	char buf[10];
	sprintf(buf,"T%-3d",compensaded_temp);			// Conversation to Char
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("TEST HOTAIR");
	lcd.setCursor(12,0);
	lcd.print(buf);							// show temp
	sprintf(buf,"V%-.1f",temp_voltage);
	lcd.print(buf);							// show ADC temp voltage
	sprintf(buf,"F%-.1f",fan_voltage/1000);
	lcd.setCursor(8,1);
	lcd.print(buf);							// show ADC fan  voltage

	// send via UART
	printf("HOTAIR tip temp:%u[C]\r\n",compensaded_temp);
	printf("Thermocouple voltage: %.1f[mV] \r\n",temp_voltage);
	printf("Fan voltage: %.1f[V] \r\n\r\n",fan_voltage/1000);
}


// Set fan PWM using HW PWM, ducy cycle from 0-100
void Set_Fan_PWM(uint8_t ducy_cycle)
{

	TIM_OC_InitTypeDef sConfigOC = {0};
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
	sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;


	HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_1);
	sConfigOC.Pulse = htim1.Init.Period*ducy_cycle/100;
	HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
}

// time in ms - minimum time 25ms
void Set_HOTAIR_Time(uint16_t time)
{
	HAL_GPIO_WritePin(HOTAIR_HEATER_CTRL_GPIO_Port, HOTAIR_HEATER_CTRL_Pin , GPIO_PIN_SET);
	HAL_Delay(time);
	HAL_GPIO_WritePin(HOTAIR_HEATER_CTRL_GPIO_Port, HOTAIR_HEATER_CTRL_Pin , GPIO_PIN_RESET);
}

void AppTest::testHOTAIR()
{
	#define HOTAIR_OPAMP_GAIN 					123			// read from schematic - non-inverting opamp gain
	#define HOTAIR_THERMOCOUPLE_COEFFICIENT 	0.040		// mv/C
	#define HOTAIR_AMBIENT_TEMP				20			// TODO - need to read this from MAX31855 or uC internat temp sensor
	const uint16_t set_temp=320;		// target  TIP temp
	int16_t compensaded_temp,compensaded_temp_old;
	float temp, temp_voltage, fan_voltage;
	uint8_t htd_cnt=0;

	printf("Testing HOTAIR, heating to %d[C] \r\n",set_temp);

	Set_Fan_PWM(100);

	while(1)
	{
		HAL_Delay(10);					// wait to all transients settle down

		temp_voltage=ADC_Read_Voltage(HOTAIR_ADC_INPUT);
		fan_voltage=ADC_Read_Voltage(FAN_ADC_INPUT);
		temp=((temp_voltage/HOTAIR_OPAMP_GAIN) + HOTAIR_AMBIENT_TEMP*HOTAIR_THERMOCOUPLE_COEFFICIENT)/HOTAIR_THERMOCOUPLE_COEFFICIENT;

		compensaded_temp=(int16_t)temp;

		// show on LCD and send to UART only if temp change
		if(compensaded_temp!=compensaded_temp_old)
		{
			Show_HOTAIR_data(display.handle(), compensaded_temp, temp_voltage, fan_voltage);
		}
		compensaded_temp_old=compensaded_temp;

		// simple temp regulator
		if(compensaded_temp<set_temp)
		{
			if(compensaded_temp<set_temp/4)
			{
				Set_HOTAIR_Time(500);

			}else if(compensaded_temp>=set_temp/4 && compensaded_temp<set_temp/2)
			{

				Set_HOTAIR_Time(400);

			}else if(compensaded_temp>=set_temp/2 && compensaded_temp<set_temp)
			{
				Set_HOTAIR_Time(200);
			}

		}else
		{


			printf("HEATED \n\r");
			display.handle().setCursor(13,1);
			display.handle().print("HTD");
			Buzzer(1000);
			HAL_Delay(3000);
			htd_cnt++;
			if(htd_cnt>2)
			{
				Set_Fan_PWM(50);
				break;
			}
		}

		HAL_Delay(500);

	} // while end
}

//------------------------------------------------------------------------------
