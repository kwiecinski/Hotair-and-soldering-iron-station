/*
 * menu.c
 *
 *  Created on: Apr 29, 2022
 *      Author: luk6xff
 */

#include "Display.h"
#include <main.h>

//------------------------------------------------------------------------------
Display::Display()
	: m_lcd(
		  LiquidCrystal::Gpio{LCD_RS_GPIO_Port, LCD_RS_Pin},
		  LiquidCrystal::Gpio{LCD_RW_GPIO_Port, LCD_RW_Pin},
		  LiquidCrystal::Gpio{LCD_EN_GPIO_Port, LCD_EN_Pin},
		  LiquidCrystal::Gpio{LCD_D4_GPIO_Port, LCD_D4_Pin},
		  LiquidCrystal::Gpio{LCD_D5_GPIO_Port, LCD_D5_Pin},
		  LiquidCrystal::Gpio{LCD_D6_GPIO_Port, LCD_D6_Pin},
		  LiquidCrystal::Gpio{LCD_D7_GPIO_Port, LCD_D7_Pin})
{

}

//------------------------------------------------------------------------------
void Display::init()
{
	m_lcd.begin(16, 2);
}

//------------------------------------------------------------------------------
LiquidCrystal& Display::handle()
{
	return m_lcd;
}

//------------------------------------------------------------------------------
