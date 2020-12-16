/**
 * @file update_bullet.c
 * @author Mahsa
 * @brief updates bullet position
 */
#include <stdio.h>
#include <assert.h>
#include "../include/map.h"
#include "../include/single_player.h"

 /**
  * @brief updates the position of generated bullet
  *
  * This function shoot a bullet in a direction in which an oppenent exists.
  * @param [in] map represent the map structure which has bullet's position and direction.
  */
void update_bullet(map_t* map , player_index_t player_num) {

	if (player_num == PLAYER_1 && map->player[PLAYER_1].bullet_is_active) { /**< We have a moving bullet shooted from player1*/
		switch (map->player[PLAYER_1].bullet.direction)
		{
		case DIRECTION_RIGHT:
			if (map->player[PLAYER_1].bullet.current_pos.x <= map->space.x_max)
			{
				map->player[PLAYER_1].bullet.current_pos.x += map->player[PLAYER_1].bullet.speed;
			}
			else {
				map->player[PLAYER_1].bullet.current_pos.x = 10000;
				map->player[PLAYER_1].bullet.current_pos.y = 10000;
				map->player[PLAYER_1].bullet_is_active = false;
				map->player[PLAYER_1].bullet.speed = 0;
			}

			break;

		case DIRECTION_LEFT:
			if (map->player[PLAYER_1].bullet.current_pos.x >= map->space.x_min)
			{
				map->player[PLAYER_1].bullet.current_pos.x -= map->player[PLAYER_1].bullet.speed;
			}
			else {
				map->player[PLAYER_1].bullet.current_pos.x = 10000;
				map->player[PLAYER_1].bullet.current_pos.y = 10000;
				map->player[PLAYER_1].bullet_is_active = false;
				map->player[PLAYER_1].bullet.speed = 0;
			}

			break;

		default:
			break;
		}
	} else if (player_num == PLAYER_2 && map->player[PLAYER_2].bullet_is_active) { /**< We have a moving bullet shooted from player2*/
		switch (map->player[PLAYER_2].bullet.direction)
		{
		case DIRECTION_RIGHT:
			if (map->player[PLAYER_2].bullet.current_pos.x <= map->space.x_max)
			{
				map->player[PLAYER_2].bullet.current_pos.x += map->player[PLAYER_2].bullet.speed;
			}
			else {
				map->player[PLAYER_2].bullet.current_pos.x = 10000;
				map->player[PLAYER_2].bullet.current_pos.y = 10000;
				map->player[PLAYER_2].bullet_is_active = false;
				map->player[PLAYER_2].bullet.speed = 0;
			}

			break;

		case DIRECTION_LEFT:
			if (map->player[PLAYER_2].bullet.current_pos.x >= map->space.x_min)
			{
				map->player[PLAYER_2].bullet.current_pos.x -= map->player[PLAYER_2].bullet.speed;
			}
			else {
				map->player[PLAYER_2].bullet.current_pos.x = 10000;
				map->player[PLAYER_2].bullet.current_pos.y = 10000;
				map->player[PLAYER_2].bullet_is_active = false;
				map->player[PLAYER_2].bullet.speed = 0;
			}

			break;

		default:
			break;
		}
	}
}