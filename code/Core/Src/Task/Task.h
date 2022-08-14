/*
 * Task.h
 *
 *  Created on: May 3, 2022
 *      Author: luk6xff
 */

#ifndef SRC_TASKS_TASK_H_
#define SRC_TASKS_TASK_H_

#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

/**
 * @brief Simple wrapper for FreeRtos task
 *
 * @author Lukasz Uszko - luk6xff
 * @date   15.10.2020
 */
class Task
{

public:
    Task(const char *name,
    	size_t stackSize = 128 * 4,
		osPriority_t priority = (osPriority_t)osPriorityNormal);
    virtual ~Task();

    virtual void start();
    void suspend();
    void resume();

    void restart();

    osThreadId_t& getTaskHandle();

    const char* getTaskName() const;

protected:
    void kill();
    virtual void run() = 0;

private:
    osThreadId_t m_handle;
    const char *m_name;
    size_t m_stackSize;
    osPriority_t m_priority;

    /**
     * @brief Adapter function that allows you to write a class
     *  	  specific run() function that interfaces with FreeRTOS.
     */
    static void taskFuncAdapter(void *args);
};
#endif /* SRC_TASKS_TASK_H_ */
