#pragma once
#include<stdio.h>

#ifndef COMMON_H_
#define COMMON_H_
/**
* \def Define the maximum heart number of a player.
*/
#define HEART 3
/**
* \def Define the maximum name length of a player.
*/
#define MAX_NAME_SIZE 100
/**
* \def Define the maximum number of barriers on a map.
*/
#define MAP_MAX_NUM_OF_BARRIERS 10
/**
* \def Define the maximum number of arrows on a map.
*/
#define MAP_MAX_NUM_OF_ARROWS 20
/**
* \def Define the maximum name length of an option item.
*/
#define OPTION_ITEM_MAX_SIZE 1000
/**
* \def Define the number of option items.
*/
#define OPTION_NUM_ITEMS 2
/**
* \def Define the number of maps.
*/
#define OPTION_NUM_MAPS 2
/**
* \def Define the number of difficulties of the game.
*/
#define OPTION_NUM_DIFFICAULTIES 3 
/**
* \def Define the step size for barrier movement.
*/
#define STEP_SIZE 2

/**
* \enum Define enumeration constants.
*/
typedef enum {
	OPTION_TOP,
	OPTION_DIFFICAULTY,
	OPTION_MAP,
}option_menus_t;

typedef enum {
	DIRECTION_RIGHT,
	DIRECTION_LEFT,
	DIRECTION_UP,
	DIRECTION_DOWN
} direction_t;

typedef enum {
	SPEED_LOW,
	SPEED_NORMAL,
	SPEED_HIGH,
} speed_t;

/**
* \struct Define relevant structures.
*/
typedef struct position {
	int x;
	int y;
} position_t;

typedef struct player{
	char name[MAX_NAME_SIZE];
	position_t current_pos;
	int heart;
} player_t;

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

typedef struct map_space {
	int x_min;
	int x_max;
	int y_min;
	int y_max;
} map_space_t;

typedef struct map_barrier {
	position_t current_pos;
	int length;
	direction_t currect_dir;
} map_barrier_t;

typedef struct map_arrow {
	position_t current_pos;
	speed_t spd;
} map_arrow_t;

typedef struct goal{
	position_t goal;
} goal_t;

typedef struct map{
	map_space_t space;
	int number_of_barriers;
	int number_of_arrows;
	map_barrier_t barrier[MAP_MAX_NUM_OF_BARRIERS];
	map_arrow_t arrow[MAP_MAX_NUM_OF_ARROWS];
	goal_t gl;
	player_t pl;
} map_t;

/**
* Function Prototypes.
*/
void update_barrier(map_barrier_t*, map_space_t);

void update_view(map);

void pause_game(void);

void user_manual(void);


void take_heart(player_t*);

//void multi_player(void);

//void print_option(option* option);

#endif /* COMMON_H_ */

