#include <SDL2/SDL.h>
#include <cstring>
#include <stdexcept>

#include "Entity.h"
#include "../../include/SDL_image.h"


Entity::Entity(SDL_Rect rect, unsigned int health, unsigned int speed, const char* sprite) :
  SDL_Rect(rect), health(health), speed(speed)
{
  std::strncpy(this->sprite, sprite, 1024);
  renderer = nullptr;
}


Entity::~Entity() {
  SDL_DestroyRenderer(renderer);
  renderer = nullptr;
  
  delete[] sprite;
}


void Entity::render(SDL_Window* window, const SDL_Rect& viewport) {
  if ( !collision(viewport) ) return;
  
  if (renderer == nullptr) {
    SDL_RenderClear(renderer); 
  } else {
    renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

      if (renderer == nullptr) throw std::runtime_error(SDL_GetError());
  }


  SDL_Texture* texture = IMG_LoadTexture(renderer, sprite);
  if (texture == nullptr) throw std::runtime_error(SDL_GetError());

  SDL_RenderCopy(renderer, texture, nullptr, new SDL_Rect {
      this->x,
      this->y,
      this->w,
      this->h
    });
}
  

  
bool Entity::collision(const SDL_Rect& rect) const {
  if ((rect.x >= x && rect.x <= x + w) &&
      (rect.y >= y && rect.y <= y + h)) return true;

  return false;
}
