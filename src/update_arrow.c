/**
 * @file update_arrow.c
 */

#include <stdio.h>
#include "../include/map.h"
#include "../include/single_player.h"
#include "../include/map_textures.h"

/**
 * @brief This function is to update arrow position in the map.
 * @param[in] arrow a pointer to access to each arrow stored in a arrow structure array.
 * @param[in] map represents map's structure.
 * @param[out] update arrow's position.
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
		/** Move the arrow pointed by p according to its current moving direction.*/
		switch (p_arr->direction) {

		case DIRECTION_UP:
			if (p_arr->current_pos.y  < map->space.y_min)  /**< the arrow reaches the up boundary of the map sapce.*/
			{
				p_arr->direction = DIRECTION_DOWN;
				p_arr->current_pos.y += ARROW_MOVE_STEP_SIZE(p_arr->speed);
				break;
			}
			else
			{
			    p_arr->current_pos.y -= ARROW_MOVE_STEP_SIZE(p_arr->speed);  /**< move the arrow upward with y value decreased by ARROW_MOVE_STEP_SIZE .*/
			}
			break;
		case DIRECTION_DOWN:
			if (p_arr->current_pos.y + MAP_TEXTURE_ARROW_HEIGHT > map->space.y_max) /**< the arrow reaches the down boundary of the map sapce.*/
			{
				p_arr->direction = DIRECTION_UP;
				p_arr->current_pos.y -= ARROW_MOVE_STEP_SIZE(p_arr->speed);
				break;
			}
			else
			{
			    p_arr->current_pos.y += ARROW_MOVE_STEP_SIZE(p_arr->speed);  /**< move the arrow downward with y value increased by ARROW_MOVE_STEP_SIZE.*/
			}
			break;
		default:
			break;
		}
	}
}
