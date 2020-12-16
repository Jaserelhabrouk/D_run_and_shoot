/**
 * @file is_bullet_hit.c
 * @brief Checks if the player is hit a bullet.
 */
#include <stdio.h>
#include <assert.h>
#include "../include/map.h"
#include "../include/multi_player.h"
#include "../include/map_textures.h"

 /**
  * @brief Checks if the the player is hit a bullet.
  *
  * This function checks if the player is hit by oppent's bullet.
  * @param [in] map represent the map structure which has player position and bullets' positions.
  * @param [in] player_index  can be PLAYER1 or PLAYER2.
  * @return flag if the player is hit, flag = 1, otherwise flag = 0.
  */

int is_bullet_hit(map_t* map, player_index_t player_index) {

	int flag = 0;

	if (player_index == PLAYER_1) {
		if (map->player[PLAYER_2].bullet_is_active) {

			if (map->player[PLAYER_1].current_pos.y <= map->player[PLAYER_2].bullet.current_pos.y &&
				map->player[PLAYER_1].current_pos.y + MAP_TEXTURE_PLAYER_HEIGHT > map->player[PLAYER_2].bullet.current_pos.y &&
				map->player[PLAYER_1].current_pos.x > map->player[PLAYER_2].bullet.current_pos.x - BULLET_MOVE_STEP_SIZE &&
				map->player[PLAYER_1].current_pos.x <= map->player[PLAYER_2].bullet.current_pos.x) {

				flag = 1;
			}

		}

	}
	else if (player_index == PLAYER_2) {
		if (map->player[PLAYER_1].bullet_is_active) {

			if (map->player[PLAYER_2].current_pos.y <= map->player[PLAYER_1].bullet.current_pos.y &&
				map->player[PLAYER_2].current_pos.y + MAP_TEXTURE_PLAYER_HEIGHT > map->player[PLAYER_1].bullet.current_pos.y &&
				map->player[PLAYER_2].current_pos.x > map->player[PLAYER_1].bullet.current_pos.x - BULLET_MOVE_STEP_SIZE &&
				map->player[PLAYER_2].current_pos.x <= map->player[PLAYER_1].bullet.current_pos.x) {

				flag = 1;
			}

		}
	}

	return flag;

}
