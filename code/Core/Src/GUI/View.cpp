/*
 * View.cpp
 *
 *  Created on: Jul 8, 2022
 *      Author: luk6xff
 */

#include "View.h"

//------------------------------------------------------------------------------
View::View(Display& display)
	: m_display(display)
	, m_widget(m_display.handle())
{

}

//------------------------------------------------------------------------------
void View::update()
{
	m_widget.update();
}
