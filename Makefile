CC    = g++
OBJ   = src/*.cpp
OBJ   += src/game_state/*.cpp
OBJ   += src/map/*.cpp
OBJ   += src/entities/*.cpp
OBJ   += src/entities/hero/*.cpp
FLAGS = -Wall -lSDL2 -lSDL2_image

all:

debug: 
	mkdir -p bin/debug
	$(CC) $(OBJ) -o bin/debug/main $(FLAGS) -g

release:
	mkdir -p bin/release
	$(CC) $(OBJ) -o bin/release/main $(FLAGS) -O3

clean:
	rm -rf bin/
