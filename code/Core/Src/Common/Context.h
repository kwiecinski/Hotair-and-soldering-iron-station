/*
 * Context.h
 *
 *  Created on: Aug 15, 2022
 *      Author: luk6xff
 */

#ifndef SRC_COMMON_CONTEXT_H_
#define SRC_COMMON_CONTEXT_H_

// Add all common (shared across the app) components
#include "../Task/Queues.h"
#include "../GUI/Display.h"

class Context
{
public:
	Context();
	static Context& ctx();

public:
	Queues queues;
	Display display;
};

#endif /* SRC_COMMON_CONTEXT_H_ */
