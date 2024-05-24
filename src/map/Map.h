#pragma once

#include <SDL2/SDL.h>

static const int TILE_WIDTH = 32;
static const int TILE_HEIGHT = 32;

enum Tile {
  Grass = 0,
  Rock,
  Water,
};


/*
 * @brief Handles all map operations.
 */
class Map {
 public:

  // Generates a map of width w, and height h.
  Map(int, int);

  // Clears map.
  ~Map();

  // Draws viewport and returns renderer.
  void render(SDL_Window*, const SDL_Rect&);

  SDL_Renderer* renderer;
  int width;
  int height;


private:

  enum Tile** grid;
};

    
