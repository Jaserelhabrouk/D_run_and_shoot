/**
 * @file print_option_test.c
 * @brief Contains print_option_test function.
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
 * @brief Tests print options function.
 *
 * A function to test the print_options function.
 * It open a SDL window and initialize options.
 * The programmer should check if all items is shown in its proper location.
 * @return void
 */
int print_options_test() {

    TTF_Init();
    int screen_width = 1000;
    int screen_higth = 700;

    /**initialize and open a window*/
    SDL_Window* p_window = SDL_CreateWindow(
                              "Run and Shoot",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              screen_width,
                              screen_higth,
                              SDL_WINDOW_RESIZABLE);

    if (p_window == NULL)
    {
       printf("Window could not create: %s\n", SDL_GetError());
       assert(false);
    }

    /**initialize menu structure*/
    option_t option = {
           .selector = OPTION_ITEM_INTERMEDIATE,
           .items[0] = {"Easy","data/map_easy.txt"},
           .items[1] = {"Intermediate","data/map_normal.txt"},
           .items[2] = {"Hard","data/map_hard.txt"},
    };

    /** initialize a renderer*/
    SDL_Renderer* p_renderer = SDL_CreateRenderer(p_window, -1, 0);

    /** call print_options function*/
    options(p_window, option);

    /* quit the window if the quit botton is pressed*/
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        SDL_WaitEvent(&event);
        switch (event.type) {
            case SDL_QUIT: {
                quit = true;
                break;
            }
        }
    }
    SDL_DestroyRenderer(p_renderer);
    SDL_DestroyWindow(p_window);
    TTF_Quit();
    return 0;
}
