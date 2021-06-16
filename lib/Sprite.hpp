#pragma once

#include <SDL2/SDL.h>
#include <memory>

struct Sprite {
  SDL_Texture * texture;
  SDL_Rect rect;
};
