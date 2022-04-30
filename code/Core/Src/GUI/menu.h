/*
 * menu.h
 *
 *  Created on: Apr 29, 2022
 *      Author: luk6xff
 */

#ifndef SRC_GUI_MENU_H_
#define SRC_GUI_MENU_H_

#include <Buttons/buttons.h>

typedef struct MenuItem
{
	char *title;
	void (*btn_handle_callbacks[BUTTONS_NUMBER])();
	struct MenuItem *submenu;
} MenuItem;


void menu_init();

void menu_draw();

void menu_draw_title_bar();


#endif /* SRC_GUI_MENU_H_ */
