/**
* @file take_heart.c
* @author Jin
*/
#include "../include/player.h"
#include <stdio.h>

/**
* \brief This function is to takes a heart from the player.
* @param [in] player a Player type pointer.
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
