#include <SDL2/SDL.h>
#include "../../include/SDL_image.h"
#include <cstdlib>
#include <ctime>
#include <stdexcept>

#include "../game_state/GameState.h"
#include "Map.h"


Map::Map(int w, int h) : width(w), height(h) {
  srand(time(nullptr));

  offset_x = SCREEN_WIDTH / TILE_WIDTH;
  offset_y = SCREEN_HEIGHT / TILE_HEIGHT;
  
  grid = new enum Tile*[height + offset_y];

  for (int i = 0; i < height + offset_y; i++) {
    enum Tile* row = new enum Tile[width + offset_x];
    memset(row, Grass, width + offset_x);
    
    for (int j = 0; j < offset_x / 2; j++) row[j] = Water;

    grid[i] = row;
  }
    
  for (int i = 0; i < height + offset_y; i++) {
    for (int j = offset_x / 2; j < width; j++) {
      if (i < offset_y / 2 || i > height) {
	grid[i][j] = Water;
	continue;
      }
      
      switch (rand() % 3) {
	
      case 1:
	grid[i][j] = Water;
	break;
	
      case 2:
	grid[i][j] = Rock;
	break;

      default:
	break;

      }
    }
  }

  for (int i = 0; i < height + offset_y; i++) {
    for (int j = width; j < width + offset_x; j++) {
      grid[i][j] = Water;
    }
  }
}

  
Map::~Map() {
  for (int i = 0; i < height + offset_y; i++) {
    delete[] grid[i];
  }

  delete[] grid;
}


void Map::render(SDL_Renderer* renderer, const SDL_Rect& viewport) {
  SDL_Texture* texture = nullptr;
  SDL_Rect tile_destination;
  
  for (int i = viewport.y, i_dest = 0; i < viewport.y + viewport.h; i++, i_dest++) {
    if (i < 0 || i >= height + offset_y) continue;
    
    for (int j = viewport.x, j_dest = 0; j < viewport.x + viewport.w; j++, j_dest++) {
      if (j < 0 || j >= width + offset_x) continue;
      
      tile_destination = SDL_Rect { .x = j_dest * TILE_WIDTH,
	.y = i_dest * TILE_HEIGHT,
	.w = TILE_WIDTH,
	.h = TILE_HEIGHT
      };

      switch (grid[i][j]) {

      case Grass:
	texture = IMG_LoadTexture(renderer, "assets/grass.png");
	if (texture == nullptr) throw std::runtime_error("Couldn't load texture!\n");
	break;

      case Rock:
	texture = IMG_LoadTexture(renderer, "assets/rock.png");
	if (texture == nullptr) throw std::runtime_error("Couldn't load texture!\n");
	break;

      case Water:
	texture = IMG_LoadTexture(renderer, "assets/water.png");
	if (texture == nullptr) throw std::runtime_error("Couldn't load texture!\n");
	break;

      default:
	throw std::logic_error("Missing tile descriptor!");
	break;

      }

      SDL_RenderCopy(renderer, texture, nullptr, &tile_destination);
      SDL_DestroyTexture(texture);
      texture = nullptr;
    }
  }
}
