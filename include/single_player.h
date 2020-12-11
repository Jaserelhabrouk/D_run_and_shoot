/**
 * @file single_player.h
 * @brief function declaration and type definition for single player mode.
 */
#ifndef SINGLE_PLAYER_H_
#define SINGLE_PLAYER_H_

#ifdef _WIN64
#include <SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif

#include <stdbool.h>
#include "map.h"
#include "menu.h"

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
 * @brief Checks if the player is hit.
 *
 * This function checks if the player is hit by an arrow.
 * @param [in] map represent the map structure which has player position and arrows' positions.
 * @param [in] player_index  can be PLAYER1 or PLAYER2.
 * @return flag if the player is hit, flag = 1, otherwise flag = 0.
 */
int is_player_hit(map_t* map, player_index_t player_index);



bool is_barrier_hit(map_t map, direction_t direction, player_index_t player_index);
void update_player_pos(player_t* player, direction_t direction);
void generate_view(SDL_Window* p_window, map_t* p_map);
bool is_reach_goal(player_t* p_player, goal_t* p_goal);
void update_barrier(map_barrier_t* p_barrier, map_t* map);
void update_arrow(arrow_t* p_arrow, map_t* map);
void take_heart(player_t* p_player);

#endif /* SINGLE_PLAYER_H_ */
