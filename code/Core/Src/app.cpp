/*
 * app.cpp
 *
 *  Created on: Apr 30, 2022
 *      Author: luk6xff
 */
#include "app.h"

#include <main.h>
#include <stdio.h>
#include <string.h>
#include "retarget.h"
#include "utils.h"
#include "adc_functions.h"
#include "adc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "MAX31855/MAX31855.h"

//------------------------------------------------------------------------------
App::App()
	: m_display()
	, m_viewsFactory(m_display)
	, m_queues()
	, m_buttonTask("ButtonTask", 128*4, osPriorityNormal, m_queues.buttonQueue)
	, m_ctrlTask("ControlTask", 256*4, osPriorityNormal, m_viewsFactory, m_queues)
{

}

//------------------------------------------------------------------------------
void App::run()
{
    //Init printf retarget
    RetargetInit(&huart2);
    // Start Timer
    Start_generic_timer();
    // Init ADC
    Init_ADC();

    printf("\r\n>>> Hello from HotAir-Soldering-Station App! <<<\r\n");
    printf(">>> Made by Kwiecinski & Uszko 2022 <<<\r\n\r\n");

    // Init display
    m_display.init();

    // Start All the tasks
    m_ctrlTask.start();
    m_buttonTask.start();
}
