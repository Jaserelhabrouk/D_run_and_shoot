#include "common.h"

/**
* \brief This function is to update barrier position in the map.
* @param [in] barrier a pointer to access to each barrier stored in a map_barrier structure array.
* @param [in] space represents a map_space structure.
*/
void update_barrier(map_barrier_t* p_barrier, map_space_t space) {

	map_barrier_t* p_bar;  
	
	if (p_barrier == NULL) {
		return;
	}
	for (int i = 0; i < MAP_MAX_NUM_OF_BARRIERS; i++)  /**< A loop repeats for MAP_MAX_NUM_OF_BARRIERS times.*/
	{
		p_bar = p_barrier + i;  /**< make p point to each barrier in a consecutive way.*/
		if (p_bar == NULL)
		{
			return;
		}
		/** Compare the position of the barrier pointed by p with the range of the given space. */
		if (p_bar->current_pos.x<space.x_min || p_bar->current_pos.x>space.x_max || p_bar->current_pos.y<space.y_min || p_bar->current_pos.y>space.y_max)
		{
			continue;
		}
		/** Move the barrier pointed by p according to its current moving direction.*/
		switch (p_bar->currect_dir) {

			case DIRECTION_RIGHT:
				if (p_bar->current_pos.x + p_bar->length == space.x_max)  /**< the barrier exceeds the right boundary of the map sapce.*/
				{
					p_bar->currect_dir = DIRECTION_LEFT;  /**< change the direction reversely.*/
					p_bar->current_pos.x -= STEP_SIZE;
					break;
				}
				p_bar->current_pos.x += STEP_SIZE;  /**< move the barrier rightward with x value increased by STEP_SIZE.*/
				break;
			case DIRECTION_LEFT:
				if (p_bar->current_pos.x == space.x_min)  /**< the barrier exceeds the left boundary of the map sapce.*/
				{
					p_bar->currect_dir = DIRECTION_RIGHT;
					p_bar->current_pos.x += STEP_SIZE;
					break;
				}
				p_bar->current_pos.x -= STEP_SIZE;  /**< move the barrier leftward with x value decreased by STEP_SIZE.*/
				break;
			case DIRECTION_UP:
				if (p_bar->current_pos.y == space.y_min)  /**< the barrier reaches the up boundary of the map sapce.*/
				{
					p_bar->currect_dir = DIRECTION_DOWN;
					p_bar->current_pos.y += STEP_SIZE;
					break;
				}
				p_bar->current_pos.y -= STEP_SIZE;  /**< move the barrier upward with y value decreased by STEP_SIZE.*/
				break;
			case DIRECTION_DOWN:
				if (p_bar->current_pos.y == space.y_max) /**< the barrier reaches the down boundary of the map sapce.*/
				{
					p_bar->currect_dir = DIRECTION_UP;
					p_bar->current_pos.y -= STEP_SIZE;
					break;
				}
				p_bar->current_pos.y += STEP_SIZE;  /**< move the barrier downward with y value increased by STEP_SIZE.*/
				break;
			default :
				break;
		}
	}

}


/**
* Generate a 2d graphic map using updated information
* Input: map
* Return: void
*/
void update_view(map_t m){

}

/**
* It pause the game
* Input: void
* Return: void
*/
void pause_game()
{

}

/**
* Displays a user manual for the player (how to Play).
* Input: void
* Output: void
* Return: void
*/
void user_manual()
{

}


/**release 2
*void print_option(option* opt);
*/

