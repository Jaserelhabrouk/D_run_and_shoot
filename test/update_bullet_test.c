/**
 * @file update_bullet_test.c
 * @brief Test file for update_bullet function.
 */
#include <stdio.h>
#include <assert.h>
#include "../include/map.h"


 /**
  * @brief tests update_bullet() function .
  *
  * This function tests if update_bullet() works properly.
  * @return 0 in success.
  */
int update_bullet_test() {
	map_t map = { 0 };
	
	map.bullet[BULLET_1].current_pos.x = 100;
	map.bullet[BULLET_1].current_pos.y = 200;
	map.bullet[BULLET_1].direction = DIRECTION_RIGHT;
	map.bullet[BULLET_2].current_pos.x = 300;
	map.bullet[BULLET_2].current_pos.y = 200;
	map.bullet[BULLET_2].direction = DIRECTION_LEFT;

	update_bullet(map);
	assert(map.bullet[BULLET_1].current_pos.x == 104 && map.bullet[BULLET_2].current_pos.x == 296);

	return 0;
}




