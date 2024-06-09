#include <SDL2/SDL.h>
#include <cstring>
#include <stdexcept>

#include "../../include/SDL_image.h"
#include "../game_state/GameState.h"
#include "Entity.h"


Entity::Entity() {
  health = 0;
  speed = 0;
  std::memset(sprite, 0, 1024);
};


Entity::Entity(char sprite[1024], unsigned int id, unsigned int health = 0, unsigned int speed = 0) :
  id(id), health(health), speed(speed)
{
  x = SCREEN_WIDTH / (TILE_WIDTH * 2);
  y = SCREEN_HEIGHT / (TILE_HEIGHT * 2);
  w = 1;
  h = 1;
  
  std::strncpy(this->sprite, sprite, 1024);

  movement.up    = false;
  movement.down  = false;
  movement.left  = false;
  movement.right = false;
}


Entity::~Entity() {}


void Entity::render(SDL_Renderer* renderer, const SDL_Rect& viewport) {
  if ( !collision(viewport) ) return;
  
  SDL_Texture* texture = IMG_LoadTexture(renderer, sprite);
  if (texture == nullptr) throw std::runtime_error(SDL_GetError());

  SDL_RenderCopy(renderer, texture, nullptr, new SDL_Rect {
      (this->x - viewport.x) * TILE_WIDTH,
      (this->y - viewport.y) * TILE_HEIGHT,
      this->w * TILE_WIDTH,
      this->h * TILE_HEIGHT
    });

}
  

bool Entity::collision(const SDL_Rect& rect) const {
  if ((rect.x >= x && rect.x <= x + w) &&
      (rect.y >= y && rect.y <= y + h)) return true;

  if ((x >= rect.x && x <= rect.x + rect.w) &&
      (y >= rect.y && y <= rect.y + rect.h)) return true;

  return false;
}


void Entity::move() {
  
  if (movement.up) {
    y--;
  }
  
  if (movement.down) {
    y++;
  }
  
  if (movement.left) {
    x--;
  }
  
  if (movement.right) {
    x++;
  }

}
