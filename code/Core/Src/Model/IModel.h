/*
 * IModel.h
 *
 *  Created on: Aug 14, 2022
 *      Author: luk6xff
 */

#ifndef SRC_MODELS_IMODEL_H_
#define SRC_MODELS_IMODEL_H_

#include <tuple>

class IModel
{

protected:
	virtual size_t size() const = 0;

};

#endif /* SRC_MODELS_IMODEL_H_ */
