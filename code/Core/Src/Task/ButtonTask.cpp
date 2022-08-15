/*
 * ButtonTask.cpp
 *
 *  Created on: May 3, 2022
 *      Author: luk6xff
 */

#include "ButtonTask.h"
#include "Queues.h"

//------------------------------------------------------------------------------
ButtonTask::ButtonTask(const char *name, size_t stackSize,
						osPriority_t priority, button::ButtonEventQueue& queue)
	: Task(name, stackSize, priority)
	, m_buttons()
	, m_queue(queue)
{

}

//------------------------------------------------------------------------------
void ButtonTask::start()
{
	registerButtonQueue();
	Task::start();
}

//------------------------------------------------------------------------------
void ButtonTask::run()
{
	button::Buttons::buttonsTask(&m_buttons);
}

//------------------------------------------------------------------------------
void ButtonTask::registerButtonQueue()
{

	for (int i = 0; i < button::ButtonType::BUTTONS_NUMBER; ++i)
	{
		// Short pressed
		m_buttons.buttonPressedShortCb(
					static_cast<button::ButtonType>(i),
					[this, i]()
					{
						button::ButtonEventQueue::Data data = {static_cast<button::ButtonType>(i), button::ButtonState::BUTTON_SHORT_PRESSED};
						m_queue.send(data);
					});

		// Long pressed
		m_buttons.buttonPressedLongCb(
					static_cast<button::ButtonType>(i),
					[this, i]()
					{
						button::ButtonEventQueue::Data data = {static_cast<button::ButtonType>(i), button::ButtonState::BUTTON_SHORT_PRESSED};
						m_queue.send(data);
					});
	}

}

//------------------------------------------------------------------------------
