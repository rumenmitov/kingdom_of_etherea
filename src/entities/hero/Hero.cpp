#include "Hero.h"


Hero::Hero(char sprite[1024], unsigned int id, unsigned int health = 0, unsigned int speed = 0) :
  Entity(sprite, id, health, speed) {};


Hero::~Hero() {};
