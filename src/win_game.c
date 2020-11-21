/**
 * @file win_game.c
 * \brief This file contains win_game function
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/single_player.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

/**
 * \brief win game function
 *
 * This function clears the renderer and shows a texture (win game) on the window.
 * \param [in] p_window the width and heigth of the window is used to put the text on the proper location.
 * \param [in] p_renderer renderer pointer
 */
void win_game(SDL_Window* p_window) {
    int w;
    int h;
    SDL_GetWindowSize(p_window, &w, &h);
    SDL_Renderer* p_renderer = SDL_GetRenderer(p_window);
    SDL_RenderClear(p_renderer);

    /*loading font file from data directory and initialize color of text*/
    TTF_Font* p_font = TTF_OpenFont("data/FreeSans.ttf", 40);
    SDL_Color color = {0, 255, 0};
    SDL_Surface* p_surface = TTF_RenderText_Solid(p_font, "Win Game", color);
    SDL_Texture* p_texture = SDL_CreateTextureFromSurface(p_renderer, p_surface);

    /*put text in a given point*/
    int tex_w = 0;
    int tex_h = 0;
    SDL_QueryTexture(p_texture, NULL, NULL, &tex_w, &tex_h);
    SDL_Rect dstrect = {w / 2 - 100, h / 2 - 50, tex_w, tex_h};

    /*update renderer*/
    SDL_RenderCopy(p_renderer, p_texture, NULL, &dstrect);
    SDL_RenderPresent(p_renderer);

     /*close commands*/
    SDL_DestroyTexture(p_texture);
    SDL_FreeSurface(p_surface);
    TTF_CloseFont(p_font);
}
