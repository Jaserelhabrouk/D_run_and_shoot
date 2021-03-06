/**
* @file take_heart.c
*/
#include "../include/single_player.h"
#include <stdio.h>

/**
 * @brief This function is to take a heart from the player.
 * @param[in] player a structure represents the player: position, heart, ....
 */
void take_heart(player_t* p_player)
{
	if (p_player == NULL) {  /**< if the player pointer is invalid, exit the function.*/
		return;
	}else if (p_player->heart >= 1) { /**< if obtained heart value is positive, decrease it by 1.*/
		p_player->heart--;
	}else {          /**< if negative or 0, exit the function.*/
		return;
	}
}
