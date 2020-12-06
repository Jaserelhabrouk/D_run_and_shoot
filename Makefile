#all:
#	gcc src/main.c 
#src/user_manual.c 
#src/is_reach_goal.c 
#src/win_game.c 
#src/print_menu.c 
#src/credit.c 
#src/single_player.c 
#src/game_over.c 
#src/take_heart.c 
#src/is_player_hit.c 
#src/is_barrier_hit.c 
#src/load_map.c 
#src/update_player_pos.c 
#src/generate_view.c 
#src/update_barrier.c 
#src/update_arrow.c -l sdl2 -l sdl2_ttf

CC=gcc 
INCLUDES = include/map.h include/menu.h include/single_player.h include/map_textures.h

#LIBFLAGS = -lmingw32 -lSDL2main -lSDL2
LIBFLAGS = -l sdl2 -l sdl2_ttf

#OBJECTS = main.o credit.o game_over.o generate_view.o is_barrier_hit.o \
# 		  is_player_hit.o is_reach_goal.o load_map.o print_menu.o \
# 		  single_player.o take_heart.o update_arrow.o update_barrier.o \
# 		  update_player_pos.o user_manual.o win_game.o

OBJECTS = build/main.o build/credit.o build/game_over.o build/generate_view.o build/is_barrier_hit.o \
 		  build/is_player_hit.o build/is_reach_goal.o build/load_map.o build/print_menu.o \
 		  build/single_player.o build/take_heart.o build/update_arrow.o build/update_barrier.o \
 		  build/update_player_pos.o build/user_manual.o build/win_game.o
 		 
main : $(OBJECTS)
	$(CC) -o main $(OBJECTS) $(LIBFLAGS)

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
