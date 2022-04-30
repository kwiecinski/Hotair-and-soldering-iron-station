/**
@file
Contains glyph definitions for LiquidMenu library.
*/

#pragma once


namespace glyphs {
/// The focus glyph shown on the right.
const uint8_t rightFocus[8] = {
	0b00000,
	0b00100,
	0b01000,
	0b11111,
	0b01000,
	0b00100,
	0b00000,
	0b00000
};

/// The focus glyph shown on the left.
const uint8_t leftFocus[8] = {
	0b00000,
	0b00100,
	0b00010,
	0b11111,
	0b00010,
	0b00100,
	0b00000,
	0b00000
};

/// The focus glyph shown when custom focus is set.
const uint8_t customFocus[8] = {
	0b00000,
	0b00000,
	0b01110,
	0b01110,
	0b01110,
	0b00000,
	0b00000,
	0b00000
};

const uint8_t heart[8] = {
	0b00000,
	0b01010,
	0b11111,
	0b11111,
	0b11111,
	0b01110,
	0b00100,
	0b00000
};

const uint8_t smiley[8] = {
	0b00000,
	0b00000,
	0b01010,
	0b00000,
	0b00000,
	0b10001,
	0b01110,
	0b00000
};

const uint8_t frownie[8] = {
	0b00000,
	0b00000,
	0b01010,
	0b00000,
	0b00000,
	0b00000,
	0b01110,
	0b10001
};

const uint8_t armsDown[8] = {
	0b00100,
	0b01010,
	0b00100,
	0b00100,
	0b01110,
	0b10101,
	0b00100,
	0b01010
};

const uint8_t armsUp[8] = {
	0b00100,
	0b01010,
	0b00100,
	0b10101,
	0b01110,
	0b00100,
	0b00100,
	0b01010
};

const uint8_t fan1[8] = {
  0b00000,
  0b11001,
  0b01011,
  0b00100,
  0b11010,
  0b10011,
  0b00000,
  0b00000
};

const uint8_t fan2[8] = {
  0b00000,
  0b10011,
  0b11010,
  0b00100,
  0b01011,
  0b11001,
  0b00000,
  0b00000
};

const uint8_t thermometer[8] = {
  0b00100,
  0b01010,
  0b01010,
  0b01010,
  0b10001,
  0b11111,
  0b01110,
  0b00000
};

const uint8_t celsiusSymbol[8] = {
  0b00011,
  0b00011,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

} //namespace glyph
