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
  enum class Cell {
    wall = 0,
    pellet = 1,
    nothing = 2,
    door = 3,
    power_pellet = 4,
    pen = 5,
  };

  Board();

  [[nodiscard]] bool isWalkableForPacMan(Position point, float d, Direction direction) const;
  [[nodiscard]] bool isWalkableForGhost(Position point, float d, Direction direction) const;

  [[nodiscard]] bool isWalkableForGost(Position point, Position origin, bool isEyes) const;
  [[nodiscard]] bool isWalkable(Position point) const;
  [[nodiscard]] bool isInPen(Position point) const;

  [[nodiscard]] std::vector<PositionInt> initialPelletPositions() const;

  [[nodiscard]] std::vector<PositionInt> initialSuperPelletPositions() const;

  static Position initialPacManPosition() { return { 13.5, 23 }; }

  static Position initialBlinkyPosition() { return { 13.5, 11 }; }
  static Position penDoorPosition() { return { 13, 11 }; }

  static Position blinkyScatterTarget() { return { 25, -3 }; }

  static Position initialSpeedyPosition() { return { 11.5, 14 }; }
  static Position speedyScatterTarget() { return { 3, -2 }; }

  static Position initialInkyPosition() { return { 13.5, 14 }; }
  static Position inkyScatterTarget() { return { 27, 30 }; }

  static Position initialClydePosition() { return { 15.5, 14 }; }
  static Position clydeScatterTarget() { return { 0, 30 }; }

private:
  [[nodiscard]] bool isWalkable(Position point, float d, Direction direction, bool pacman) const;
  uint8_t board_state[ROWS][COLUMNS]{};
};
