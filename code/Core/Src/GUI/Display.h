/*
 * menu.h
 *
 *  Created on: Apr 29, 2022
 *      Author: luk6xff
 */

#ifndef SRC_GUI_DISPLAY_H_
#define SRC_GUI_DISPLAY_H_

#include "../Buttons/buttons.h"
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

	static void displayTask(void *args);

private:
	LiquidCrystal m_lcd;

	MainMenu m_mainMenu;
};

#endif /* SRC_GUI_DISPLAY_H_ */
