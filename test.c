#include "common.h"
#include <assert.h>

void test_update_barrier()
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

void test_take_heart() {

    player_t p1 = { "Mark",{.x = 40,.y = 20},1 };
    player_t p2 = { "Marry",{.x = 30,.y = 10},0 };
    player_t p3 = { "Marry",{.x = 30,.y = 10},-1 };

    take_heart(&p1);
    take_heart(&p2);
    take_heart(&p3);

    assert(p1.heart == 0);
    assert(p2.heart == 0);
    assert(p3.heart == -1);
}