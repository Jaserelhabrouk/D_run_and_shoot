#include "common.h"

/**
* \brief This function is to update barrier position in the map.
* @param [in] barrier a pointer to access to each barrier stored in a MapBarrier structure array.
* @param [in] space represents a MapSpace structure.
*/
void updateBarrier(MapBarrier* barrier, MapSpace space) {

	MapBarrier* p;  
	
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
		if (p->currentPos.x<space.xMin || p->currentPos.x>space.xMax || p->currentPos.y<space.yMin || p->currentPos.y>space.yMax)
		{
			continue;
		}
		/** Move the barrier pointed by p according to its current moving direction.*/
		switch (p->currectDir) {

			case DIRECTION_RIGHT:
				if (p->currentPos.x + p->length == space.xMax)  /**< the barrier exceeds the right boundary of the map sapce.*/
				{
					p->currectDir = DIRECTION_LEFT;  /**< change the direction reversely.*/
					p->currentPos.x -= STEP_SIZE;
					break;
				}
				p->currentPos.x += STEP_SIZE;  /**< move the barrier rightward with x value increased by STEP_SIZE.*/
				break;
			case DIRECTION_LEFT:
				if (p->currentPos.x == space.xMin)  /**< the barrier exceeds the left boundary of the map sapce.*/
				{
					p->currectDir = DIRECTION_RIGHT; 
					p->currentPos.x += STEP_SIZE;
					break;
				}
				p->currentPos.x -= STEP_SIZE;  /**< move the barrier leftward with x value decreased by STEP_SIZE.*/
				break;
			case DIRECTION_UP:
				if (p->currentPos.y == space.yMin)  /**< the barrier reaches the up boundary of the map sapce.*/
				{
					p->currectDir = DIRECTION_DOWN; 
					p->currentPos.y += STEP_SIZE;
					break;
				}
				p->currentPos.y -= STEP_SIZE;  /**< move the barrier upward with y value decreased by STEP_SIZE.*/
				break;
			case DIRECTION_DOWN:
				if (p->currentPos.y == space.yMax) /**< the barrier reaches the down boundary of the map sapce.*/
				{
					p->currectDir = DIRECTION_UP;
					p->currentPos.y -= STEP_SIZE;
					break;
				}
				p->currentPos.y += STEP_SIZE;  /**< move the barrier downward with y value increased by STEP_SIZE.*/
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
void updateView(Map map){

}

/**
* It pause the game
* Input: void
* Return: void
*/
void pauseGame(void)
{

}

/**
* Displays a user manual for the player (how to Play).
* Input: void
* Output: void
* Return: void
*/
void userManual(void)
{

}


/**release 2
*void printOption(Option* option);
*/

