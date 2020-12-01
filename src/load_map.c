/**
 * @file load_map.c
 * @brief Loads the map.
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../include/map.h"

/**
 * @brief loads the map.
 *
 * This function parses the map file and initializes the map structure using input file.
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

