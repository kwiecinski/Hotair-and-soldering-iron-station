/*
 * ViewsFactory.h
 *
 *  Created on: Aug 15, 2022
 *      Author: luk6xff
 */

#include "ViewsFactory.h"

//------------------------------------------------------------------------------
namespace view
{

//------------------------------------------------------------------------------
ViewsFactory::ViewsFactory(Display& display)
: m_display(display)
{

}

//------------------------------------------------------------------------------
std::unique_ptr<view::View> ViewsFactory::createMainMenu()
{
	return  std::make_unique<MainMenuView>(m_display);
}

//------------------------------------------------------------------------------
std::unique_ptr<view::View> ViewsFactory::createHotAir()
{
	// TODO HotAir
	return std::make_unique<MainMenuView>(m_display);
}

//------------------------------------------------------------------------------

}
