/**
* @file is_reach_goal.c
*/

#include <stdio.h>
#include <stdbool.h>
#include "../include/map.h"
#include "../include/single_player.h"

int abs(int x)
{
    if (x >= 0)
    {
        return x;
    }
    return -x;
}

/**
 * @brief Checks if the player reached the goal
 *
 * @param[in] p_player
 * @param[in] p_goal
 * @return false if the player does not reach the goal and true otherwise.
 */
bool is_reach_goal(player_t* p_player, goal_t* p_goal)
{
    if (abs(p_player->current_pos.x - p_goal->pos.x) < 20 &&
        abs(p_player->current_pos.y - p_goal->pos.y) < 20)
    {
        return true;
    }
    return false;
}


