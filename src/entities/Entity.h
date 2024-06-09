#pragma once

#include <SDL2/SDL.h>
#include <string>


/*
 * @brief Base class for all entities in the game.
 */
class Entity : public SDL_Rect {
  
public:
  Entity();
  
  /*
   * @brief Creates an entity.
   * @param char sprite[1024]  Path to sprite file.
   * @param unsigned int       Unique ID.
   * @param unsigned int       Health.
   * @param unsigned int       Speed.
   */
  Entity(char[1024], unsigned int, unsigned int, unsigned int);
  
  ~Entity();

  void render(SDL_Renderer*, const SDL_Rect&);
  bool collision(const SDL_Rect&) const;

  /*
   * @brief Move entity.
   */
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

  unsigned id;

  
 protected:
  char sprite[1024];

};
