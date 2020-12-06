CC=gcc 

#ifdef _WIN64
	LIBFLAGS= -lmingw32 -lSDL2main -lSDL2
#elif __APPLE__
	LIBFLAGS = -l sdl2 -l sdl2_ttf
#endif


#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME IF THEY DO NOT EXIST
bin_folder := $(shell mkdir -p bin) 
build_folder := $(shell mkdir -p build) 
results_folder := $(shell mkdir -p program_output) 

#TARGET TO GENERATE THE OBJECT FILES 
INCLUDES = include/map.h include/menu.h include/single_player.h include/map_textures.h include/option.h

build/main.o: src/main.c $(INCLUDES)
	$(CC) -g -c src/main.c -o build/main.o
	
build/credit.o: src/credit.c $(INCLUDES)
	$(CC) -g -c src/credit.c -o build/credit.o
	
build/game_over.o: src/game_over.c $(INCLUDES)
	$(CC) -g -c src/game_over.c -o build/game_over.o
	
build/generate_view.o: src/generate_view.c $(INCLUDES)
	$(CC) -g -c src/generate_view.c -o build/generate_view.o
	
build/is_barrier_hit.o: src/is_barrier_hit.c $(INCLUDES)
	$(CC) -g -c src/is_barrier_hit.c -o build/is_barrier_hit.o

build/is_player_hit.o: src/is_player_hit.c $(INCLUDES)
	$(CC) -g -c src/is_player_hit.c -o build/is_player_hit.o

build/is_reach_goal.o: src/is_reach_goal.c $(INCLUDES)
	$(CC) -g -c src/is_reach_goal.c -o build/is_reach_goal.o

build/load_map.o: src/load_map.c $(INCLUDES)
	$(CC) -g -c src/load_map.c -o build/load_map.o

build/print_menu.o: src/print_menu.c $(INCLUDES)
	$(CC) -g -c src/print_menu.c -o build/print_menu.o

build/single_player.o: src/single_player.c $(INCLUDES)
	$(CC) -g -c src/single_player.c -o build/single_player.o

build/take_heart.o: src/take_heart.c $(INCLUDES)
	$(CC) -g -c src/take_heart.c -o build/take_heart.o

build/update_arrow.o: src/update_arrow.c $(INCLUDES)
	$(CC) -g -c src/update_arrow.c -o build/update_arrow.o

build/update_barrier.o: src/update_barrier.c $(INCLUDES)
	$(CC) -g -c src/update_barrier.c -o build/update_barrier.o

build/update_player_pos.o: src/update_player_pos.c $(INCLUDES)
	$(CC) -g -c src/update_player_pos.c -o build/update_player_pos.o
	
build/user_manual.o: src/user_manual.c $(INCLUDES)
	$(CC) -g -c src/user_manual.c -o build/user_manual.o
	
build/win_game.o: src/win_game.c $(INCLUDES)
	$(CC) -g -c src/win_game.c -o build/win_game.o
	
	
build/choose_menu_item_test.o: test/choose_menu_item_test.c $(INCLUDES)
	$(CC) -g -c test/choose_menu_item_test.c -o build/choose_menu_item_test.o
	
build/game_over_test.o: test/game_over_test.c $(INCLUDES)
	$(CC) -g -c test/game_over_test.c -o build/game_over_test.o

build/generate_view_test.o: test/generate_view_test.c $(INCLUDES)
	$(CC) -g -c test/generate_view_test.c -o build/generate_view_test.o

build/is_barrier_hit_test.o: test/is_barrier_hit_test.c $(INCLUDES)
	$(CC) -g -c test/is_barrier_hit_test.c -o build/is_barrier_hit_test.o

build/is_player_hit_test.o: test/is_player_hit_test.c $(INCLUDES)
	$(CC) -g -c test/is_player_hit_test.c -o build/is_player_hit_test.o

build/is_reach_goal_test.o: test/is_reach_goal_test.c $(INCLUDES)
	$(CC) -g -c test/is_reach_goal_test.c -o build/is_reach_goal_test.o

build/load_map_test.o: test/load_map_test.c $(INCLUDES)
	$(CC) -g -c test/load_map_test.c -o build/load_map_test.o

build/print_menu_test.o: test/print_menu_test.c $(INCLUDES)
	$(CC) -g -c test/print_menu_test.c -o build/print_menu_test.o

build/take_heart_test.o: test/take_heart_test.c $(INCLUDES)
	$(CC) -g -c test/take_heart_test.c -o build/take_heart_test.o

build/update_arrow_test.o: test/update_arrow_test.c $(INCLUDES)
	$(CC) -g -c test/update_arrow_test.c -o build/update_arrow_test.o

build/update_barrier_test.o: test/update_barrier_test.c $(INCLUDES)
	$(CC) -g -c test/update_barrier_test.c -o build/update_barrier_test.o

build/update_player_pos_test.o: test/update_player_pos_test.c $(INCLUDES)
	$(CC) -g -c test/update_player_pos_test.c -o build/update_player_pos_test.o

build/update_selector_test.o: test/update_selector_test.c $(INCLUDES)
	$(CC) -g -c test/update_selector_test.c -o build/update_selector_test.o
	
build/win_game_test.o: test/win_game_test.c $(INCLUDES)
	$(CC) -g -c test/win_game_test.c -o build/win_game_test.o
	



#TARGET TO GENERATE THE EXECUTABLE OF THE PROGRAM (and the tests) - LINK OBJECT FILES

TEST_OBJECTS = build/choose_menu_item_test.o build/game_over_test.o build/generate_view_test.o build/is_barrier_hit_test.o build/is_player_hit_test.o build/is_reach_goal_test.o build/load_map_test.o build/print_menu_test.o build/take_heart_test.o build/update_arrow_test.o build/update_barrier_test.o build/update_player_pos_test.o build/update_selector_test.o build/win_game_test.o

tests: $(TEST_OBJECTS)

	$(CC) -g -o bin/test $(TEST_OBJECTS) $(LIBFLAGS)

OBJECTS = build/main.o build/credit.o build/game_over.o build/generate_view.o build/is_barrier_hit.o build/is_player_hit.o build/is_reach_goal.o build/load_map.o build/print_menu.o build/single_player.o build/take_heart.o build/update_arrow.o build/update_barrier.o build/update_player_pos.o build/user_manual.o build/win_game.o

main: $(OBJECTS)

	$(CC) -g -o bin/main $(OBJECTS) $(LIBFLAGS)

#TARGET TO GENERATE ALL THE EXECUTABLES (MAIN PROGRAM + TESTS TOGETHER)
all: tests main

#CLEAN COMMANDS 
clean:  
	rm -f bin/* build/* 
	