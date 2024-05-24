#include <stdexcept>
#include <SDL2/SDL.h>
#include "../../include/SDL_image.h"

#include "GameState.h"

GameState::GameState() {
  window = nullptr;
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

  viewport = SDL_Rect { .x = 0, .y = 0, .w = 5, .h = 5 };
}


GameState::~GameState() {
  SDL_DestroyWindow(window);
  window = nullptr;
  
  IMG_Quit();
  SDL_Quit();
}
