# Run and Shoot
# Organization
Carleton University, Ottawa, Canada
# Authors
  - Mahsa Layeghi
  - Parichehreh Firoozishahmirzadi
  - Jin Xu
  - Jaser El-Habrouk
# Introduction 
Run and Shoot is a game that is developed for entertainment purposes. The user should reach the goal while avoiding the moving objects to win the game. The game starts by showing a menu to the user. User can choose between menu items which are formed of the user manual, single-player, multi-player, options, credit, and exit. In single-player mode, the user will see a map with one player. In multi-player mode, there are two players on the map who are also able to shoot each other. Players will be able to move using some control keys from the keyboard which is described in the user manual. In the options section, the user can choose between three different difficulty levels: easy, intermediate, hard. Finally, choosing the exit item, the game will be quit.
# File organization
- bin: contains executables after linking.
- build: contains object files.
- data: contains map files and a font file. The tests’ log file after compilation will be created here as well.
- doc: contains documentation that is prepared during the course as well as html folder which is created for doxygen comments.
- include: contains all header files.
lib
- src: contains source files including all functions and the main file.
- test: contains all test functions.
- Doxyfile: a file that is created for doxygen usage.
- Makefile: a file in which the user will be able to run the whole program and its tests directly with one command.
- Readme.md: a file with the name of the application, authors, a quick review, and how to use information.
# Dependencies
- gcc compiler
- SDL2 library
- SDL2-ttf library
Refer to [Installation](https://github.com/Jaserelhabrouk/D_run_and_shoot/wiki/Installation) to find how to install SDL2 and SDL2-ttf libraries as well as compiler for your system.
# Installation
### On mac OS and Linux
Lunch Terminal and copy the following commands. `make` command, first run all tests and creates a log file in [log.txt]() where you can see if test functions passed or failed. Then the user will be able to run the program by executing `bin/main`.
```sh
$ git clone https://github.com/Jaserelhabrouk/D_run_and_shoot repo
$ cd repo
$ make
$ bin/main
```
`make clean` will remove all created object files and executables and log file.
```sh
$ make clean
```
`doxygen` will create a html folder in [doc]() and you will be able to open the doxygen comments using the following command.
```sh
$ doxygen
$ open doc/html/index.html
```
### On Windows
Lunch cmd window and use the following commands.
```sh
$ git clone https://github.com/Jaserelhabrouk/D_run_and_shoot repo
$ cd repo
$ mingw32-make
$ bin/main.exe
```
# Documentation
You can find a complete description of the game, user guide and developer guide of the application on [Wiki](https://github.com/Jaserelhabrouk/D_run_and_shoot/wiki).