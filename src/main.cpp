#include <SDL2/SDL.h>
#include <iostream>
#include <stdexcept>

#include "init/Init.h"

int main(int argc, char* args[]) {

  SDL_Window* window = nullptr;
  try {
    window = init();
  } catch (std::runtime_error e) {
    std::cerr << "Error with init process: " << e.what() << std::endl;
    return 1;
  }
  

  return 0;
}
