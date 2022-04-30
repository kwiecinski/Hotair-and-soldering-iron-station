/*
 * app.h
 *
 *  Created on: Apr 30, 2022
 *      Author: luk6xff
 */

#ifndef SRC_APPTEST_H_
#define SRC_APPTEST_H_


#include "iapp.h"
#include "GUI/LCD/LiquidCrystal.h"

/**
 * @brief TestApplication, used during development only.
 */
class AppTest : public IApp
{
public:

    AppTest();
    void run() override;

private:
    // Test methods
    void testLcd();
    void testWEP();
    void testT12();
    void testHOTAIR();

private:
    LiquidCrystal lcd;
};


#endif /* SRC_APPTEST_H_ */
