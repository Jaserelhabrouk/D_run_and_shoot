/**
 * @file shoot_test.c
 * @brief Test file for shoot function.
 */
#include <stdio.h>
#include <assert.h>
#include "../include/map.h"


 /**
  * @brief tests shoot() function .
  *
  * This function tests if shoot() works properly.
  * @return 0 in success.
  */
int shoot_test() {
	map_t map = { 0 };
	/**< Player1 is on the left of player2 */
	map.player[PLAYER_1].current_pos.x = 100;
	map.player[PLAYER_1].current_pos.y = 200;
	map.player[PLAYER_2].current_pos.x = 300;
	map.player[PLAYER_2].current_pos.y = 200;

	shoot(map, 1); /**< Player1 shoots player2 */
	assert(map.bullet[BULLET_1].current_pos.x == 100 && map.bullet[BULLET_1].current_pos.y == 200 && map.bullet[BULLET_1].direction == DIRECTION_RIGHT);
	shoot(map, 1); /**< Player2 shoots player1 */
	assert(map.bullet[BULLET_2].current_pos.x == 300 && map.bullet[BULLET_2].current_pos.y == 200 && map.bullet[BULLET_2].direction == DIRECTION_LEFT);

	return 0;
}




