/*
 * read_input.c
 *
 *  Created on: Nov 4, 2020
 *      Author: pari
 */
#include <stdio.h>
#include <stdbool.h>

#include "../include/map.h"
#include "SDL2/SDL.h"
// key codes:
// return = 13, space = 32, up =1073741906 ,down = 1073741905,right = 1073741903, left =1073741904 , esc = 27,

int main() {
	int window_width = 1000;
	int window_heigth = 600;
	SDL_Window* window;
	window = SDL_CreateWindow(
			"Run and Shoot",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			window_width,
			window_heigth,
			SDL_WINDOW_RESIZABLE);
	if (window == NULL) {
		printf("Window could not create: %s\n",SDL_GetError());
		return 1;
	}
	map_t map ;
	map = load_map("./test_file.txt");
	SDL_Event event;
	bool quit = false;
	while (!quit) {
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
			case SDL_QUIT: {
				quit = true;
				break;
			}
			case SDL_KEYDOWN: {
				if(event.key.keysym.sym == SDLK_ESCAPE) {// esc: to back to menu.
					back_to_menu();
				} else if (event.key.keysym.sym == SDLK_SPACE) { //space: to stop the game
					pause_game();
				} else if (event.key.keysym.sym == SDLK_UP ||
						   event.key.keysym.sym == SDLK_DOWN ||
						   event.key.keysym.sym == SDLK_RIGHT ||
						   event.key.keysym.sym == SDLK_LEFT) {
					 if (is_barrier_hit() == false) {
									 update_player_pos();
								 }
								 update_barrier();
								 update_arrow();
								 if (is_player_hit() == true) {
									 take_heart();
									 if (map.player.heart == 0) {
										 game_over();
									 }
								 } else {
									 if (is_reach_goal() == true) {
										 win_game();
									 } else {
										 update_view();
									 }
								 }
				}
				break;
				}

			}
			default: {
				break;
			}
			}
		}
	SDL_DestroyWindow(window);
	}

	return 0;
}
