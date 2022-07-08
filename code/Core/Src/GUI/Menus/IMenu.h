/*
 * IMenu.h
 *
 *  Created on: May 3, 2022
 *      Author: luk6xff
 */

#ifndef SRC_GUI_MENUS_IMENU_H_
#define SRC_GUI_MENUS_IMENU_H_

#include <cstring>
#include "../../Buttons/Buttons.h"


class IMenu
{

public:

	IMenu(const char *title, Buttons& buttons)
		: m_buttons(buttons)
	{
		m_title[0] = '<';
		std::size_t s = std::strlen(title);
		if (s > 13)
		{
			s = 13;
		}
		m_title[s+1] = '>';
		m_title[s+2] = 0;
		std::memcpy(&m_title[1], title, s);
	}

//	virtual IMenu* prevMenu() = 0;
//	virtual IMenu* nextMenu() = 0;
	virtual void init() = 0;
	virtual void update() = 0;

protected:
	char m_title[16];
	Buttons m_buttons;
};

#endif /* SRC_GUI_MENUS_IMENU_H_ */
