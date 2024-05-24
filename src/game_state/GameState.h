#pragma once

#include <SDL2/SDL.h>

#define SCREEN_WIDTH  1280
#define SCREEN_HEIGHT 640
#define TILE_WIDTH    64
#define TILE_HEIGHT   64

/*
 * @brief Handles the window object and other game state.
 */
class GameState {
 public:
  GameState();
  ~GameState();

  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Rect viewport;
};
