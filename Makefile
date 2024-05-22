CC=g++
OBJ=src/*.cpp
FLAGS=-Wall -lSDL2

all:

debug:
	mkdir -p bin/debug
	$(CC) $(OBJ) -o bin/debug/main $(FLAGS) -g

release:
	mkdir -p bin/release
	$(CC) $(OBJ) -o bin/release/main $(FLAGS) -O3

clean:
	rm -rf bin/
