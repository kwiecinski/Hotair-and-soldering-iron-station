/*
 * HotAirCtrl.h
 *
 *  Created on: Aug 14, 2022
 *      Author: luk6xff
 */

#ifndef SRC_CONTROLLER_HOTAIRCTRL_H_
#define SRC_CONTROLLER_HOTAIRCTRL_H_

#include "IController.h"

class HotAirCtrl : public IController
{
	HotAirCtrl();

	void onButtonChanged() override;
};

#endif /* SRC_CONTROLLER_HOTAIRCTRL_H_ */
