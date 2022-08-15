/*
 * IController.h
 *
 *  Created on: Aug 14, 2022
 *      Author: luk6xff
 */

#ifndef SRC_CONTROLLER_ICONTROLLER_H_
#define SRC_CONTROLLER_ICONTROLLER_H_

#include "ControllerId.h"
#include "../View/View.h"
#include "../Model/IModel.h"
#include "../Button/ButtonEventQueue.h"
#include <memory>

namespace ctrl
{

class IController
{
public:
	IController(ControllerId id, std::unique_ptr<view::View> view, IModel& model)
		: m_id(id)
		, m_view(std::move(view))
		, m_model(model)
	{

	}

	virtual void onButtonChanged(const button::ButtonEventQueue::Data& data) = 0;
	virtual void onParameterChanged() = 0;

private:
	ControllerId m_id;

protected:
	std::unique_ptr<view::View> m_view;
	IModel& m_model;
};

}

#endif /* SRC_CONTROLLER_ICONTROLLER_H_ */
