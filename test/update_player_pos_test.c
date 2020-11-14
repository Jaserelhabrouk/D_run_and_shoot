/**
 * @file update_player_pos_test.c
 * @author Mahsa
 * @brief Tests the update_player_pos function
 */

#include <stdio.h>
#include <stdbool.h>
#include "map.h"
#include "update_player_pos.h"


int main(){


    player_t * p;
    direction_t dir;


    /** player is in place of (6,5)*/
    p->current_pos.x = 6;
    p->current_pos.y = 5;

    /** defining direction in which we want player moves to */

    /** 1. Moving UP */
    dir = DIRECTION_UP;

    update_player_pos(p,dir);

    assert(p->current_pos.x == 6 && p->current_pos.y == 4);


    /** 2. Moving RIGHT */

    dir = DIRECTION_RIGHT;

    update_player_pos(p,dir);

    assert(p->current_pos.x == 4 && p->current_pos.y == 7);

    /** 3. Moving DOWN */

    dir = DIRECTION_DOWN;

    update_player_pos(p,dir);

    assert(p->current_pos.x == 7 && p->current_pos.y == 5);

    /** 4. Moving LEFT */

    dir = DIRECTION_LEFT;

    update_player_pos(p,dir);

    assert(p->current_pos.x == 5 && p->current_pos.y == 6);



    return 0;
}



