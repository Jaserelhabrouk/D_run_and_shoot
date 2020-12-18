/**
 * @file update_arrow_test.c
 */

#include <assert.h>
#include "../include/map.h"
#include "../include/single_player.h"

/**
 * @brief update arrow's test function
 *
 * Checks if update_arrow() works properly.
 * @return 0 in success
 */
int update_arrow_test()
{
    map_t map = {0};
    map.space.x_min = 0;
    map.space.x_max = 100;
    map.space.y_min = 0;
    map.space.y_max = 100;
    map.number_of_arrows = 4;

    arrow_t arrow[4] = {
      {{.x = 30,.y = 30}, 5, DIRECTION_UP},
      {{.x = 03,.y = 90}, 5, DIRECTION_DOWN},
      {{.x = 10,.y = 20}, 5, DIRECTION_UP},
      {{.x = 10,.y = 70}, 5, DIRECTION_DOWN},
    };

    memcpy(&map.arrow[0], &arrow[0], sizeof(arrow_t) * map.number_of_arrows);
    update_arrow(&map.arrow[0], &map);

    assert(map.arrow[0].current_pos.x == 30 && map.arrow[0].current_pos.y == 18);
    assert(map.arrow[1].current_pos.x == 03 && map.arrow[1].current_pos.y == 78);
    assert(map.arrow[2].current_pos.x == 10 && map.arrow[2].current_pos.y == 8);
    assert(map.arrow[3].current_pos.x == 10 && map.arrow[3].current_pos.y == 58);

    printf("update_arrow_test PASSED\n");
    return 0;
}

int main() {
    return update_arrow_test();
}