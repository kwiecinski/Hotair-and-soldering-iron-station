/*
 * MainMenu.h
 *
 *  Created on: May 3, 2022
 *      Author: luk6xff
 */

#ifndef SRC_GUI_MENUS_MAINMENU_H_
#define SRC_GUI_MENUS_MAINMENU_H_

#include "IMenu.h"
#include "../LCD/LiquidMenu.h"

class MainMenu : public IMenu
{

public:
	MainMenu(const char *title, LiquidCrystal& lcd);
	virtual ~MainMenu() = default;

	void init() override;
	void update() override;

private:
	LiquidCrystal& m_lcd;
	// Menu structure
	LiquidLine m_titleLine;
	LiquidLine m_hotAirLine;
	LiquidLine m_wepLine;
	LiquidLine m_t12Line;
	LiquidLine m_aboutLine;
	LiquidScreen m_screen;
	LiquidMenu m_menu;
};

#endif /* SRC_GUI_MENUS_MAINMENU_H_ */
