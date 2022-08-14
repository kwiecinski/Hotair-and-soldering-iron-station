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
	MainMenuCtrl(MainMenuView& view, MainMenuModel& model);

	void onButtonChanged() override;
	void onParameterChanged() override;
};

}

#endif /* SRC_CONTROLLER_MAINMENUCTRL_H_ */
