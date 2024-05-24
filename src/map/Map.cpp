#include <SDL2/SDL.h>
#include "../../include/SDL_image.h"
#include <cstdlib>
#include <ctime>
#include <stdexcept>

#include "Map.h"

Map::Map(int w, int h) : renderer(nullptr), width(w), height(h) {
  srand(time(nullptr));
  
  grid = new enum Tile*[height];

  for (int i = 0; i < height; i++) {
    enum Tile* row = new enum Tile[width];

    for (int j = 0; j < width; j++) {
      switch (rand() % 3) {
	
      case 1:
	row[j] = Water;
	break;
	
      case 2:
	row[j] = Rock;
	break;

      default:
	row[j] = Grass;
	break;

      }
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
  
  for (int i = viewport.y, i_dest = 0; i < viewport.y + viewport.h; i++, i_dest++) {
    if (i < 0 || i >= height) continue;
    
    for (int j = viewport.x, j_dest = 0; j < viewport.x + viewport.w; j++, j_dest++) {
      if (j < 0 || j >= width) continue;
      
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
