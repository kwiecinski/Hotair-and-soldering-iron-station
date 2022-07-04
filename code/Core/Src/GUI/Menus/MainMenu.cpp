/*
 * MainMenu.cpp
 *
 *  Created on: May 3, 2022
 *      Author: luk6xff
 */

#include "MainMenu.h"

#include "../../Buttons/Buttons.h"
#include "../LCD/glyphs.h"

// LU_TODO
// Pin definitions and variables for their state.
const uint8_t pin6 = 6;
uint8_t pin6_level = 0;

uint8_t pinA4_value = 0;

uint8_t pinA5_value = 0;

// The analog reading sample period in seconds.
// It is later overwritten by it's EEPROM value.
unsigned short sample_period = 2;

// Text used for indication for the save lines.
char input_saved[3];
char output_saved[3];

char string_saved[] = " *";
char string_notSaved[] = "  ";


// F_focus_menu
const bool pullup = true;
static LiquidLine welcome_line1(1, 0, "LiquidMenu ", LIQUIDMENU_VERSION);
static LiquidLine welcome_line2(1, 1, "Focus example");
static LiquidScreen welcome_screen(welcome_line1, welcome_line2);

LiquidLine leftFocus_line(1, 0, "Left focus");
LiquidLine rightFocus_line(1, 1, "Right focus");
LiquidScreen leftright_screen(leftFocus_line, rightFocus_line);

LiquidLine customFocus_line(1, 0, "Custom focus");
LiquidScreen customFocus_screen(customFocus_line);

LiquidLine leftF1_line(6, 0, "Left");
LiquidLine leftF2_line(6, 1, "focus");
LiquidScreen leftF12_screen(leftF1_line, leftF2_line);

// Indicator symbol definition, it will change the default symbol for the right focus.
// http://omerk.github.io/lcdchargen/
uint8_t rFocus[8] = {
	0b00000,
	0b00000,
	0b00100,
	0b01110,
	0b00100,
	0b00000,
	0b00000,
	0b00000
};
// Blank function, it is attached to the lines so that they become focusable.
void func() {
	return;
}


Buttons buttons;
//------------------------------------------------------------------------------
MainMenu::MainMenu(const char *title, LiquidCrystal& lcd)
	: IMenu("SETTINGS")
	, m_lcd(lcd)
	, m_titleLine(0, 0, m_title) // LU_TODO
	, m_hotAirLine(1, 1, "HotAir settings")
	, m_wepLine(1, 2, "WEP settings")
	, m_t12Line(1, 3, "T12 settings")
	, m_aboutLine(1, 4, "About")
	, m_menu(m_lcd)
{

}


void MainMenu::init()
{
	m_screen.add_line(m_titleLine);
	m_screen.add_line(m_hotAirLine);
	m_screen.add_line(m_wepLine);
	m_screen.add_line(m_t12Line);
	m_screen.add_line(m_aboutLine);

	m_screen.set_displayLineCount(2);

	// Set focus symbols
	//m_screen.set_focusSymbol(Position::LEFT, glyphs::leftFocus);
	//m_screen.set_focusPosition(Position::LEFT);

	m_hotAirLine.set_focusPosition(Position::LEFT);
	m_wepLine.set_focusPosition(Position::LEFT);
	m_t12Line.set_focusPosition(Position::LEFT);
	m_aboutLine.set_focusPosition(Position::LEFT);

	m_hotAirLine.attach_function(1, func);
	m_wepLine.attach_function(1, func);
	m_t12Line.attach_function(1, func);
	m_aboutLine.attach_function(1, func);

    // Set the number of decimal places for a "line".
	//line1.set_decimalPlaces(5);

	m_menu.add_screen(m_screen);

	// Set first focus line
	m_menu.switch_focus();
//	m_menu.update();

	buttons.button_pressed_short_cb(ButtonType::BUTTON_MENU_RIGHT, [this](){m_menu.switch_focus();});
}


//------------------------------------------------------------------------------
void MainMenu::update()
{
//	// LU_TODO For tests only
//	static int i = 0;
//	if (i++ % 100 == 0)
//	{
//		m_menu.next_screen();
//		m_menu.set_focusSymbol(Position::LEFT, glyphs::leftFocus);
//		m_menu.get_currentScreen()->set_focusPosition(Position::LEFT);
//	}
//  m_menu.update();

	  if (buttons.buttons_state(BUTTON_MENU_RIGHT) == BUTTON_SHORT_PRESSED)
	  {
		  m_menu.switch_focus();
	  }
	  if (buttons.buttons_state(BUTTON_MENU_LEFT) == BUTTON_SHORT_PRESSED)
	  {
		  m_menu.switch_focus(false);
	  }
	  if (buttons.buttons_state(BUTTON_HOTAIR_TEMP_UP) == BUTTON_SHORT_PRESSED)
	  {
	    //menu_system.call_function(increase);
	  }
	  if (buttons.buttons_state(BUTTON_HOTAIR_TEMP_DOWN) == BUTTON_SHORT_PRESSED)
	  {
	    //menu_system.call_function(decrease);
	  }
	  	  if (buttons.buttons_state(BUTTON_MENU_OK) == BUTTON_SHORT_PRESSED)
	  	  {
	  }

	  m_menu.update();

}

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
