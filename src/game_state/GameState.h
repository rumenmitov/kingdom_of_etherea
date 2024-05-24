#pragma once

#include <SDL2/SDL.h>

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
