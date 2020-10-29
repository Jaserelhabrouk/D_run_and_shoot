#pragma once
#include<stdio.h>

/**
* \def Define the maximun heart number of a player.
*/
#ifndef HEART
#define HEART 3
#endif
/**
* \def Define the maximun name length of a player.
*/
#ifndef MAX_NAME_SIZE
#define MAX_NAME_SIZE 100
#endif 
/**
* \def Define the maximun number of barriers on a map.
*/
#ifndef MAP_MAX_NUM_OF_BARRIERS
#define MAP_MAX_NUM_OF_BARRIERS 10
#endif
/**
* \def Define the maximun number of arrows on a map.
*/
#ifndef MAP_MAX_NUM_OF_ARROWS
#define MAP_MAX_NUM_OF_ARROWS 20
#endif 
/**
* \def Define the maximun name length of an option item.
*/
#ifndef OPTION_ITEM_MAX_SIZE
#define OPTION_ITEM_MAX_SIZE 1000
#endif 
/**
* \def Define the number of option items.
*/
#ifndef OPTION_NUM_ITEMS
#define OPTION_NUM_ITEMS 2
#endif 
/**
* \def Define the number of maps.
*/
#ifndef OPTION_NUM_MAPS
#define OPTION_NUM_MAPS 2
#endif 
/**
* \def Define the number of difficulties of the game.
*/
#ifndef OPTION_NUM_DIFFICAULTIES
#define OPTION_NUM_DIFFICAULTIES 3
#endif 
/**
* \def Define the step size for barrier movement.
*/
#ifndef STEP_SIZE
#define STEP_SIZE 2
#endif 

/**
* \enum Define enumeration constants.
*/
typedef enum {
	OPTION_TOP,
	OPTION_DIFFICAULTY,
	OPTION_MAP,
}option_menus;

typedef enum {
	DIRECTION_RIGHT,
	DIRECTION_LEFT,
	DIRECTION_UP,
	DIRECTION_DOWN
} direction;

typedef enum {
	SPEED_LOW,
	SPEED_NORMAL,
	SPEED_HIGH,
} speed;

/**
* \struct Define relevant structures.
*/
typedef struct tag_position {
	int x;
	int y;
} position;

typedef struct tag_player{
	char name[MAX_NAME_SIZE];
	position current_pos;
	int heart;
} player;

typedef struct tag_option_item{
	char str[OPTION_ITEM_MAX_SIZE];
} option_item;

typedef struct tag_option{
	int selector;
	int difficualty_selector;
	int map_selector;
	option_item items[OPTION_NUM_ITEMS];
	option_item difficaulty_items[OPTION_NUM_DIFFICAULTIES];
	option_item map_items[OPTION_NUM_ITEMS];
	option_menus option_menu;
	FILE* config_file;
} Option;

typedef struct tag_map_space {
	int xMin;
	int xMax;
	int yMin;
	int yMax;
} map_space;

typedef struct tag_map_barrier {
	position current_pos;
	int length;
	direction currect_dir;
} map_barrier;

typedef struct tag_map_arrow {
	position current_pos;
	speed spd;
} map_arrow;

typedef struct tag_goal{
	position goal;
} goal;

typedef struct tag_map{
	map_space space;
	int number_of_barriers;
	int number_of_arrows;
	map_barrier barrier[MAP_MAX_NUM_OF_BARRIERS];
	map_arrow arrow[MAP_MAX_NUM_OF_ARROWS];
	goal gl;
	player pl;
} map;

/**
* Function Prototypes.
*/
void update_barrier(map_barrier*, map_space);

void update_view(map);

void pause_game(void);

void user_manual(void);


void take_heart(player*);

//void multi_player(void);

//void print_option(option* option);



