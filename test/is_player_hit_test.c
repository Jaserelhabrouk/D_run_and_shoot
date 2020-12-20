/**
 * @file is_player_hit_test.c
 * @brief Test file for is_player_hit function.
 */
#include <stdio.h>
#include <assert.h>
#include "../include/map.h"
#include "../include/single_player.h"

/**
 * @brief tests is_player_hit() function .
 *
 * This function tests if is_player_hit() works properly.
 * @return 0 in success.
 */
int is_player_hit_test() {
	map_t map = {0};
	map.number_of_arrows = 1;
	map.player[PLAYER_1].current_pos.x = 500;
	map.player[PLAYER_1].current_pos.y = 400;
	map.arrow[0].current_pos.x = 500;
	map.arrow[0].current_pos.y = 400;
	int is_hit = is_player_hit(&map, PLAYER_1);
	assert(is_hit == 1);
	map.arrow[0].current_pos.x = 200;
	map.arrow[0].current_pos.y = 300;
	is_hit = is_player_hit(&map, PLAYER_1);
	assert(is_hit == 0);

	printf("is_player_hit_test PASSED\n");
	return 0;
}

int main() {
	return is_player_hit_test();
}
