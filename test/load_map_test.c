/**
 * @file load_map_test.c
 * @brief A testcase to check if load_map() works properly.
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../include/map.h"

/**
 * @brief load_map_test() function.
 *
 * This is the test function for load_map(). It has no input or output variable.
 * This function creates a map_file and defines the map requirements into that.
 * Then checks if load_map() file works correctly.
 *
 * @return 0 in success.
 */
int load_map_test(){

	char file_path[1000] = "../data/test_file.txt";
	FILE* map_file = fopen((const char*)file_path, "w");
	fprintf(map_file,
			"space = 0 1000 0 1000\n"
			"goal = 50 50\n"
	        "number_of_players = 1\n"
			"player = 900 500 3\n"
			"number_of_barriers = 2\n"
			"barrier = 250 200 300 0\n"
			"barrier = 500 400 300 0\n"
			"number_of_arrows = 5\n"
			"arrow = 100 0 1 3\n"
			"arrow = 300 0 1 3\n"
			"arrow = 500 0 1 3\n"
			"arrow = 700 0 1 3\n"
			"arrow = 900 0 1 3\n");
	fclose(map_file);

	map_t map = load_map(file_path);

	assert(map.space.x_min == 0 && map.space.x_max == 1000);
	assert(map.space.y_min == 0 && map.space.y_max == 1000);
	assert(map.number_of_barriers == 2);
	assert(map.barrier[0].current_pos.x == 250 && map.barrier[0].current_pos.y == 200);
	assert(map.barrier[1].current_pos.x == 500 && map.barrier[1].current_pos.y == 400);
	assert(map.barrier[0].current_dir == 0 && map.barrier[0].length == 300);
	assert(map.barrier[1].current_dir == 0 && map.barrier[0].length == 300);
	assert(map.number_of_arrows == 5);
	assert(map.arrow[0].current_pos.x == 100 && map.arrow[0].current_pos.y == 0);
	assert(map.arrow[0].speed == 1 && map.arrow[0].direction == 3);
	assert(map.arrow[1].current_pos.x == 300 && map.arrow[1].current_pos.y == 0);
	assert(map.arrow[1].speed == 1 && map.arrow[1].direction == 3);
	assert(map.arrow[2].current_pos.x == 500 && map.arrow[2].current_pos.y == 0);
	assert(map.arrow[2].speed == 1 && map.arrow[2].direction == 3);
	assert(map.arrow[3].current_pos.x == 700 && map.arrow[3].current_pos.y == 0);
	assert(map.arrow[3].speed == 1 && map.arrow[3].direction == 3);
	assert(map.arrow[4].current_pos.x == 900 && map.arrow[4].current_pos.y == 0);
	assert(map.arrow[4].speed == 1 && map.arrow[4].direction == 3);
	assert(map.goal.pos.x == 50 && map.goal.pos.y == 50);
	assert(map.number_of_players == 1);
	assert(map.player[PLAYER_1].current_pos.x == 900 && map.player[PLAYER_1].current_pos.y == 500);
	assert(map.player[PLAYER_1].heart == 3);

	printf("load_map_test PASSED\n");
	return 0;
}


