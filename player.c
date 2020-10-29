#include "common.h"

/**
* \brief This function is to takes a heart from the player.
* @param [in] player a Player type pointer.
*/
void take_heart(player* pl){
	if (pl == NULL) {  /**< if the player pointer is invalid, exit the function.*/
		return;
	}else if (pl->heart >= 1) { /**< if obtained heart value is positive, decrease it by 1.*/
		pl->heart--;
	}else {          /**< if negative or 0, exit the function.*/
		return;
	}
}

/**release 2
*void multiPlayer(void);
*/
