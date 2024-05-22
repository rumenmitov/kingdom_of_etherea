#include <stdexcept>

#include "Init.h"

SDL_Window* init(void) {
  SDL_Window* window = nullptr;
  if (SDL_Init(SDL_INIT_VIDEO) < 0) throw std::runtime_error(SDL_GetError());

  window = SDL_CreateWindow(
			    "Kingdom of Etherea",
			    SDL_WINDOWPOS_UNDEFINED,
			    SDL_WINDOWPOS_UNDEFINED,
			    640,
			    400,
			    SDL_WINDOW_SHOWN);
  if (window == nullptr) throw std::runtime_error(SDL_GetError());

  return window;
}
