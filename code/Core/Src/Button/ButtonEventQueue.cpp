/*
 * ButtonEventQueue.cpp
 *
 *  Created on: Aug 14, 2022
 *      Author: luk6xff
 */


#include "ButtonEventQueue.h"
#include <stdio.h>

namespace button
{

//------------------------------------------------------------------------------
ButtonEventQueue::ButtonEventQueue(size_t size)
{
	m_queue = xQueueCreate(size, sizeof(ButtonEventQueue::Data));

    if(m_queue == nullptr)
    {
        printf("ButtonEventQueue init failed!");
    }
}

//------------------------------------------------------------------------------
void ButtonEventQueue::send(const Data& data)
{
    xQueueSend(m_queue, (void*)&data, (TickType_t)0);
}

//------------------------------------------------------------------------------
bool ButtonEventQueue::receive(Data& data)
{
    BaseType_t result;
    result = xQueueReceive(m_queue, &data, (TickType_t)0);

    return (result == pdPASS);
}

}
