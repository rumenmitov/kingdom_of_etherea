#include <stdexcept>
#include <SDL2/SDL_image.h>

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

  if ( !( IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG ) ) {
    throw std::runtime_error(SDL_GetError());
  }

  return window;
}


void quit(SDL_Window* window) {
  SDL_DestroyWindow(window);
  window = nullptr;
  
  IMG_Quit();
  SDL_Quit();
}
