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
	: m_dispTask("DisplayTask", 256*4, osPriorityNormal)
	, m_buttonTask("ButtonTask", 128*4, osPriorityNormal)
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

    // Start All the tasks
    m_dispTask.start();
    m_buttonTask.start();

}







//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------TEST_APPLICATION--------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
