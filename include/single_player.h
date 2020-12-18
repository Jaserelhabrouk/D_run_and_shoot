/**
 * @file single_player.h
 * @brief function declaration and type definition for single player mode.
 */
#ifndef SINGLE_PLAYER_H_
#define SINGLE_PLAYER_H_

#ifdef _WIN64
#include <SDL2/SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif

#include <stdbool.h>
#include "map.h"
#include "menu.h"

/**
 * @brief game_state_t enumeration of game states
 */
typedef enum game_state {
    GAME_STATE_UNDEFINED,
    GAME_STATE_RUN,
    GAME_STATE_PAUSE,
    GAME_STATE_LOSE,
    GAME_STATE_WIN,
} game_state_t;

/**
 * @brief game over function
 *
 * This function clears the renderer and shows a texture (game over) on the window.
 * @param [in] p_window the same window is used to display win game text.
 * @return void
 */
void game_over(SDL_Window* p_window);

/**
 * @brief win game function
 *
 * This function clears the renderer and shows a texture (win game) on the window.
 * @param [in] p_window the same window is used to display win game text .
 * @return void
 */
void win_game(SDL_Window* p_window);

/**
 * @brief Checks if a player is hit by arrows.
 *
 * This function checks if a player is hit by arrows.
 * @param [in] map represent the map structure which has player position and arrows' positions.
 * @param [in] player_index  can be PLAYER1 or PLAYER2.
 * @return flag if the player is hit, flag = 1, otherwise flag = 0.
 */
int is_player_hit(map_t* map, player_index_t player_index);

/**
 * @brief check the collision
 *
 * This function get player's position and checks if it hits any of the barriers/borders.
 * NOTE: The border of the map also be considered as barrier.
 * @param[in] map  map structure represents players, barriers, and... position.
 * @param[in] direction specify player's next movement.
 * @param[in] player_index specify the player: PLAYER_1/PLAYER_2.
 * @return bool true if player hit a barrier or borders and false otherwise.
 */
bool is_barrier_hit(map_t map, direction_t direction, player_index_t player_index);

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
void update_player_pos(player_t* player, direction_t direction);

/**
* @brief generate_view function
*
* This function is to generate a graphic map using updated information
* @param[in] p_window a SDL window which is passed from the main function.
* @param[in] p_map a defined map which is passed from the main function.
* @return void
*/
void generate_view(SDL_Window* p_window, map_t* p_map);

/**
 * @brief Checks if the player reached the goal
 *
 * @param[in] p_player player information including position.
 * @param[in] p_goal goal's position
 * @return false if the player does not reach the goal and true otherwise.
 */
bool is_reach_goal(player_t* p_player, goal_t* p_goal);

/**
 * @brief This function is to update barrier position in the map.
 * @param[in] barrier a pointer to access to each barrier stored in a map_barrier structure array.
 * @param[in] map represents the map structure including borders,... .
 * @param[out] update barrier's position.
 */
void update_barrier(map_barrier_t* p_barrier, map_t* map);

/**
 * @brief This function is to update arrow position in the map.
 * @param[in] arrow a pointer to access to each arrow stored in a arrow structure array.
 * @param[in] map represents map's structure.
 * @param[out] update arrow's position.
 */
void update_arrow(arrow_t* p_arrow, map_t* map);

/**
 * @brief This function is to take a heart from the player.
 * @param[in] player a structure represents the player: position, heart, ....
 */
void take_heart(player_t* p_player);

#endif /* SINGLE_PLAYER_H_ */
