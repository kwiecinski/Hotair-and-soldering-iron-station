/*
 * MainMenu.cpp
 *
 *  Created on: May 3, 2022
 *      Author: luk6xff
 */

#include "MainMenu.h"

//------------------------------------------------------------------------------
MainMenu::MainMenu(const char *title, LiquidCrystal& lcd)
	: IMenu(title)
	, m_lcd(lcd)
	, m_titleLine(0, 0, title)
	, m_aboutLine(0, 1, "About")
	, m_hotAirLine(0, 2, "HotAir settings")
	, m_wepLine(0, 3, "WEP settings")
	, m_screen(m_titleLine, m_aboutLine, m_hotAirLine, m_wepLine)
	, m_menu(m_lcd, m_screen)
{

}

//------------------------------------------------------------------------------
void MainMenu::update()
{
	m_menu.update();
}

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
