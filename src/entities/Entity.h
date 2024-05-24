#pragma once

#include <SDL2/SDL.h>


/*
 * @brief Base class for all entities in the game.
 */
class Entity : public SDL_Rect {
  
public:
  // Creates an entity with a sprite file path, health
  // and speed.
  Entity(const char[1024], unsigned int, unsigned int);
  
  ~Entity();

  void render(SDL_Renderer*, const SDL_Rect&);
  bool collision(const SDL_Rect&) const;

  unsigned int health;
  unsigned int speed;

 protected:
  char sprite[1024];
};
