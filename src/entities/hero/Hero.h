#pragma once

#include "../Entity.h"


/*
 * @brief Handles player character.
 */
class Hero : public Entity {
 public:
  Hero(char*, unsigned int, unsigned int, unsigned int);
  ~Hero();

};
