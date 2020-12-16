/**
 * @file update_bullet_test.c
 * @brief Test file for update_bullet function.
 */
#include <stdio.h>
#include <assert.h>
#include "../include/map.h"
#include "../include/multi_player.h"


 /**
  * @brief tests update_bullet() function .
  *
  * This function tests if update_bullet() works properly.
  * @return 0 in success.
  */
int update_bullet_test() {
    map_t map = {0};

    map.space.x_min = 0;
    map.space.x_max = 400;
    map.space.y_min = 0;
    map.space.y_max = 400;

    map.player[PLAYER_1].bullet.current_pos.x = 100;
    map.player[PLAYER_1].bullet.current_pos.y = 200;
    map.player[PLAYER_1].bullet.direction = DIRECTION_RIGHT;
    map.player[PLAYER_1].bullet.speed = BULLET_MOVE_STEP_SIZE;
    map.player[PLAYER_1].bullet_is_active = true;
    map.player[PLAYER_2].bullet.current_pos.x = 300;
    map.player[PLAYER_2].bullet.current_pos.y = 200;
    map.player[PLAYER_2].bullet.direction = DIRECTION_LEFT;
    map.player[PLAYER_2].bullet.speed = BULLET_MOVE_STEP_SIZE;
    map.player[PLAYER_2].bullet_is_active = true;

    update_bullet(&map,PLAYER_1);
    assert(map.player[PLAYER_1].bullet.current_pos.x == 100 + BULLET_MOVE_STEP_SIZE);

    update_bullet(&map, PLAYER_2);
    assert(map.player[PLAYER_2].bullet.current_pos.x == 300 - BULLET_MOVE_STEP_SIZE);

    printf("update_bullet_test PASSED\n");
    return 0;
}
