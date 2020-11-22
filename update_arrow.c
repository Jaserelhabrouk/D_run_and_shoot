/**
* @file update_arrow.c
* @author Jaser
*/

#include "map.h"
#include <stdio.h>

/**
* \brief This function is to update arrow position in the map.
* @param [in] arrow a pointer to access to each arrow stored in a arrow structure array.
* @param [in] space represents a map_space structure.
*/

void update_arrow(arrow_t* p_arrow, map_t* map) {

	arrow_t* p_arr;

	if (p_arrow == NULL) {
		return;
	}
	for (int i = 0; i < map->number_of_arrows; i++)  /**< A loop repeats for MAP_MAX_NUM_OF_ARROWS times.*/
	{
		p_arr = p_arrow + i;  /**< make p point to each arrow in a consecutive way.*/
		if (p_arr == NULL)
		{
			return;
		}
		/** Compare the position of the arrow pointed by p with the range of the given space. */
		if (p_arr->current_pos.y < map->space.y_min || p_arr->current_pos.y > map->space.y_max)
		{
			continue;
		}
		/** Move the arrow pointed by p according to its current moving direction.*/
		switch (p_arr->direction) {

		case DIRECTION_UP:
			if (p_arr->current_pos.y == map->space.y_min)  /**< the arrow reaches the up boundary of the map sapce.*/
			{
				p_arr->current_pos = DIRECTION_DOWN;
				p_arr->current_pos.y += ARROW_MOVE_STEP_SIZE;
				break;
			}
			p_arr->current_pos.y -= ARROW_MOVE_STEP_SIZE;  /**< move the arrow upward with y value decreased by STEP_SIZE.*/
			break;
		case DIRECTION_DOWN:
			if (p_arr->current_pos.y == map->space.y_max) /**< the arrow reaches the down boundary of the map sapce.*/
			{
				p_arr->current_pos = DIRECTION_UP;
				p_arr->current_pos.y -= ARROW_MOVE_STEP_SIZE;
				break;
			}
			p_arr->current_pos.y += ARROW_MOVE_STEP_SIZE;  /**< move the arrow downward with y value increased by STEP_SIZE.*/
			break;
		default:
			break;
		}
	}

}