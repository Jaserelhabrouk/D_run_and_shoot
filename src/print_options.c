/**
 * @file print_options.c
 * @brief Contains print_options function.
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
#include "../include/menu.h"

/**
* @brief Prints the game different difficulty options on an SDL window.
* @param[in] p_window A SDL window is passed to the function.
* @param[in] p_options A structure represents options item.
* @return void
*/
void print_options(SDL_Window* p_window, option_t* p_options) {
    int w;
    int h;
    SDL_GetWindowSize(p_window, &w, &h);
    SDL_Renderer* p_renderer = SDL_GetRenderer(p_window);
    SDL_RenderClear(p_renderer);

    /**loading font file from data directory and initialize color of text*/
    TTF_Font* p_font = TTF_OpenFont("data/FreeSans.ttf", 40);
    assert(p_font != NULL);
    SDL_Color default_color = {0, 255, 0};

    int menu_item_step = 60;

    for (int i = 0; i < OPTION_ITEM_NUM_OF_ITEMS; i++)
    {
        SDL_Color color = default_color;
        if (i == p_options->selector)
        {
            color.b = 255;
        }

        SDL_Surface* p_surface = TTF_RenderText_Solid(p_font,
                                                      p_options->items[i].str,
                                                      color);

        SDL_Texture* p_texture = SDL_CreateTextureFromSurface(p_renderer, p_surface);

        /**put text in a given point*/
        int tex_w = 0;
        int tex_h = 0;
        SDL_QueryTexture(p_texture, NULL, NULL, &tex_w, &tex_h);
        SDL_Rect dstrect = {w / 2 - tex_w / 2, 200 + menu_item_step * i, tex_w, tex_h};

        /**update renderer*/
        SDL_RenderCopy(p_renderer, p_texture, NULL, &dstrect);

        SDL_DestroyTexture(p_texture);
        SDL_FreeSurface(p_surface);
    }
    SDL_RenderPresent(p_renderer);
    TTF_CloseFont(p_font);
}




