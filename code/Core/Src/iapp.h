/*
 * iapp.h
 *
 *  Created on: Apr 30, 2022
 *      Author: luk6xff
 */

#ifndef SRC_IAPP_H_
#define SRC_IAPP_H_

/**
 * @brief App Interface
 */
class IApp
{
public:
    IApp() = default;
    virtual void run() = 0;
};



#endif /* SRC_IAPP_H_ */
