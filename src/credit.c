/**
 * @file credit.c
 * @author Mahsa
 * @brief Gives Credit Information
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "credit.h"


/**
 * @brief Prints Credits Information on a New Window
 * @return void
 */


void credit(void) {

	const int WIDTH = 800, HEIGHT = 600;

    SDL_Window* p_window = SDL_CreateWindow(
        "Credits",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_RESIZABLE
    );

    if (p_window == NULL) {
        printf("Window could not create: %s\n", SDL_GetError());
        assert(false);
    }

    //initialize a renderer
    SDL_Renderer* p_renderer = SDL_CreateRenderer(p_window, -1, 0);

    //select the color for drawing
    SDL_SetRenderDrawColor(p_renderer, 143, 138, 124, 255);

    //clear the entire screen to our selected color
    SDL_RenderClear(p_renderer);

    //initialize ttf
    TTF_Init();



    //setups for font and color of the text
    TTF_Font* p_font = TTF_OpenFont("data/FreeSans.ttf", 30);
    SDL_Color color = { 0, 0, 0 };
    SDL_Surface* p_surface = TTF_RenderText_Solid(p_font, "CREDITS:", color);
    SDL_Texture* p_texture = SDL_CreateTextureFromSurface(p_renderer, p_surface);





    //set location of the text
    int text_w = 0;
    int text_h = 0;
    SDL_QueryTexture(p_texture, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect = { WIDTH / 2 - 80, HEIGHT / 2 - 150, text_w, text_h };


    //The previous steps for other names

    p_surface = TTF_RenderText_Solid(p_font, "El-Habrouk Jaser", color);
    SDL_Texture* p_texture_1 = SDL_CreateTextureFromSurface(p_renderer, p_surface);
    SDL_QueryTexture(p_texture_1, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect_1 = { WIDTH / 2 - 100, HEIGHT / 2 - 50, text_w, text_h };

    p_surface = TTF_RenderText_Solid(p_font, "Firoozishahmirzadi Parichehreh", color);
    SDL_Texture* p_texture_2 = SDL_CreateTextureFromSurface(p_renderer, p_surface);
    SDL_QueryTexture(p_texture_2, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect_2 = { WIDTH / 2 - 200, HEIGHT / 2 , text_w, text_h };

    p_surface = TTF_RenderText_Solid(p_font, "Layeghi Mahsa", color);
    SDL_Texture* p_texture_3 = SDL_CreateTextureFromSurface(p_renderer, p_surface);
    SDL_QueryTexture(p_texture_3, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect_3 = { WIDTH / 2 - 100, HEIGHT / 2 + 50 , text_w, text_h };


    p_surface = TTF_RenderText_Solid(p_font, "Xu Jin", color);
    SDL_Texture* p_texture_4 = SDL_CreateTextureFromSurface(p_renderer, p_surface);
    SDL_QueryTexture(p_texture_4, NULL, NULL, &text_w, &text_h);
    SDL_Rect rect_4 = { WIDTH / 2 - 50, HEIGHT / 2 + 100 , text_w, text_h };


    //update renderer
    SDL_RenderCopy(p_renderer, p_texture, NULL, &rect);
    SDL_RenderCopy(p_renderer, p_texture_1, NULL, &rect_1);
    SDL_RenderCopy(p_renderer, p_texture_2, NULL, &rect_2);
    SDL_RenderCopy(p_renderer, p_texture_3, NULL, &rect_3);
    SDL_RenderCopy(p_renderer, p_texture_4, NULL, &rect_4);
    SDL_RenderPresent(p_renderer);



    SDL_Event event;

    while (true)
    {
        if (SDL_PollEvent(&event)) {
            if (SDL_QUIT == event.type) {
                break;
            }
        }
    }

    //close commands
    SDL_DestroyTexture(p_texture);
    SDL_FreeSurface(p_surface);
    TTF_CloseFont(p_font);
    TTF_Quit();
    SDL_DestroyRenderer(p_renderer);
    SDL_DestroyWindow(p_window);
}