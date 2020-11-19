/**
* @file update_view.c
* @author Jin
*/

#include"map.h"
#include<stdio.h>
#include <SDL.h>


extern SDL_Window* g_window ;
extern SDL_Renderer* g_renderer;

extern TTF_Font* g_font;
/**define the constants representing different texture*/
extern SDL_Texture* g_player_texture;
extern SDL_Texture* g_barrier_texture;
extern SDL_Texture* g_arrow_down_texture;
extern SDL_Texture* g_arrow_up_texture;
extern SDL_Texture* g_goal_texture;


/* Block: generate a view- first release
* Assigned to: Jin
* Generate a 2d graphic map using updated information
* Input: map
* Return: void */
void generate_view(map_t* p_map){

    for (int i = 0;i < p_map->number_of_barriers;i++)
    {
        map_barrier_t* p_bar = &p_map->barrier[i];
        SDL_Rect barrier_rect = { p_bar->current_pos.x, p_bar->current_pos.y,  250, 10 };
        SDL_RenderCopy(g_renderer, g_barrier_texture, NULL, &barrier_rect);
    }


    for (int i = 0;i < p_map->number_of_arrows;i++)
    {
        arrow_t* p_arr = &p_map->arrow[i];
        SDL_Rect arrow_rect = { p_arr->current_pos.x, p_arr->current_pos.y,  11, 50 };
        SDL_RenderCopy(g_renderer, g_arrow_down_texture, NULL, &arrow_rect);

       /* if (p_arr->direction == DIRECTION_DOWN)
        {
            SDL_RenderCopy(p_renderer, p_arrow_down_texture, NULL, &arrow_rect);
        }
        else {
            SDL_RenderCopy(p_renderer, p_arrow_up_texture, NULL, &arrow_rect);

        }*/
    }

    SDL_Rect goal_rect = { p_map->goal.pos.x, p_map->goal.pos.y,  50, 50 };
    SDL_RenderCopy(g_renderer, g_goal_texture, NULL, &goal_rect);

    SDL_Rect player_rect = {  p_map->player.current_pos.x, p_map->player.current_pos.y,  50, 50    };
    SDL_RenderCopy(g_renderer, g_player_texture, NULL, &player_rect);

    /**Display the content to render*/
    SDL_RenderPresent(g_renderer);
}
