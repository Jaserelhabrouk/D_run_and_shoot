/**
* @file is_reach_goal.c
* @author Jaser
*/

#include "map.h"
#include <stdio.h>

/* Block: player reached the goal - first release
* Assigned to:
* Checks if the player reached the goal
* Input: player, goal
* Output: 1 ---> if the player reached the goal
* Return: int */

bool is_reach_goal(player_t* p_player, goal_t* p_goal){
    if ((p_player->current_pos.x == p_goal->pos.x) && (p_player->current_pos.y == p_goal->pos.y))
    {
        return true;
    }
    return false;
}


