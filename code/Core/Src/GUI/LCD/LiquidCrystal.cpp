#include "LiquidCrystal.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

// Platfrom Dependent code - LU_TODO
#include "tim.h"
#include "utils.h"
#define HW_DELAY 			1
#define BACKLIGHT_ON  		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2)
#define BACKLIGHT_OFF  		HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_2)

// When the display powers up, it is configured as follows:
//
// 1. Display clear
// 2. Function set:
//    DL = 1; 8-bit interface data
//    N = 0; 1-line display
//    F = 0; 5x8 dot character font
// 3. Display on/off control:
//    D = 0; Display off
//    C = 0; Cursor off
//    B = 0; Blinking off
// 4. Entry mode set:
//    I/D = 1; Increment by 1
//    S = 0; No shift
//
// Note, however, that resetting the Arduino doesn't reset the LCD, so we
// can't assume that it's in that state when a sketch starts (and the
// LiquidCrystal constructor is called).

/* Pin definitions */
//############################################################################################
LiquidCrystal::LiquidCrystal(LiquidCrystal::Gpio rs, LiquidCrystal::Gpio rw, LiquidCrystal::Gpio enable,
  LiquidCrystal::Gpio d0, LiquidCrystal::Gpio d1,	LiquidCrystal::Gpio d2, LiquidCrystal::Gpio d3,
  LiquidCrystal::Gpio d4, LiquidCrystal::Gpio d5, LiquidCrystal::Gpio d6, LiquidCrystal::Gpio d7)
{
  init(0, rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7);
}

LiquidCrystal::LiquidCrystal(LiquidCrystal::Gpio rs, LiquidCrystal::Gpio enable,
  LiquidCrystal::Gpio d0, LiquidCrystal::Gpio d1,	LiquidCrystal::Gpio d2, LiquidCrystal::Gpio d3,
  LiquidCrystal::Gpio d4, LiquidCrystal::Gpio d5, LiquidCrystal::Gpio d6, LiquidCrystal::Gpio d7)
{
  init(0, rs, {0, 255}, enable, d0, d1, d2, d3, d4, d5, d6, d7);
}

LiquidCrystal::LiquidCrystal(LiquidCrystal::Gpio rs, LiquidCrystal::Gpio rw, LiquidCrystal::Gpio enable,
  LiquidCrystal::Gpio d0, LiquidCrystal::Gpio d1,	LiquidCrystal::Gpio d2, LiquidCrystal::Gpio d3)
{
  init(1, rs, rw, enable, d0, d1, d2, d3, {0, 0}, {0, 0}, {0, 0}, {0, 0});
}

LiquidCrystal::LiquidCrystal(LiquidCrystal::Gpio rs, LiquidCrystal::Gpio enable,
  LiquidCrystal::Gpio d0, LiquidCrystal::Gpio d1,	LiquidCrystal::Gpio d2, LiquidCrystal::Gpio d3)
{
  init(1, rs, {0, 255}, enable, d0, d1, d2, d3, {0, 0}, {0, 0}, {0, 0}, {0, 0});
}

void LiquidCrystal::init(uint8_t fourbitmode, LiquidCrystal::Gpio rs, LiquidCrystal::Gpio rw, LiquidCrystal::Gpio enable,
  LiquidCrystal::Gpio d0, LiquidCrystal::Gpio d1,	LiquidCrystal::Gpio d2, LiquidCrystal::Gpio d3,
  LiquidCrystal::Gpio d4, LiquidCrystal::Gpio d5, LiquidCrystal::Gpio d6, LiquidCrystal::Gpio d7)
{
  // Control
  _pins[GpioType::RS] = rs;
  _pins[GpioType::RW] = rw;
  _pins[GpioType::ENABLE] = enable;

  // Data
  _pins[GpioType::D0] = d0;
  _pins[GpioType::D1] = d1;
  _pins[GpioType::D2] = d2;
  _pins[GpioType::D3] = d3;
  _pins[GpioType::D4] = d4;
  _pins[GpioType::D5] = d5;
  _pins[GpioType::D6] = d6;
  _pins[GpioType::D7] = d7;

  if (fourbitmode)
    _displayfunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS;
  else
    _displayfunction = LCD_8BITMODE | LCD_1LINE | LCD_5x8DOTS;

  //begin(16, 2);
}

