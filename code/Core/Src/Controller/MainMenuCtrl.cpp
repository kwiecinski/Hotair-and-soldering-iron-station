/*
 * MainMenuCtrl.cpp
 *
 *  Created on: Aug 14, 2022
 *      Author: luk6xff
 */

#include "MainMenuCtrl.h"

namespace ctrl
{

//------------------------------------------------------------------------------
MainMenuCtrl::MainMenuCtrl(std::unique_ptr<view::View> view, MainMenuModel& model)
	: IController(ControllerId::MAINMENU, std::move(view), model)
{

}

//------------------------------------------------------------------------------
void MainMenuCtrl::onButtonChanged(const button::ButtonEventQueue::Data& data)
{
	// Handle buttons change
	if (data.button == button::ButtonType::BUTTON_MENU_RIGHT)
	{
		if (data.state == button::ButtonState::BUTTON_SHORT_PRESSED)
		{
			static_cast<view::MainMenuView*>(m_view.get())->changeMenu();
		}
	}
	else if (data.button == button::ButtonType::BUTTON_MENU_LEFT)
	{
		if (data.state == button::ButtonState::BUTTON_SHORT_PRESSED)
		{
			static_cast<view::MainMenuView*>(m_view.get())->changeMenu(false);
		}
	}
}

//------------------------------------------------------------------------------
void MainMenuCtrl::onParameterChanged()
{

}

//------------------------------------------------------------------------------

}
