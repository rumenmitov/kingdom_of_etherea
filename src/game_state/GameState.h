#pragma once

#include <SDL2/SDL.h>

static const int SCREEN_WIDTH = 640;
static const int SCREEN_HEIGHT = 640;

/*
 * @brief Handles the window object and other game state.
 */
class GameState {
 public:
  GameState();
  ~GameState();

  SDL_Window* window;
  SDL_Rect viewport;
};
