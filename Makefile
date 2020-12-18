ifdef ($(OS),Windows_NT)
# WINDOWS version
#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -IC:\mingw_dev_lib\include

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -LC:\mingw_dev_lib\lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LIBFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf

#CC specifies which compiler we're using
CC = gcc

INCLUDES = $(INCLUDE_PATHS) -Iinclude

OBJECTS = build/main.o build/credit.o build/game_over.o build/generate_view.o build/is_barrier_hit.o \
		  build/is_player_hit.o build/is_reach_goal.o build/load_map.o build/print_menu.o \
		  build/single_player.o build/take_heart.o build/update_arrow.o build/update_barrier.o \
		  build/update_player_pos.o build/user_manual.o build/win_game.o \
		  build/options.o build/print_options.o build/multi_player.o build/generate_view_multi.o \
		  build/is_bullet_hit.o build/update_bullet.o build/shoot.o
		 
bin/main : $(OBJECTS)
	$(CC) -o bin/main $(OBJECTS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LIBFLAGS)
   
	
#TARGET TO GENERATE THE OBJECT FILES FOR SRC.
build/main.o: 
	$(CC) -c src/main.c $(INCLUDES) -o build/main.o

build/credit.o:
	$(CC) -c src/credit.c $(INCLUDES) -o build/credit.o

build/game_over.o:
	$(CC) -c src/game_over.c  $(INCLUDES)  -o build/game_over.o

build/generate_view.o: 
	$(CC) -c src/generate_view.c $(INCLUDES)  -o build/generate_view.o

build/is_barrier_hit.o: 
	$(CC) -c src/is_barrier_hit.c $(INCLUDES)  -o build/is_barrier_hit.o

build/is_player_hit.o: 
	$(CC) -c src/is_player_hit.c $(INCLUDES)  -o build/is_player_hit.o

build/is_reach_goal.o:
	$(CC) -c src/is_reach_goal.c $(INCLUDES)  -o build/is_reach_goal.o

build/load_map.o:
	$(CC) -c src/load_map.c  $(INCLUDES)  -o build/load_map.o

build/print_menu.o: 
	$(CC) -c src/print_menu.c $(INCLUDES)  -o build/print_menu.o

build/single_player.o: 
	$(CC) -c src/single_player.c $(INCLUDES)  -o build/single_player.o

build/take_heart.o: 
	$(CC) -c src/take_heart.c $(INCLUDES)  -o build/take_heart.o

build/update_arrow.o: 
	$(CC) -c src/update_arrow.c $(INCLUDES)  -o build/update_arrow.o

build/update_barrier.o:
	$(CC) -c src/update_barrier.c $(INCLUDES) -o build/update_barrier.o

build/update_player_pos.o:  
	$(CC) -c src/update_player_pos.c $(INCLUDES)  -o build/update_player_pos.o

build/user_manual.o:
	$(CC) -c src/user_manual.c $(INCLUDES)  -o build/user_manual.o

build/win_game.o:
	$(CC) -c src/win_game.c $(INCLUDES) -o build/win_game.o

build/options.o: 
	$(CC) -c src/options.c $(INCLUDES) -o build/options.o

build/print_options.o:  
	$(CC) -c src/print_options.c $(INCLUDES)  -o build/print_options.o
	
build/multi_player.o:
	$(CC) -c src/multi_player.c $(INCLUDES)  -o build/multi_player.o
	
build/generate_view_multi.o: 
	$(CC) -c src/generate_view_multi.c $(INCLUDES)  -o build/generate_view_multi.o
	
build/is_bullet_hit.o: 
	$(CC) -c src/is_bullet_hit.c $(INCLUDES)  -o build/is_bullet_hit.o
build/update_bullet.o: 
	$(CC) -c src/update_bullet.c $(INCLUDES)  -o build/update_bullet.o
	
build/shoot.o: 
	$(CC) -c src/shoot.c $(INCLUDES)  -o build/shoot.o
	
	
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
build/is_barrier_hit_test.o: 
	$(CC) -c test/is_barrier_hit_test.c $(INCLUDES) -o build/is_barrier_hit_test.o

build/is_player_hit_test.o: 
	$(CC) -c test/is_player_hit_test.c $(INCLUDES) -o build/is_player_hit_test.o

build/is_reach_goal_test.o: 
	$(CC) -c test/is_reach_goal_test.c $(INCLUDES) -o build/is_reach_goal_test.o

build/load_map_test.o: 
	$(CC) -c test/load_map_test.c $(INCLUDES) -o build/load_map_test.o

build/take_heart_test.o: 
	$(CC) -c test/take_heart_test.c $(INCLUDES) -o build/take_heart_test.o

build/update_arrow_test.o: 
	$(CC) -c test/update_arrow_test.c $(INCLUDES) -o build/update_arrow_test.o

build/update_barrier_test.o: 
	$(CC) -c test/update_barrier_test.c $(INCLUDES) -o build/update_barrier_test.o

build/update_player_pos_test.o: 
	$(CC) -c test/update_player_pos_test.c $(INCLUDES) -o build/update_player_pos_test.o


