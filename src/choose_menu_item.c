/**
 * @file choose_menu_item.c
 * \brief Chooses menu items and test it.
 *
 * This file chooses a menu item and test if the function is working.
 */
#include <stdio.h>
#include <assert.h>
#include "menu.h"


void user_manual() {
	/*TODO*/
}

void single_player() {
	/*TODO*/
}

void credit() {
	/*TODO*/
}

void exit_game() {
	/*TODO*/
}
/**
 * \brief chooses a menu item.
 *
 * This function choose one of the menu items based on the selector.
 * @param [in] menu which is a structure.
 * @return void.
 */
void choose_menu_item(menu_t menu) {
	switch (menu.selector)
	{
		case MENU_ITEM_USER_MANUAL:
			user_manual();
			break;
		case MENU_ITEM_SINGLE_PLAYER:
			single_player();
			break;
		case MENU_ITEM_CREDIT:
			credit();
			break;
		case MENU_ITEM_EXIT:
			exit_game();
			break;
		default:
			assert(FALSE);
			break;
	}
}


