/**
 * @file update_barrier_test.c
 */

#include "../include/map.h"
#include "../include/single_player.h"
#include <assert.h>

/**
 * @brief update barrier's test function
 *
 * Checks if update_barrier() works properly.
 * @return 0 in success
 */
int update_barrier_test()
{
    map_t map = {0};
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

    map.space.x_min = 0;
    map.space.x_max = 100; 
    map.space.y_min = 0;
    map.space.y_max = 100;
    map.number_of_barriers = MAP_MAX_NUM_OF_BARRIERS;

    update_barrier(barriers, &map);

    assert(barriers[0].current_pos.x == 61 && barriers[0].current_pos.y == 10);
    assert(barriers[1].current_pos.x == 39 && barriers[1].current_pos.y == 20);
    assert(barriers[2].current_pos.x == 30 && barriers[2].current_pos.y == 30);
    assert(barriers[3].current_pos.x == 3 && barriers[3].current_pos.y == 90);
    assert(barriers[4].current_pos.x == 94 && barriers[4].current_pos.y == 30);
    assert(barriers[5].current_pos.x == 1 && barriers[5].current_pos.y == 10);
    assert(barriers[6].current_pos.x == 10 && barriers[6].current_pos.y == 0);
    assert(barriers[7].current_pos.x == 10 && barriers[7].current_pos.y == 100);
    assert(barriers[8].current_pos.x == 1 && barriers[8].current_pos.y == 4);
    assert(barriers[9].current_pos.x == 21 && barriers[9].current_pos.y == 20);

    printf("update_barrier_test PASSED\n");
    return 0;
}

int main() {
  return update_barrier_test();
}
