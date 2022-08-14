/*
 * ButtonTask.h
 *
 *  Created on: May 3, 2022
 *      Author: luk6xff
 */

#ifndef SRC_TASKS_BUTTONTASK_H_
#define SRC_TASKS_BUTTONTASK_H_

#include "Task.h"
#include "../Button/Buttons.h"

class ButtonTask : public Task
{

public:
	ButtonTask(const char *name, size_t stackSize,
				osPriority_t priority);

	void start() override;
	void run() override;

private:
	void registerButtonQueue();

private:
	button::Buttons m_buttons;
};

#endif /* SRC_TASKS_BUTTONTASK_H_ */
