#ifndef SINGLE_PLAYER_H_
#define SINGLE_PLAYER_H_

#include "SDL2/SDL.h"

typedef enum game_state {
	GAME_STATE_UNDEFINED,
	GAME_STATE_RUN,
	GAME_STATE_PAUSE,
	GAME_STATE_LOSE,
	GAME_STATE_WIN,
} game_state_t;


void game_over(SDL_Window* p_window, SDL_Renderer* p_renderer);


#endif /* SINGLE_PLAYER_H_ */
