/**
 * @file menu.h
 * @brief decleration of the menu related variables.
 *
 * Function decleration and type definition for the game's menu.
 */

#ifndef MENU_H_
#define MENU_H_

#ifdef _WIN64
#include <SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif

#include <stdbool.h>

#define MAX_ITEM_SIZE 100              /**< maximum legth of menu item*/

/**
 * @enum menu_items_t
 * The enumeration of menu items.
 */
typedef enum menu_items {
	MENU_ITEM_USER_MANUAL,
	MENU_ITEM_SINGLE_PLAYER,
	MENU_ITEM_MULTI_PLAYER,
	MENU_ITEM_OPTIONS,
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
 * @enum options_items_t
 * The enumeration of option items.
 */
typedef enum option_items{
    OPTION_ITEM_EASY,
    OPTION_ITEM_INTERMEDIATE,
    OPTION_ITEM_HARD,
    OPTION_ITEM_NUM_OF_ITEMS,
}option_items_t;

/**
 * @typedef option_t
 * A structure represents option's item.
 */
typedef struct option{
    option_items_t selector;
    item_t items[OPTION_ITEM_NUM_OF_ITEMS];
} option_t;

/**
 * @brief Prints user manual on an input window.
 * @param[in] p_window a SDL window which is passed from the main function.
 * @return bool if window is quit or back_space key is pressed, return true.
 */
bool user_manual(SDL_Window* p_window);

/**
 * @brief single_player function
 *
 * This is the main function which handle single player mode.
 * Different functions are called here: first a map file is loaded and then
 * according to the input key different entities is updated and a view will be generated.
 * A timer is initialized to update every thing in each TIMER_INTERVAL seconds.
 * @param[in] p_window a SDL window which is passed from the main function.
 * @param[in] difficulty game difficulty specify the map file that should be loaded.
 * @return bool if window is quit or back_space key is pressed, return true.
 */
bool single_player(SDL_Window* p_window, option_items_t difficulty);

/**
 * @brief multi_player function
 *
 * This is the main function which handle multi player mode.
 * Different functions are called here: first a map file is loaded and then
 * according to the input key different entities is updated and a view will be generated.
 * A timer is initialized to update every thing in each TIMER_INTERVAL seconds.
 * @param[in] p_window a SDL window which is passed from the main function.
 * @param[in] difficulty game difficulty specify the map file that should be loaded.
 * @return bool if window is quit or back_space key is pressed, return true.
 */
bool multi_player(SDL_Window* p_window,option_items_t difficulty);

/**
* @brief Handles user input to choose between difficulty levels.
*
* This function show you different level of difficulty and let
* user to choose between difficulty levels using return/enter key.
*
* @param[in] p_window A SDL window is passed to the function.
* @param[out] p_option_items final selected item.
* @return bool if window is quit or back_space key is pressed, return true.
*/
bool options(SDL_Window* p_window, option_items_t* p_option_items);

/**
 * @brief Prints Credits Information on the input window.
 *
 * @param[in] p_window a SDL window which is passed from the main function.
 * @return bool if window is quit or back_space key is pressed, return true.
 */
bool credit(SDL_Window* p_window);

/**
* @brief Prints the game start up menu on an input SDL window.
*
* @param[in] p_window A SDL window is passed to the function.
* @param[in] p_menu A structure represents menu items.
* @return void
*/
void print_menu(SDL_Window* p_window, menu_t* p_menu);

/**
* @brief Prints the game different difficulty options on an SDL window.
* @param[in] p_window A SDL window is passed to the function.
* @param[in] p_options A structure represents options item.
* @return void
*/
void print_options(SDL_Window* p_window, option_t* p_options);

#endif /* MENU_H_ */
