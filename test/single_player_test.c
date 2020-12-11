/**
 * @file single_player_test.c
 * @breif This file contains single player functionality test case.
 */
#ifdef _WIN64
#include <SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "../include/map.h"
#include "../include/single_player.h"
#include "../include/map_textures.h"

int single_player_test()
{
    map_t map = load_map("data/map_file.txt");
    int screen_width = map.space.x_max - map.space.x_min + 1;
    int screen_higth = map.space.y_max - map.space.y_min + 1;

    /*initialize SDL*/
    TTF_Init();

    /*initialize and open a window*/
    SDL_Window* p_window = SDL_CreateWindow(
                               "Run and Shoot",
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               screen_width,
                               screen_higth,
                               SDL_WINDOW_OPENGL);

    if (p_window == NULL)
    {
        printf("Window could not create: %s\n", SDL_GetError());
        assert(false);
    }

    /*initialize a renderer*/
    SDL_Renderer* p_renderer = SDL_CreateRenderer(p_window, -1, 0);

    bool quit = false;

    quit = single_player(p_window);

    SDL_DestroyRenderer(p_renderer);
    SDL_DestroyWindow(p_window);
    TTF_Quit();
    return 0;
}


