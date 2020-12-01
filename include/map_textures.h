/**
 * @file map_texture.h
 * @brief function declaration and type definition to create the map texture.
 */

#ifndef INCLUDE_MAP_TEXTURES_H_
#define INCLUDE_MAP_TEXTURES_H_

#ifdef _WIN64
#include <SDL.h>
#include <sdl_ttf.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/sdl_ttf.h>
#endif


#define MAP_TEXTURE_PLAYER_WIDTH 30
#define MAP_TEXTURE_PLAYER_HEIGHT 30
#define MAP_TEXTURE_HEART_WIDTH 25
#define MAP_TEXTURE_HEART_HEIGHT 25
#define MAP_TEXTURE_GOAL_WIDTH 30
#define MAP_TEXTURE_GOAL_HEIGHT 30
#define MAP_TEXTURE_ARROW_WIDTH 10
#define MAP_TEXTURE_ARROW_HEIGHT 40
#define MAP_TEXTURE_BARRIER_HEIGHT 3

/**
 * @brief creats player texture.
 * @param[in] p_renderer
 * @return p_texture player texture
 */
static inline SDL_Texture* get_player_texture(SDL_Renderer* p_renderer)
{
    SDL_Surface* p_surface = SDL_CreateRGBSurface(SDL_SWSURFACE,
                                                  MAP_TEXTURE_PLAYER_WIDTH,   //width,
                                                  MAP_TEXTURE_PLAYER_HEIGHT,  //height,
                                                  32,    //depth,
                                                  0xff000000,  // Rmask,
                                                  0x00ff0000,  // Gmask,
                                                  0x0000ff00,  // Bmask,
                                                  0x000000ff); //Amask



    Uint32 pixels[MAP_TEXTURE_PLAYER_HEIGHT * MAP_TEXTURE_PLAYER_WIDTH] = {
            0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
            0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
            0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
            0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1,
            0, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 0,
            0, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 0,
            0, 0, 1, 1, 1, 1, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 1, 1, 1, 1, 0, 0,
            0, 0, 0, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < MAP_TEXTURE_PLAYER_HEIGHT * MAP_TEXTURE_PLAYER_WIDTH; i++)
    {
        if (pixels[i] == 1)
        {
            pixels[i] = 0xffff00ff;
        }
        else if(pixels[i] == 3)
        {
            pixels[i] = 0xe31b1bff;
        }
    }

    SDL_LockSurface(p_surface);
    SDL_memcpy(p_surface->pixels, pixels, p_surface->h * p_surface->pitch);
    SDL_UnlockSurface(p_surface);

    SDL_Texture* p_texture = SDL_CreateTextureFromSurface(p_renderer, p_surface);

    return p_texture;
}

/**
 * @brief creats heart texture.
 * @param[in] p_renderer
 * @return p_texture heart texture
 */
static inline SDL_Texture* get_heart_texture(SDL_Renderer* p_renderer)
{
    SDL_Surface* p_surface = SDL_CreateRGBSurface(SDL_SWSURFACE,
                                                  MAP_TEXTURE_HEART_WIDTH,   //width,
                                                  MAP_TEXTURE_HEART_HEIGHT,  //height,
                                                  32,    //depth,
                                                  0xff000000,  // Rmask,
                                                  0x00ff0000,  // Gmask,
                                                  0x0000ff00,  // Bmask,
                                                  0x000000ff); //Amask



    Uint32 pixels[MAP_TEXTURE_HEART_WIDTH * MAP_TEXTURE_HEART_HEIGHT] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
            0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 
            0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
           };


    for (int i = 0; i < MAP_TEXTURE_HEART_WIDTH * MAP_TEXTURE_HEART_HEIGHT; i++)
    {
        if (pixels[i] == 1)
        {
            pixels[i] = 0xe31b1bff;
        }
       
    }

    SDL_LockSurface(p_surface);
    SDL_memcpy(p_surface->pixels, pixels, p_surface->h * p_surface->pitch);
    SDL_UnlockSurface(p_surface);

    SDL_Texture* p_texture = SDL_CreateTextureFromSurface(p_renderer, p_surface);

    return p_texture;
}

