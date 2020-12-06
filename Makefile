CC=gcc 

LIBFLAGS= -lmingw32 -lSDL2main -lSDL2

#CREATE BIN AND BUILD FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME IF THEY DO NOT EXIST
bin_folder := $(shell mkdir -p bin) 
build_folder := $(shell mkdir -p build) 
results_folder := $(shell mkdir -p program_output) 

#TARGET TO GENERATE THE OBJECT FILES 
main.o: src/main.c
	$(CC) -g -c $(LIBFLAGS) src/main.c -o build/main.o
	
credit.o: src/credit.c
	$(CC) -g -c $(LIBFLAGS) src/credit.c -o build/credit.o
	
game_over.o: src/game_over.c
	$(CC) -g -c $(LIBFLAGS) src/game_over.c -o build/game_over.o
	
generate_view.o: src/generate_view.c
	$(CC) -g -c $(LIBFLAGS) src/generate_view.c -o build/generate_view.o
	
is_barrier_hit.o: src/is_barrier_hit.c
	$(CC) -g -c $(LIBFLAGS) src/is_barrier_hit.c -o build/is_barrier_hit.o

is_player_hit.o: src/is_player_hit.c
	$(CC) -g -c $(LIBFLAGS) src/is_player_hit.c -o build/is_barrier_hit.o

is_reach_goal.o: src/is_reach_goal.c
	$(CC) -g -c $(LIBFLAGS) src/is_reach_goal.c -o build/is_reach_goal.o

load_map.o: src/load_map.c
	$(CC) -g -c $(LIBFLAGS) src/load_map.c -o build/load_map.o

print_menu.o: src/print_menu.c
	$(CC) -g -c $(LIBFLAGS) src/print_menu.c -o build/print_menu.o

single_player.o: src/single_player.c
	$(CC) -g -c $(LIBFLAGS) src/single_player.c -o build/single_player.o

take_heart.o: src/take_heart.c
	$(CC) -g -c $(LIBFLAGS) src/take_heart.c -o build/take_heart.o

update_arrow.o: src/update_arrow.c
	$(CC) -g -c $(LIBFLAGS) src/update_arrow.c -o build/update_arrow.o

update_barrier.o: src/update_barrier.c
	$(CC) -g -c $(LIBFLAGS) src/update_barrier.c -o build/update_barrier.o

update_player_pos.o: src/update_player_pos.c
	$(CC) -g -c $(LIBFLAGS) src/update_player_pos.c -o build/update_player_pos.o
	
user_manual.o: src/user_manual.c
	$(CC) -g -c $(LIBFLAGS) src/user_manual.c -o build/user_manual.o
	
win_game.o: src/win_game.c
	$(CC) -g -c $(LIBFLAGS) src/win_game.c -o build/win_game.o
	
	
choose_menu_item_test.o: test/choose_menu_item_test.c
	$(CC) -g -c $(LIBFLAGS) test/choose_menu_item_test.c -o build/choose_menu_item_test.o
	
game_over_test.o: test/game_over_test.c
	$(CC) -g -c $(LIBFLAGS) test/game_over_test.c -o build/game_over_test.o

generate_view_test.o: test/generate_view_test.c
	$(CC) -g -c $(LIBFLAGS) test/generate_view_test.c -o build/generate_view_test.o

is_barrier_hit_test.o: test/is_barrier_hit_test.c
	$(CC) -g -c $(LIBFLAGS) test/is_barrier_hit_test.c -o build/is_barrier_hit.o

is_player_hit_test.o: test/is_player_hit_test.c
	$(CC) -g -c $(LIBFLAGS) test/is_player_hit_test.c -o build/is_player_hit_test.o

is_reach_goal_test.o: test/is_reach_goal_test.c
	$(CC) -g -c $(LIBFLAGS) test/is_reach_goal_test.c -o build/is_reach_goal_test.o

load_map_test.o: test/load_map_test.c
	$(CC) -g -c $(LIBFLAGS) test/load_map_test.c -o build/load_map_test.o

print_menu_test.o: test/print_menu_test.c
	$(CC) -g -c $(LIBFLAGS) test/print_menu_test.c -o build/print_menu_test.o

