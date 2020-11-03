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


    /** player is in place of (5,6)*/
    p->current_pos.x = 5;
    p->current_pos.y = 6;

    /** defining direction in which we want player moves to */

    /** 1. Moving UP */
    dir = DIRECTION_UP;

    printf("player is now at the place of (%d,%d): \n", p->current_pos.x, p->current_pos.y);

    update_player_pos(p,dir);

    assert(p->current_pos.x == 4 && p->current_pos.y == 6);

    printf("player is at the place of (%d,%d) after moving UP. \n", p->current_pos.x, p->current_pos.y);

    /** 2. Moving RIGHT */

    dir = DIRECTION_RIGHT;

    printf("player is now at the place of (%d,%d): \n", p->current_pos.x, p->current_pos.y);

    update_player_pos(p,dir);

    assert(p->current_pos.y == 7 && p->current_pos.x == 4);

    printf("player is at the place of (%d,%d) after moving RIGHT. \n", p->current_pos.x, p->current_pos.y);


    /** 3. Moving DOWN */

    dir = DIRECTION_DOWN;

    printf("player is now at the place of (%d,%d): \n", p->current_pos.x, p->current_pos.y);

    update_player_pos(p,dir);

    assert(p->current_pos.x == 5 && p->current_pos.y == 7);

    printf("player is at the place of (%d,%d) after moving DOWN. \n", p->current_pos.x, p->current_pos.y);



    /** 4. Moving LEFT */

    dir = DIRECTION_LEFT;

    printf("player is now at the place of (%d,%d): \n", p->current_pos.x, p->current_pos.y);

    update_player_pos(p,dir);

    assert(p->current_pos.y == 6 && p->current_pos.x == 5);

    printf("player is at the place of (%d,%d) after moving LEFT. \n", p->current_pos.x, p->current_pos.y);



    return 0;
}



