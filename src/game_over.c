/**
 * @file game_over.c
 * @brief game over file
 */
#ifdef _WIN64
#include <SDL.h>
#include <SDL_ttf.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include "../include/single_player.h"

/**
 * @brief game over function
 *
 * This function clears the renderer and shows a texture (game over) on the window.
 * @param [in] p_window the same window is used to display win game text.
 * @return void
 */
void game_over(SDL_Window* p_window) {
	int w;
	int h;
	SDL_GetWindowSize(p_window, &w, &h);
	SDL_Renderer* p_renderer = SDL_GetRenderer(p_window);
    SDL_RenderClear(p_renderer);

	/**loading font file from data directory and initialize color of text*/
	TTF_Font* p_font = TTF_OpenFont("data/FreeSans.ttf", 40);
	SDL_Color color = {255, 0, 0};
	SDL_Surface* p_surface = TTF_RenderText_Solid(p_font, "Game Over", color);
	SDL_Texture* p_texture = SDL_CreateTextureFromSurface(p_renderer, p_surface);

	/**put text in a given point*/
	int tex_w = 0;
	int tex_h = 0;
	SDL_QueryTexture(p_texture, NULL, NULL, &tex_w, &tex_h);
	SDL_Rect dstrect = {w / 2 - 100, h / 2 - 50, tex_w, tex_h};

	/**update renderer*/
	SDL_RenderCopy(p_renderer, p_texture, NULL, &dstrect);
	SDL_RenderPresent(p_renderer);

	/**close commands*/
	SDL_DestroyTexture(p_texture);
	SDL_FreeSurface(p_surface);
	TTF_CloseFont(p_font);
}
