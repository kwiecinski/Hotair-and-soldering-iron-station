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
ControlTask::ControlTask(const char *name, size_t stackSize, osPriority_t priority)
	: Task(name, stackSize, priority)
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
	registerController(std::make_unique<ctrl::IController>());
}
//------------------------------------------------------------------------------
