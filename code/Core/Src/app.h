/*
 * app.h
 *
 *  Created on: Apr 30, 2022
 *      Author: luk6xff
 */

#ifndef SRC_APP_H_
#define SRC_APP_H_


#include "iapp.h"
#include "GUI/LCD/LiquidCrystal.h"

/**
 * @brief Main Soldering station application.
 */
class App : public IApp
{
public:

    App();
    void run() override;

private:
    LiquidCrystal lcd;
};


#endif /* SRC_APP_H_ */
