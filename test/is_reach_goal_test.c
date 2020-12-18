/**
* @file is_reach_goal_test.c
*/

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "../include/single_player.h"
#include "../include/map.h"

/**
 * @brief is_reach_goal's test function
 *
 * Checks if is_reach_goal() works properly.
 * @return 0 in success
 */
int is_reach_goal_test() {
    player_t player = {{.x=30,.y=30}, 1};
    goal_t goal = {{.x=30,.y=30}};
    bool x = is_reach_goal(&player, &goal);
    assert(x==true);
    goal.pos.x = 50;
    goal.pos.y = 90;
    x = is_reach_goal(&player, &goal);
    assert(x==false);
    printf("is_reach_goal_test PASSED\n");
    return 0;
}

int main() {
    return is_reach_goal_test();
}
