#include <SDL2/SDL.h>
#include "../../include/SDL_image.h"
#include <stdexcept>

#include "Map.h"

Map::Map(int w, int h) : renderer(nullptr), width(w), height(h) {
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

  SDL_DestroyRenderer(renderer);
  renderer = nullptr;
}

void Map::render(SDL_Window* window, const SDL_Rect& viewport) {
  using namespace std;
  if (renderer != nullptr) SDL_RenderClear(renderer);
  else {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) throw std::runtime_error("Couldn't create renderer!");
  }
  
  SDL_Texture* texture = nullptr;
  SDL_Rect tile_destination;
  
  for (int i = viewport.y; i < viewport.y + viewport.h; i++) {
    for (int j = viewport.x; j < viewport.x + viewport.w; j++) {
      if (i < 0 || i >= height) throw std::out_of_range("Viewport exceeded map height!");
      if (j < 0 || j >= width) throw std::out_of_range("Viewport exceeded map width!");
      
      tile_destination = SDL_Rect { .x = j * TILE_WIDTH,
	.y = i * TILE_HEIGHT,
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
	texture = IMG_LoadTexture(renderer, "assets/rock.png");
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
