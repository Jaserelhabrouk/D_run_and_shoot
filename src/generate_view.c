/**
* @file update_view.c
* @author Jin
*/

#include"map.h"
#include<stdio.h>
#include <SDL.h>


/* Block: generate a view- first release
* Assigned to: Jin
* Generate a 2d graphic map using updated information
* Input: map
* Return: void */
void update_view(map_t* p_map, SDL_Renderer* p_renderer, SDL_Texture* p_player_texture,SDL_Texture* p_goal_texture, SDL_Texture* p_barrier_texture, SDL_Texture* p_arrow_down_texture, SDL_Texture* p_arrow_up_texture) {
    if (p_map->barrier != NULL)
    {
        update_barrier(p_map);
    }
    if (p_map->arrow != NULL)
    {
        update_arrow(p_map);
    }

    //updatePlayerPos(&map.player, arrowKey);

    for (int i = 0;i < p_map->number_of_barriers;i++)
    {
        map_barrier_t* p_bar = &p_map->barrier[i];
        SDL_Rect barrier_rect = { p_bar->current_pos.x, p_bar->current_pos.y,  250, 10 };
        SDL_RenderCopy(p_renderer, p_barrier_texture, NULL, &barrier_rect);
    }


    for (int i = 0;i < p_map->number_of_arrows;i++)
    {
        map_barrier_t* p_arr = &p_map->arrow[i];
        SDL_Rect arrow_rect = { p_arr->current_pos.x, p_arr->current_pos.y,  11, 50 };
        if (p_arr->current_dir == DIRECTION_DOWN)
        {
            SDL_RenderCopy(p_renderer, p_arrow_down_texture, NULL, &arrow_rect);
        }
        else {
            SDL_RenderCopy(p_renderer, p_arrow_up_texture, NULL, &arrow_rect);

        }
    }

    SDL_Rect goal_rect = { p_map->goal.pos.x, p_map->goal.pos.y,  50, 50 };
    SDL_RenderCopy(p_renderer, p_goal_texture, NULL, &goal_rect);

    SDL_Rect player_rect = {  p_map->player.current_pos.x, p_map->player.current_pos.y,  50, 50    };
    SDL_RenderCopy(p_renderer, p_player_texture, NULL, &player_rect);
}
