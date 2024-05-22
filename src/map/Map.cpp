#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdexcept>

#include "Map.h"

Map::Map(int w, int h) : width(w), height(h) {
  grid = new enum Tile*[height];

  for (int i = 0; i < height; i++) {
    enum Tile* row = new enum Tile[width];

    for (int j = 0; j < width; j++) {
      row[j] = Grass;
    }

    grid[i] = row;
  }
}

  
Map::~Map() {
  for (int i = 0; i < height; i++) {
    delete[] grid[i];
  }

  delete[] grid;
}


void Map::render(SDL_Window* window) const {
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_Texture* texture;
  SDL_Rect tile_destination;

  
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      tile_destination = SDL_Rect { .x = i * TILE_HEIGHT,
	.y = j * TILE_WIDTH,
	.w = TILE_WIDTH,
	.h = TILE_HEIGHT
      };
      
      switch (grid[i][j]) {

      case Grass:
	texture = IMG_LoadTexture(renderer, "assets/grass.png");
	break;

      case Rock:
	texture = IMG_LoadTexture(renderer, "assets/rock.png");
	break;

      case Water:
	texture = IMG_LoadTexture(renderer, "assets/rock.png");
	break;

      default:
	throw std::logic_error("Missing tile descriptor!");
	break;

      }

      
      SDL_RenderCopy(renderer, texture, nullptr, &tile_destination);

      
}
