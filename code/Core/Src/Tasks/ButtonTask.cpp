/*
 * ButtonTask.cpp
 *
 *  Created on: May 3, 2022
 *      Author: luk6xff
 */

#include "ButtonTask.h"

//------------------------------------------------------------------------------
ButtonTask::ButtonTask(const char *name, size_t stackSize, osPriority_t priority)
	: Task(name, stackSize, priority)
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
	buttons_task(nullptr);
}
