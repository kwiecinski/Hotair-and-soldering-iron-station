/*
The MIT License (MIT)

Copyright (c) 2016 Vasil Kalchev

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/**
@file
Contains the LiquidLine class definition.
*/

#include "LiquidMenu.h"


bool LiquidLine::attach_function(uint8_t number, void (*function)(void)) {
	LIQUID_DEBUG(("LLine ")); print_me(reinterpret_cast<uintptr_t>(this));

	LIQUID_DEBUG(("Attach function ")); LIQUID_DEBUG(number);

	if (number <= MAX_FUNCTIONS) {
		_function[number - 1] = function;
		_focusable = true;

		LIQUID_DEBUGLN((""));
		return true;
	} else {
		LIQUID_DEBUGLN((" failed, edit LiquidMenu_config.h to allow for more functions"));
		return false;
	}
}

void LiquidLine::set_decimalPlaces(uint8_t decimalPlaces) {
	_floatDecimalPlaces = decimalPlaces;
}

bool LiquidLine::set_focusPosition(Position position,
								   uint8_t column, uint8_t row) {
	LIQUID_DEBUG(("LLine ")); print_me(reinterpret_cast<uintptr_t>(this));

	if (position <= Position::CUSTOM) {
		_focusPosition = position;
		_focusColumn = column;
		_focusRow = row;
		LIQUID_DEBUG(("Focus position set to ")); LIQUID_DEBUG((uint8_t)_focusPosition);
		if (_focusPosition == Position::CUSTOM) {
			LIQUID_DEBUG((" at (")); LIQUID_DEBUG(_focusRow); LIQUID_DEBUG((", "));
			LIQUID_DEBUG(_focusColumn); LIQUID_DEBUG((")"));
		}
		return true;
	} else {
		LIQUID_DEBUGLN(("Failed setting focus position, options are 'RIGHT', 'LEFT' and 'CUSTOM'"));
		return false;
	}
}

bool LiquidLine::set_asGlyph(uint8_t number) {
	uint8_t index = number - 1;
	if ( (index < MAX_VARIABLES) && (_variableType[index] == DataType::UINT8_T) ) {
		_variableType[index] = DataType::GLYPH;
		return true;
	} else {
		LIQUID_DEBUG(("Setting variable ")); LIQUID_DEBUG(number);
		LIQUID_DEBUGLN((" as glyph failed, the variable must be of 'byte' data type"));
		return false;
	}
}

bool LiquidLine::set_asProgmem(uint8_t number) {
	uint8_t index = number - 1;
	if ((index < MAX_VARIABLES) && (_variableType[index] == DataType::CONST_CHAR_PTR)) {
		_variableType[index] = DataType::PROG_CONST_CHAR_PTR;
		return true;
	} else {
		LIQUID_DEBUG(("Setting variable ")); LIQUID_DEBUG(number);
		LIQUID_DEBUGLN((" as PROG_CONST_CHAR failed, the variable must be of 'const char[]' data type"));
		return false;
	}
}

void LiquidLine::print(DisplayClass *p_liquidCrystal, bool isFocused) {
	p_liquidCrystal->setCursor(_column, _row);
	LIQUID_DEBUG((" (")); LIQUID_DEBUG(_column); LIQUID_DEBUG((", ")); LIQUID_DEBUG(_row); LIQUID_DEBUGLN((")"));

	LIQUID_DEBUG(("|\t"));
	for (uint8_t v = 0; v < MAX_VARIABLES; v++) {
		print_variable(p_liquidCrystal, v);
	}

	if (isFocused) {
		LIQUID_DEBUG(("\t\t<Focus position: "));
		switch (_focusPosition) {
		case Position::RIGHT: {
			p_liquidCrystal->write((uint8_t)15);
			LIQUID_DEBUGLN(("right>"));
			//p_liquidCrystal->print(NOTHING);
			break;
		} //case RIGHT
		case Position::LEFT: {
			//p_liquidCrystal->print(NOTHING);
			p_liquidCrystal->setCursor(_column - 1, _row);
			p_liquidCrystal->write((uint8_t)14);
			LIQUID_DEBUGLN(("left>"));
			break;
		} //case LEFT
		case Position::CUSTOM: {
			//p_liquidCrystal->print(NOTHING);
			p_liquidCrystal->setCursor(_focusColumn, _focusRow);
			p_liquidCrystal->write((uint8_t)13);
			LIQUID_DEBUGLN(("custom (")); LIQUID_DEBUG(_focusColumn);
			LIQUID_DEBUG((", ")); LIQUID_DEBUG(_focusRow); LIQUID_DEBUGLN((")>"));
			break;
		} //case CUSTOM
		default: {
			LIQUID_DEBUG(("invalid (")); LIQUID_DEBUG((uint8_t)_focusPosition);
			LIQUID_DEBUGLN(("), switching to default>"));
			_focusPosition = Position::NORMAL;
			p_liquidCrystal->write((uint8_t)15);
			//p_liquidCrystal->print(NOTHING);
			break;
		} //default
		} //switch (_focusPosition)
	} else {
		//p_liquidCrystal->print(NOTHING);
	}
}

