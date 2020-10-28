#pragma once
#include<stdio.h>

/**
* \def Define constants.
*/
#define HEART 3
#define MAX_NAME_SIZE 100
#define MAP_MAX_NUM_OF_BARRIERS 10
#define MAP_MAX_NUM_OF_ARROWS 20
#define OPTION_ITEM_MAX_SIZE 1000
#define OPTION_NUM_ITEMS 2
#define OPTION_NUM_MAPS 2
#define OPTION_NUM_DIFFICAULTIES 3
#define STEP_SIZE 2

/**
* \enum Define enumeration constants.
*/
typedef enum {
	OPTION_TOP,
	OPTION_DIFFICAULTY,
	OPTION_MAP,
} OptionMenues;

typedef enum {
	DIRECTION_RIGHT,
	DIRECTION_LEFT,
	DIRECTION_UP,
	DIRECTION_DOWN
} Direction;

typedef enum {
	SPEED_LOW,
	SPEED_NORMAL,
	SPEED_HIGH,
} Speed;

/**
* \struct Define relevant structures.
*/
typedef struct tagPosition {
	int x;
	int y;
} Position;

typedef struct tagPlayer{
	char name[MAX_NAME_SIZE];
	Position currentPos;
	int heart;
} Player;

typedef struct tagOptionItem{
	char str[OPTION_ITEM_MAX_SIZE];
} OptionItem;

typedef struct tagOption{
	int selector;
	int difficualtySelector;
	int mapSelector;
	OptionItem items[OPTION_NUM_ITEMS];
	OptionItem difficaultyItems[OPTION_NUM_DIFFICAULTIES];
	OptionItem mapItems[OPTION_NUM_ITEMS];
	OptionMenues optionMenu;
	FILE* configFile;
} Option;

typedef struct tagMapSpace {
	int xMin;
	int xMax;
	int yMin;
	int yMax;
} MapSpace;

typedef struct tagMapBarrier {
	Position currentPos;
	int length;
	Direction currectDir;
} MapBarrier;

typedef struct tagMapArrow {
	Position currentPos;
	Speed speed;
} MapArrow;

typedef struct tagGoal{
	Position goal;
} Goal;

typedef struct tagMap{
	MapSpace space;
	int numberOfBarriers;
	int numberOfArrows;
	MapBarrier barrier[MAP_MAX_NUM_OF_BARRIERS];
	MapArrow arrow[MAP_MAX_NUM_OF_ARROWS];
	Goal goal;
	Player player;
} Map;

/**
* Function Prototypes.
*/
void updateBarrier(MapBarrier* barrier, MapSpace space);

void updateView(Map map);

void pauseGame(void);

void userManual(void);


void takeHeart(Player* player);

//void multiPlayer(void);

//void printOption(Option* option);



