#ifndef SINGLE_PLAYER_H_
#define SINGLE_PLAYER_H_

#include "SDL2/SDL.h"
#include <stdbool.h>
#include "map.h"

typedef enum game_state {
    GAME_STATE_UNDEFINED,
    GAME_STATE_RUN,
    GAME_STATE_PAUSE,
    GAME_STATE_LOSE,
    GAME_STATE_WIN,
} game_state_t;


void game_over(SDL_Window* p_window);
void win_game(SDL_Window* p_window);
bool credit(SDL_Window* p_window);
bool user_manual(SDL_Window* p_window);
bool is_barrier_hit(map_t map, direction_t direction);
void update_player_pos(player_t* player, direction_t direction);
int is_player_hit(map_t* map);
bool single_player(SDL_Window* p_window);
void generate_view(SDL_Window* p_window, map_t* p_map);
bool is_reach_goal(player_t* p_player, goal_t* p_goal);
void update_barrier(map_barrier_t* p_barrier, map_t* map);
void update_arrow(arrow_t* p_arrow, map_t* map);
void take_heart(player_t* p_player);

#endif /* SINGLE_PLAYER_H_ */
