/**
 * @file is_player_hit.c
 * @author: pari
 * @brief Checks if the player is hit.
 *
 * This file contains is_player_hit() function.
 */
#include <stdio.h>
#include <assert.h>

#include "map.h"


/**
 * @brief Checks if the player is hit.
 *
 * This function checks if the player is hit by an arrow.
 * @param [in] map represent the map structure which has player position and arrows' positions.
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





