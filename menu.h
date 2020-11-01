/**
 * @file menu.h
 * @author Jaser El-Habrouk
 * @brief decleration of the menu
 *
 * Function decleration and type definition for the game's menu.
 */

#ifndef MENU_H_
#define MENU_H_

#define MAX_ITEM_SIZE 100      /**< maximum legth of menu item*/
#define TRUE 1
#define FALSE 0

/**
 * @enum menu_items_t
 * The enumeration of menu items.
 */
typedef enum menu_items_t {
	MENU_ITEM_USER_MANUAL,
	MENU_ITEM_SINGLE_PLAYER,
	MENU_ITEM_MULTI_PLAYER,
	MENU_ITEM_OPTION,
	MENU_ITEM_CREDIT,
	MENU_ITEM_EXIT,
	MENU_ITEM_NUM_OF_ITEMS
} menu_items_t;

/**
 * @typedef item_t
 * A structure represents items' name.
 */
typedef struct item_t {
	char str[MAX_ITEM_SIZE];    /**< the name of the item in the menu*/
} item_t;

/**
 * @typedef menu_t
 * A structure represents menu item.
 */
typedef struct menu_t {
	menu_items_t selector;
	item_t items[MENU_ITEM_NUM_OF_ITEMS ];
} menu_t;

#endif /* MENU_H_ */