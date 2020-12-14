ifdef OS
# WINDOWS version
# TODO
else
	LIBFLAGS = -l sdl2 -l sdl2_ttf
endif

CC=gcc 

INCLUDES = include/map.h include/menu.h include/single_player.h include/map_textures.h include/multi_player.h

OBJECTS = build/main.o build/credit.o build/game_over.o build/generate_view.o build/is_barrier_hit.o \
 		  build/is_player_hit.o build/is_reach_goal.o build/load_map.o build/print_menu.o \
 		  build/single_player.o build/take_heart.o build/update_arrow.o build/update_barrier.o \
 		  build/update_player_pos.o build/user_manual.o build/win_game.o \
 		  build/options.o build/print_options.o build/multi_player.o build/generate_view_multi.o
 		 
bin/main : run_tests $(OBJECTS)
	$(CC) -o bin/main $(OBJECTS) $(LIBFLAGS)

#TARGET TO GENERATE THE OBJECT FILES FOR SRC.
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
	
build/multi_player.o: src/multi_player.c $(INCLUDES)
	$(CC) -c src/multi_player.c -o build/multi_player.o
	
build/generate_view_multi.o: src/generate_view_multi.c $(INCLUDES)
	$(CC) -c src/generate_view_multi.c -o build/generate_view_multi.o
	

OBJECTS_TEST = build/is_player_hit.o build/is_player_hit_test.o \
			   build/is_reach_goal.o build/is_reach_goal_test.o \
			   build/load_map.o build/load_map_test.o \
			   build/take_heart.o build/take_heart_test.o \
			   build/is_barrier_hit.o build/is_barrier_hit_test.o \
			   build/update_arrow.o build/update_arrow_test.o \
			   build/update_barrier.o build/update_barrier_test.o \
			   build/update_player_pos.o build/update_player_pos_test.o

TESTS = bin/is_player_hit_test \
		bin/is_reach_goal_test \
		bin/load_map_test \
		bin/take_heart_test \
		bin/is_barrier_hit_test \
		bin/update_arrow_test \
		bin/update_barrier_test \
		bin/update_player_pos_test

LOG = data/log.txt

run_tests: $(TESTS)
	rm -rf $(LOG)
	touch $(LOG)
	-echo "is_player_hit_test STARTED" >> $(LOG); ./bin/is_player_hit_test >> $(LOG) 2>&1
	-echo "is_reach_goal_test STARTED" >> $(LOG); ./bin/is_reach_goal_test >> $(LOG) 2>&1 
	-echo "load_map_test STARTED" >> $(LOG); ./bin/load_map_test >> $(LOG) 2>&1
	-echo "take_heart_test STARTED" >> $(LOG); ./bin/take_heart_test >> $(LOG) 2>&1
	-echo "is_barrier_hit_test STARTED" >> $(LOG); ./bin/is_barrier_hit_test >> $(LOG) 2>&1
	-echo "update_arrow_test STARTED" >> $(LOG); ./bin/update_arrow_test >> $(LOG) 2>&1
	-echo "update_barrier_test STARTED" >> $(LOG); ./bin/update_barrier_test >> $(LOG) 2>&1
	-echo "update_player_pos_test STARTED" >> $(LOG); ./bin/update_player_pos_test >> $(LOG) 2>&1


# build test executables
bin/is_player_hit_test: $(OBJECTS_TEST)
	$(CC) -e _is_player_hit_test -o bin/is_player_hit_test $(OBJECTS_TEST)

bin/is_reach_goal_test: $(OBJECTS_TEST)
	$(CC) -e  _is_reach_goal_test -o bin/is_reach_goal_test $(OBJECTS_TEST)

bin/load_map_test: $(OBJECTS_TEST)
	$(CC) -e _load_map_test -o bin/load_map_test $(OBJECTS_TEST) 

bin/take_heart_test: $(OBJECTS_TEST)
	$(CC) -e _take_heart_test -o bin/take_heart_test $(OBJECTS_TEST)

bin/is_barrier_hit_test: $(OBJECTS_TEST)
	$(CC) -e _is_barrier_hit_test -o bin/is_barrier_hit_test $(OBJECTS_TEST)

bin/update_arrow_test: $(OBJECTS_TEST)
	$(CC) -e _update_arrow_test -o bin/update_arrow_test $(OBJECTS_TEST)

bin/update_barrier_test: $(OBJECTS_TEST)
	$(CC) -e _update_barrier_test -o bin/update_barrier_test $(OBJECTS_TEST)

bin/update_player_pos_test: $(OBJECTS_TEST)
	$(CC) -e _update_player_pos_test -o bin/update_player_pos_test $(OBJECTS_TEST)	

# build .o files for tests
build/is_barrier_hit_test.o: test/is_barrier_hit_test.c $(INCLUDES)
	$(CC) -c test/is_barrier_hit_test.c -o build/is_barrier_hit_test.o

build/is_player_hit_test.o: test/is_player_hit_test.c $(INCLUDES)
	$(CC) -c test/is_player_hit_test.c -o build/is_player_hit_test.o

build/is_reach_goal_test.o: test/is_reach_goal_test.c $(INCLUDES)
	$(CC) -c test/is_reach_goal_test.c -o build/is_reach_goal_test.o

build/load_map_test.o: test/load_map_test.c $(INCLUDES)
	$(CC) -c test/load_map_test.c -o build/load_map_test.o

build/take_heart_test.o: test/take_heart_test.c $(INCLUDES)
	$(CC) -c test/take_heart_test.c -o build/take_heart_test.o

build/update_arrow_test.o: test/update_arrow_test.c $(INCLUDES)
	$(CC) -c test/update_arrow_test.c -o build/update_arrow_test.o

build/update_barrier_test.o: test/update_barrier_test.c $(INCLUDES)
	$(CC) -c test/update_barrier_test.c -o build/update_barrier_test.o

build/update_player_pos_test.o: test/update_player_pos_test.c $(INCLUDES)
	$(CC) -c test/update_player_pos_test.c -o build/update_player_pos_test.o

	
#CLEAN COMMANDS 
clean:  
	rm -f bin/* build/* data/log.txt