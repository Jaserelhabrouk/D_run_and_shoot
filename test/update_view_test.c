/**
* @file update_map_test.c
* @author Jin
*/

#include "../include/map.h"
#include <assert.h>

void update_map_test()
{
    map_barrier_t barriers[MAP_MAX_NUM_OF_BARRIERS] = {
      {{.x = 60,.y = 10} ,5,DIRECTION_RIGHT},
      {{.x = 40,.y = 20} ,5,DIRECTION_LEFT},
      {{.x = 30,.y = 30} ,5,DIRECTION_UP},
      {{.x = 3,.y = 90} ,5,DIRECTION_DOWN},
      {{.x = 95,.y = 30} ,5,DIRECTION_RIGHT},
      {{.x = 0,.y = 10} ,5,DIRECTION_LEFT},
      {{.x = 10,.y = 0} ,5,DIRECTION_UP},
      {{.x = 10,.y = 100} ,5,DIRECTION_DOWN},
      {{.x = 0,.y = 4} ,5,DIRECTION_RIGHT},
      {{.x = 20,.y = 20} ,5,DIRECTION_RIGHT}
    };

    arrow_t arrow[MAP_MAX_NUM_OF_ARROWS] = {
      {{.x = 60,.y = 10} ,5,DIRECTION_RIGHT},
      {{.x = 40,.y = 20} ,5,DIRECTION_LEFT},
      {{.x = 30,.y = 30} ,5,DIRECTION_UP},
      {{.x = 3,.y = 90} ,5,DIRECTION_DOWN},
      {{.x = 95,.y = 30} ,5,DIRECTION_RIGHT},
      {{.x = 0,.y = 10} ,5,DIRECTION_LEFT},
      {{.x = 10,.y = 0} ,5,DIRECTION_UP},
      {{.x = 10,.y = 100} ,5,DIRECTION_DOWN},
      {{.x = 0,.y = 4} ,5,DIRECTION_RIGHT},
      {{.x = 20,.y = 20} ,5,DIRECTION_RIGHT}
    };

    map_space_t space = { 0,100,0,100 };

    goal_t goal = { {.x = 20,.y = 20} };
    player_t player = { "MARIO",{.x = 30,.y = 20} ,3};




    map_t map;
    map.space = space;
    map.number_of_barriers = 5;
    map.number_of_arrows = 5;
    for (int i = 0;i < map.number_of_barriers;i++)
    {    
        map.barrier[i] = barriers[i];
    }
    for (int i = 0;i < map.number_of_arrows;i++)
    {
        map.arrow[i] = arrow[i];
    }
    map.goal = goal;
    map.player = player;


    update_view(map);

    assert(map.player.current_pos.x == 93);
    assert(map.player.current_pos.y == 2);

}