/**
 * @file is_barrier_hit_test.c
 * @author Mahsa
 * @brief Tests the is_barrier_hit function
 */

#include <stdio.h>
#include <stdbool.h>
#include "map.h"
#include "is_barrier_hit.h"



int main(){


    player_t p;
    map_barrier_t* map_b;
    map_space_t sp;

    /** size of map is 8*8 */
    sp.x_min = 0;
    sp.x_max = 7;
    sp.y_min = 0;
    sp.y_max =7;


    /** player is in place of (5,6)*/
    p.current_pos.x = 5;
    p.current_pos.y = 6;

    /** defining barriers position, direction and size*/
    map_b[0].current_dir = DIRECTION_RIGHT;
    map_b[0].current_pos.x = 4;
    map_b[0].current_pos.y = 2;
    map_b[0].length = 6;

    map_b[1].current_dir = DIRECTION_LEFT;
    map_b[1].current_pos.x = 6;
    map_b[1].current_pos.y = 4;
    map_b[1].length = 3;

    bool hit = false;

    /** 1.Checking the collision with barriers of the map*/

    printf("player is now at the place of (%d,%d): \n", p.current_pos.x, p.current_pos.y);

    hit = is_barrier_hit(p,map_b,sp,DIRECTION_UP);

    printf("The player wants to go up. Hits? (Y/N): %d \n",hit);



    hit = is_barrier_hit(p,map_b,sp,DIRECTION_RIGHT);

    printf("The player wants to go right. Hits? (Y/N): %d \n",hit);


	hit = is_barrier_hit(p,map_b,sp,DIRECTION_DOWN);

    printf("The player wants to go down. Hits? (Y/N): %d \n",hit);


    hit = is_barrier_hit(p,map_b,sp,DIRECTION_LEFT);

    printf("The player wants to go left. Hits? (Y/N): %d \n",hit);


    /** player is in place of (4,1)*/
    p.current_pos.x = 4;
    p.current_pos.y = 1;

    printf("player is now at the place of (%d,%d): \n", p.current_pos.x, p.current_pos.y);

    hit = is_barrier_hit(p,map_b,sp,DIRECTION_RIGHT);

    printf("The player wants to go right. Hits? (Y/N): %d \n",hit);


    /** player is in place of (6,7)*/
    p.current_pos.x = 6;
    p.current_pos.y = 7;

    printf("player is now at the place of (%d,%d): \n", p.current_pos.x, p.current_pos.y);

    hit = is_barrier_hit(p,map_b,sp,DIRECTION_LEFT);

    printf("The player wants to go left. Hits? (Y/N): %d \n",hit);


    /** player is in place of (7,5)*/
    p.current_pos.x = 7;
    p.current_pos.y = 5;

    printf("player is now at the place of (%d,%d): \n", p.current_pos.x, p.current_pos.y);

    hit = is_barrier_hit(p,map_b,sp,DIRECTION_UP);

    printf("The player wants to go up. Hits? (Y/N): %d \n",hit);


    /** 2.Checking the borders of the map*/

	/** player is in place of (0,7) top right corner*/
    p.current_pos.x = 0;
    p.current_pos.y = 7;

    printf("player is now at the place of (%d,%d): \n", p.current_pos.x, p.current_pos.y);

	hit = is_barrier_hit(p,map_b,sp,DIRECTION_UP);

    printf("The player wants to go up. Hits? (Y/N): %d \n",hit);

	hit = is_barrier_hit(p,map_b,sp,DIRECTION_RIGHT);

    printf("The player wants to go right. Hits? (Y/N): %d \n",hit);


    /** player is in place of (0,0) top left corner*/
    p.current_pos.x = 0;
    p.current_pos.y = 0;

    printf("player is now at the place of (%d,%d): \n", p.current_pos.x, p.current_pos.y);

	hit = is_barrier_hit(p,map_b,sp,DIRECTION_UP);

    printf("The player wants to go up. Hits? (Y/N): %d \n",hit);

	hit = is_barrier_hit(p,map_b,sp,DIRECTION_LEFT);

    printf("The player wants to go left. Hits? (Y/N): %d \n",hit);


    /** player is in place of (7,0) bottom left corner*/
    p.current_pos.x = 7;
    p.current_pos.y = 0;

    printf("player is now at the place of (%d,%d): \n", p.current_pos.x, p.current_pos.y);

	hit = is_barrier_hit(p,map_b,sp,DIRECTION_DOWN);

    printf("The player wants to go down. Hits? (Y/N): %d \n",hit);

	hit = is_barrier_hit(p,map_b,sp,DIRECTION_LEFT);

    printf("The player wants to go left. Hits? (Y/N): %d \n",hit);



    /** player is in place of (7,7) bottom right corner*/
    p.current_pos.x = 7;
    p.current_pos.y = 7;

    printf("player is now at the place of (%d,%d): \n", p.current_pos.x, p.current_pos.y);

	hit = is_barrier_hit(p,map_b,sp,DIRECTION_DOWN);

    printf("The player wants to go down. Hits? (Y/N): %d \n",hit);

	hit = is_barrier_hit(p,map_b,sp,DIRECTION_RIGHT);

    printf("The player wants to go right. Hits? (Y/N): %d \n",hit);


    return 0;
}
