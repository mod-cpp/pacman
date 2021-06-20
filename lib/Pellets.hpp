#pragma once

#include "Board.hpp"
#include "Position.hpp"

class Pellets {
public:
  explicit Pellets(const Board & board);

  [[nodiscard]] PositionInt currentSprite() const {
    return sprite;
  };

  [[nodiscard]] std::vector<PositionInt> currentPositions() const {
    return positions;
  }

  bool eatPelletAtPosition(Position p);

private:
  const PositionInt sprite = { 1, 9 };
  std::vector<PositionInt> positions;
};
