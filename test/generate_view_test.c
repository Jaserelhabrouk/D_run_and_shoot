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
#include"../include/map.h"

extern SDL_Window* g_window;
extern SDL_Renderer* g_renderer;

extern TTF_Font* g_font;
/**define the constants representing different texture*/
extern SDL_Texture* g_player_texture;
extern SDL_Texture* g_barrier_texture;
extern SDL_Texture* g_arrow_down_texture;
extern SDL_Texture* g_arrow_up_texture;
extern SDL_Texture* g_goal_texture; 


/** define the width and height of the scrren.*/
extern int g_screen_width;
extern int g_screen_height;


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
     /**Initialize the SDL*/
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        exit(-1);
    }
    atexit(SDL_Quit);//



    /**Load the map*/
    char file_path[1000] = "data/map.txt";
    map_t map = load_map(file_path);

    g_screen_width = map.space.x_max - map.space.x_min;
    g_screen_height = map.space.y_max - map.space.y_min;

    /**Create the window*/
    g_window = SDL_CreateWindow("GAME WINDOW", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, g_screen_width, g_screen_height, SDL_WINDOW_SHOWN);
    if (NULL == g_window)
    {
        SDL_Quit();
        return -1;
    }

    /**Create the Renderer*/
    g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    /**Initialize Image library*/
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

  

    /**Load the image resource*/
    g_player_texture = Load_image("data/player.jpg");
    g_barrier_texture = Load_image("data/barrier.jpg");
    g_arrow_down_texture = Load_image("data/arrow_down.jpg");
    g_arrow_up_texture = Load_image("data/arrow_up.jpg");
    g_goal_texture = Load_image("data/goal.jpg");
    /**Initialize font library*/
    if (TTF_Init() == -1)
        return -1;
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
                game_running = false;
                break;
            case SDL_KEYDOWN:/**< User presses a key*/
            {                
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
        generate_view(&map);
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



