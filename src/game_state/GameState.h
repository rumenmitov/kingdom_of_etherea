#pragma once

#include <SDL2/SDL.h>
#include <unordered_map>

#include "../map/Map.h"
#include "../entities/Entity.h"
#include "../entities/hero/Hero.h"


#define SCREEN_WIDTH  1280
#define SCREEN_HEIGHT 640
#define TILE_WIDTH    64
#define TILE_HEIGHT   64


/*
 * @brief Describes the action that resulted from user's keypress.
 */
enum Action {
  Quit,
  Nothing,
  Something
};


/*
 * @brief Handles the window object and other game state.
 */
class GameState {
 public:
  GameState();
  ~GameState();

  void render() const;
  enum Action handle_actions(const SDL_Event&);
  void update();

  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Rect viewport;


private:
  Hero* hero;
  Map* map;
  std::unordered_map<unsigned int, Entity*> entities;


};
