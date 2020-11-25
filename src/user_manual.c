/**
 * @file user_manual.c
 * @brief Gives Credit Information
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#ifdef _WIN64
#include <SDL.h>
#include <sdl_ttf.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/sdl_ttf.h>
#endif
#include "../include/menu.h"
#include "../include/common.h"



bool user_manual(SDL_Window* p_window)
{
    //initialize a renderer
    SDL_Renderer* p_renderer = SDL_GetRenderer(p_window);

    //clear the entire screen to our selected color
    SDL_RenderClear(p_renderer);

    //setups for font and color of the text
    TTF_Font* p_font = TTF_OpenFont("data/FreeSans.ttf", 30);
    SDL_Color color = { 0, 255, 255 };
    SDL_Surface* p_surface = TTF_RenderText_Solid(p_font, "USER MANUAL", color);
    SDL_Texture* p_texture = SDL_CreateTextureFromSurface(p_renderer, p_surface);

    //set location of the text
    int text_w = 0;
    int text_h = 0;
    SDL_QueryTexture(p_texture, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect = { SCREEN_WIDTH / 2 - 80, SCREEN_HEIGHT / 2 - 150, text_w, text_h };


    //The previous steps for other names
    SDL_Surface* p_surface_1 = TTF_RenderText_Solid(p_font, "UP KEY: Select above menu item or Player move upwards", color);
    SDL_Texture* p_texture_1 = SDL_CreateTextureFromSurface(p_renderer, p_surface_1);
    SDL_QueryTexture(p_texture_1, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect_1 = { SCREEN_WIDTH / 2 - 350, SCREEN_HEIGHT / 2 - 50, text_w, text_h };

    SDL_Surface* p_surface_2 = TTF_RenderText_Solid(p_font, "DOWN KEY: Select below menu item or Player move downwards", color);
    SDL_Texture* p_texture_2 = SDL_CreateTextureFromSurface(p_renderer, p_surface_2);
    SDL_QueryTexture(p_texture_2, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect_2 = { SCREEN_WIDTH / 2 - 350, SCREEN_HEIGHT / 2 , text_w, text_h };

    SDL_Surface* p_surface_3 = TTF_RenderText_Solid(p_font, "LEFT KEY: Player move leftwards", color);
    SDL_Texture* p_texture_3 = SDL_CreateTextureFromSurface(p_renderer, p_surface_3);
    SDL_QueryTexture(p_texture_3, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect_3 = { SCREEN_WIDTH / 2 - 350, SCREEN_HEIGHT / 2 + 50 , text_w, text_h };


    SDL_Surface* p_surface_4 = TTF_RenderText_Solid(p_font, "RIGHT KEY: Player move rightwards", color);
    SDL_Texture* p_texture_4 = SDL_CreateTextureFromSurface(p_renderer, p_surface_4);
    SDL_QueryTexture(p_texture_4, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect_4 = { SCREEN_WIDTH / 2 - 350, SCREEN_HEIGHT / 2 + 100 , text_w, text_h };

    SDL_Surface* p_surface_5 = TTF_RenderText_Solid(p_font, "Esc KEY: Return back to menu options", color);
    SDL_Texture* p_texture_5 = SDL_CreateTextureFromSurface(p_renderer, p_surface_5);
    SDL_QueryTexture(p_texture_5, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect_5 = { SCREEN_WIDTH / 2 - 350, SCREEN_HEIGHT / 2 + 150 , text_w, text_h };


    //update renderer
    SDL_RenderCopy(p_renderer, p_texture, NULL, &rect);
    SDL_RenderCopy(p_renderer, p_texture_1, NULL, &rect_1);
    SDL_RenderCopy(p_renderer, p_texture_2, NULL, &rect_2);
    SDL_RenderCopy(p_renderer, p_texture_3, NULL, &rect_3);
    SDL_RenderCopy(p_renderer, p_texture_4, NULL, &rect_4);
    SDL_RenderCopy(p_renderer, p_texture_5, NULL, &rect_5);
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

    //close commands
    SDL_DestroyTexture(p_texture);
    SDL_DestroyTexture(p_texture_1);
    SDL_DestroyTexture(p_texture_2);
    SDL_DestroyTexture(p_texture_3);
    SDL_DestroyTexture(p_texture_4);
    SDL_DestroyTexture(p_texture_5);

    SDL_FreeSurface(p_surface);
    SDL_FreeSurface(p_surface_1);
    SDL_FreeSurface(p_surface_2);
    SDL_FreeSurface(p_surface_3);
    SDL_FreeSurface(p_surface_4);
    SDL_FreeSurface(p_surface_5);

    TTF_CloseFont(p_font);

    return event.type == SDL_QUIT;
}
