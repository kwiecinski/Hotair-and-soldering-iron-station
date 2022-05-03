/*
 * menu.c
 *
 *  Created on: Apr 29, 2022
 *      Author: luk6xff
 */

#include "Display.h"
#include <main.h>
// LU_TODO Move to the tasks
#include "FreeRTOS.h"
#include "task.h"

//------------------------------------------------------------------------------
Display::Display()
	: m_lcd(LiquidCrystal::Gpio{LCD_RS_GPIO_Port, LCD_RS_Pin},
		  LiquidCrystal::Gpio{LCD_RW_GPIO_Port, LCD_RW_Pin},
		  LiquidCrystal::Gpio{LCD_EN_GPIO_Port, LCD_EN_Pin},
		  LiquidCrystal::Gpio{LCD_D4_GPIO_Port, LCD_D4_Pin},
		  LiquidCrystal::Gpio{LCD_D5_GPIO_Port, LCD_D5_Pin},
		  LiquidCrystal::Gpio{LCD_D6_GPIO_Port, LCD_D6_Pin},
		  LiquidCrystal::Gpio{LCD_D7_GPIO_Port, LCD_D7_Pin})
	, m_mainMenu("MainMenu", m_lcd)
{

}

//------------------------------------------------------------------------------
void Display::init()
{
	// Init LCD
	m_lcd.begin(16, 2);
}

//------------------------------------------------------------------------------
void Display::update()
{
	m_mainMenu.update();
}

//------------------------------------------------------------------------------
LiquidCrystal& Display::getLcdHandle()
{
	return m_lcd;
}

//------------------------------------------------------------------------------