/**
 * @brief creats goal texture.
 * @param[in] p_renderer
 * @return p_texture goal texture
 */
static inline SDL_Texture* get_goal_texture(SDL_Renderer* p_renderer)
{
    SDL_Surface* p_surface = SDL_CreateRGBSurface(SDL_SWSURFACE,
                                                  MAP_TEXTURE_GOAL_WIDTH,   //width,
                                                  MAP_TEXTURE_GOAL_HEIGHT,  //height,
                                                  32,    //depth,
                                                  0xff000000,  // Rmask,
                                                  0x00ff0000,  // Gmask,
                                                  0x0000ff00,  // Bmask,
                                                  0x000000ff); //Amask

    Uint32 pixels[MAP_TEXTURE_GOAL_WIDTH * MAP_TEXTURE_GOAL_HEIGHT] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0,
            0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0,
            0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < MAP_TEXTURE_GOAL_WIDTH * MAP_TEXTURE_GOAL_HEIGHT; i++)
    {
      if (pixels[i] == 1)
      {
          pixels[i] = 0xffff00ff;
      }
    }

    SDL_LockSurface(p_surface);
    SDL_memcpy(p_surface->pixels, pixels, p_surface->h * p_surface->pitch);
    SDL_UnlockSurface(p_surface);

    SDL_Texture* p_texture = SDL_CreateTextureFromSurface(p_renderer, p_surface);

    return p_texture;
}

/**
 * @brief creats arrow down texture.
 * @param[in] p_renderer
 * @return p_texture arrow down texture
 */
static inline SDL_Texture* get_arrow_down_texture(SDL_Renderer* p_renderer)
{
    int width = 10;
    int height = 40;

    SDL_Surface* p_surface = SDL_CreateRGBSurface(SDL_SWSURFACE,
                                                  MAP_TEXTURE_ARROW_WIDTH ,   //width,
                                                  MAP_TEXTURE_ARROW_HEIGHT ,  //height,
                                                  32,    //depth,
                                                  0xff000000,  // Rmask,
                                                  0x00ff0000,  // Gmask,
                                                  0x0000ff00,  // Bmask,
                                                  0x000000ff); //Amask

    Uint32 pixels[MAP_TEXTURE_ARROW_WIDTH * MAP_TEXTURE_ARROW_HEIGHT] = {
            1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
            0, 1, 1, 0, 1, 1, 0, 1, 1, 0,
            0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
            1, 0, 0, 1, 1, 1, 1, 0, 0, 1,
            0, 1, 0, 0, 1, 1, 0, 0, 1, 0,
            0, 0, 1, 0, 1, 1, 0, 1, 0, 0,
            1, 0, 0, 1, 1, 1, 1, 0, 0, 1,
            0, 1, 0, 0, 1, 1, 0, 0, 1, 0,
            0, 0, 1, 0, 1, 1, 0, 1, 0, 0,
            0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 2, 2, 2, 1, 1, 2, 2, 2, 0,
            0, 0, 2, 2, 1, 1, 2, 2, 0, 0,
            0, 0, 2, 2, 1, 1, 2, 2, 0, 0,
            0, 0, 2, 2, 1, 1, 2, 2, 0, 0,
            0, 0, 0, 2, 1, 1, 2, 0, 0, 0,
            0, 0, 0, 2, 2, 2, 2, 0, 0, 0,
            0, 0, 0, 2, 2, 2, 2, 0, 0, 0};

    for (int i = 0; i < MAP_TEXTURE_ARROW_WIDTH * MAP_TEXTURE_ARROW_HEIGHT; i++)
    {
      if (pixels[i] == 2)
      {
          pixels[i] = 0xf51da9ff;
      }
      else if (pixels[i] == 1)
      {
          pixels[i] = 0xefc7ffff;
      }
    }

    SDL_LockSurface(p_surface);
    SDL_memcpy(p_surface->pixels, pixels, p_surface->h * p_surface->pitch);
    SDL_UnlockSurface(p_surface);

    SDL_Texture* p_texture = SDL_CreateTextureFromSurface(p_renderer, p_surface);

    return p_texture;
}

