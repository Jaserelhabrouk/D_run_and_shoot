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
void update_bullet(map_t* map) {

	if (map->bullet[BULLET_1].speed != 0) { /**< We have a moving bullet shooted from player1*/
		switch (map->bullet[BULLET_1].direction)
		{
		case DIRECTION_RIGHT:
			if (map->bullet[BULLET_1].current_pos.x <= map->space.x_max)
			{
				map->bullet[BULLET_1].current_pos.x += map->bullet[BULLET_1].speed;
			}
			else {
				map->bullet[BULLET_1].current_pos.x = 10000000;
				map->bullet[BULLET_1].current_pos.y = 10000000;
				map->bullet[BULLET_1].speed = 0;
			}

			break;

		case DIRECTION_LEFT:
			if (map->bullet[BULLET_1].current_pos.x >= map->space.x_min)
			{
				map->bullet[BULLET_1].current_pos.x -= map->bullet[BULLET_1].speed;
			}
			else {
				map->bullet[BULLET_1].current_pos.x = 10000000;
				map->bullet[BULLET_1].current_pos.y = 10000000;
				map->bullet[BULLET_1].speed = 0;
			}

			break;

		default:
			break;
		}
	} else if (map->bullet[BULLET_2].speed != 0) { /**< We have a moving bullet shooted from player2*/
		switch (map->bullet[BULLET_2].direction)
		{
		case DIRECTION_RIGHT:
			if (map->bullet[BULLET_2].current_pos.x <= map->space.x_max)
			{
				map->bullet[BULLET_2].current_pos.x += map->bullet[BULLET_2].speed;
			}
			else {
				map->bullet[BULLET_2].current_pos.x = 10000000;
				map->bullet[BULLET_2].current_pos.y = 10000000;
				map->bullet[BULLET_2].speed = 0;
			}

			break;

		case DIRECTION_LEFT:
			if (map->bullet[BULLET_2].current_pos.x >= map->space.x_min)
			{
				map->bullet[BULLET_2].current_pos.x -= map->bullet[BULLET_1].speed;
			}
			else {
				map->bullet[BULLET_2].current_pos.x = 10000000;
				map->bullet[BULLET_2].current_pos.y = 10000000;
				map->bullet[BULLET_2].speed = 0;
			}

			break;

		default:
			break;
		}
	}
}