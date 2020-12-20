/**
 * @file multi_player.h
 * @brief function declaration and type definition for multi player mode.
 */
#pragma once
#ifndef MULTI_PLAYER_H_
#define MULTI_PLAYER_H_

#include "single_player.h"

/**
 * @brief timer
 */
Uint32 timer_callback(Uint32, void*);

/**
 * @brief multi_player function
 *
 * This is the main function which handle multi player mode.
 * Different functions are called here: first a map file is loaded and then
 * according to the input key different entities is updated and a view will be generated.
 * A timer is initialized to update every thing in each TIMER_INTERVAL seconds.
 * @param[in] p_window a SDL window which is passed from the main function.
 * @return bool if window is quit or back_space key is pressed, return true.
 */
bool multi_player(SDL_Window* p_window,option_items_t difficulty);

/**
* @brief generate_view_multi function
*
* This function is to generate a graphic map using updated information
* @param[in] p_window a SDL window which is passed from the main function.
* @param[in] p_map a defined map which is passed from the main function.
* @return: void
*/
void generate_view_multi(SDL_Window* p_window, map_t* p_map);

/**
 * @brief Generates a bullet
 *
 * This function generates a bullet in the player's current position
 * and initialize the speed and direction.
 * @param[in] map represent the map structure which has players' position.
 * @param[in] player_num represent the player index: PLAYER_1/PLAYER_2.
 */
void shoot(map_t* map, player_index_t player_num);

/**
 * @brief updates the position of generated bullet
 *
 * This function shoot a bullet in a direction in which an oppenent exists.
 * @param [in] map represent the map structure which has bullet's position and direction.
 */
void update_bullet(map_t* map, player_index_t player_num);

/**
 * @brief Checks if a bullet hit a player.
 *
 * This function checks if the player is hit by oppent's bullet.
 * @param [in] map represent the map structure which has player position and bullets' positions.
 * @param [in] player_index  can be PLAYER1 or PLAYER2.
 * @return flag if the player is hit, flag = 1, otherwise flag = 0.
 */
int is_bullet_hit(map_t* map, player_index_t player_index);

#endif /* MULTI_PLAYER_H_ */
#pragma once
