#pragma once

#include <SDL2/SDL.h>
#include <string>


/*
 * @brief Base class for all entities in the game.
 */
class Entity : public SDL_Rect {
  
public:
  Entity();
  
  // Creates an entity with a sprite file path, health
  // and speed.
  Entity(char[1024], unsigned int, unsigned int);
  
  ~Entity();

  void render(SDL_Renderer*, const SDL_Rect&);
  bool collision(const SDL_Rect&) const;
  void move();

  unsigned int health;
  unsigned int speed;

  /*
   * @brief Keeps track in which direction(s) the
   * entity is moving.
   */
  struct {
    bool up;
    bool down;
    bool right;
    bool left;
  } movement;

  
 protected:
  char sprite[1024];

};
