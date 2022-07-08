/*
 * ButtonTask.cpp
 *
 *  Created on: May 3, 2022
 *      Author: luk6xff
 */

#include "ButtonTask.h"

//------------------------------------------------------------------------------
ButtonTask::ButtonTask(const char *name, size_t stackSize,
						osPriority_t priority, Buttons& buttons)
	: Task(name, stackSize, priority)
	, m_buttons(buttons)
{

}

//------------------------------------------------------------------------------
void ButtonTask::start()
{
	Task::start();
}

//------------------------------------------------------------------------------
void ButtonTask::run()
{
	Buttons::buttons_task(&m_buttons);
}

//------------------------------------------------------------------------------