void LiquidLine::print_variable(DisplayClass *p_liquidCrystal, uint8_t number) {
	switch (_variableType[number]) {
	    // Variables -----
		case DataType::CONST_CHAR_PTR: {
			const char* variable = reinterpret_cast<const char*>(_variable[number]);
			LIQUID_DEBUG(("(const char*)")); LIQUID_DEBUG(variable);
			p_liquidCrystal->print(variable);
			break;
		} //case CONST_CHAR_PTR
		case DataType::CHAR_PTR: {
			char* variable = const_cast<char*>(reinterpret_cast<const char *>(_variable[number]));
			LIQUID_DEBUG(("(char*)")); LIQUID_DEBUG(variable);
			p_liquidCrystal->print(variable);
			break;
		} //case CHAR_PTR
		case DataType::CHAR: {
			const char variable = *static_cast<const char*>(_variable[number]);
			LIQUID_DEBUG(("(char)")); LIQUID_DEBUG(variable);
			p_liquidCrystal->write(variable);
			break;
		} //case CHAR

		case DataType::INT8_T: {
			const int8_t variable = *static_cast<const int8_t*>(_variable[number]);
			LIQUID_DEBUG(("(int8_t)")); LIQUID_DEBUG(variable);
			p_liquidCrystal->write(variable);
			break;
		} //case INT8_T
		case DataType::UINT8_T: {
			const uint8_t variable = *static_cast<const uint8_t*>(_variable[number]);
			LIQUID_DEBUG(("(uint8_t)")); LIQUID_DEBUG(variable);
			p_liquidCrystal->write(variable);
			break;
		} //case UINT8_T

		case DataType::INT16_T: {
			const int16_t variable = *static_cast<const int16_t*>(_variable[number]);
			char buffer[12];
			snprintf(buffer, sizeof buffer, "%d", variable);
			LIQUID_DEBUG(("(int16_t)")); LIQUID_DEBUG(variable);
			p_liquidCrystal->print(buffer);
			break;
		} //case INT16_T
		case DataType::UINT16_T: {
			const uint16_t variable = *static_cast<const uint16_t*>(_variable[number]);
			char buffer[12];
			snprintf(buffer, sizeof buffer, "%d", variable);
			LIQUID_DEBUG(("(uint16_t)")); LIQUID_DEBUG(variable);
			p_liquidCrystal->print(buffer);
			break;
		} //case UINT16_T

		case DataType::INT32_T: {
			const int32_t variable = *static_cast<const int32_t*>(_variable[number]);
			char buffer[12];
			snprintf(buffer, sizeof buffer, "%lu", variable);
			LIQUID_DEBUG(("(int32_t)")); LIQUID_DEBUG(variable);
			p_liquidCrystal->print(buffer);
			break;
		} //case INT32_T
		case DataType::UINT32_T: {
			const uint32_t variable = *static_cast<const uint32_t*>(_variable[number]);
			char buffer[12];
			snprintf(buffer, sizeof buffer, "%lu", variable);
			LIQUID_DEBUG(("(uint32_t)")); LIQUID_DEBUG(variable);
			p_liquidCrystal->print(buffer);
			break;
		} //case UINT32_T

		case DataType::FLOAT: {
			const float variable = *static_cast<const float*>(_variable[number]);
			char buffer[12];
			snprintf(buffer, sizeof buffer, "%f", variable);
			LIQUID_DEBUG(("(float)")); LIQUID_DEBUG(variable);
			p_liquidCrystal->print(buffer);
			break;
		} //case FLOAT

		case DataType::BOOL: {
			const bool variable = *static_cast<const bool*>(_variable[number]);
			LIQUID_DEBUG(("(bool)")); LIQUID_DEBUG(variable);
			p_liquidCrystal->write((uint8_t)variable);
			break;
		} //case BOOL

		case DataType::GLYPH: {
			const uint8_t variable = *static_cast<const uint8_t*>(_variable[number]);
			LIQUID_DEBUG(("(glyph)")); LIQUID_DEBUG(variable);
			p_liquidCrystal->write((uint8_t)variable);
			break;
		} //case BOOL

	    // ~Variables -----

	    // Getter functions -----
		case DataType::CONST_CHAR_PTR_GETTER: {
			const constcharPtrFnPtr getterFunction = reinterpret_cast<constcharPtrFnPtr>(_variable[number]);
			if (getterFunction != nullptr) {
				const char * variable = (getterFunction)();
			    LIQUID_DEBUG(("(const char*)")); LIQUID_DEBUG(variable);
				p_liquidCrystal->print(variable);
			}
			break;
		} // case CONST_CHAR_PTR_GETTER

		case DataType::CHAR_PTR_GETTER: {
			const charPtrFnPtr getterFunction = reinterpret_cast<charPtrFnPtr>(_variable[number]);
			if (getterFunction != nullptr) {
				char* variable = (getterFunction)();
				LIQUID_DEBUG(("(char*)")); LIQUID_DEBUG(variable);
				p_liquidCrystal->print(variable);
			}
			break;
		} // case CHAR_PTR_GETTER

		case DataType::CHAR_GETTER: {
			const charFnPtr getterFunction = reinterpret_cast<charFnPtr>(_variable[number]);
			if (getterFunction != nullptr) {
				char variable = (getterFunction)();
				LIQUID_DEBUG(("(char)")); LIQUID_DEBUG(variable);
				p_liquidCrystal->write(variable);
			}
			break;
		} // case CHAR_GETTER

		case DataType::INT8_T_GETTER: {
			const int8tFnPtr getterFunction = reinterpret_cast<int8tFnPtr>(_variable[number]);
			if (getterFunction != nullptr) {
				int8_t variable = (getterFunction)();
				LIQUID_DEBUG(("(int8_t)")); LIQUID_DEBUG(variable);
				p_liquidCrystal->write(variable);
			}
			break;
		} // case INT8_T_GETTER

		case DataType::UINT8_T_GETTER: {
			const uint8tFnPtr getterFunction = reinterpret_cast<uint8tFnPtr>(_variable[number]);
			if (getterFunction != nullptr) {
				uint8_t variable = (getterFunction)();
				LIQUID_DEBUG(("(uint8_t)")); LIQUID_DEBUG(variable);
				p_liquidCrystal->write(variable);
			}
			break;
		} // case UINT8_T_GETTER

		case DataType::INT16_T_GETTER: {
			const int16tFnPtr getterFunction = reinterpret_cast<int16tFnPtr>(_variable[number]);
			if (getterFunction != nullptr) {
				int16_t variable = (getterFunction)();
				char buffer[12];
				snprintf(buffer, sizeof buffer, "%d", variable);
				LIQUID_DEBUG(("(int16_t)")); LIQUID_DEBUG(variable);
				p_liquidCrystal->print(buffer);
			}
			break;
		} // case INT16_T_GETTER

		case DataType::UINT16_T_GETTER: {
			const uint16tFnPtr getterFunction = reinterpret_cast<uint16tFnPtr>(_variable[number]);
			if (getterFunction != nullptr) {
				uint16_t variable = (getterFunction)();
				char buffer[12];
				snprintf(buffer, sizeof buffer, "%d", variable);
				LIQUID_DEBUG(("(uint16_t)")); LIQUID_DEBUG(variable);
				p_liquidCrystal->print(buffer);
			}
			break;
		} // case UINT16_T_GETTER

		case DataType::INT32_T_GETTER: {
			const int32tFnPtr getterFunction = reinterpret_cast<int32tFnPtr>(_variable[number]);
			if (getterFunction != nullptr) {
				int32_t variable = (getterFunction)();
				char buffer[12];
				snprintf(buffer, sizeof buffer, "%ld", variable);
				LIQUID_DEBUG(("(int32_t)")); LIQUID_DEBUG(variable);
				p_liquidCrystal->print(buffer);
			}
			break;
		} // case INT32_T_GETTER

		case DataType::UINT32_T_GETTER: {
			const uint32tFnPtr getterFunction = reinterpret_cast<uint32tFnPtr>(_variable[number]);
			if (getterFunction != nullptr) {
				uint32_t variable = (getterFunction)();
				char buffer[12];
				snprintf(buffer, sizeof buffer, "%lu", variable);
				LIQUID_DEBUG(("(uint32_t)")); LIQUID_DEBUG(variable);
				p_liquidCrystal->print(buffer);
			}
			break;
		} // case UINT32_T_GETTER

		case DataType::FLOAT_GETTER: {
			const floatFnPtr getterFunction = reinterpret_cast<floatFnPtr>(_variable[number]);
			if (getterFunction != nullptr) {
				const float variable = (getterFunction)();
				char buffer[12];
				snprintf(buffer, sizeof buffer, "%3.2f", variable);
				LIQUID_DEBUG(("(float)")); LIQUID_DEBUG(variable);
				p_liquidCrystal->print(buffer);
			}
			break;
		} // case FLOAT_GETTER

		case DataType::BOOL_GETTER: {
			const boolFnPtr getterFunction = reinterpret_cast<boolFnPtr>(_variable[number]);
			if (getterFunction != nullptr) {
				bool variable = (getterFunction)();
				LIQUID_DEBUG(("(bool)")); LIQUID_DEBUG(variable);
				p_liquidCrystal->write(variable);
			}
			break;
		} // case BOOL_GETTER
	    // ~Getter functions -----

		default: { break; }
	} //switch (_variableType)

	LIQUID_DEBUG((" "));
}

bool LiquidLine::is_callable(uint8_t number) const {
	if (_function[number - 1]) return true;
	else return false;
}

bool LiquidLine::call_function(uint8_t number) const {
	if (_function[number - 1]) {
		(*_function[number - 1])();
		return true;
	} else {
		return false;
	}
}
