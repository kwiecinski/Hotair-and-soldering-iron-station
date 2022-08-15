/*
 * ViewsFactory.h
 *
 *  Created on: Aug 15, 2022
 *      Author: luk6xff
 */

#ifndef SRC_VIEW_VIEWSFACTORY_H_
#define SRC_VIEW_VIEWSFACTORY_H_

#include <memory>

#include "MainMenuView.h"

namespace view
{

class ViewsFactory
{

public:
	ViewsFactory(Display& display);

	// Create all the views
	std::unique_ptr<view::View> createMainMenu();
	std::unique_ptr<view::View> createHotAir();

private:
	Display& m_display;

};

}

#endif /* SRC_VIEW_VIEWSFACTORY_H_ */