void LiquidCrystal::begin(uint8_t cols, uint8_t lines, uint8_t dotsize) {
  if (lines > 1) {
    _displayfunction |= LCD_2LINE;
  }
  _numlines = lines;

  for (int i = 0; i < 10; ++i)
  {
    printf("i=%d, pin=0x%x, port=0x%x\n\r", i, _pins[i].pin, _pins[i].port);
  }

  setRowOffsets(0x00, 0x40, 0x00 + cols, 0x40 + cols);

  // for some 1 line displays you can select a 10 pixel high font
  if ((dotsize != LCD_5x8DOTS) && (lines == 1)) {
    _displayfunction |= LCD_5x10DOTS;
  }

  BACKLIGHT_ON;

  initGpios();

  // SEE PAGE 45/46 FOR INITIALIZATION SPECIFICATION!
  // according to datasheet, we need at least 40ms after power rises above 2.7V
  // so we'll wait 50 just to make sure
  delayMs(50);

  // Now we pull both RS and R/W low to begin commands
  setGpio(GpioType::RS, GpioState::LOW);
  setGpio(GpioType::ENABLE, GpioState::LOW);

  if (_pins[GpioType::RW].pin != 255) {
	  setGpio(GpioType::RW, GpioState::LOW);
  }

  //put the LCD into 4 bit or 8 bit mode
  if (! (_displayfunction & LCD_8BITMODE)) {
    // this is according to the hitachi HD44780 datasheet
    // figure 24, pg 46

    // we start in 8bit mode, try to set 4 bit mode
    write4bits(0x03);
    delayMs(5); // wait min 4.1ms

    // second try
    write4bits(0x03);
    delayMs(5); // wait min 4.1ms

    // third go!
    write4bits(0x03);
    delayMs(1);

    // finally, set to 4-bit interface
    write4bits(0x02);
  } else {
    // this is according to the hitachi HD44780 datasheet
    // page 45 figure 23

    // Send function set command sequence
    command(LCD_FUNCTIONSET | _displayfunction);
    delayMs(5);  // wait more than 4.1ms

    // second try
    command(LCD_FUNCTIONSET | _displayfunction);
    delayMs(1);

    // third go
    command(LCD_FUNCTIONSET | _displayfunction);
  }

  // finally, set # lines, font size, etc.
  command(LCD_FUNCTIONSET | _displayfunction);

  // turn the display on with no cursor or blinking default
  _displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
  display();

  // clear it off
  clear();

  // Initialize to default text direction (for romance languages)
  _displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
  // set the entry mode
  command(LCD_ENTRYMODESET | _displaymode);
}

void LiquidCrystal::setRowOffsets(int row0, int row1, int row2, int row3)
{
  _row_offsets[0] = row0;
  _row_offsets[1] = row1;
  _row_offsets[2] = row2;
  _row_offsets[3] = row3;
}

/********** high level commands, for the user! */
void LiquidCrystal::clear()
{
  command(LCD_CLEARDISPLAY);  // clear display, set cursor position to zero
  delayMs(2);  // this command takes a long time!
}

void LiquidCrystal::home()
{
  command(LCD_RETURNHOME);  // set cursor position to zero
  delayMs(2);  // this command takes a long time!
}

void LiquidCrystal::setCursor(uint8_t col, uint8_t row)
{
  const size_t max_lines = sizeof(_row_offsets) / sizeof(*_row_offsets);
  if ( row >= max_lines ) {
    row = max_lines - 1;    // we count rows starting w/ 0
  }
  if ( row >= _numlines ) {
    row = _numlines - 1;    // we count rows starting w/ 0
  }

  command(LCD_SETDDRAMADDR | (col + _row_offsets[row]));
}

