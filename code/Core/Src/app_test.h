/*
 * app.h
 *
 *  Created on: Apr 30, 2022
 *      Author: luk6xff
 */

#ifndef SRC_APPTEST_H_
#define SRC_APPTEST_H_


#include "iapp.h"
#include "GUI/Display.h"

/**
 * @brief TestApplication, used during development only.
 */
class AppTest : public IApp
{
public:

    AppTest();
    void run() override;

    // For tests
    Display& getDisplayHandle();

private:
    // Test methods
    void testLcd();
    void testWEP();
    void testT12();
    void testHOTAIR();

private:
    Display display;

};


#endif /* SRC_APPTEST_H_ */
