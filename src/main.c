#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <SDL.h>
#include <sdl_ttf.h>
#include <SDL_image.h>
#include <stdbool.h>
#include "map.h"

SDL_Window* g_window = NULL;
SDL_Renderer* g_renderer = NULL;

TTF_Font* g_font = NULL;
/**define the constants representing different texture*/
SDL_Texture* g_player_texture = NULL;
SDL_Texture* g_barrier_texture = NULL;
SDL_Texture* g_arrow_down_texture = NULL;
SDL_Texture* g_arrow_up_texture = NULL;
SDL_Texture* g_goal_texture = NULL;

int g_screen_width = 1024;
int g_screen_height = 768;

///** define the width and height of the scrren.*/
//const int SCREEN_WIDTH = 1024;
//const int SCREEN_HEIGHT = 768;
//
//SDL_Window* g_window = NULL;
//SDL_Renderer* g_renderer = NULL;
//
//TTF_Font* g_font=NULL;
///**define the global variables representing different texture*/
//SDL_Texture* g_player_texture = NULL;			
//SDL_Texture* g_barrier_texture = NULL;
//SDL_Texture* g_arrow_down_texture = NULL;
//SDL_Texture* g_arrow_up_texture = NULL;
//SDL_Texture* g_goal_texture = NULL;	

//SDL_Texture* Load_image(const char* filePath)
//{
//    SDL_Surface* p_picture = NULL;
//
//    p_picture = IMG_Load(filePath);
//    
//    /**set the background to be transparent*/
//    Uint32 colorkey = SDL_MapRGB(p_picture->format, 0, 0, 0);
//    SDL_SetColorKey(p_picture, SDL_TRUE, colorkey);
//
//    SDL_Texture* p_result = SDL_CreateTextureFromSurface(g_renderer, p_picture);
//    SDL_FreeSurface(p_picture);
//
//    return p_result;
//}

int main()
{
    //update_barrier_test();
    //take_heart_test();

    generate_view_test();
}



