/*
 * RtosUtils.h
 *
 *  Created on: Aug 14, 2022
 *      Author: luk6xff
 */

#ifndef SRC_TASKS_RTOSUTILS_H_
#define SRC_TASKS_RTOSUTILS_H_

#include <FreeRTOS.h>
#include <semphr.h>

namespace rtos
{

/**
 * @brief Simple RAII lock_guard implementation
 */
template<typename T>
class LockGuard
{

public:
    LockGuard(T& handle)
        : m_handle(handle)
    {
        m_handle.lock();
    }

    ~LockGuard()
    {
        m_handle.unlock();
    }

    LockGuard(const LockGuard& other) = delete;
    LockGuard(LockGuard&& other) = delete;
    LockGuard& operator=(const LockGuard& other) = delete;

private:
    T& m_handle;
};


/**
 * @brief FreeRtos mutex wrapper
 */
class Mutex final
{

public:
    Mutex();
    ~Mutex();

    void lock();
    void unlock();
    void reset();

private:
    SemaphoreHandle_t m_handle;
};


} // rtos

#endif /* SRC_TASKS_RTOSUTILS_H_ */
