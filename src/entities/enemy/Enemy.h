#pragma once

#include "../Entity.h"

/*
 * @brief Handles base enemy functionalities.
 */
class Enemy : public Entity {
 public:
  Enemy(char*, unsigned int, unsigned int);
  ~Enemy();
};
