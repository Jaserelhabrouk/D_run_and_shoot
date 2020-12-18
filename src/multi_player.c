/**
 * @file multi_player.c
 * @author Jin
 * \brief main file which handle multi player mode.
 */
#ifdef _WIN64
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "../include/map.h"
#include "../include/multi_player.h"
#include "../include/map_textures.h"

#define TIMER_INTERVAL 20


/**
 * @brief multi_player function
 *
 * This is the main function which handle multi player mode.
 * Different functions are called here: first a map file is loaded and then
 * according to the input key different entities is updated and a view will be generated.
 * A timer is initialized to update every thing in each TIMER_INTERVAL seconds.
 * @param[in] p_window a SDL window which is passed from the main function.
 * @param[in] difficulty game difficulty specify the map file that should be loaded.
 * @return bool if window is quit or back_space key is pressed, return true.
 */
bool multi_player(SDL_Window* p_window,option_items_t difficulty)
{
	/*initialize timer*/
	SDL_TimerID timer = SDL_AddTimer(TIMER_INTERVAL, timer_callback, NULL);

	/*initialize game state*/
	game_state_t game_state = GAME_STATE_RUN;

	/*initialize and load map*/
    map_t map = {0};
    switch (difficulty)
    {
        case OPTION_ITEM_EASY:
        {
            map = load_map("data/multi_player_easy.txt");
            break;
        }
        case OPTION_ITEM_INTERMEDIATE:
        {
            map = load_map("data/multi_player_intermediate.txt");
            break;
        }
        case OPTION_ITEM_HARD:
        {
            map = load_map("data/multi_player_hard.txt");
            break;
        }
        default:
        {
            map = load_map("data/multi_player_easy.txt");
            break;
        }
    }

	SDL_Renderer* p_renderer = SDL_GetRenderer(p_window);
	SDL_RenderClear(p_renderer);
	SDL_RenderPresent(p_renderer);

	/*initialize map textures*/
	map.textures.p_texture_player[PLAYER_1] = get_player_texture(p_renderer, PLAYER_1);
	map.textures.p_texture_player[PLAYER_2] = get_player_texture(p_renderer, PLAYER_2);
	map.textures.p_texture_heart[PLAYER_1] = get_heart_texture(p_renderer, PLAYER_1);
	map.textures.p_texture_heart[PLAYER_2] = get_heart_texture(p_renderer, PLAYER_2);
	map.textures.p_texture_goal = get_goal_texture(p_renderer);
	map.textures.p_texture_arrow_down = get_arrow_down_texture(p_renderer);
	map.textures.p_texture_arrow_up = get_arrow_up_texture(p_renderer);
	map.textures.p_texture_barrier = get_barrier_texture(p_renderer, map.barrier[0].length);
	map.textures1.p_textture_bullet = get_bullet_texture(p_renderer);

	/*read an event until window is not quit.*/
	SDL_Event event;
	bool quit = false;
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
			case SDL_KEYUP:
			{
				if (event.key.keysym.sym == SDLK_BACKSPACE)
				{
					quit = true;
				}
				else if (event.key.keysym.sym == SDLK_SPACE)
				{
					/**press space key to stop or play the game*/
					if (game_state == GAME_STATE_RUN)
					{
						game_state = GAME_STATE_PAUSE;
					}
					else if (game_state == GAME_STATE_PAUSE)
					{
						game_state = GAME_STATE_RUN;
					}
					else
					{
						assert(false);
					}
				}
				else if (event.key.keysym.sym == SDLK_UP ||
					event.key.keysym.sym == SDLK_DOWN ||
					event.key.keysym.sym == SDLK_RIGHT ||
					event.key.keysym.sym == SDLK_LEFT)
				{
					direction_t direction = event.key.keysym.sym == SDLK_UP ? DIRECTION_UP :
						event.key.keysym.sym == SDLK_DOWN ? DIRECTION_DOWN :
						event.key.keysym.sym == SDLK_RIGHT ? DIRECTION_RIGHT : DIRECTION_LEFT;

					if ((is_barrier_hit(map, direction, PLAYER_1) == false) && (map.player[PLAYER_1].heart > 0))
					{
						update_player_pos(&map.player[PLAYER_1], direction);
					}
				}
				else if (event.key.keysym.sym == SDLK_w ||
					event.key.keysym.sym == SDLK_s||
					event.key.keysym.sym == SDLK_d ||
					event.key.keysym.sym == SDLK_a)
				{
					direction_t direction = event.key.keysym.sym == SDLK_w ? DIRECTION_UP :
						event.key.keysym.sym == SDLK_s ? DIRECTION_DOWN :
						event.key.keysym.sym == SDLK_d ? DIRECTION_RIGHT : DIRECTION_LEFT;

					if ((is_barrier_hit(map, direction, PLAYER_2) == false) && (map.player[PLAYER_2].heart > 0))
					{
						update_player_pos(&map.player[PLAYER_2], direction);
					}
				}

				else if (event.key.keysym.sym == SDLK_m) {
					shoot(&map, PLAYER_1);
				}
				else if (event.key.keysym.sym == SDLK_g) {
					shoot(&map, PLAYER_2);
				}


				break;
			}
			case SDL_USEREVENT: /**timer*/
			{
				if (game_state == GAME_STATE_RUN)
				{
					update_barrier(map.barrier, &map);
					update_arrow(map.arrow, &map);
					update_bullet(&map, PLAYER_1);
					update_bullet(&map, PLAYER_2);
					generate_view_multi(p_window, &map);

					if (is_player_hit(&map, PLAYER_1) == true)
					{
						take_heart(&map.player[PLAYER_1]);
						if ((map.player[PLAYER_1].heart == 0) && (map.player[PLAYER_2].heart == 0))
						{
							game_over(p_window);
							game_state = GAME_STATE_LOSE;
						}
						
					}
					else if (is_player_hit(&map, PLAYER_2) == true)
					{
						take_heart(&map.player[PLAYER_2]);
						if ((map.player[PLAYER_1].heart == 0) && (map.player[PLAYER_2].heart == 0))
						{
							game_over(p_window);
							game_state = GAME_STATE_LOSE;
						}

					}
					else if (is_bullet_hit(&map, PLAYER_1) == true) {
						take_heart(&map.player[PLAYER_1]);
					}
					else if (is_bullet_hit(&map, PLAYER_2) == true) {
						take_heart(&map.player[PLAYER_2]);
					}
					else if ((is_reach_goal(&map.player[PLAYER_1], &map.goal) == true) || (is_reach_goal(&map.player[PLAYER_2], &map.goal) == true))
					{
						win_game(p_window);
						game_state = GAME_STATE_WIN;
					}
				}
				break;
			}
			default:
			{
				break;
			}
			}
		}
	}
	SDL_RemoveTimer(timer);
	return event.type == SDL_QUIT;
}
