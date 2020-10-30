/**
 * @file is_player_hit.c
 * @author: pari
 * @brief Checks if the player is hit and its test function
 *
 * This file contains is_player_hit() function and its test() function.
 */
#include <stdio.h>
#include <assert.h>

#include "map.h"


/**
 * @brief Checks if the player is hit.
 *
 * This function checks if the player is hit by an arrow.
 * @param [in] player represent the player structure.
 * @param [in] arrow represenr an arrow structure.
 * @return flag if the player is hit, flag = 1, otherwise flag = 0.
 */
int is_player_hit(map_t* map) {
	int flag = 0;
	for (int i = 0; i < map->number_of_arrows; i++) {
		if (map->player.current_pos.x == map->arrow[i].current_pos.x &&
		    map->player.current_pos.y == map->arrow[i].current_pos.y) {
			flag = 1;
			break;
		}
	}
	return flag;
}

/**
 * @brief tests is_player_hit() function .
 *
 * This function tests if is_player_hit() works properly.
 * @return 0 in success.
 */
int test_is_player_hit() {
	map_t map = {0};
	map.number_of_arrows = 1;
	map.player.current_pos.x = 500;
	map.player.current_pos.y = 400;
	map.arrow[0].current_pos.x = 500;
	map.arrow[0].current_pos.y = 400;
	int is_hit = is_player_hit(&map);
	assert(is_hit == 1);
	map.arrow[0].current_pos.x = 200;
	map.arrow[0].current_pos.y = 300;
	is_hit = is_player_hit(&map);
	assert(is_hit == 0);
	return 0;
}




