#pragma once
#include"map.h"
#include<stdio.h>

#ifndef OPTION_H_
#define OPTION_H_
/**
* \def Define constants.
*/
#define OPTION_ITEM_MAX_SIZE 1000
#define OPTION_NUM_ITEMS 2
#define OPTION_NUM_MAPS 2
#define OPTION_NUM_DIFFICAULTIES 3 

/**
* \enum Define enumeration constants.
*/
typedef enum {
	OPTION_TOP,
	OPTION_DIFFICAULTY,
	OPTION_MAP,
}option_menus_t;

typedef struct option_item{
	char str[OPTION_ITEM_MAX_SIZE];
} option_item_t;

typedef struct option{
	int selector;
	int difficualty_selector;
	int map_selector;
	option_item_t items[OPTION_NUM_ITEMS];
	option_item_t difficaulty_items[OPTION_NUM_DIFFICAULTIES];
	option_item_t map_items[OPTION_NUM_ITEMS];
	option_menus_t option_menu;
	FILE* config_file;
} option_t;

/**
* Function Prototypes.
*/
void pause_game(void);

void user_manual(void);

//void print_option(option* option);

#endif /* OPTION_H_ */

