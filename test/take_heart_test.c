/**
* @file take_heart_test.c
* @author Jin
*/

#include "../include/map.h"
#include <assert.h>

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