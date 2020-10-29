/**
 * @file choose_menu_item.c
 * @author Pari
 * @brief Chooses menu items and test it.
 *
 * This file chooses a menu item and test if the function is working.
 */
#include <stdio.h>
#include <assert.h>
#include "menu.h"


/**
 * @brief chooses a menu item.
 *
 * This function choose one of the menu items based on the selector.
 *
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

/**
 * @brief tests choose_menu_item() functions.
 *
 * This is a test function for choose_menu_item() and check if it performs correctly.
 * It has no input.
 *maa
 * @return 0 in success
 */
int test_choose_menu_item() {
	menu_t menu;
	for (int item = 0; item < MENU_ITEM_NUM_OF_ITEMS; item++)
	{
		menu.selector = item;
		choose_menu_item(menu);
	}
	return 0;
}
