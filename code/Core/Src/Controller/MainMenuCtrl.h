/*
 * MainMenuCtrl.h
 *
 *  Created on: Aug 14, 2022
 *      Author: luk6xff
 */

#ifndef SRC_CONTROLLER_MAINMENUCTRL_H_
#define SRC_CONTROLLER_MAINMENUCTRL_H_

#include "IController.h"
#include "../View/MainMenuView.h"
#include "../Model/MainMenuModel.h"

namespace ctrl
{

class MainMenuCtrl : public IController
{

public:
	MainMenuCtrl(std::unique_ptr<view::View> view, MainMenuModel& model);

	void onButtonChanged(const button::ButtonEventQueue::Data& data) override;
	void onParameterChanged() override;
};

}

#endif /* SRC_CONTROLLER_MAINMENUCTRL_H_ */
