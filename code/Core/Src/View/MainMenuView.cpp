/*
 * MainMenuView.cpp
 *
 *  Created on: May 3, 2022
 *      Author: luk6xff
 */

#include "MainMenuView.h"

#include "../Button/Buttons.h"
#include "../GUI/LCD/glyphs.h"

//------------------------------------------------------------------------------
namespace view
{

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

//------------------------------------------------------------------------------
MainMenuView::MainMenuView(Display& disp)
	: View(disp)
	, m_hotAirLine(1, 0, "HotAir settings")
	, m_wepLine(1, 1, "WEP settings")
	, m_t12Line(1, 2, "T12 settings")
	, m_aboutLine(1, 3, "About")
{

}


void MainMenuView::init()
{
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

	m_widget.add_screen(m_screen);

	// Set first focus line
	m_widget.switch_focus();

//	m_buttons.button_pressed_short_cb(ButtonType::BUTTON_MENU_RIGHT, [this](){m_menu.switch_focus();});
//	m_buttons.button_pressed_short_cb(ButtonType::BUTTON_MENU_LEFT, [this](){m_menu.switch_focus(false);});
}

//------------------------------------------------------------------------------
void MainMenuView::changeMenu(bool forward)
{
	m_widget.switch_focus(forward);
}

//------------------------------------------------------------------------------
}

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
