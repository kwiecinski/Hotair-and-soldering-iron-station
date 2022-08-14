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

namespace ctrl
{

class IController
{
public:
	IController(ControllerId id, View& view, IModel& model)
		: m_id(id)
		, m_view(view)
		, m_model(model)
	{

	}

protected:
	virtual void onButtonChanged() = 0;
	virtual void onParameterChanged() = 0;

private:
	ControllerId m_id;
	View& m_view;
	IModel& m_model;
};

}

#endif /* SRC_CONTROLLER_ICONTROLLER_H_ */
