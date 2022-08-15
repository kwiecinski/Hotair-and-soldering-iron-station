/*
 * HotAirCtrl.h
 *
 *  Created on: Aug 14, 2022
 *      Author: luk6xff
 */

#ifndef SRC_CONTROLLER_HOTAIRCTRL_H_
#define SRC_CONTROLLER_HOTAIRCTRL_H_

#include "IController.h"

namespace ctrl
{

class HotAirCtrl : public IController
{

public:
	HotAirCtrl();

	void onButtonChanged(const button::ButtonEventQueue::Data& data) override;
	void onParameterChanged() override;
};

}


#endif /* SRC_CONTROLLER_HOTAIRCTRL_H_ */
