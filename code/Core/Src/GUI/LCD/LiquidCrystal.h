#ifndef LiquidCrystal_h
#define LiquidCrystal_h

#include <inttypes.h>
// Platform dependent GPIO header
#include "gpio.h"
// Multithread Synchronization mechanism
#include "../../Tasks/RtosUtils.h"

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

class LiquidCrystal
{

public:
  // Platform dependent GPIO structure
  enum GpioType : uint8_t
  {
    RS = 0,
    RW,
    ENABLE,
    D0,
    D1,
    D2,
    D3,
    D4,
    D5,
    D6,
    D7,
    D8,
    GPIO_NUM,
  };

  enum GpioState: uint8_t
  {
    LOW = 0,
    HIGH
  };

  struct Gpio
  {
    GPIO_TypeDef *port;
    uint16_t 	  pin;
  };

public:
  LiquidCrystal(LiquidCrystal::Gpio rs, LiquidCrystal::Gpio rw, LiquidCrystal::Gpio enable,
    LiquidCrystal::Gpio d0, LiquidCrystal::Gpio d1,	LiquidCrystal::Gpio d2, LiquidCrystal::Gpio d3,
    LiquidCrystal::Gpio d4, LiquidCrystal::Gpio d5, LiquidCrystal::Gpio d6, LiquidCrystal::Gpio d7);

  LiquidCrystal(LiquidCrystal::Gpio rs, LiquidCrystal::Gpio enable,
    LiquidCrystal::Gpio d0, LiquidCrystal::Gpio d1,	LiquidCrystal::Gpio d2, LiquidCrystal::Gpio d3,
    LiquidCrystal::Gpio d4, LiquidCrystal::Gpio d5, LiquidCrystal::Gpio d6, LiquidCrystal::Gpio d7);

  LiquidCrystal(LiquidCrystal::Gpio rs, LiquidCrystal::Gpio rw, LiquidCrystal::Gpio enable,
    LiquidCrystal::Gpio d0, LiquidCrystal::Gpio d1,	LiquidCrystal::Gpio d2, LiquidCrystal::Gpio d3);

  LiquidCrystal(LiquidCrystal::Gpio rs, LiquidCrystal::Gpio enable,
    LiquidCrystal::Gpio d0, LiquidCrystal::Gpio d1,	LiquidCrystal::Gpio d2, LiquidCrystal::Gpio d3);

  void init(uint8_t fourbitmode, LiquidCrystal::Gpio rs, LiquidCrystal::Gpio rw, LiquidCrystal::Gpio enable,
    LiquidCrystal::Gpio d0, LiquidCrystal::Gpio d1,	LiquidCrystal::Gpio d2, LiquidCrystal::Gpio d3,
    LiquidCrystal::Gpio d4, LiquidCrystal::Gpio d5, LiquidCrystal::Gpio d6, LiquidCrystal::Gpio d7);

  void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);

  void clear();
  void home();

  void noDisplay();
  void display();
  void noBlink();
  void blink();
  void noCursor();
  void cursor();
  void scrollDisplayLeft();
  void scrollDisplayRight();
  void leftToRight();
  void rightToLeft();
  void autoscroll();
  void noAutoscroll();

  void setRowOffsets(int row1, int row2, int row3, int row4);
  void createChar(uint8_t, const uint8_t[]);
  void setCursor(uint8_t, uint8_t);
  size_t write(uint8_t);
  size_t print(const char str[]);
  void command(uint8_t);

private:
  void send(uint8_t, uint8_t);
  void write4bits(uint8_t);
  void write8bits(uint8_t);
  void pulseEnable();

  // Platform (HAL, etc) dependent methods
  void initGpios();
  void setGpio(GpioType type, GpioState state);
  void delayUs(uint16_t us);
  void delayMs(uint16_t ms);

  Gpio _pins[GpioType::GPIO_NUM];

  uint8_t _displayfunction;
  uint8_t _displaycontrol;
  uint8_t _displaymode;

  uint8_t _initialized;

  uint8_t _numlines;
  uint8_t _row_offsets[4];

  rtos::Mutex _displayMtx;
};

#endif
