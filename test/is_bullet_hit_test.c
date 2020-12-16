/**
 * @file is_bullet_hit_test.c
 * @brief Test file for is_bullet_hit function.
 */
#include <stdio.h>
#include <assert.h>
#include "../include/map.h"


 /**
  * @brief tests is_bullet_hit() function .
  *
  * This function tests if is_bullet_hit() works properly.
  * @return 0 in success.
  */

int is_bullet_hit_test() {
	map_t map = { 0 };

	map.player[PLAYER_1].bullet.current_pos.x = 100;
	map.player[PLAYER_1].bullet.current_pos.y = 200;
	map.player[PLAYER_1].bullet.direction = DIRECTION_RIGHT;
	map.player[PLAYER_1].bullet_is_active = true;
	map.player[PLAYER_2].bullet.current_pos.x = 104;
	map.player[PLAYER_2].bullet.current_pos.y = 200;
	map.player[PLAYER_2].bullet.direction = DIRECTION_LEFT;
	map.player[PLAYER_2].bullet_is_active = true;

	is_bullet_hit(map, PLAYER_2);
	assert(map.player[PLAYER_1].bullet.current_pos.x == map.player[PLAYER_2].current_pos.x);

	map.player[PLAYER_1].bullet.current_pos.x = 196;
	map.player[PLAYER_2].bullet.current_pos.x = 200;

	is_bullet_hit(map, PLAYER_1);

	assert(map.player[PLAYER_2].bullet.current_pos.x == map.player[PLAYER_1].current_pos.x);


	return 0;
}




