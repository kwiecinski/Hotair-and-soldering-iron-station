/*
 * RtosUtils.cpp
 *
 *  Created on: Aug 14, 2022
 *      Author: luk6xff
 */


#include "RtosUtils.h"

using namespace rtos;


//------------------------------------------------------------------------------
Mutex::Mutex()
    : m_handle(nullptr)
{
    m_handle = xSemaphoreCreateMutex();
}

//------------------------------------------------------------------------------
Mutex::~Mutex()
{
    unlock();
    reset();
}

//------------------------------------------------------------------------------
void Mutex::lock()
{
    if (m_handle)
    {
        xSemaphoreTake(m_handle, portMAX_DELAY);
    }
}

//------------------------------------------------------------------------------
void Mutex::unlock()
{
    if (m_handle)
    {
        xSemaphoreGive(m_handle);
    }
}

//------------------------------------------------------------------------------
void Mutex::reset()
{
    m_handle = nullptr;
}
