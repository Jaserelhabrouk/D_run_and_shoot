#ifdef _WIN64
#include <SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "../include/map.h"
#include "../include/single_player.h"
#include "../include/map_textures.h"

#define TIMER_INTERVAL 20

Uint32 timer_callback(Uint32 interval, void *param)
{
	SDL_Event event;
	event.type = SDL_USEREVENT;
	SDL_PushEvent(&event);
	return TIMER_INTERVAL;
}

bool single_player(SDL_Window* p_window)
{
	/*initialize timer*/
    SDL_TimerID timer = SDL_AddTimer(TIMER_INTERVAL, timer_callback, NULL);

	/*initialize game state*/
	game_state_t game_state = GAME_STATE_RUN;

	/*initialize and load map*/
	map_t map = load_map("data/map_file.txt");

	SDL_Renderer* p_renderer = SDL_GetRenderer(p_window);
	SDL_RenderClear(p_renderer);
	SDL_RenderPresent(p_renderer);

	/*initialize map textures*/
    map.textures.p_texture_player = get_player_texture(p_renderer);
	map.textures.p_texture_heart = get_heart_texture(p_renderer);
    map.textures.p_texture_goal = get_goal_texture(p_renderer);
    map.textures.p_texture_arrow_down = get_arrow_down_texture(p_renderer);
    map.textures.p_texture_arrow_up = get_arrow_up_texture(p_renderer);
    map.textures.p_texture_barrier = get_barrier_texture(p_renderer, map.barrier[0].length);

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
				case SDL_KEYDOWN:
				{
				    if (event.key.keysym.sym == SDLK_BACKSPACE)
				    {
				        quit = true;
				    }
				    else if (event.key.keysym.sym == SDLK_SPACE)
				    {
						/*space: to stop the game*/
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
				                                event.key.keysym.sym == SDLK_DOWN ? DIRECTION_DOWN:
				                                event.key.keysym.sym == SDLK_RIGHT? DIRECTION_RIGHT: DIRECTION_LEFT;

						if (is_barrier_hit(map, direction) == false)
						{
						    update_player_pos(&map.player, direction);
						}
					}
					break;
				}
				case SDL_USEREVENT: /*timer*/
				{
					if (game_state == GAME_STATE_RUN)
					{
						update_barrier(map.barrier, &map);
						update_arrow(map.arrow, &map);
                        generate_view(p_window, &map);

					    if (is_player_hit(&map) == true)
                        {
                            take_heart(&map.player);
                            if (map.player.heart == 0)
                            {
                                game_over(p_window);
                                game_state = GAME_STATE_LOSE;
                            }
                        }
                        else if (is_reach_goal(&map.player, &map.goal) == true)
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

