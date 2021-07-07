#pragma once

#include "Board.hpp"
#include "Position.hpp"

namespace pacman {

class SuperPellets {
public:
  explicit SuperPellets();

  [[nodiscard]] GridPosition currentSprite() const {
    return sprite;
  }

  [[nodiscard]] std::vector<GridPosition> currentPositions() const {
    return positions;
  }

  bool eatPelletAtPosition(GridPosition p);

private:
  const GridPosition sprite = { 0, 9 };
  std::vector<GridPosition> positions;
};

} // namespace pacman
