/**
 * @file shoot_test.c
 * @brief Test file for shoot function.
 */
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "../include/map.h"
#include "../include/multi_player.h"

 /**
  * @brief tests shoot() function .
  *
  * This function tests if shoot() works properly.
  * @return 0 in success.
  */
int shoot_test() {
    map_t map = {0};
    /**< Player1 is on the left of player2 */
    map.number_of_players = 2;
    map.player[PLAYER_1].current_pos.x = 100;
    map.player[PLAYER_1].current_pos.y = 200;
    map.player[PLAYER_1].heart = 3;
    map.player[PLAYER_2].current_pos.x = 300;
    map.player[PLAYER_2].current_pos.y = 200;
    map.player[PLAYER_2].heart = 3;

    shoot(&map, PLAYER_1); /**< Player1 shoots player2 */
    assert(map.player[PLAYER_1].bullet.current_pos.x == 100 &&
           map.player[PLAYER_1].bullet.current_pos.y == 200 &&
           map.player[PLAYER_1].bullet.direction == DIRECTION_RIGHT &&
           map.player[PLAYER_1].bullet_is_active == true);

    shoot(&map, PLAYER_2); /**< Player2 shoots player1 */
    assert(map.player[PLAYER_2].bullet.current_pos.x == 300 &&
           map.player[PLAYER_2].bullet.current_pos.y == 200 &&
           map.player[PLAYER_2].bullet.direction == DIRECTION_LEFT &&
           map.player[PLAYER_2].bullet_is_active == true);

    printf("shoot_test PASSED\n");
    return 0;
}


int main() {
  return shoot_test();
}