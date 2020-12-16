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
void shoot(map_t * map, player_index_t player_num) {


	if (player_num == PLAYER_1 && !map->player[PLAYER_1].bullet_is_active && map->player[PLAYER_1].heart != 0) {/**< player1 shoots towards player2*/
		map->player[PLAYER_1].bullet.current_pos.x = map->player[PLAYER_1].current_pos.x;
		map->player[PLAYER_1].bullet.current_pos.y = map->player[PLAYER_1].current_pos.y;
		map->player[PLAYER_1].bullet_is_active = true;

		/**< Defining bullet's direction based on player 2 position*/
		if (map->player[PLAYER_2].current_pos.x > map->player[PLAYER_1].current_pos.x) { /**< player2 is on the right of player1 -> player1 shoots right*/
			map->player[PLAYER_1].bullet.direction = DIRECTION_RIGHT;
			map->player[PLAYER_1].bullet.speed = BULLET_MOVE_STEP_SIZE;
		}
		else { /**< player2 is on the left of player1*/
			map->player[PLAYER_1].bullet.direction = DIRECTION_LEFT;
			map->player[PLAYER_1].bullet.speed = BULLET_MOVE_STEP_SIZE;
		}

	}
	else if(player_num == PLAYER_2 && !map->player[PLAYER_2].bullet_is_active && map->player[PLAYER_2].heart != 0) { /**< player2 shoots towards player1*/
			map->player[PLAYER_2].bullet.current_pos.x = map->player[PLAYER_2].current_pos.x;
			map->player[PLAYER_2].bullet.current_pos.y = map->player[PLAYER_2].current_pos.y;
			map->player[PLAYER_2].bullet_is_active = true;

			/**< Defining bullet's direction based on player 1 position*/
			if (map->player[PLAYER_1].current_pos.x > map->player[PLAYER_2].current_pos.x) { /**< player1 is on the right of player2 -> player2 shoots right*/
				map->player[PLAYER_2].bullet.direction = DIRECTION_RIGHT;
				map->player[PLAYER_2].bullet.speed = BULLET_MOVE_STEP_SIZE;
			}
			else { /**< player1 is on the left of player2*/
				map->player[PLAYER_2].bullet.direction = DIRECTION_LEFT;
				map->player[PLAYER_2].bullet.speed = BULLET_MOVE_STEP_SIZE;
			}
	}
}
