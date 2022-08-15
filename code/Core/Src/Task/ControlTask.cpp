/*
 * ControlTask.cpp
 *
 *  Created on: May 3, 2022
 *      Author: luk6xff
 */

#include "ControlTask.h"

// Controllers
#include "../Controller/MainMenuCtrl.h"

//------------------------------------------------------------------------------
ControlTask::ControlTask(const char *name, size_t stackSize,
						 osPriority_t priority,
					     view::ViewsFactory& viewsFactory,
						 Queues& queues)
	: Task(name, stackSize, priority)
	, m_viewsFactory(viewsFactory)
	, m_queues(queues)
{

}

//------------------------------------------------------------------------------
void ControlTask::start()
{
	Task::start();
}

//------------------------------------------------------------------------------
void ControlTask::run()
{
	const TickType_t k_sleepTime = 10/portTICK_PERIOD_MS;
	for (;;)
	{
		// Check for buttons change
		button::ButtonEventQueue::Data data;
		if (m_queues.buttonQueue.receive(data))
		{
			m_controlers[0]->onButtonChanged(data);
		}
		// Check for parameter change
	}
}


//------------------------------------------------------------------------------
void ControlTask::registerController(std::unique_ptr<ctrl::IController> ctrl)
{
	m_controlers.push_back(std::move(ctrl));
}

//------------------------------------------------------------------------------
void ControlTask::createAllControllers()
{
	registerController(std::make_unique<ctrl::MainMenuCtrl>(m_viewsFactory.createMainMenu(), m_mainMenuModel));
}
//------------------------------------------------------------------------------