take_heart_test.o: test/take_heart_test.c
	$(CC) -g -c $(LIBFLAGS) test/take_heart_test.c -o build/take_heart_test.o

update_arrow_test.o: test/update_arrow_test.c
	$(CC) -g -c $(LIBFLAGS) test/update_arrow_test.c -o build/update_arrow.o

update_barrier_test.o: test/update_barrier_test.c
	$(CC) -g -c $(LIBFLAGS) test/update_barrier_test.c -o build/update_barrier_test.o

update_player_pos_test.o: test/update_player_pos_test.c
	$(CC) -g -c $(LIBFLAGS) test/update_player_pos_test.c -o build/update_player_pos_test.o

update_selector_test.o: test/update_selector_test.c
	$(CC) -g -c $(LIBFLAGS) test/update_selector_test.c -o build/update_selector_test.o
	
win_game_test.o: test/win_game_test.c
	$(CC) -g -c $(LIBFLAGS) test/win_game_test.c -o build/win_game_test.o
	



#TARGET TO GENERATE THE EXECUTABLE OF THE PROGRAM (and the tests) - LINK OBJECT FILES

tests: choose_menu_item_test.o game_over_test.o generate_view_test.o is_barrier_hit_test.o is_player_hit_test.o is_reach_goal_test.o load_map_test.o print_menu_test.o take_heart_test.o update_arrow_test.o update_barrier_test.o update_player_pos_test.o update_selector_test.o win_game_test.o

	$(CC) -g -o bin/choose_menu_item_test build/choose_menu_item_test.o
	$(CC) -g -o bin/game_over_test build/game_over_test.o
	$(CC) -g -o bin/generate_view_test build/generate_view_test.o
	$(CC) -g -o bin/is_barrier_hit_test build/is_barrier_hit_test.o
	$(CC) -g -o bin/is_player_hit_test build/is_player_hit_test.o
	$(CC) -g -o bin/is_reach_goal_test build/is_reach_goal_test.o
	$(CC) -g -o bin/load_map_test build/load_map_test.o
	$(CC) -g -o bin/print_menu_test build/print_menu_test.o
	$(CC) -g -o bin/take_heart_test build/take_heart_test.o
	$(CC) -g -o bin/update_arrow_test build/update_arrow_test.o
	$(CC) -g -o bin/update_barrier_test build/update_barrier_test.o
	$(CC) -g -o bin/update_player_pos_test build/update_player_pos_test.o
	$(CC) -g -o bin/update_selector_test build/update_selector_test.o
	$(CC) -g -o bin/win_game_test build/win_game_test.o


	
main: main.o credit.o game_over.o generate_view.o is_barrier_hit.o is_player_hit.o is_reach_goal.o load_map.o print_menu.o single_player.o take_heart.o update_arrow.o update_barrier.o update_player_pos.o user_manual.o win_game.o

	$(CC) -g -o bin/Run_and_Shoot build/main.o
	$(CC) -g -o bin/credit build/credit.o
	$(CC) -g -o bin/game_over build/game_over.o
	$(CC) -g -o bin/generate_view build/generate_view.o
	$(CC) -g -o bin/is_barrier_hit build/is_barrier_hit.o
	$(CC) -g -o bin/is_player_hit build/is_player_hit.o
	$(CC) -g -o bin/is_reach_goal build/is_reach_goal.o
	$(CC) -g -o bin/load_map build/load_map.o
	$(CC) -g -o bin/print_menu build/print_menu.o
	$(CC) -g -o bin/single_player single_player/main.o
	$(CC) -g -o bin/take_heart build/take_heart.o
	$(CC) -g -o bin/update_arrow build/update_arrow.o
	$(CC) -g -o bin/update_barrier build/update_barrier.o
	$(CC) -g -o bin/update_player_pos build/update_player_pos.o
	$(CC) -g -o bin/user_manual build/user_manual.o
	$(CC) -g -o bin/win_game build/win_game.o

#TARGET TO GENERATE ALL THE EXECUTABLES (MAIN PROGRAM + TESTS TOGETHER)
all: main tests

#CLEAN COMMANDS 
clean:  
	rm -f bin/* build/* 
	