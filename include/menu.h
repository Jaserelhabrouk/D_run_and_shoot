/**
 * @file menu.h
 * \brief decleration of the menu
 *
 * Function decleration and type definition for the game's menu.
 */

#ifndef MENU_H_
#define MENU_H_

#include <SDL2/SDL.h>

#define MAX_ITEM_SIZE 100      /**< maximum legth of menu item*/

/**
 * @enum menu_items_t
 * The enumeration of menu items.
 */
typedef enum menu_items {
	MENU_ITEM_USER_MANUAL,
	MENU_ITEM_SINGLE_PLAYER,
	MENU_ITEM_CREDIT,
	MENU_ITEM_EXIT,
	MENU_ITEM_NUM_OF_ITEMS
} menu_items_t;


/**
 * @typedef item_t
 * A structure represents items' name.
 */
typedef struct item {
	char str[MAX_ITEM_SIZE];    /**< the name of the item in the menu*/
} item_t;

/**
 * @typedef menu_t
 * A structure represents menu item.
 */
typedef struct menu {
	menu_items_t selector;
	item_t items[MENU_ITEM_NUM_OF_ITEMS ];
} menu_t;

/**
 * \brief chooses a menu item.
 *
 * This function choose one of the menu items based on the selector.
 * @param [in] menu which is a structure.
 * @return void.
 */
void choose_menu_item(menu_t menu);
void print_menu(SDL_Window* p_window, menu_t* p_menu);


#endif /* MENU_H_ */
