/*
 * app.h
 *
 *  Created on: Apr 30, 2022
 *      Author: luk6xff
 */

#ifndef SRC_APP_H_
#define SRC_APP_H_


#include "iapp.h"
#include "Task/ButtonTask.h"
#include "Task/ControlTask.h"


/**
 * @brief Main Soldering station application.
 */
class App : public IApp
{
public:

    App();
    void run() override;

private:
    // Application Tasks
    ButtonTask m_buttonTask;
    ControlTask m_ctrlTask;
};


#endif /* SRC_APP_H_ */
