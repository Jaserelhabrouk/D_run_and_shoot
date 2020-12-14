/**
 * @file is_barrier_hit_test.c
 * @author Mahsa
 * @brief Tests the is_barrier_hit function
 */

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "../include/map.h"
#include "../include/single_player.h"



int is_barrier_hit_test(){

    map_t map = {0};

    /** size of map is 8*8 */
    map.space.x_min = 0;
    map.space.x_max = 7;
    map.space.y_min = 0;
    map.space.y_max = 7;


    /** player is in place of (6,5)*/
    map.player[PLAYER_1].current_pos.x = 6;
    map.player[PLAYER_1].current_pos.y = 5;


    /** defining barriers position, direction and size*/
    map.number_of_barriers = 2;

    map.barrier[0].current_dir = DIRECTION_RIGHT;
    map.barrier[0].current_pos.x = 2;
    map.barrier[0].current_pos.y = 4;
    map.barrier[0].length = 6;

    map.barrier[1].current_dir = DIRECTION_LEFT;
    map.barrier[1].current_pos.x = 4;
    map.barrier[1].current_pos.y = 6;
    map.barrier[1].length = 3;




    bool hit = false;

    /** 1.Checking the collision with barriers of the map*/

    hit = is_barrier_hit(map,DIRECTION_UP, PLAYER_1);

    assert(hit==1);



    hit = is_barrier_hit(map,DIRECTION_RIGHT, PLAYER_1);

    assert(hit==1);


	hit = is_barrier_hit(map,DIRECTION_DOWN, PLAYER_1);

    assert(hit==1);


    hit = is_barrier_hit(map,DIRECTION_LEFT, PLAYER_1);

    assert(hit==1);


    /** player is in place of (1,4)*/
    map.player[PLAYER_1].current_pos.x = 1;
    map.player[PLAYER_1].current_pos.y = 4;


    hit = is_barrier_hit(map,DIRECTION_RIGHT, PLAYER_1);

    assert(hit==1);



    /** player is in place of (7,6)*/
    map.player[PLAYER_1].current_pos.x = 7;
    map.player[PLAYER_1].current_pos.y = 6;


    hit = is_barrier_hit(map,DIRECTION_LEFT, PLAYER_1);

    assert(hit==1);



    /** player is in place of (5,7)*/
    map.player[PLAYER_1].current_pos.x = 5;
    map.player[PLAYER_1].current_pos.y = 7;


    hit = is_barrier_hit(map,DIRECTION_UP, PLAYER_1);

    assert(hit==1);



    /** 2.Checking the borders of the map*/

	/** player is in place of (7,0) top right corner*/
	map.player[PLAYER_1].current_pos.x = 7;
    map.player[PLAYER_1].current_pos.y = 0;


	hit = is_barrier_hit(map,DIRECTION_UP, PLAYER_1);

    assert(hit==1);

	hit = is_barrier_hit(map,DIRECTION_RIGHT, PLAYER_1);

    assert(hit==1);



    /** player is in place of (0,0) top left corner*/
    map.player[PLAYER_1].current_pos.x = 0;
    map.player[PLAYER_1].current_pos.y = 0;


	hit = is_barrier_hit(map,DIRECTION_UP, PLAYER_1);

    assert(hit==1);

	hit = is_barrier_hit(map,DIRECTION_LEFT, PLAYER_1);

    assert(hit==1);


    /** player is in place of (0,7) bottom left corner*/
    map.player[PLAYER_1].current_pos.x = 0;
    map.player[PLAYER_1].current_pos.y = 7;


	hit = is_barrier_hit(map,DIRECTION_DOWN, PLAYER_1);

    assert(hit==1);

	hit = is_barrier_hit(map,DIRECTION_LEFT, PLAYER_1);

    assert(hit==1);



    /** player is in place of (7,7) bottom right corner*/
    map.player[PLAYER_1].current_pos.x = 20;
    map.player[PLAYER_1].current_pos.y = 40;



	hit = is_barrier_hit(map,DIRECTION_DOWN, PLAYER_1);

    assert(hit==1);

	hit = is_barrier_hit(map,DIRECTION_RIGHT, PLAYER_1);

    assert(hit==1);

    printf("is_barrier_hit_test PASSED\n");
    return 0;
}
