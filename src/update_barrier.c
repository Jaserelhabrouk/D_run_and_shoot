/**
* @file update_barrier.c
* @author Jin
*/
#include <stdio.h>
#include"../include/map.h"
#include "../include/single_player.h"

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
		/** Move the barrier pointed by p according to its current moving direction.*/
		switch (p_bar->current_dir) {

		case DIRECTION_RIGHT:
			if (p_bar->current_pos.x + p_bar->length >= map->space.x_max)  /**< the barrier exceeds the right boundary of the map sapce.*/
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
		//case DIRECTION_UP:
		//	if (p_bar->current_pos.y == map->space.y_min)  /**< the barrier reaches the up boundary of the map sapce.*/
		//	{
		//		p_bar->current_dir = DIRECTION_DOWN;
		//		p_bar->current_pos.y += BARRIER_MOVE_STEP_SIZE;
		//		break;
		//	}
		//	p_bar->current_pos.y -= BARRIER_MOVE_STEP_SIZE;  /**< move the barrier upward with y value decreased by STEP_SIZE.*/
		//	break;
		//case DIRECTION_DOWN:
		//	if (p_bar->current_pos.y == map->space.y_max) /**< the barrier reaches the down boundary of the map sapce.*/
		//	{
		//		p_bar->current_dir = DIRECTION_UP;
		//		p_bar->current_pos.y -= BARRIER_MOVE_STEP_SIZE;
		//		break;
		//	}
		//	p_bar->current_pos.y += BARRIER_MOVE_STEP_SIZE;  /**< move the barrier downward with y value increased by STEP_SIZE.*/
		//	break;
		default:
			break;
		}
	}

}
