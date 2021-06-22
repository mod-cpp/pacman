#pragma once

#include "Board.hpp"
#include "Position.hpp"

class SuperPellets {
public:
  explicit SuperPellets(const Board & board);

  [[nodiscard]] PositionInt currentSprite() const {
    return sprite;
  }

  [[nodiscard]] std::vector<PositionInt> currentPositions() const {
    return positions;
  }

  bool eatPelletAtPosition(Position p);

private:
  const PositionInt sprite = { 0, 9 };
  std::vector<PositionInt> positions;
};
