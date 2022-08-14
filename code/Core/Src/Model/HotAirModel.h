/*
 * HotAirModel.h
 *
 *  Created on: Aug 14, 2022
 *      Author: luk6xff
 */

#ifndef SRC_MODELS_HOTAIRMODEL_H_
#define SRC_MODELS_HOTAIRMODEL_H_

#include "IModel.h"

class HotAirModel : public IModel
{
public:
	uint16_t temperatureSet;
	uint16_t temperatureCurrent;
	uint8_t fanSet;

	size_t size() const override
	{
		return sizeof(temperatureSet) + sizeof(temperatureCurrent) + sizeof(fanSet);
	}
};


#endif /* SRC_MODELS_HOTAIRMODEL_H_ */
