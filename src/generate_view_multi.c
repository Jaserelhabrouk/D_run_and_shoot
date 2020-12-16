/**
* @file generate_view_multi.c
* @author Jin
*/

#include"../include/map.h"
#include <stdio.h>

#ifdef _WIN32
#include <SDL.h>
#include <SDL_ttf.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#endif


/**
* \brief generate_view_multi function
*
* This function is to generate a graphic map using updated information
* @param[in] p_window a SDL window which is passed from the main function.
* @param[in] p_map a defined map which is passed from the main function.
* @return void
*/
void generate_view_multi(SDL_Window* p_window, map_t* p_map)
{
    SDL_Renderer* p_renderer = SDL_GetRenderer(p_window);
    SDL_RenderClear(p_renderer);

    /**setups for font and color of the text*/
    TTF_Font* p_font = TTF_OpenFont("data/FreeSans.ttf", 15);
    SDL_Color color = { 0, 255, 255 };
    char heart_num[10], heart_num1[10];

    SDL_Texture* p_barrier_texture = p_map->textures.p_texture_barrier;
    SDL_Texture* p_arrow_down_texture = p_map->textures.p_texture_arrow_down;
    SDL_Texture* p_arrow_up_texture = p_map->textures.p_texture_arrow_up;
    SDL_Texture* p_goal_texture = p_map->textures.p_texture_goal;
    SDL_Texture* p_player_texture = p_map->textures.p_texture_player[PLAYER_1];
    SDL_Texture* p_heart_texture = p_map->textures.p_texture_heart[PLAYER_1];
    SDL_Texture* p_heartNum_texture = NULL;
    SDL_Texture* p_player_texture1 = p_map->textures.p_texture_player[PLAYER_2];
    SDL_Texture* p_heart_texture1 = p_map->textures.p_texture_heart[PLAYER_2];
    SDL_Texture* p_heartNum_texture1 = NULL;
    SDL_Texture* p_bullet_texture = p_map->textures1.p_textture_bullet;


    int w = 0;
    int h = 0;

    /**draw barriers'textures on a SDL window with renders*/
    for (int i = 0; i < p_map->number_of_barriers; i++)
    {
        SDL_QueryTexture(p_barrier_texture, NULL, NULL, &w, &h);
        map_barrier_t* p_bar = &p_map->barrier[i];
        SDL_Rect barrier_rect = { p_bar->current_pos.x, p_bar->current_pos.y, w, h };
        SDL_RenderCopy(p_renderer, p_barrier_texture, NULL, &barrier_rect);
    }

    /**draw arrows'textures on a SDL window with renders*/
    for (int i = 0; i < p_map->number_of_arrows; i++)
    {
        if (p_map->arrow[i].direction == DIRECTION_DOWN)
        {
            SDL_QueryTexture(p_arrow_down_texture, NULL, NULL, &w, &h);
            arrow_t* p_arr = &p_map->arrow[i];
            SDL_Rect arrow_rect = { p_arr->current_pos.x, p_arr->current_pos.y,  w, h };
            SDL_RenderCopy(p_renderer, p_arrow_down_texture, NULL, &arrow_rect);
        }
        else if (p_map->arrow[i].direction == DIRECTION_UP)
        {
            SDL_QueryTexture(p_arrow_up_texture, NULL, NULL, &w, &h);
            arrow_t* p_arr = &p_map->arrow[i];
            SDL_Rect arrow_rect = { p_arr->current_pos.x, p_arr->current_pos.y,  w, h };
            SDL_RenderCopy(p_renderer, p_arrow_up_texture, NULL, &arrow_rect);
        }
    }
    /**draw the goal's texture on a SDL window with renders*/
    SDL_QueryTexture(p_goal_texture, NULL, NULL, &w, &h);
    SDL_Rect goal_rect = { p_map->goal.pos.x, p_map->goal.pos.y,  w, h };
    SDL_RenderCopy(p_renderer, p_goal_texture, NULL, &goal_rect);

    /**draw the player's 1 texture on a SDL window with renders*/
    if (p_map->player[PLAYER_1].heart > 0) {
        SDL_QueryTexture(p_player_texture, NULL, NULL, &w, &h);
        SDL_Rect player_rect = { p_map->player[PLAYER_1].current_pos.x, p_map->player[PLAYER_1].current_pos.y,  w, h };
        SDL_RenderCopy(p_renderer, p_player_texture, NULL, &player_rect);

        /**draw the hearts'texture on a SDL window with renders*/
        SDL_QueryTexture(p_heart_texture, NULL, NULL, &w, &h);
        SDL_Rect heart_rect = { p_map->space.x_max - 50, p_map->space.y_max - 50,  w, h };
        SDL_RenderCopy(p_renderer, p_heart_texture, NULL, &heart_rect);

        /**draw the texture of the number of the player's hearts on a SDL window with renders*/
        sprintf(heart_num, "%d", p_map->player[PLAYER_1].heart);
        SDL_Surface* p_surface = TTF_RenderText_Solid(p_font, heart_num, color);

        p_heartNum_texture = SDL_CreateTextureFromSurface(p_renderer, p_surface);
        SDL_QueryTexture(p_heartNum_texture, NULL, NULL, &w, &h);
        SDL_Rect heartNum_rect = { p_map->space.x_max - 28, p_map->space.y_max - 48,  w, h };
        SDL_RenderCopy(p_renderer, p_heartNum_texture, NULL, &heartNum_rect);
        SDL_FreeSurface(p_surface);
    }

    /**draw the player's 1 texture on a SDL window with renders*/
    if (p_map->player[PLAYER_2].heart > 0) {
        SDL_QueryTexture(p_player_texture1, NULL, NULL, &w, &h);
        SDL_Rect player_rect1 = { p_map->player[PLAYER_2].current_pos.x, p_map->player[PLAYER_2].current_pos.y,  w, h };
        SDL_RenderCopy(p_renderer, p_player_texture1, NULL, &player_rect1);

        /**draw the hearts'texture on a SDL window with renders*/
        SDL_QueryTexture(p_heart_texture1, NULL, NULL, &w, &h);
        SDL_Rect heart_rect1 = { p_map->space.x_min + 50, p_map->space.y_max - 50,  w, h };
        SDL_RenderCopy(p_renderer, p_heart_texture1, NULL, &heart_rect1);

        /**draw the texture of the number of the player's hearts on a SDL window with renders*/
        sprintf(heart_num1, "%d", p_map->player[PLAYER_2].heart);
        SDL_Surface*  p_surface = TTF_RenderText_Solid(p_font, heart_num1, color);

        p_heartNum_texture1 = SDL_CreateTextureFromSurface(p_renderer, p_surface);
        SDL_QueryTexture(p_heartNum_texture1, NULL, NULL, &w, &h);
        SDL_Rect heartNum_rect1 = { p_map->space.x_min + 72, p_map->space.y_max - 48,  w, h };
        SDL_RenderCopy(p_renderer, p_heartNum_texture1, NULL, &heartNum_rect1);
        SDL_FreeSurface(p_surface);
    }


    if (p_map->player[PLAYER_1].bullet_is_active) {
        SDL_QueryTexture(p_bullet_texture, NULL, NULL, &w, &h);
        SDL_Rect bullet_rect1 = { p_map->player[PLAYER_1].bullet.current_pos.x, p_map->player[PLAYER_1].bullet.current_pos.y,  w, h };
        SDL_RenderCopy(p_renderer, p_bullet_texture, NULL, &bullet_rect1);
    }

    if (p_map->player[PLAYER_2].bullet_is_active) {
        SDL_QueryTexture(p_bullet_texture, NULL, NULL, &w, &h);
        SDL_Rect bullet_rect2 = { p_map->player[PLAYER_2].bullet.current_pos.x, p_map->player[PLAYER_2].bullet.current_pos.y,  w, h };
        SDL_RenderCopy(p_renderer, p_bullet_texture, NULL, &bullet_rect2);
    }

    /**Display the content to render*/
    SDL_RenderPresent(p_renderer);
    /**Destroy*/
    SDL_DestroyTexture(p_heartNum_texture);
    TTF_CloseFont(p_font);
}
