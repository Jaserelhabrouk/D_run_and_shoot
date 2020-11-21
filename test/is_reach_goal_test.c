/**
* @file is_reach_goal_test.c
* @author Jaser
*/

#include "map.h"
#include <stdio.h>


void is_reach_goal_test(){
    player_t p_player = {
        "Jaser", {.x=30,.y=30},1
    };
    goal_t p_goal = {
        {.x=30,.y=30}
    };
    bool x = is_reach_goal(&p_player,&p_goal);
    assert(x==true);

    
    p_player = {
    "Jaser", {.x=30,.y=30},1
    };
    p_goal = {
        {.x=45,.y=20}
    };
    bool x = is_reach_goal(&p_player,&p_goal);
    assert(x==false);

}