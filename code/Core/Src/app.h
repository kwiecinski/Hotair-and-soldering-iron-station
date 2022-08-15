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

#include "View/ViewsFactory.h"
#include "Task/Queues.h"
#include "GUI/Display.h"
#include "Model/MainMenuModel.h"


/**
 * @brief Main Soldering station application.
 */
class App : public IApp
{
public:

    App();
    void run() override;

private:
    // Common Objects
	Display m_display;
    view::ViewsFactory m_viewsFactory;
	Queues m_queues;

    // Application Tasks
    ButtonTask m_buttonTask;
    ControlTask m_ctrlTask;
};


#endif /* SRC_APP_H_ */
