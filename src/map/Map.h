#pragma once

#include <SDL2/SDL.h>


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

  // Draws viewport on renderer.
  void render(SDL_Renderer*, const SDL_Rect&);

  int width;
  int height;

  int offset_x;
  int offset_y;


private:

  enum Tile** grid;
  bool requires_redraw;
};

    
