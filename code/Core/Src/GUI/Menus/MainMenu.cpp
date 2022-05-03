/*
 * MainMenu.cpp
 *
 *  Created on: May 3, 2022
 *      Author: luk6xff
 */

#include "MainMenu.h"

#include "../LCD/glyphs.h"

//------------------------------------------------------------------------------
MainMenu::MainMenu(const char *title, LiquidCrystal& lcd)
	: IMenu(title)
	, m_lcd(lcd)
	, m_titleLine(0, 0, title)
	, m_aboutLine(0, 1, "About")
	, m_hotAirLine(0, 0, "HotAir settings")
	, m_wepLine(0, 1, "WEP settings")
	, m_screen1(m_titleLine, m_aboutLine)
	, m_screen2(m_hotAirLine, m_wepLine)
	, m_menu(m_lcd, m_screen1, m_screen2)
{

}

//------------------------------------------------------------------------------
void MainMenu::update()
{
	// LU_TODO For tests only
	static int i = 0;
	if (i++ % 100 == 0)
	{
		m_menu.next_screen();
		m_menu.set_focusSymbol(Position::LEFT, glyphs::leftFocus);
		m_menu.get_currentScreen()->set_focusPosition(Position::LEFT);
	}

	m_menu.update();
}

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