// Turn the display on/off (quickly)
void LiquidCrystal::noDisplay() {
  _displaycontrol &= ~LCD_DISPLAYON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void LiquidCrystal::display() {
  _displaycontrol |= LCD_DISPLAYON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turns the underline cursor on/off
void LiquidCrystal::noCursor() {
  _displaycontrol &= ~LCD_CURSORON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void LiquidCrystal::cursor() {
  _displaycontrol |= LCD_CURSORON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turn on and off the blinking cursor
void LiquidCrystal::noBlink() {
  _displaycontrol &= ~LCD_BLINKON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void LiquidCrystal::blink() {
  _displaycontrol |= LCD_BLINKON;
  command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// These commands scroll the display without changing the RAM
void LiquidCrystal::scrollDisplayLeft(void) {
  command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
}
void LiquidCrystal::scrollDisplayRight(void) {
  command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
}

// This is for text that flows Left to Right
void LiquidCrystal::leftToRight(void) {
  _displaymode |= LCD_ENTRYLEFT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// This is for text that flows Right to Left
void LiquidCrystal::rightToLeft(void) {
  _displaymode &= ~LCD_ENTRYLEFT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'right justify' text from the cursor
void LiquidCrystal::autoscroll(void) {
  _displaymode |= LCD_ENTRYSHIFTINCREMENT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'left justify' text from the cursor
void LiquidCrystal::noAutoscroll(void) {
  _displaymode &= ~LCD_ENTRYSHIFTINCREMENT;
  command(LCD_ENTRYMODESET | _displaymode);
}

// Allows us to fill the first 8 CGRAM locations
// with custom characters
void LiquidCrystal::createChar(uint8_t location, const uint8_t charmap[]) {
  location &= 0x7; // we only have 8 locations 0-7
  command(LCD_SETCGRAMADDR | (location << 3));
  for (int i=0; i<8; i++) {
    write(charmap[i]);
  }
}

// This will print character string to the LCD
size_t LiquidCrystal::print(const char str[])
{
  if (str == NULL) return 0;

  const uint8_t *buffer = (const uint8_t *)str;
  size_t size = strlen(str);
  size_t n = 0;

  while (size--) {
    if (write(*buffer++)) n++;
    else break;
  }
  return n;
}

/*********** mid level commands, for sending data/cmds */

inline void LiquidCrystal::command(uint8_t value) {
  send(value, GpioState::LOW);
}

size_t LiquidCrystal::write(uint8_t value) {
  send(value, GpioState::HIGH);
  return 1; // assume sucess
}

/************ low level data pushing commands **********/

// write either command or data, with automatic 4/8-bit selection
void LiquidCrystal::send(uint8_t value, uint8_t mode) {

  setGpio(GpioType::RS, (GpioState)mode);

  // if there is a RW pin indicated, set it low to Write
  if (_pins[GpioType::RW].pin != 255) {
	  setGpio(GpioType::RW, GpioState::LOW);
  }

  if (_displayfunction & LCD_8BITMODE) {
    write8bits(value);
  } else {
    write4bits(value>>4);
    write4bits(value & 0x0F);
 }
}

void LiquidCrystal::pulseEnable(void) {
  setGpio(GpioType::ENABLE, GpioState::LOW);
  delayUs(50);
  setGpio(GpioType::ENABLE, GpioState::HIGH);
  delayUs(50);    // enable pulse must be >450 ns
  setGpio(GpioType::ENABLE, GpioState::LOW);
  delayUs(50);    // commands need >37 us to settle
}

void LiquidCrystal::write4bits(uint8_t cmd) {
  setGpio(GpioType::D3, (GpioState)(cmd & 0x08));
  setGpio(GpioType::D2, (GpioState)(cmd & 0x04));
  setGpio(GpioType::D1, (GpioState)(cmd & 0x02));
  setGpio(GpioType::D0, (GpioState)(cmd & 0x01));
  pulseEnable();
}

void LiquidCrystal::write8bits(uint8_t cmd) {
  setGpio(GpioType::D7, (GpioState)(cmd & 0x80));
  setGpio(GpioType::D6, (GpioState)(cmd & 0x40));
  setGpio(GpioType::D5, (GpioState)(cmd & 0x20));
  setGpio(GpioType::D4, (GpioState)(cmd & 0x10));
  setGpio(GpioType::D3, (GpioState)(cmd & 0x08));
  setGpio(GpioType::D2, (GpioState)(cmd & 0x04));
  setGpio(GpioType::D1, (GpioState)(cmd & 0x02));
  setGpio(GpioType::D0, (GpioState)(cmd & 0x01));
  pulseEnable();
}

// Platform (HAL, etc) dependent methods
void LiquidCrystal::initGpios()
{
  GPIO_InitTypeDef  gpio;
  gpio.Mode = GPIO_MODE_OUTPUT_PP;
  gpio.Speed = GPIO_SPEED_FREQ_HIGH;
  gpio.Pull = GPIO_NOPULL;

  for (int i=0; i<(GpioType::D0); ++i)
  {
    gpio.Pin = _pins[i].pin;
    HAL_GPIO_Init(_pins[i].port, &gpio);
  }

  for (int i=0; i<((_displayfunction & LCD_8BITMODE) ? 8 : 4); ++i)
  {
    gpio.Pin = _pins[(GpioType::D0)+i].pin;
    HAL_GPIO_Init(_pins[(GpioType::D0)+i].port, &gpio);
  }
}

void LiquidCrystal::setGpio(GpioType type, GpioState state)
{
  HAL_GPIO_WritePin(_pins[type].port, _pins[type].pin, (GPIO_PinState)state);
}

void LiquidCrystal::delayUs(uint16_t us)
{
	Delay_us(us);
}

void LiquidCrystal::delayMs(uint16_t ms)
{
#if _LCD_USE_FREERTOS==1
	osDelay(ms);
#else
	HAL_Delay(ms);
#endif
}
