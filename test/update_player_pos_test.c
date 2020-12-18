/**
 * @file update_player_pos_test.c
 */

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "../include/map.h"
#include "../include/single_player.h"

/**
 * @brief update player position's test function
 *
 * Checks if update_player_pos() works properly.
 * @return 0 in success
 */
int update_player_pos_test() {

    player_t p;
    direction_t dir;


    /** player is in place of (6,5)*/
    p.current_pos.x = 20;
    p.current_pos.y = 50;

    /** defining direction in which we want player moves to */

    /** 1. Moving UP */
    dir = DIRECTION_UP;

    update_player_pos(&p, dir);

    assert(p.current_pos.x == 20 && p.current_pos.y == 40);


    /** 2. Moving RIGHT */

    dir = DIRECTION_RIGHT;

    update_player_pos(&p, dir);

    assert(p.current_pos.x == 30 && p.current_pos.y == 40);

    /** 3. Moving DOWN */

    dir = DIRECTION_DOWN;

    update_player_pos(&p,dir);

    assert(p.current_pos.x == 30 && p.current_pos.y == 50);

    /** 4. Moving LEFT */

    dir = DIRECTION_LEFT;

    update_player_pos(&p,dir);

    assert(p.current_pos.x == 20 && p.current_pos.y == 50);

    printf("update_player_pos_test PASSED\n");
    return 0;
}

int main() {
    return update_player_pos_test();
}



