/**
 * @file user_manual.c
 * \brief contain user_manul function.
 */
#ifdef _WIN64
#include <SDL.h>
#include <sdl_ttf.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/sdl_ttf.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "../include/menu.h"
#include "../include/single_player.h"

/**
 * \brief Prints user manual on an input window.
 * @param[in] p_window a SDL window which is passed from the main function.
 * @return bool if window is quit or back_space key is pressed, return true.
 */
bool user_manual(SDL_Window* p_window)
{
    int w;
    int h;
    SDL_GetWindowSize(p_window, &w, &h);
    SDL_Renderer* p_renderer = SDL_GetRenderer(p_window);
    SDL_RenderClear(p_renderer);

    /**setups for font and color of the text*/
    TTF_Font* p_font = TTF_OpenFont("data/FreeSans.ttf", 20);
    SDL_Color color = { 0, 255, 255 };
    SDL_Surface* p_surface = TTF_RenderText_Solid(p_font, "Wellcome to Run and Shoot User Manual", color);
    SDL_Texture* p_texture = SDL_CreateTextureFromSurface(p_renderer, p_surface);

    /**set location of the text*/
    int text_w = 0;
    int text_h = 0;
    SDL_QueryTexture(p_texture, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect = { w / 2 - 140, h / 2 - 200, text_w, text_h };


    /**The previous steps for other names*/
    SDL_Surface* p_surface_1 = TTF_RenderText_Solid(p_font, "up, down keys: move between items", color);
    SDL_Texture* p_texture_1 = SDL_CreateTextureFromSurface(p_renderer, p_surface_1);
    SDL_QueryTexture(p_texture_1, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect_1 = { w / 2 - 420, h / 2 - 50, text_w, text_h };

    SDL_Surface* p_surface_2 = TTF_RenderText_Solid(p_font, "up, down, left, right keys: first player control keys", color);
    SDL_Texture* p_texture_2 = SDL_CreateTextureFromSurface(p_renderer, p_surface_2);
    SDL_QueryTexture(p_texture_2, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect_2 = { w / 2 - 420, h / 2 , text_w, text_h };

    SDL_Surface* p_surface_3 = TTF_RenderText_Solid(p_font, " key: first player shooting key", color);
    SDL_Texture* p_texture_3 = SDL_CreateTextureFromSurface(p_renderer, p_surface_3);
    SDL_QueryTexture(p_texture_3, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect_3 = { w/ 2 - 420, h / 2 + 50 , text_w, text_h };


    SDL_Surface* p_surface_4 = TTF_RenderText_Solid(p_font, "w, s, a, d keys: second player control keys", color);
    SDL_Texture* p_texture_4 = SDL_CreateTextureFromSurface(p_renderer, p_surface_4);
    SDL_QueryTexture(p_texture_4, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect_4 = { w/ 2 - 420, h / 2 + 100 , text_w, text_h };

    SDL_Surface* p_surface_5 = TTF_RenderText_Solid(p_font, " key: second player shooting key", color);
    SDL_Texture* p_texture_5 = SDL_CreateTextureFromSurface(p_renderer, p_surface_5);
    SDL_QueryTexture(p_texture_5, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect_5 = { w / 2 - 420, h / 2 + 150 , text_w, text_h };

    SDL_Surface* p_surface_6 = TTF_RenderText_Solid(p_font, "space key: pause and play the game", color);
    SDL_Texture* p_texture_6 = SDL_CreateTextureFromSurface(p_renderer, p_surface_6);
    SDL_QueryTexture(p_texture_6, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect_6 = { w / 2 - 420, h / 2 + 200 , text_w, text_h };

    SDL_Surface* p_surface_7 = TTF_RenderText_Solid(p_font, "Goal: reach the goal & avoid moving objects", color);
    SDL_Texture* p_texture_7 = SDL_CreateTextureFromSurface(p_renderer, p_surface_7);
    SDL_QueryTexture(p_texture_7, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect_7 = { w / 2 - 420, h / 2 - 100 , text_w, text_h };

    SDL_Surface* p_surface_8 = TTF_RenderText_Solid(p_font, "enter/return key: choose an item", color);
    SDL_Texture* p_texture_8 = SDL_CreateTextureFromSurface(p_renderer, p_surface_8);
    SDL_QueryTexture(p_texture_8, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect_8 = { w / 2 - 420, h / 2 + 250 , text_w, text_h };


    /**update renderer*/
    SDL_RenderCopy(p_renderer, p_texture, NULL, &rect);
    SDL_RenderCopy(p_renderer, p_texture_1, NULL, &rect_1);
    SDL_RenderCopy(p_renderer, p_texture_2, NULL, &rect_2);
    SDL_RenderCopy(p_renderer, p_texture_3, NULL, &rect_3);
    SDL_RenderCopy(p_renderer, p_texture_4, NULL, &rect_4);
    SDL_RenderCopy(p_renderer, p_texture_5, NULL, &rect_5);
    SDL_RenderCopy(p_renderer, p_texture_6, NULL, &rect_6);
    SDL_RenderCopy(p_renderer, p_texture_7, NULL, &rect_7);
    SDL_RenderCopy(p_renderer, p_texture_8, NULL, &rect_8);
    SDL_RenderPresent(p_renderer);

    SDL_Event event;

    while (true)
    {
        if (SDL_PollEvent(&event))
        {
            if (SDL_QUIT == event.type)
            {
                break;
            }
            else if (SDL_KEYDOWN == event.type)
            {
                if (SDLK_BACKSPACE == event.key.keysym.sym)
                {
                    break;
                }
            }
        }
    }

    /**close commands*/
    SDL_DestroyTexture(p_texture);
    SDL_DestroyTexture(p_texture_1);
    SDL_DestroyTexture(p_texture_2);
    SDL_DestroyTexture(p_texture_3);
    SDL_DestroyTexture(p_texture_4);
    SDL_DestroyTexture(p_texture_5);
    SDL_DestroyTexture(p_texture_6);
    SDL_DestroyTexture(p_texture_7);
    SDL_DestroyTexture(p_texture_8);

    SDL_FreeSurface(p_surface);
    SDL_FreeSurface(p_surface_1);
    SDL_FreeSurface(p_surface_2);
    SDL_FreeSurface(p_surface_3);
    SDL_FreeSurface(p_surface_4);
    SDL_FreeSurface(p_surface_5);
    SDL_FreeSurface(p_surface_6);
    SDL_FreeSurface(p_surface_7);
    SDL_FreeSurface(p_surface_8);

    TTF_CloseFont(p_font);

    return event.type == SDL_QUIT;
}
