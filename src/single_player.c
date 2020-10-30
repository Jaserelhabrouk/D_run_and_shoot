#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "../include/map.h"
#include "../include/single_player.h"
#include "SDL2/SDL.h"

/* key codes:
* return = 13, space = 32, up =1073741906 ,down = 1073741905,
* right = 1073741903, left =1073741904 , esc = 27,
*/

#define TIMER_INTERVAL 1000

Uint32 timer_callback(Uint32 interval, void *param) {
	SDL_Event event;
	event.type = SDL_USEREVENT;
	SDL_PushEvent(&event);
	return TIMER_INTERVAL;
}

void single_player() {

	/*initialize timer*/
	SDL_AddTimer(TIMER_INTERVAL, timer_callback, NULL);

	/*initialize game state*/
	game_state_t game_state = GAME_STATE_RUN;

	/*initialize and load map*/
	map_t map = load_map("../data/map_file.txt");

	/*initialize and open a window*/
	int window_width = 1000;
	int window_heigth = 600;

	SDL_Window* p_window = SDL_CreateWindow(
			"Run and Shoot",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			window_width,
			window_heigth,
			SDL_WINDOW_RESIZABLE);

	if (p_window == NULL) {
		printf("Window could not create: %s\n", SDL_GetError());
		assert(false);
	}

	/*initialize a renderer*/
	SDL_Renderer* p_renderer = SDL_CreateRenderer(p_window, -1, 0);

	/*read an event until window is not quit.*/
	SDL_Event event;
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT: {
					quit = true;
					break;
				} case SDL_KEYDOWN: {
					if(event.key.keysym.sym == SDLK_ESCAPE) {
						/* esc: to back to menu.*/
						//TODO back_to_menu();
					} else if (event.key.keysym.sym == SDLK_SPACE) {
						/*space: to stop the game*/
						if (game_state == GAME_STATE_RUN) {
							game_state = GAME_STATE_PAUSE;
						} else if (game_state == GAME_STATE_PAUSE) {
							game_state = GAME_STATE_RUN;
						} else {
							assert(false);
						}
					} else if (event.key.keysym.sym == SDLK_UP ||
							  event.key.keysym.sym == SDLK_DOWN ||
							  event.key.keysym.sym == SDLK_RIGHT ||
							  event.key.keysym.sym == SDLK_LEFT) {
						if (is_barrier_hit() == false) { //TODO is_barrier_hit()
							//TODO update_player_pos();
						}
						if (is_player_hit() == true) { //TODO is_player_hit()
							//TODO take_heart();
							if (map.player.heart == 0) {
								game_over(p_window, p_renderer);
								game_state = GAME_STATE_LOSE;
							}
						} else {
							if (is_reach_goal() == true) { //TODO is_reach_goal()
								//TODO win_game();
								game_state = GAME_STATE_WIN;
							}
						}
					}
					break;
				} case SDL_USEREVENT: {
					if (game_state == GAME_STATE_RUN) {
						//TODO update_barriers();
						//TODO update_arrows();
						//TODO update_view();
					}
					break;
				} default: {
					break;
				}
			}
		}
	}
	SDL_DestroyRenderer(p_renderer);
	SDL_DestroyWindow(p_window);

}

