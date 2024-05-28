#include <stdexcept>
#include <SDL2/SDL.h>

#include "../../include/SDL_image.h"
#include "GameState.h"


GameState::GameState() {
  window = nullptr;
  renderer = nullptr;
  
  if (SDL_Init(SDL_INIT_VIDEO) < 0) throw std::runtime_error(SDL_GetError());

  window = SDL_CreateWindow(
			    "Kingdom of Etherea",
			    SDL_WINDOWPOS_UNDEFINED,
			    SDL_WINDOWPOS_UNDEFINED,
			    SCREEN_WIDTH,
			    SCREEN_HEIGHT,
			    SDL_WINDOW_SHOWN);
  if (window == nullptr) throw std::runtime_error(SDL_GetError());

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == nullptr) throw std::runtime_error(SDL_GetError());

  if ( !( IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG ) ) {
    throw std::runtime_error(SDL_GetError());
  }

  viewport = SDL_Rect {
    .x = 0,
    .y = 0,
    .w = SCREEN_WIDTH / TILE_WIDTH,
    .h = SCREEN_HEIGHT / TILE_HEIGHT
  };

  
  map = new Map(100, 100);

  // TODO: Replace this with an actual texture spritesheet
  char hero_asset[] = "assets/knight.png";
  hero = new Hero(hero_asset, 0, 0);
  
  entities.insert(std::pair(0, hero));
}


GameState::~GameState() {
  SDL_DestroyRenderer(renderer);
  renderer = nullptr;
  
  SDL_DestroyWindow(window);
  window = nullptr;
  
  IMG_Quit();
  SDL_Quit();
}


void GameState::render() const {
  SDL_SetRenderDrawColor(renderer, 0x0a, 0x30, 0x01, 0xff);
  SDL_RenderFillRect(renderer, new SDL_Rect {
      .x = 0,
      .y = 0,
      .w = SCREEN_WIDTH,
      .h = SCREEN_HEIGHT
    });

  map->render(renderer, viewport);

  for (std::pair entity : entities)
    entity.second->render(renderer, viewport);

    
  SDL_RenderPresent(renderer);
}


enum Action GameState::handle_actions(const SDL_Event& e) {
  switch (e.type) {

      case SDL_QUIT:
	return Quit;

      case SDL_KEYDOWN:
	switch (e.key.keysym.sym) {

	case SDLK_q:
	  return Quit;

	case SDLK_w:
	  if (viewport.y - 1 >= 0) {
	    viewport.y--;
	    hero->movement.up = true;
	  } else {
	    if (hero->y - 1 >= 0) hero->movement.up = true;
	    else hero->movement.up = false;
	  }
	  break;
	  
	case SDLK_s:
	  if (viewport.y + 1 + viewport.h <= map->height) {
	    viewport.y++;
	    hero->movement.down = true;
	  } else {
	    if (hero->y + hero->h < map->height) hero->movement.down = true;
	    else hero->movement.down = false;
	  }
	  break;
	  
	case SDLK_d:
	  if (viewport.x + 1 + viewport.w <= map->width) {
	    viewport.x++;
	    hero->movement.right = true;
	  } else {
	    if (hero->x + hero->w < map->width) hero->movement.right = true;
	    else hero->movement.right = false;
	  }
	  break;
	  
	case SDLK_a:
	  if (viewport.x - 1 >= 0) {
	    viewport.x--;
	    hero->movement.left = true;
	  } else {
	    if (hero->x - 1 >= 0) hero->movement.left = true;
	    else hero->movement.left = false;
	  }
	  break;

	default:
	  break;

	}
	break;

      case SDL_KEYUP:
	switch (e.key.keysym.sym) {

	case SDLK_w:
	  hero->movement.up = false;
	  break;

	case SDLK_s:
	  hero->movement.down = false;
	  break;

	case SDLK_d:
	  hero->movement.right = false;
	  break;

	case SDLK_a:
	  hero->movement.left = false;
	  break;

	default:
	  break;
	  
	}
	break;

      default:
	return Nothing;
	
  }

  return Something;
}


void GameState::update() {
  for (std::pair entry : entities) entry.second->move();
}
