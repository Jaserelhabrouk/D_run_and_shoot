all:
	gcc src/main.c src/user_manual.c src/is_reach_goal.c src/win_game.c src/print_menu.c src/credit.c src/single_player.c src/game_over.c src/take_heart.c src/is_player_hit.c src/is_barrier_hit.c src/load_map.c src/update_player_pos.c src/generate_view.c src/update_barrier.c src/update_arrow.c -l sdl2 -l sdl2_ttf -l sdl2_image
