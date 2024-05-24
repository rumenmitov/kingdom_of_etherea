#pragma once

#include <SDL2/SDL.h>


/*
 * @brief Base class for all entities in the game.
 */
class Entity : public SDL_Rect {

  // Creates an entity from rectangle with a certain health, speed,
  // and sprite file path.
  Entity(SDL_Rect, unsigned int, unsigned int, const char*);
  
  ~Entity();

  void render(SDL_Window*, const SDL_Rect&);
  bool collision(const SDL_Rect&) const;

  SDL_Renderer* renderer;

  unsigned int health;
  unsigned int speed;

 protected:
  char* sprite;
};
