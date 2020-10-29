/**
 * @file map.h
 * @author Pari
 * @brief decleration of the map
 *
 * Function decleration and type definition for the game's map.
 */
#ifndef MAP_H_
#define MAP_H_

#define MAP_MAX_NUM_OF_BARRIERS 10
#define MAP_MAX_NUM_OF_ARROWS 20

/**
 * @typedef position_t
 * A structure represents the position.
 */
typedef struct position {
	int x;             /**< position in x coordinate */
	int y;             /**< position in y coordinate */
} position_t;

/**
 * @enum direction_t
 * The enumeration of movement direction.
 */
typedef enum direction {
	DIRECTION_RIGHT,
	DIRECTION_LEFT,
	DIRECTION_UP,
	DIRECTION_DOWN
} direction_t;

/**
 * @enum speed_t
 * The enumeration of speed level.
 */
typedef enum speed {
	SPEED_LOW,
	SPEED_NORMAL,
	SPEED_HIGH,
} speed_t;

/**
 * @typedef map_space_t
 * A structure represents the space which map is defined in it.
 */
typedef struct map_space {
	int x_min;
	int x_max;
	int y_min;
	int y_max;
} map_space_t;

/**
 * @typedef map_barrier_t
 * A structure represents the a barrier in the map.
 */
typedef struct map_barrier {
	position_t current_pos;     /**< current position of a barrier*/
	int length;                 /**< length of a barrier*/
	direction_t current_dir;    /**< current direction of a barrier*/
} map_barrier_t;

/**
 * @typedef arrow_t
 * A structure represents an arrow in the map
 */
typedef struct arrow {
	position_t current_pos;    /**< current position of an arrow*/
	speed_t speed;             /**< the speed of an arrow*/
	direction_t direction;     /**< direction of an arrow*/
} arrow_t;

/**
 * @typedef player_t
 * A structure represents a player in the map
 */
typedef struct player {
	char name;                 /**< name of the player*/
	position_t current_pos;    /**< current position of the player*/
	int heart;                 /**< number of the heart the player have*/
} player_t;

/**
 * @typedef goal_t
 * A structure represents the goal in the map
 */
typedef struct goal {
	position_t pos;         /**< position of the goal in the map*/
} goal_t;

/**
 * @typedef map_t
 * A structure represents the map
 */
typedef struct map {
	map_space_t space;                                 /**< space of the map*/
	int number_of_barriers;                            /**< number of barriers in the map*/
	int number_of_arrows;                              /**< number of arrows in the map*/
	map_barrier_t barrier[MAP_MAX_NUM_OF_BARRIERS];    /**< barries in the map*/
	arrow_t arrow[MAP_MAX_NUM_OF_ARROWS];              /**< arrows in the map*/
	goal_t goal;                                       /**< goal in the map*/
	player_t player;                                   /**< player in the map*/
} map_t;

#endif /* MAP_H_ */

