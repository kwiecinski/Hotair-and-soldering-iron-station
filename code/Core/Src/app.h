/*
 * app.h
 *
 *  Created on: Apr 30, 2022
 *      Author: luk6xff
 */

#ifndef SRC_APP_H_
#define SRC_APP_H_


#include "iapp.h"
#include "Task/DisplayTask.h"
#include "Task/ButtonTask.h"

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
    DisplayTask m_dispTask;
    ButtonTask m_buttonTask;

    // Common objects
    button::Buttons m_buttons;
};


#endif /* SRC_APP_H_ */
