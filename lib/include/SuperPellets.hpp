#pragma once

#include "Board.hpp"
#include "Position.hpp"

class SuperPellets {
public:
  explicit SuperPellets(const Board & board);

  [[nodiscard]] GridPosition currentSprite() const {
    return sprite;
  }

  [[nodiscard]] std::vector<GridPosition> currentPositions() const {
    return positions;
  }

  bool eatPelletAtPosition(Position p);

private:
  const GridPosition sprite = { 0, 9 };
  std::vector<GridPosition> positions;
};
