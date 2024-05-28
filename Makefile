CC=g++
GAME_STATE=src/game_state/*.cpp
MAP=src/map/*.cpp
ENTITIES=src/entities/*.cpp src/entities/hero/*.cpp
OBJ=src/*.cpp $(GAME_STATE) $(MAP) $(ENTITIES)
FLAGS=-Wall -lSDL2 -lSDL2_image

all:

debug: 
	mkdir -p bin/debug
	$(CC) $(OBJ) -o bin/debug/main $(FLAGS) -g

release:
	mkdir -p bin/release
	$(CC) $(OBJ) -o bin/release/main $(FLAGS) -O3

clean:
	rm -rf bin/
