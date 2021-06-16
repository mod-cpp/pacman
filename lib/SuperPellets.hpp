#pragma once

#include "Board.hpp"
#include "Position.hpp"

#include <SDL2/SDL_rect.h>

class SuperPellets {
public:
  explicit SuperPellets(const Board & board);

  [[nodiscard]] SDL_Point currentSprite() const {
    return sprite;
  }

  [[nodiscard]] std::vector<SDL_Point> currentPositions() const {
    return positions;
  }

private:
  const SDL_Point sprite = { 0, 9 };
  std::vector<SDL_Point> positions;
};
