/*
 * View.h
 *
 *  Created on: Jul 8, 2022
 *      Author: luk6xff
 */

#ifndef SRC_GUI_VIEW_H_
#define SRC_GUI_VIEW_H_

#include "../GUI/Display.h"
#include "../GUI/LCD/LiquidMenu.h"

/**
 * @brief Class responsible for managing displaying stuff on LCD
 */
class View
{
public:
	View(Display& display);

	virtual void init() = 0;

protected:
	virtual void update();

private:
	Display& m_display;

protected:
	LiquidMenu m_widget;
};

#endif /* SRC_GUI_VIEW_H_ */
