#include "map.h"
#include <assert.h>

void update_barrier_test()
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

    map_space_t space = { 0,100,0,100 };

    update_barrier(&barriers, space);

    assert(barriers[4].current_pos.x == 93);
    assert(barriers[5].current_pos.x == 2);
    assert(barriers[6].current_pos.y == 2);
    assert(barriers[7].current_pos.y == 98);

}

void take_heart_test() {

    player_t p1 = { "Mark",{.x = 20,.y = 20},2 };
    player_t p2 = { "Mark",{.x = 40,.y = 20},1 };
    player_t p3 = { "Marry",{.x = 30,.y = 10},0 };
    player_t p4 = { "Marry",{.x = 30,.y = 10},-1 };
   
    take_heart(&p1);
    take_heart(&p2);
    take_heart(&p3);
    take_heart(&p4);
    take_heart(NULL);

    assert(p1.heart == 1);
    assert(p2.heart == 0);
    assert(p3.heart == 0);
    assert(p4.heart == -1);
}