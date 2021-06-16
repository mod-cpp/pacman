#pragma once

#include <SDL2/SDL_rect.h>

struct Position {
  float x;
  float y;
};

inline bool operator==(const SDL_Point & b, const Position & a) {
  return a.x == b.x && a.y == b.y;
}
