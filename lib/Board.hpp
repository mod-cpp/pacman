#pragma once

#include <SFML/Graphics.hpp>

#include "Direction.hpp"
#include "Position.hpp"
#include <cstdint>
#include <vector>

const uint8_t ROWS = 31;
const uint8_t COLUMNS = 28;

class Board {
public:
  Board();

  [[nodiscard]] bool isWalkableForPacMan(Position point, float d, Direction direction) const;
  [[nodiscard]] bool isWalkableForGhost(Position point, float d, Direction direction) const;

  [[nodiscard]] std::vector<PositionInt> initialPelletPositions() const;

  [[nodiscard]] std::vector<PositionInt> initialSuperPelletPositions() const;

  static Position initialPacManPosition() { return { 14, 23 }; }

private:
  [[nodiscard]] bool isWalkable(Position point, float d, Direction direction, bool pacman) const;
  uint8_t board_state[ROWS][COLUMNS]{};
};
