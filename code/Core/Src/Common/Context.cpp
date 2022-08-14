/*
 * Context.cpp
 *
 *  Created on: Aug 15, 2022
 *      Author: luk6xff
 */


#include "Context.h"


Context::Context()
: queues()
{

}

//------------------------------------------------------------------------------
Context& Context::ctx()
{
	static Context ctx;
	return ctx;
}

//------------------------------------------------------------------------------
