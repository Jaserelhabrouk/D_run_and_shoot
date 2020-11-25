/**
* @file update_barrier.c
* @author Jin
*/

#include"../include/map.h"
#include<stdio.h>

/**
* \brief This function is to update barrier position in the map.
* @param [in] barrier a pointer to access to each barrier stored in a map_barrier structure array.
* @param [in] space represents a map_space structure.
*/

void update_barrier(map_barrier_t* p_barrier, map_t* map) {

	map_barrier_t* p_bar;

	if (p_barrier == NULL) {
		return;
	}
	for (int i = 0; i < map->number_of_barriers; i++)  /**< A loop repeats for MAP_MAX_NUM_OF_BARRIERS times.*/
	{
		p_bar = p_barrier + i;  /**< make p point to each barrier in a consecutive way.*/
		if (p_bar == NULL)
		{
			return;
		}
		/** Compare the position of the barrier pointed by p with the range of the given space. */
		if (p_bar->current_pos.x<map->space.x_min || p_bar->current_pos.x>map->space.x_max || p_bar->current_pos.y<map->space.y_min || p_bar->current_pos.y>map->space.y_max)
		{
			continue;
		}
		/** Move the barrier pointed by p according to its current moving direction.*/
		switch (p_bar->current_dir) {

		case DIRECTION_RIGHT:
			if (p_bar->current_pos.x + 250 >= map->space.x_max)  /**< the barrier exceeds the right boundary of the map sapce.*/
			{
				p_bar->current_dir = DIRECTION_LEFT;  /**< change the direction reversely.*/
				p_bar->current_pos.x -= BARRIER_MOVE_STEP_SIZE;
				break;
			}
			p_bar->current_pos.x += BARRIER_MOVE_STEP_SIZE;  /**< move the barrier rightward with x value increased by STEP_SIZE.*/
			break;
		case DIRECTION_LEFT:
			if (p_bar->current_pos.x <= map->space.x_min)  /**< the barrier exceeds the left boundary of the map sapce.*/
			{
				p_bar->current_dir = DIRECTION_RIGHT;
				p_bar->current_pos.x += BARRIER_MOVE_STEP_SIZE;
				break;
			}
			p_bar->current_pos.x -= BARRIER_MOVE_STEP_SIZE;  /**< move the barrier leftward with x value decreased by STEP_SIZE.*/
			break;	
		default:
			break;
		}
	}

}
