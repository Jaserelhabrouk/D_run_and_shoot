ifdef OS
# WINDOWS version
# TODO
else
	LIBFLAGS = -l sdl2 -l sdl2_ttf
endif

CC=gcc 

INCLUDES = include/map.h include/menu.h include/single_player.h include/map_textures.h

OBJECTS = build/main.o build/credit.o build/game_over.o build/generate_view.o build/is_barrier_hit.o \
 		  build/is_player_hit.o build/is_reach_goal.o build/load_map.o build/print_menu.o \
 		  build/single_player.o build/take_heart.o build/update_arrow.o build/update_barrier.o \
 		  build/update_player_pos.o build/user_manual.o build/win_game.o \
 		  build/options.o build/print_options.o
 		 
build/main : $(OBJECTS)
	$(CC) -o build/main $(OBJECTS) $(LIBFLAGS)

#TARGET TO GENERATE THE OBJECT FILES 
build/main.o: src/main.c $(INCLUDES)
	$(CC) -c src/main.c -o build/main.o

build/credit.o: src/credit.c $(INCLUDES)
	$(CC) -c src/credit.c -o build/credit.o

build/game_over.o: src/game_over.c $(INCLUDES)
	$(CC) -c src/game_over.c -o build/game_over.o

build/generate_view.o: src/generate_view.c $(INCLUDES)
	$(CC) -c src/generate_view.c -o build/generate_view.o

build/is_barrier_hit.o: src/is_barrier_hit.c $(INCLUDES)
	$(CC) -c src/is_barrier_hit.c -o build/is_barrier_hit.o

build/is_player_hit.o: src/is_player_hit.c $(INCLUDES)
	$(CC) -c src/is_player_hit.c -o build/is_player_hit.o

build/is_reach_goal.o: src/is_reach_goal.c $(INCLUDES)
	$(CC) -c src/is_reach_goal.c -o build/is_reach_goal.o

build/load_map.o: src/load_map.c $(INCLUDES)
	$(CC) -c src/load_map.c -o build/load_map.o

build/print_menu.o: src/print_menu.c $(INCLUDES)
	$(CC) -c src/print_menu.c -o build/print_menu.o

build/single_player.o: src/single_player.c $(INCLUDES)
	$(CC) -c src/single_player.c -o build/single_player.o

build/take_heart.o: src/take_heart.c $(INCLUDES)
	$(CC) -c src/take_heart.c -o build/take_heart.o

build/update_arrow.o: src/update_arrow.c $(INCLUDES)
	$(CC) -c src/update_arrow.c -o build/update_arrow.o

build/update_barrier.o: src/update_barrier.c $(INCLUDES)
	$(CC) -c src/update_barrier.c -o build/update_barrier.o

build/update_player_pos.o: src/update_player_pos.c $(INCLUDES)
	$(CC) -c src/update_player_pos.c -o build/update_player_pos.o

build/user_manual.o: src/user_manual.c $(INCLUDES)
	$(CC) -c src/user_manual.c -o build/user_manual.o

build/win_game.o: src/win_game.c $(INCLUDES)
	$(CC) -c src/win_game.c -o build/win_game.o

build/options.o: src/options.c $(INCLUDES)
	$(CC) -c src/options.c -o build/options.o

build/print_options.o: src/print_options.c $(INCLUDES)
	$(CC) -c src/print_options.c -o build/print_options.o

	
#CLEAN COMMANDS 
clean:  
	rm -f bin/* build/* 