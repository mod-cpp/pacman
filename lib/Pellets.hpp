#pragma once

#include "Position.hpp"
#include "Board.hpp"

#include <SDL2/SDL_rect.h>

class Pellets {
public:
  explicit Pellets(const Board & board);

  [[nodiscard]] SDL_Point currentSprite() const {
    return sprite;
  };

  [[nodiscard]] std::vector<SDL_Point> currentPositions() const {
    return positions;
  }

private:
  const SDL_Point sprite = { 1, 9 };
  std::vector<SDL_Point> positions;
};
