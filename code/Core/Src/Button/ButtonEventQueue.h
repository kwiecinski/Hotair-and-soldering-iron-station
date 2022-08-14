/*
 * ButtonEventQueue.h
 *
 *  Created on: Aug 14, 2022
 *      Author: luk6xff
 */

#ifndef SRC_BUTTON_BUTTONEVENTQUEUE_H_
#define SRC_BUTTON_BUTTONEVENTQUEUE_H_

#include "ButtonTypes.h"
#include "FreeRTOS.h"
#include "queue.h"

namespace button
{

class ButtonEventQueue
{

	struct Data
	{
		ButtonType button;
		ButtonState state;
	};

public:
	explicit ButtonEventQueue(size_t size);

private:
	QueueHandle_t m_queue;
};

}

#endif /* SRC_BUTTON_BUTTONEVENTQUEUE_H_ */