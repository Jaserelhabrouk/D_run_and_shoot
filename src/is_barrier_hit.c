/**
 * @file is_barrier_hit.c
 * @author Mahsa
 * @brief Check the collision between the player and a barrier
 */

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "../include/map.h"
#include "../include/is_barrier_hit.h"



/**
 * @brief check the collision
 *
 * This function get player's position and checks if it hits any of the barriers/borders.
 * NOTE: The border of the map also be considered as barrier.
 * @param [in] player , gets player for its position
 * @param [in] barrier, pointer to barriers for identifying their positions
 * @param [in] space, for checking borders of the map
 * @param [in] direction, for player's next move prediction
 * @return boolean that represents if player hit a barrier or not
 */
bool is_barrier_hit(map_t map, direction_t direction)
{
    bool hitted = false;

    /** 1.Checking the borders */

    switch (direction)
    {
        case DIRECTION_UP:
            if(map.player.current_pos.y == map.space.y_min){
                hitted = true;
            }

        break;

        case DIRECTION_DOWN:
            if(map.player.current_pos.y == map.space.y_max){
                hitted = true;
            }
        break;

        case DIRECTION_RIGHT:
            if(map.player.current_pos.x == map.space.x_max){
                hitted = true;
            }
        break;

        case DIRECTION_LEFT:
            if(map.player.current_pos.x == map.space.x_min){
                hitted = true;
            }
        break;

        default:
            hitted = false;
    }

    /** The player already hit one the borders which is considered as a barrier. No need to check the barriers. */
    if(hitted == true){

        return hitted;
    }


    /** 2.Checking the barriers collision with player*/

    map_barrier_t* p_barrier;


    for (int i = 0 ; i < map.number_of_barriers; i++){ /** iteration through all the barriers in the map*/

        p_barrier = map.barrier + i; /** Pointer to barrier of number i in the map*/


        switch(direction){

            case DIRECTION_UP:
                if( (map.player.current_pos.y -1) == p_barrier->current_pos.y){
                    if( (map.player.current_pos.x >= p_barrier->current_pos.x) &&
                        (map.player.current_pos.x <= (p_barrier->current_pos.x + p_barrier->length -1))){
                            hitted = true;
                    }
                }
            break;

            case DIRECTION_DOWN:
                if( (map.player.current_pos.y +1) == p_barrier->current_pos.y){
                    if( (map.player.current_pos.x >= p_barrier->current_pos.x) &&
                        (map.player.current_pos.x <= (p_barrier->current_pos.x + p_barrier->length -1))){
                        hitted = true;
                    }
                }
            break;

            case DIRECTION_RIGHT:
                if( (map.player.current_pos.y) == p_barrier->current_pos.y){
                    if( (map.player.current_pos.x +1 >= p_barrier->current_pos.x) &&
                        (map.player.current_pos.x +1 <= (p_barrier->current_pos.x + p_barrier->length -1))){
                        hitted = true;
                    }
                }
            break;

            case DIRECTION_LEFT:
                 if( (map.player.current_pos.y) == p_barrier->current_pos.y){
                    if( (map.player.current_pos.x -1 >= p_barrier->current_pos.x) &&
                        (map.player.current_pos.x -1 <= (p_barrier->current_pos.x + p_barrier->length -1))){
                        hitted = true;
                    }
                 }
            break;

            default:
                hitted = false;

        }

        /** The player already hit one the barriers. No need to check others. END LOOP */
        if(hitted == true){
            return hitted;
        }


    }/** End for loop */

    return hitted;

}
