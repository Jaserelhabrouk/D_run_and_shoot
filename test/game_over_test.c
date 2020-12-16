/**
 * @file game_over_test.c
 * @brief game over test file
 */
#ifdef _WIN64
#include <SDL.h>
#include <SDL_ttf.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "../include/single_player.h"

/**
 * @brief game over test function
 *
 * This function creates a window and renderer and pass them as inputs to the game_over function.
 * By calling game_over a text (game over) is shown on the window.
 * The user should check the text location and its color manually.
 * The window will quit if the quit botton is pressed.
 * At the end window and renderer will destroy.
 *
 * @return 0 in sucess
 */
int game_over_test() {
	/**initialize and open a window*/
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
		printf("Window could not be created.n");
		assert(false);
	}

	/**initialize a renderer*/
	SDL_Renderer* p_renderer = SDL_CreateRenderer(p_window, -1, 0);

	TTF_Init();

	/**call game_over function*/
	game_over(p_window);

	/**quit the window if the quit botton is pressed*/
	bool quit = false;
	SDL_Event event;
	while (!quit)
	{
		SDL_WaitEvent(&event);
		switch (event.type)
		{
			case SDL_QUIT:
				quit = true;
				break;
			default:
				break;
		}
	}

	SDL_DestroyRenderer(p_renderer);
	SDL_DestroyWindow(p_window);
	TTF_Quit();
	return 0;
}
