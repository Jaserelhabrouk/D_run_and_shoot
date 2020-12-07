#pragma once
#include"map.h"
#include<stdio.h>




#ifdef _WIN64
#include <SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif


#ifndef OPTION_H_
#define OPTION_H_
/**
* \def Define constants.
*/
#define OPTION_ITEM_MAX_SIZE 1000
#define OPTION_NUM_ITEMS 2
#define OPTION_NUM_MAPS 2
#define OPTION_NUM_DIFFICULTIES 3 



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
 * @typedef item_t
 * A structure represents items' name.
 */
typedef struct item{
	char str[OPTION_ITEM_MAX_SIZE];
	char *map_file_path;
} item_t;

/**
 * @typedef option_t
 * A structure represents option item.
 */
typedef struct option{
	option_items_t selector;
	item_t items[OPTION_ITEM_NUM_OF_ITEMS];
} option_t;


/**
* @brief Prints the game options menu on SDL window.
* @param[in] p_window A SDL window is passed to the function.
* @param[in] p_option A structure represents option item.
* @return void
*/
void print_options(SDL_Window* p_window, option_t* p_option);


#endif /* OPTION_H_ */

