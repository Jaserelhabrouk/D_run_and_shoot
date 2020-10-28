#include "common.h"

/**
* \brief This function is to takes a heart from the player.
* @param [in] player a Player type pointer.
*/
void takeHeart(Player* player){
	if (player == NULL) {  /**< if the player pointer is invalid, exit the function.*/
		return;
	}else if (player->heart >= 1) { /**< if obtained heart value is positive, decrease it by 1.*/
		player->heart--;
	}else {          /**< if negative, exit the function.*/
		return;
	}
}

/**release 2
*void multiPlayer(void);
*/
