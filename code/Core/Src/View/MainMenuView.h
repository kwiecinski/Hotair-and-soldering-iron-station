/*
 * MainMenu.h
 *
 *  Created on: May 3, 2022
 *      Author: luk6xff
 */

#ifndef SRC_GUI_VIEWS_MAINMENU_H_
#define SRC_GUI_VIEWS_MAINMENU_H_


#include "View.h"

class MainMenuView : public View
{

public:
	MainMenuView(Display& disp);

	void init() override;

private:
	// Menu structure
	LiquidLine m_hotAirLine;
	LiquidLine m_wepLine;
	LiquidLine m_t12Line;
	LiquidLine m_aboutLine;
	LiquidScreen m_screen;
};

#endif /* SRC_GUI_VIEWS_MAINMENU_H_ */
