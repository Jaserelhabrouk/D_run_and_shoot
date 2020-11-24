/**
 * @file update_player_pos.c
 * @author Mahsa
 * @brief updates player's position
 */

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "../include/map.h"

/**
 * @brief update the position of the player
 *
 * This function gets the direction in which the player wants to move as well as the player
 * itself and updates the player's position based on the direction.
 * NOTE: This function only be called after validation of the player's move;
 * So we are not worry about the collision with any barrier(s).
 * @param [in] player , gets player for its current position
 * @param [in] direction, gets the direction to move player into that direction
 * @param [out] player, the position of the player will be updated
 */
void update_player_pos(player_t* player, direction_t direction)
{
    int step_size = 5;
    switch(direction)
    {
        case DIRECTION_UP:
            player->current_pos.y -= step_size;
            break;
        case DIRECTION_DOWN:
            player->current_pos.y += step_size;
            break;
        case DIRECTION_RIGHT:
            player->current_pos.x += step_size;
            break;
        case DIRECTION_LEFT:
            player->current_pos.x -= step_size;
            break;
        default:
            break;
    }
}
