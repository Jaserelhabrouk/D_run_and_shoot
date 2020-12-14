/**
* @file update_barrier_test.c
* @author Jin
*/
#ifdef _WIN32
#include <SDL.h>
#include <SDL_ttf.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "../include/map.h"
#include "../include/single_player.h"
#include "../include/map_textures.h"

int generate_view_test()
{
    /*initialize SDL*/
    TTF_Init();

    /**Load the map*/
    char file_path[1000] = "data/single_player_easy.txt";
    map_t map = load_map(file_path);
    int screen_width = map.space.x_max - map.space.x_min + 1;
    int screen_higth = map.space.y_max - map.space.y_min + 1;
    /*initialize and open a window*/
    SDL_Window* p_window = SDL_CreateWindow(
                               "Run and Shoot",
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               screen_width,
                               screen_higth,
                               SDL_WINDOW_OPENGL);
    assert(p_window != NULL);
    SDL_Renderer* p_renderer = SDL_GetRenderer(p_window);
    SDL_RenderClear(p_renderer);
    SDL_RenderPresent(p_renderer);

    /*initialize map textures*/
    map.textures.p_texture_player[PLAYER_1] = get_player_texture(p_renderer, PLAYER_1);
    map.textures.p_texture_heart[PLAYER_1] = get_heart_texture(p_renderer, PLAYER_1);
    map.textures.p_texture_goal = get_goal_texture(p_renderer);
    map.textures.p_texture_arrow_down = get_arrow_down_texture(p_renderer);
    map.textures.p_texture_arrow_up = get_arrow_up_texture(p_renderer);
    map.textures.p_texture_barrier = get_barrier_texture(p_renderer, map.barrier[0].length);

    /**Main loop flag*/
    bool game_running = true;
    /**Event handler*/
    SDL_Event event;

    generate_view(p_window, &map);
    /**While application is running*/
    while (game_running)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
            {
                game_running = false;
                break;
            }
            case SDL_KEYDOWN:/**< User presses a key*/
            {
                break;
            }
            default:
            {
                break;
            }
        }
    }

    /**Destroy the Renderer*/
    SDL_DestroyRenderer(p_renderer);
    /**Destroy the Window*/
    SDL_DestroyWindow(p_window);
    /**Exit SDL subsystem*/
    SDL_Quit();
    printf("generate_view_test PASSED\n");
    return 0;
}



