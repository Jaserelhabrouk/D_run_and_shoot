/**
 * @file load_map.c
 * @author Pari
 * @brief Loads the map.
 *
 * This file implements map loading functionality
 * and a basic testcase to check if it works correctly.
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "map.h"

/**
 * @brief loads the map.
 *
 * This function parses the map file and initializes the map structure using input file.
 *
 * @param [in] file_path input file path.
 * @return filled map structure.
 */
map_t load_map(char* file_path) {

	FILE* map_file = fopen((const char *)file_path, "r");

	if (map_file == NULL) {
		printf("Error opening file.\n");
		assert(0);
	}
	map_t map = {0};

	fscanf(map_file, "space = %d %d %d %d\n",
		   &map.space.x_min,
		   &map.space.x_max,
		   &map.space.y_min,
		   &map.space.y_max);

	fscanf(map_file, "goal = %d %d\n",
		   &map.goal.pos.x,
		   &map.goal.pos.y);

	fscanf(map_file, "player = %d %d %d\n",
		   &map.player.current_pos.x,
		   &map.player.current_pos.y,
		   &map.player.heart);

	fscanf(map_file,"number_of_barriers = %d\n", &map.number_of_barriers);
	assert(map.number_of_barriers <= MAP_MAX_NUM_OF_BARRIERS);

	for (int i = 0; i < map.number_of_barriers; i++) {
		fscanf(map_file, "barrier = %d %d %d %d\n",
			   &map.barrier[i].current_pos.x,
			   &map.barrier[i].current_pos.y,
			   &map.barrier[i].length,
			   &map.barrier[i].current_dir);
 	}


	fscanf(map_file, "number_of_arrows = %d\n", &map.number_of_arrows);
	assert(map.number_of_arrows <= MAP_MAX_NUM_OF_ARROWS);

	for (int i = 0; i < map.number_of_arrows; i++) {
		fscanf(map_file, "arrow = %d %d %d %d\n",
			   &map.arrow[i].current_pos.x,
			   &map.arrow[i].current_pos.y,
			   &map.arrow[i].speed,
			   &map.arrow[i].direction);
	}

	fclose(map_file);
	return map;
}

/**
 * @brief test load_map() function.
 *
 * This is the test function for load_map(). It has no input or output variable.
 * This function creates a map_file and defines the map requirements into that.
 * Then checks if load_map() file works correctly.
 *
 * @return 0 in success.
 */
int test_load_map(){

	char file_path[1000] = "./test_file.txt";
	FILE* map_file = fopen((const char*)file_path, "w");
	fprintf(map_file,
			"space = 0 1000 0 1000\n"
			"goal = 50 50\n"
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
	assert(map.player.current_pos.x == 900 && map.player.current_pos.y == 500);
	assert(map.player.heart == 3);

	return 0;
}
