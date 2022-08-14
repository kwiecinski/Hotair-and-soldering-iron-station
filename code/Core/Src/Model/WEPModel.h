/*
 * WepModel.h
 *
 *  Created on: Aug 14, 2022
 *      Author: luk6xff
 */

#ifndef SRC_MODELS_WEPMODEL_H_
#define SRC_MODELS_WEPMODEL_H_

#include "IModel.h"

class WepModel : public IModel
{
public:
	uint16_t temperatureSet;
	uint16_t temperatureCurrent;

	size_t size() const override
	{
		return sizeof(temperatureSet) + sizeof(temperatureCurrent);
	}
};


#endif /* SRC_MODELS_WEPMODEL_H_ */
