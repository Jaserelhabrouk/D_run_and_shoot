/**
 * @file is_barrier_hit.c
 * @author Mahsa
 * @brief Check the collision between the player and a barrier
 */

#include <stdio.h>
#include <stdbool.h>
#include "map.h"
#include "is_barrier_hit.h"


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
bool is_barrier_hit(player_t player,map_barrier_t* barrier, map_space_t space, direction_t direction){

    bool hitted = false;

    /** 1.Checking the borders */

    switch(direction){
        case DIRECTION_UP:
            if(player.current_pos.x == space.x_min){
                hitted = true;
            }

        break;

        case DIRECTION_DOWN:
            if(player.current_pos.x == space.x_max){
                hitted = true;
            }
        break;

        case DIRECTION_RIGHT:
            if(player.current_pos.y == space.y_max){
                hitted = true;
            }
        break;

        case DIRECTION_LEFT:
            if(player.current_pos.y == space.y_min){
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


    for (int i = 0 ; i < MAP_MAX_NUM_OF_BARRIERS; i++){ /** iteration through all the barriers in the map*/

        p_barrier = barrier + i; /** Pointer to barrier of number i in the map*/


        switch(direction){

            case DIRECTION_UP:
                if( (player.current_pos.x -1) == p_barrier->current_pos.x){
                    if( (player.current_pos.y >= p_barrier->current_pos.y) &&
                        (player.current_pos.y <= (p_barrier->current_pos.y + p_barrier->length -1))){
                            hitted = true;
                    }
                }
            break;

            case DIRECTION_DOWN:
                if( (player.current_pos.x +1) == p_barrier->current_pos.x){
                    if( (player.current_pos.y >= p_barrier->current_pos.y) &&
                        (player.current_pos.y <= (p_barrier->current_pos.y + p_barrier->length -1))){
                        hitted = true;
                    }
                }
            break;

            case DIRECTION_RIGHT:
                if( (player.current_pos.x) == p_barrier->current_pos.x){
                    if( (player.current_pos.y +1 >= p_barrier->current_pos.y) &&
                        (player.current_pos.y +1 <= (p_barrier->current_pos.y + p_barrier->length -1))){
                        hitted = true;
                    }
                }
            break;

            case DIRECTION_LEFT:
                 if( (player.current_pos.x) == p_barrier->current_pos.x){
                    if( (player.current_pos.y -1 >= p_barrier->current_pos.y) &&
                        (player.current_pos.y -1 <= (p_barrier->current_pos.y + p_barrier->length -1))){
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