/**
 * @brief creats arrow up texture.
 * @param[in] p_renderer
 * @return p_texture arrow up texture
 */
static inline SDL_Texture* get_arrow_up_texture(SDL_Renderer* p_renderer)
{
    SDL_Surface* p_surface = SDL_CreateRGBSurface(SDL_SWSURFACE,
                                                  MAP_TEXTURE_ARROW_WIDTH ,   //width,
                                                  MAP_TEXTURE_ARROW_HEIGHT,  //height,
                                                  32,    //depth,
                                                  0xff000000,  // Rmask,
                                                  0x00ff0000,  // Gmask,
                                                  0x0000ff00,  // Bmask,
                                                  0x000000ff); //Amask

    Uint32 pixels[MAP_TEXTURE_ARROW_WIDTH * MAP_TEXTURE_ARROW_HEIGHT] = {
            0, 0, 0, 2, 2, 2, 2, 0, 0, 0,
            0, 0, 0, 2, 2, 2, 2, 0, 0, 0,
            0, 0, 0, 2, 1, 1, 2, 0, 0, 0,
            0, 0, 2, 2, 1, 1, 2, 2, 0, 0,
            0, 0, 2, 2, 1, 1, 2, 2, 0, 0,
            0, 0, 2, 2, 1, 1, 2, 2, 0, 0,
            0, 2, 2, 2, 1, 1, 2, 2, 2, 0,
            0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
            0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
            0, 0, 1, 0, 1, 1, 0, 1, 0, 0,
            0, 1, 0, 0, 1, 1, 0, 0, 1, 0,
            1, 0, 0, 1, 1, 1, 1, 0, 0, 1,
            0, 0, 1, 0, 1, 1, 0, 1, 0, 0,
            0, 1, 0, 0, 1, 1, 0, 0, 1, 0,
            1, 0, 0, 1, 1, 1, 1, 0, 0, 1,
            0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
            0, 1, 1, 0, 1, 1, 0, 1, 1, 0,
            1, 1, 0, 0, 1, 1, 0, 0, 1, 1,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 1};

    for (int i = 0; i < MAP_TEXTURE_ARROW_WIDTH * MAP_TEXTURE_ARROW_HEIGHT; i++)
    {
      if (pixels[i] == 2)
      {
          pixels[i] = 0xf51da9ff;
      }
      else if (pixels[i] == 1)
      {
          pixels[i] = 0xefc7ffff;
      }
    }

    SDL_LockSurface(p_surface);
    SDL_memcpy(p_surface->pixels, pixels, p_surface->h * p_surface->pitch);
    SDL_UnlockSurface(p_surface);

    SDL_Texture* p_texture = SDL_CreateTextureFromSurface(p_renderer, p_surface);

    return p_texture;
}

/**
 * @brief creats barrier texture.
 * @param[in] p_renderer
 * @param[in] length of barrier. Read from map file.
 * @return p_texture barrier texture
 */
static inline SDL_Texture* get_barrier_texture(SDL_Renderer* p_renderer, int length)
{
    int width = length;

    SDL_Surface* p_surface = SDL_CreateRGBSurface(SDL_SWSURFACE,
                                                  width,   //width,
                                                  MAP_TEXTURE_BARRIER_HEIGHT,  //height,
                                                  32,    //depth,
                                                  0xff000000,  // Rmask,
                                                  0x00ff0000,  // Gmask,
                                                  0x0000ff00,  // Bmask,
                                                  0x000000ff); //Amask

    Uint32 pixels[MAP_TEXTURE_BARRIER_HEIGHT * width];

    for (int i = 0; i < MAP_TEXTURE_BARRIER_HEIGHT * width; i++)
    {
        pixels[i] = 0xfaa32aff;
    }

    SDL_LockSurface(p_surface);
    SDL_memcpy(p_surface->pixels, pixels, p_surface->h * p_surface->pitch);
    SDL_UnlockSurface(p_surface);

    SDL_Texture* p_texture = SDL_CreateTextureFromSurface(p_renderer, p_surface);

    return p_texture;
}

#endif /* INCLUDE_MAP_TEXTURES_H_ */
