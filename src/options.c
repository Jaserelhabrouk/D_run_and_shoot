/**
 * @file option.c
 * @brief Contains print_option and options function.
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
#include "../include/menu.h"

/**
* @brief Handles user input to choose between difficulty levels.
*
* This function show you different level of difficulty and let
* user to choos between difficulty levels using return key.
* @param[in] p_window A SDL window is passed to the function.
* @param[out] p_option_items final selected item.
* @return bool if window is quit or back_space key is pressed, return true.
*/
bool options(SDL_Window* p_window, option_items_t* p_option_items) {

    /**initialize menu structure*/
    option_t options = {
           .selector = OPTION_ITEM_INTERMEDIATE,
           .items[0] = {"Easy"},
           .items[1] = {"Intermediate"},
           .items[2] = {"Hard"},
    };
    /**read an event until window is not quit.*/
    SDL_Event event;
    bool quit = false;
    print_options(p_window, &options);
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
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
                        if (options.selector < OPTION_ITEM_NUM_OF_ITEMS - 1)
                        {
                            options.selector++;
                        }
                    }
                    else if (event.key.keysym.sym == SDLK_UP)
                    {
                        if (options.selector > 0)
                        {
                            options.selector--;
                        }
                    }
                    else if (event.key.keysym.sym == SDLK_RETURN)
                    {
                        *p_option_items = options.selector;
                        quit = true;
                    }
                    print_options(p_window, &options);
                    break;
                }
                default:
                    break;
            }
        }
    }
    return event.type == SDL_QUIT;
}
