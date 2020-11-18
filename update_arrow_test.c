/**
* @file update_arrow_test.c
* @author Jaser
*/

#include "map.h"
#include <assert.h>

void update_arrow_test()
{
    map_t map = {0};
    arrow_t arrow[MAP_MAX_NUM_OF_ARROWS] = {
      {{.x = 30,.y = 30} ,5,DIRECTION_UP},
      {{.x = 3,.y = 90} ,5,DIRECTION_DOWN},
      {{.x = 10,.y = 0} ,5,DIRECTION_UP},
      {{.x = 10,.y = 100} ,5,DIRECTION_DOWN},
    };

    map.space.x_min = 0;
    map.space.x_max = 100; 
    map.space.y_min = 0;
    map.space.y_max = 100;
    map.number_of_arrows = 10;

    update_arrow(&arrow, &map);

    assert(arrow[4].current_pos.x == 93);
    assert(arrow[5].current_pos.x == 2);
    assert(arrow[6].current_pos.y == 2);
    assert(arrow[7].current_pos.y == 98);

}