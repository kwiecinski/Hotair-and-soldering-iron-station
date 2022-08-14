/*
 * Task.cpp
 *
 *  Created on: May 3, 2022
 *      Author: luk6xff
 */

#include "Task.h"

//------------------------------------------------------------------------------
Task::Task(const char *name, size_t stackSize, osPriority_t priority)
    : m_handle(nullptr)
    , m_name(name)
    , m_stackSize(stackSize)
    , m_priority(priority)
{

}

//------------------------------------------------------------------------------
Task::~Task()
{
    kill();
}


//------------------------------------------------------------------------------
void Task::suspend()
{
    vTaskSuspend(m_handle);
}


//------------------------------------------------------------------------------
void Task::resume()
{
    vTaskResume(m_handle);
}


//------------------------------------------------------------------------------
void Task::restart()
{
    kill();
    vTaskDelay(1);
    start();
}

//------------------------------------------------------------------------------
osThreadId_t& Task::getTaskHandle()
{
    return m_handle;
}

//------------------------------------------------------------------------------
const char* Task::getTaskName() const
{
    return pcTaskGetTaskName(m_handle);
}


//------------------------------------------------------------------------------
void Task::kill()
{
    if (m_handle)
    {
        vTaskDelete(m_handle);
    }
    m_handle = nullptr;
}

//------------------------------------------------------------------------------
void Task::start()
{
	const osThreadAttr_t attributes =
	{
		m_name,
		.stack_size = m_stackSize,
		.priority = m_priority,
	};

	m_handle = osThreadNew(&Task::taskFuncAdapter, this, &attributes);
}

//------------------------------------------------------------------------------
void Task::taskFuncAdapter(void *args)
{
    Task *task = static_cast<Task *>(args);
    task->run();
    task->kill();
}
