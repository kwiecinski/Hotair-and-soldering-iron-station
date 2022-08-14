/*
 * ControlTask.h
 *
 *  Created on: May 3, 2022
 *      Author: luk6xff
 */

#ifndef SRC_TASKS_CONTROLTASK_H_
#define SRC_TASKS_CONTROLTASK_H_

#include "Task.h"
#include "../Controller/IController.h"
#include <memory>
#include <vector>

class ControlTask : public Task
{

public:
	ControlTask(const char *name, size_t stackSize, osPriority_t priority);

	void start() override;
	void run() override;

private:
	void registerController(std::unique_ptr<ctrl::IController> ctrl);

	void createAllControllers();

private:
	std::vector<std::unique_ptr<ctrl::IController>> m_controlers;
};

#endif /* SRC_TASKS_CONTROLTASK_H_ */
