/**
 * @file is_player_hit_test.c
 * @author: pari
 * @brief Test file for is_player_hit function.
 *
 * This file contains is_player_hit_test() function.
 */
#include <stdio.h>
#include <assert.h>

#include "map.h"

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




