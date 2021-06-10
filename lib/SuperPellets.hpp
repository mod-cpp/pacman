#pragma once

#include "Position.hpp"
#include "Board.hpp"

#include <SDL2/SDL_rect.h>

class SuperPellets {
public:
  explicit SuperPellets(const Board & board);

  [[nodiscard]] SDL_Rect currentSprite() const {
    return sprite;
  }

  [[nodiscard]] std::vector<SDL_Point> currentPositions() const {
    return positions;
  }

private:
  const SDL_Rect sprite = {0 * 32, 9 * 32, 32, 32};
  std::vector<SDL_Point> positions;
};
