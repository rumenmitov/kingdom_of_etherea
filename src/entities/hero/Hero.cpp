#include "Hero.h"


Hero::Hero(char sprite[1024], unsigned int health = 0, unsigned int speed = 0) :
  Entity(sprite, health, speed) {};


Hero::~Hero() {};
