/**
 * @file win_game_test.c
 * @brief win game test file
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
#include <stdbool.h>
#include <assert.h>
#include "../include/single_player.h"

/**
 * @brief win game test function
 *
 * This function creates a window and renderer and pass them as inputs to the win_game function.
 * By calling win_game a text (win game) is shown on the window.
 * The user should check the text location and its color.
 * The window will quit if the quit botton is pressed.
 * At the end window and renderer will destroy.
 *
 * @return 0 in sucess
 */
int win_game_test() {
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
    win_game(p_window);

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
