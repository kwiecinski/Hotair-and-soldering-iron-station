/*
 * app.cpp
 *
 *  Created on: Apr 30, 2022
 *      Author: luk6xff
 */
#include "app.h"


//------------------------------------------------------------------------------
App::App()
    : lcd(LiquidCrystal::Gpio{LCD_RS_GPIO_Port, LCD_RS_Pin},
            LiquidCrystal::Gpio{LCD_RW_GPIO_Port, LCD_RW_Pin},
            LiquidCrystal::Gpio{LCD_EN_GPIO_Port, LCD_EN_Pin},
            LiquidCrystal::Gpio{LCD_D4_GPIO_Port, LCD_D4_Pin},
            LiquidCrystal::Gpio{LCD_D5_GPIO_Port, LCD_D5_Pin},
            LiquidCrystal::Gpio{LCD_D6_GPIO_Port, LCD_D6_Pin},
            LiquidCrystal::Gpio{LCD_D7_GPIO_Port, LCD_D7_Pin})
{

}

//------------------------------------------------------------------------------
void App::run()
{

}







//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------TEST_APPLICATION--------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
