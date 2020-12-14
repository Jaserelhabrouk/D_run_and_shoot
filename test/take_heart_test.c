/**
* @file take_heart_test.c
*/

#include <assert.h>
#include "../include/map.h"
#include "../include/single_player.h"

int take_heart_test() {

    player_t p1 = {{.x = 20,.y = 20},2 };
    player_t p2 = {{.x = 40,.y = 20},1 };
    player_t p3 = {{.x = 30,.y = 10},0 };
    player_t p4 = {{.x = 30,.y = 10},-1 };

    take_heart(&p1);
    take_heart(&p2);
    take_heart(&p3);
    take_heart(&p4);
    take_heart(NULL);

    assert(p1.heart == 1);
    assert(p2.heart == 0);
    assert(p3.heart == 0);
    assert(p4.heart == -1);

    printf("take_heart_test PASSED\n");
    return 0;
}
