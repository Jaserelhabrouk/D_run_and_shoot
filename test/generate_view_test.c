/**
* @file update_barrier_test.c
* @author Jin
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <SDL.h>
#include <sdl_ttf.h>
#include <SDL_image.h>
#include <stdbool.h>
#include "map.h"


/** define the width and height of the scrren.*/
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

SDL_Window* g_window = NULL;
SDL_Renderer* g_renderer = NULL;

TTF_Font* g_font = NULL;
/**define the global variables representing different texture*/
SDL_Texture* g_player_texture = NULL;
SDL_Texture* g_barrier_texture = NULL;
SDL_Texture* g_arrow_down_texture = NULL;
SDL_Texture* g_arrow_up_texture = NULL;
SDL_Texture* g_goal_texture = NULL;

SDL_Texture* Load_image(const char* filePath)
{
    SDL_Surface* p_picture = NULL;

    p_picture = IMG_Load(filePath);

    /**set the background to be transparent*/
    Uint32 colorkey = SDL_MapRGB(p_picture->format, 0, 0, 0);
    SDL_SetColorKey(p_picture, SDL_TRUE, colorkey);

    SDL_Texture* p_result = SDL_CreateTextureFromSurface(g_renderer, p_picture);
    SDL_FreeSurface(p_picture);

    return p_result;
}

int generate_view_test()
{
    //update_barrier_test();
    //take_heart_test();

    /**Initialize the SDL*/
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        exit(-1);
    }

    /**Initialize Image library*/
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

    /**Create the window*/
    g_window = SDL_CreateWindow("GAME WINDOW", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (NULL == g_window)
    {
        SDL_Quit();
        return -1;
    }

    /**Initialize font library*/
    if (TTF_Init() == -1)
        return -1;
    /**Open the font*/
 /*   g_font = TTF_OpenFont("simkai.ttf", 16);
    if (!g_font)
    {
        printf("TTF_OpenFont: Open simsun.ttf %s\n", TTF_GetError());
        return -1;
    }*/


    /**Create the Renderer*/
    g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    /**Load the image resource*/
    g_player_texture = Load_image("data/player.jpg");
    g_barrier_texture = Load_image("data/barrier.jpg");
    g_arrow_down_texture = Load_image("data/arrow_down.jpg");
    g_arrow_up_texture = Load_image("data/arrow_up.jpg");
    g_goal_texture = Load_image("data/goal.jpg");


    /**Load the map*/
    char file_path[1000] = "data/map.txt";
    map_t map = load_map(file_path);

    /**Load Texture of player, target,barriers and arrows*/

    /**Check if it's the phase of operating the menu*/
    bool is_menu = true;

    /**Main loop flag*/
    bool game_running = true;

    /**Event handler*/
    SDL_Event event;

    /**While application is running*/
    while (game_running)
    {
        /**Handle events on queue*/
        while (SDL_PollEvent(&event) != 0)
        {
            /**User requests quit*/
            switch (event.type)
            {
            case SDL_QUIT:
                game_running = true;
                break;
            case SDL_KEYDOWN:/**< User presses a key*/
            {
                if (is_menu)
                {
                    /**Menu select*/
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_UP:

                        break;

                    case SDLK_DOWN:
                        break;

                    case SDLK_LEFT:
                        break;

                    case SDLK_RIGHT:
                        break;

                    default:
                        break;

                    }
                }
                else
                {
                    /**Game playing*/
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_UP:
                        /**Check if collision between player and barriers*/

                        /**Update position of the player*/


                        break;

                    case SDLK_DOWN:
                        break;

                    case SDLK_LEFT:
                        break;

                    case SDLK_RIGHT:
                        break;

                    default:
                        break;
                    }
                }
                break;
            }
            default:
                break;
            }

        }


        /**Clear the cashe region*/
        SDL_RenderClear(g_renderer);
        SDL_SetRenderDrawColor(g_renderer, 0xff, 0xff, 0xff, 0xff);

        /**Check if collision between player and arrows*/

        /**Draw all objects*/
        generate_view(&map, g_renderer, g_player_texture, g_goal_texture, g_barrier_texture, g_arrow_down_texture, g_arrow_up_texture);

        /**Display the content to render*/
        SDL_RenderPresent(g_renderer);
    }

    TTF_CloseFont(g_font);
    TTF_Quit();

    SDL_DestroyTexture(g_player_texture);
    SDL_DestroyTexture(g_barrier_texture);
    SDL_DestroyTexture(g_arrow_down_texture);
    SDL_DestroyTexture(g_arrow_up_texture);
    SDL_DestroyTexture(g_goal_texture);
    /**Destroy the Renderer*/
    SDL_DestroyRenderer(g_renderer);
    /**Destroy the Window*/
    SDL_DestroyWindow(g_window);

    /**Exit SDL subsystem*/
    SDL_Quit();
    return 0;
}



