#pragma once

#include <SFML/Graphics.hpp>

#include "Direction.hpp"
#include "Position.hpp"
#include <array>
#include <cstdint>
#include <vector>

const std::size_t ROWS = 31;
const std::size_t COLUMNS = 28;

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

  [[nodiscard]] static bool isWalkableForPacMan(Position point, double d, Direction direction) ;

  [[nodiscard]] static bool isWalkableForGost(Position point, Position origin, bool isEyes) ;
  [[nodiscard]] static bool isWalkable(Position point) ;
  [[nodiscard]] static bool isInPen(Position point) ;

  [[nodiscard]] static std::vector<GridPosition> initialPelletPositions() ;

  [[nodiscard]] static std::vector<GridPosition> initialSuperPelletPositions() ;

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
  [[nodiscard]] static bool isWalkable(Position point, double d, Direction direction, bool pacman) ;
  static std::array<
    std::array<int, COLUMNS>,
    ROWS>
    board;
};
