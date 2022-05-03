/*
 * DisplayTask.h
 *
 *  Created on: May 3, 2022
 *      Author: luk6xff
 */

#ifndef SRC_TASKS_DISPLAYTASK_H_
#define SRC_TASKS_DISPLAYTASK_H_

#include "Task.h"
#include "../GUI/Display.h"

class DisplayTask : public Task
{

public:
	DisplayTask(const char *name, size_t stackSize, osPriority_t priority);

	void start() override;
	void run() override;

private:
	Display m_display;
};

#endif /* SRC_TASKS_DISPLAYTASK_H_ */
