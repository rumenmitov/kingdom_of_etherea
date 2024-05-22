#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstring>
#include <stdexcept>

#include "Entity.h"

Entity::Entity(SDL_Rect rect, unsigned int health, unsigned int speed, char* sprite) :
  SDL_Rect(rect), health(health), speed(speed)
{
  std::strncpy(this->sprite, sprite, 1024);
}


Entity::~Entity() {}


SDL_Renderer* Entity::render(SDL_Window* window) const {
  SDL_Renderer* renderer =
    SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (renderer == nullptr) throw std::runtime_error(SDL_GetError());

  SDL_Texture* texture = IMG_LoadTexture(renderer, sprite);
  if (texture == nullptr) throw std::runtime_error(SDL_GetError());

  

  
bool Entity::collision(SDL_Rect*) const;