#CLEAN COMMANDS 
clean:  
	rm -f bin/* build/* data/log.txt
else
# Mac and Linux version
LIBFLAGS = -l SDL2 -l SDL2_ttf

CC=gcc 

INCLUDES = include/map.h include/menu.h include/single_player.h include/map_textures.h include/multi_player.h

OBJECTS = build/main.o build/credit.o build/game_over.o build/generate_view.o build/is_barrier_hit.o \
 		  build/is_player_hit.o build/is_reach_goal.o build/load_map.o build/print_menu.o \
 		  build/single_player.o build/take_heart.o build/update_arrow.o build/update_barrier.o \
 		  build/update_player_pos.o build/user_manual.o build/win_game.o \
 		  build/options.o build/print_options.o build/multi_player.o build/generate_view_multi.o \
 		  build/is_bullet_hit.o build/shoot.o build/update_bullet.o
 		 
bin/main : run_tests $(OBJECTS)
	$(CC) -o bin/main $(OBJECTS) $(LIBFLAGS)

#TARGET TO GENERATE THE OBJECT FILES.
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

build/is_bullet_hit.o: src/is_bullet_hit.c $(INCLUDES)
	$(CC) -c src/is_bullet_hit.c -o build/is_bullet_hit.o

build/shoot.o: src/shoot.c $(INCLUDES)
	$(CC) -c src/shoot.c -o build/shoot.o

build/update_bullet.o: src/update_bullet.c $(INCLUDES)
	$(CC) -c src/update_bullet.c -o build/update_bullet.o
	

TESTS = bin/is_player_hit_test \
		bin/is_reach_goal_test \
		bin/load_map_test \
		bin/take_heart_test \
		bin/is_barrier_hit_test \
		bin/update_arrow_test \
		bin/update_barrier_test \
		bin/update_player_pos_test \
		bin/is_bullet_hit_test \
		bin/shoot_test \
		bin/update_bullet_test

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
	-echo "is_bullet_hit_test STARTED" >> $(LOG); ./bin/is_bullet_hit_test >> $(LOG) 2>&1
	-echo "shoot_test STARTED" >> $(LOG); ./bin/shoot_test >> $(LOG) 2>&1
	-echo "update_bullet_test STARTED" >> $(LOG); ./bin/update_bullet_test >> $(LOG) 2>&1

# BUILD TEST EXECUTABLES
bin/is_player_hit_test: build/is_player_hit_test.o build/is_player_hit.o
	$(CC) -o bin/is_player_hit_test build/is_player_hit_test.o build/is_player_hit.o

bin/is_reach_goal_test: build/is_reach_goal_test.o build/is_reach_goal.o
	$(CC) -o bin/is_reach_goal_test build/is_reach_goal_test.o build/is_reach_goal.o

bin/load_map_test: build/load_map_test.o build/load_map.o
	$(CC) -o bin/load_map_test build/load_map_test.o build/load_map.o

bin/take_heart_test: build/take_heart_test.o build/take_heart.o
	$(CC) -o bin/take_heart_test build/take_heart_test.o build/take_heart.o

bin/is_barrier_hit_test: build/is_barrier_hit_test.o build/is_barrier_hit.o
	$(CC) -o bin/is_barrier_hit_test build/is_barrier_hit_test.o build/is_barrier_hit.o

bin/update_arrow_test: build/update_arrow_test.o build/update_arrow.o
	$(CC) -o bin/update_arrow_test build/update_arrow_test.o build/update_arrow.o

bin/update_barrier_test: build/update_barrier_test.o build/update_barrier.o
	$(CC) -o bin/update_barrier_test build/update_barrier_test.o build/update_barrier.o

bin/update_player_pos_test: build/update_player_pos.o build/update_player_pos_test.o
	$(CC) -o bin/update_player_pos_test build/update_player_pos.o build/update_player_pos_test.o

bin/is_bullet_hit_test: build/is_bullet_hit_test.o build/is_bullet_hit.o
	$(CC) -o bin/is_bullet_hit_test build/is_bullet_hit_test.o build/is_bullet_hit.o

bin/shoot_test: build/shoot.o build/shoot_test.o
	$(CC) -o bin/shoot_test build/shoot.o build/shoot_test.o 

bin/update_bullet_test: build/update_bullet_test.o build/update_bullet.o
	$(CC) -o bin/update_bullet_test build/update_bullet_test.o build/update_bullet.o

# BUILD .o FILES FOR TESTS
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

build/is_bullet_hit_test.o: test/is_bullet_hit_test.c $(INCLUDES)
	$(CC) -c test/is_bullet_hit_test.c -o build/is_bullet_hit_test.o

build/shoot_test.o: test/shoot_test.c $(INCLUDES)
	$(CC) -c test/shoot_test.c -o build/shoot_test.o

build/update_bullet_test.o: test/update_bullet_test.c $(INCLUDES)
	$(CC) -c test/update_bullet_test.c -o build/update_bullet_test.o

	
#CLEAN COMMANDS 
clean:  
	rm -f bin/* build/* data/log.txt data/test_file.txt

endif