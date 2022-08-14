/*
 * DisplayTask.cpp
 *
 *  Created on: May 3, 2022
 *      Author: luk6xff
 */

#include "DisplayTask.h"


//------------------------------------------------------------------------------
DisplayTask::DisplayTask(const char *name, size_t stackSize, osPriority_t priority)
	: Task(name, stackSize, priority)
{

}

//------------------------------------------------------------------------------
void DisplayTask::start()
{
	m_display.init();
	Task::start();
}

//------------------------------------------------------------------------------
void DisplayTask::run()
{
	const TickType_t k_refreshTime = 100/portTICK_PERIOD_MS;
	for (;;)
	{
		//m_display.update();
		vTaskDelay(k_refreshTime);
	}
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
