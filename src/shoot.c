/**
 * @file shoot.c
 * @author Mahsa
 * @brief shoots a bullet towards opponent
 */
#include <stdio.h>
#include <assert.h>
#include "../include/map.h"
#include "../include/single_player.h"

 /**
  * @brief Generates a bullet
  *
  * This function generate a bullet in the player's current position and give it proper speed and direction. 
  * Bullet1 is shooted from player1 and Bullet2 is shooted from player2
  * @param [in] map represent the map structure which has players' position.
  */

void shoot(map_t * map, int player_num) { 


	if (player_num == 1 && map->bullet[BULLET_1].speed == 0) {/**< player1 shoots towards player2*/
		map->bullet[BULLET_1].current_pos.x = map->player[PLAYER_1].current_pos.x;
		map->bullet[BULLET_1].current_pos.y = map->player[PLAYER_1].current_pos.y;

		/**< Defining bullet's direction based on player 2 position*/

		if (map->player[PLAYER_2].current_pos.x > map->player[PLAYER_1].current_pos.x) { /**< player2 is on the right of player1*/
			map->bullet[BULLET_1].direction = DIRECTION_RIGHT;
			map->bullet[BULLET_1].speed = BULLET_MOVE_STEP_SIZE;
		}
		else { /**< player2 is on the left of player1*/
			map->bullet[BULLET_1].direction = DIRECTION_LEFT;
			map->bullet[BULLET_1].speed = BULLET_MOVE_STEP_SIZE;
		}

	}
	else { /**< player2 shoots towards player1*/
		if (map->bullet[BULLET_2].speed == 0) { /**< If we don't have any existing bullet already, it generates a bullet2*/
			map->bullet[BULLET_2].current_pos.x = map->player[PLAYER_2].current_pos.x;
			map->bullet[BULLET_2].current_pos.y = map->player[PLAYER_2].current_pos.y;

			/**< Defining bullet's direction based on player 1 position*/

			if (map->player[PLAYER_1].current_pos.x > map->player[PLAYER_2].current_pos.x) { /**< player1 is on the right of player2*/
				map->bullet[BULLET_2].direction = DIRECTION_RIGHT;
				map->bullet[BULLET_2].speed = BULLET_MOVE_STEP_SIZE;
			}
			else { /**< player1 is on the left of player2*/
				map->bullet[BULLET_2].direction = DIRECTION_LEFT;
				map->bullet[BULLET_2].speed = BULLET_MOVE_STEP_SIZE;
			}
		}
	}
	

}
