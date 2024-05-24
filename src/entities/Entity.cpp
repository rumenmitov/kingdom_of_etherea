#include <SDL2/SDL.h>
#include <cstring>
#include <stdexcept>

#include "../../include/SDL_image.h"
#include "../game_state/GameState.h"
#include "Entity.h"


Entity::Entity(const char sprite[1024], unsigned int health = 0, unsigned int speed = 0) :
  health(health), speed(speed)
{
  x = SCREEN_WIDTH / (TILE_WIDTH * 2);
  y = SCREEN_HEIGHT / (TILE_HEIGHT * 2);
  w = TILE_WIDTH;
  h = TILE_HEIGHT;
  
  std::strncpy(this->sprite, sprite, 1024);
}


Entity::~Entity() {}


void Entity::render(SDL_Renderer* renderer, const SDL_Rect& viewport) {
  if ( !collision(viewport) ) return;
  
  SDL_Texture* texture = IMG_LoadTexture(renderer, sprite);
  if (texture == nullptr) throw std::runtime_error(SDL_GetError());

  SDL_RenderCopy(renderer, texture, nullptr, new SDL_Rect {
      this->x * TILE_WIDTH,
      this->y * TILE_HEIGHT,
      this->w,
      this->h
    });
}
  

bool Entity::collision(const SDL_Rect& rect) const {
  if ((rect.x >= x && rect.x <= x + w) &&
      (rect.y >= y && rect.y <= y + h)) return true;

  if ((x >= rect.x && x <= rect.x + rect.w) &&
      (y >= rect.y && y <= rect.y + rect.h)) return true;

  return false;
}
