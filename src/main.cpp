#include <SDL2/SDL.h>
#include <exception>
#include <iostream>

#include "game_state/GameState.h"
#include "map/Map.h"

int main(int argc, char* args[]) {

  GameState* game_state = nullptr;
  try {
    game_state = new GameState();
  } catch (std::exception* e) {
    std::cerr << "Error with init process: " << e->what() << std::endl;
    return 1;
  }

  Map map(100, 100);

  try {
  map.render(game_state->window, game_state->viewport);
  } catch (std::exception* e) {
    std::cerr << "Error with render: " << e->what() << std::endl;
  }
  SDL_RenderPresent(map.renderer);

  while (true) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
      switch (e.type) {

      case SDL_QUIT:
	goto QUIT;
	break;

      case SDL_KEYDOWN:
	switch (e.key.keysym.sym) {

	case SDLK_q:
	  goto QUIT;
	  break;

	case SDLK_w:
	  if (game_state->viewport.y - 1 >= 0)
	    game_state->viewport.y--;
	  break;
	  
	case SDLK_s:
	  if (game_state->viewport.y + 1 + game_state->viewport.h <= map.height)
	    game_state->viewport.y++;
	  break;
	  
	case SDLK_d:
	  if (game_state->viewport.x + 1 + game_state->viewport.w <= map.width)
	    game_state->viewport.x++;
	  break;
	  
	case SDLK_a:
	  if (game_state->viewport.x - 1 >= 0)
	    game_state->viewport.x--;
	  break;

	default:
	  break;

	}

	try {
	  map.render(game_state->window, game_state->viewport);
	} catch (std::exception* e) {
	  std::cerr << "Error with render: " << e->what() << std::endl;
	}
	SDL_RenderPresent(map.renderer);
	break;

      default:
	break;

      }
    }
  }

 QUIT:
  return 0;
}
