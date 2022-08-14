/*
 * menu.h
 *
 *  Created on: Apr 29, 2022
 *      Author: luk6xff
 */

#ifndef SRC_GUI_DISPLAY_H_
#define SRC_GUI_DISPLAY_H_

#include "LCD/LiquidCrystal.h"

/**
 * @brief Class responsible for managing the LCD display
 */
class Display
{

public:
	Display();
	~Display() = default;

	void init();

	LiquidCrystal& handle();

private:
	LiquidCrystal m_lcd;
};

#endif /* SRC_GUI_DISPLAY_H_ */
