/*
 * menu.h
 *
 *  Created on: Apr 29, 2022
 *      Author: luk6xff
 */

#ifndef SRC_GUI_DISPLAY_H_
#define SRC_GUI_DISPLAY_H_

#include "../Buttons/Buttons.h"
#include "Menus/MainMenu.h"

/**
 * @brief Class responsible for managing the whole app display
 */
class Display
{

public:
	Display();
	~Display() = default;

	void init();
	void update();

	// Remove later
	LiquidCrystal& getLcdHandle();

private:
	LiquidCrystal m_lcd;

	MainMenu m_mainMenu;
};

#endif /* SRC_GUI_DISPLAY_H_ */
