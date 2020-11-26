#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#ifdef _WIN64
#include <SDL.h>
#include <sdl_ttf.h>
#include <SDL_image.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/sdl_ttf.h>
#include <SDL2/SDL_image.h>
#endif
#include <stdbool.h>
#include "../include/map.h"
#include "../include/common.h"
#include "../include/menu.h"
#include "../include/credit.h"
#include "../include/single_player.h"

int main()
{

    /*initialize SDL*/
    TTF_Init();

    /*initialize and open a window*/
    SDL_Window* p_window = SDL_CreateWindow(
                               "Run and Shoot",
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               SCREEN_WIDTH,
                               SCREEN_HEIGHT,
                               SDL_WINDOW_RESIZABLE);

    if (p_window == NULL)
    {
        printf("Window could not create: %s\n", SDL_GetError());
        assert(false);
    }

    menu_t menu = {
            .selector = MENU_ITEM_USER_MANUAL,
            .items[0] = {"User manual"},
            .items[1] = {"Single player"},
            .items[2] = {"Credit"},
            .items[3] = {"Exit"}
    };

    /*initialize a renderer*/
    SDL_Renderer* p_renderer = SDL_CreateRenderer(p_window, -1, 0);

    print_menu(p_window, &menu);

    /*quit the window if the quit botton is pressed*/
    bool quit = false;
    SDL_Event event;
    while (!quit)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
            {
                quit = true;
                break;
            }
            case SDL_KEYDOWN:
            {
                if (event.key.keysym.sym == SDLK_DOWN)
                {
                    if (menu.selector < MENU_ITEM_NUM_OF_ITEMS - 1)
                    {
                        menu.selector++;
                    }
                    print_menu(p_window, &menu);

                }
                else if (event.key.keysym.sym == SDLK_UP)
                {
                    if (menu.selector > 0)
                    {
                        menu.selector--;
                    }
                    print_menu(p_window, &menu);
                }
                else if (event.key.keysym.sym == SDLK_RETURN)
                {
                    if (menu.selector == MENU_ITEM_USER_MANUAL)
                    {
                        quit = user_manual(p_window);
                        print_menu(p_window, &menu);
                    }
                    else if (menu.selector == MENU_ITEM_SINGLE_PLAYER)
                    {
                        quit = single_player(p_window);
                        print_menu(p_window, &menu);
                    }
                    else if (menu.selector == MENU_ITEM_CREDIT)
                    {
                        quit = credit(p_window);
                        print_menu(p_window, &menu);
                    }
                    if (menu.selector == MENU_ITEM_EXIT)
                    {
                        quit = true;
                    }
                    break;
                }
                break;
            }
            default:
                break;
        }
    }

    SDL_DestroyRenderer(p_renderer);
    SDL_DestroyWindow(p_window);
    TTF_Quit();
    return 0;
}



