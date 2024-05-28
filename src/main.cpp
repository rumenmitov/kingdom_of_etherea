#include <SDL2/SDL.h>
#include <exception>
#include <iostream>

#include "game_state/GameState.h"


int main(int argc, char* args[]) {

  GameState* game_state = nullptr;
  try {
    game_state = new GameState();
  } catch (const std::exception& e) {
    std::cerr << "Error with init process: " << e.what() << std::endl;
    return 1;
  }


  try {
    game_state->render();
  } catch (const std::exception& e) {
    std::cerr << "Error with render: " << e.what() << std::endl;
  }

  
  while (true) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
      switch (game_state->handle_actions(e)) {
	
      case Quit:
	goto QUIT;

      case Something:
	game_state->update();
	game_state->render();
	break;

      default:
	continue;

      }
    }
  }

 QUIT:
  return 0;
}
