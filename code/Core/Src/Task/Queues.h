/*
 * Queues.h
 *
 *  Created on: Aug 15, 2022
 *      Author: luk6xff
 */

#ifndef SRC_TASK_QUEUES_H_
#define SRC_TASK_QUEUES_H_

#include "../Button/ButtonEventQueue.h"

class Queues
{

public:
	Queues();

public:
	button::ButtonEventQueue buttonQueue;
};

#endif /* SRC_TASK_QUEUES_H_ */
