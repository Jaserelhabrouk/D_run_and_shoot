/**
 * @file choose_menu_item_test.c
 * \brief A testcase to check if choose_menu_item() works correctly.
 */
#include <stdio.h>
#include <assert.h>
#include "menu.h"

/**
 * \brief tests choose_menu_item() function.
 *
 * This is a test function for choose_menu_item() and check if it performs correctly.
 * It has no input.
 * @return 0 in success
 */
int choose_menu_item_test() {
	menu_t menu;
	for (int item = 0; item < MENU_ITEM_NUM_OF_ITEMS; item++)
	{
		menu.selector = item;
		choose_menu_item(menu);
	}
	return 0;
}



