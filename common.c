#include "common.h"

/**
* \brief This function is to update barrier position in the map.
* @param [in] barrier a pointer to access to each barrier stored in a map_barrier structure array.
* @param [in] space represents a map_space structure.
*/
void updateBarrier(map_barrier* barrier, map_space space) {

	map_barrier* p;  
	
	if (barrier == NULL) {
		return;
	}
	for (int i = 0; i < MAP_MAX_NUM_OF_BARRIERS; i++)  /**< A loop repeats for MAP_MAX_NUM_OF_BARRIERS times.*/
	{
		p = barrier + i;  /**< make p point to each barrier in a consecutive way.*/
		if (p == NULL)
		{
			return;
		}
		/** Compare the position of the barrier pointed by p with the range of the given space. */
		if (p->current_pos.x<space.xMin || p->current_pos.x>space.xMax || p->current_pos.y<space.yMin || p->current_pos.y>space.yMax)
		{
			continue;
		}
		/** Move the barrier pointed by p according to its current moving direction.*/
		switch (p->currect_dir) {

			case DIRECTION_RIGHT:
				if (p->current_pos.x + p->length == space.xMax)  /**< the barrier exceeds the right boundary of the map sapce.*/
				{
					p->currect_dir = DIRECTION_LEFT;  /**< change the direction reversely.*/
					p->current_pos.x -= STEP_SIZE;
					break;
				}
				p->current_pos.x += STEP_SIZE;  /**< move the barrier rightward with x value increased by STEP_SIZE.*/
				break;
			case DIRECTION_LEFT:
				if (p->current_pos.x == space.xMin)  /**< the barrier exceeds the left boundary of the map sapce.*/
				{
					p->currect_dir = DIRECTION_RIGHT; 
					p->current_pos.x += STEP_SIZE;
					break;
				}
				p->current_pos.x -= STEP_SIZE;  /**< move the barrier leftward with x value decreased by STEP_SIZE.*/
				break;
			case DIRECTION_UP:
				if (p->current_pos.y == space.yMin)  /**< the barrier reaches the up boundary of the map sapce.*/
				{
					p->currect_dir = DIRECTION_DOWN; 
					p->current_pos.y += STEP_SIZE;
					break;
				}
				p->current_pos.y -= STEP_SIZE;  /**< move the barrier upward with y value decreased by STEP_SIZE.*/
				break;
			case DIRECTION_DOWN:
				if (p->current_pos.y == space.yMax) /**< the barrier reaches the down boundary of the map sapce.*/
				{
					p->currect_dir = DIRECTION_UP;
					p->current_pos.y -= STEP_SIZE;
					break;
				}
				p->current_pos.y += STEP_SIZE;  /**< move the barrier downward with y value increased by STEP_SIZE.*/
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
void update_view(map m){

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

