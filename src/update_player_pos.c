/**
 * @file update_player_pos.c
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
 * @param[in] player information of the player: position, ... .
 * @param[in] direction player's movement direction.
 * @param[out] player's position will be updated.
 */
void update_player_pos(player_t* player, direction_t direction)
{
    switch(direction)
    {
        case DIRECTION_UP:
            player->current_pos.y -= PLAYER_MOVE_STEP_SIZE;
            break;
        case DIRECTION_DOWN:
            player->current_pos.y += PLAYER_MOVE_STEP_SIZE;
            break;
        case DIRECTION_RIGHT:
            player->current_pos.x += PLAYER_MOVE_STEP_SIZE;
            break;
        case DIRECTION_LEFT:
            player->current_pos.x -= PLAYER_MOVE_STEP_SIZE;
            break;
        default:
            break;
    }
}
