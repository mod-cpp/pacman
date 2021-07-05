#include "Board.hpp"

// Legend
// 0 - wall
// 1 - pellet
// 2 - nothing
// 3 - door
// 4 - superpower
// 5 - pen doors

std::array<std::array<int, COLUMNS>, ROWS> Board::board = {{
 // 0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 0
  { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 }, // 1
  { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0 }, // 2
  { 0, 4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 4, 0 }, // 3
  { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0 }, // 4
  { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 }, // 5
  { 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0 }, // 6
  { 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0 }, // 7
  { 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0 }, // 8
  { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, // 9
  { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, // 10
  { 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, // 11
  { 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 5, 5, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, // 12
  { 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 5, 5, 5, 5, 5, 5, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, // 13
  { 3, 2, 2, 2, 2, 2, 1, 2, 2, 2, 0, 5, 5, 5, 5, 5, 5, 0, 2, 2, 2, 1, 2, 2, 2, 2, 2, 3 }, // 14
  { 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 5, 5, 5, 5, 5, 5, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, // 15
  { 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, // 16
  { 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, // 17
  { 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, // 18
  { 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, // 19
  { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 }, // 20
  { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0 }, // 21
  { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0 }, // 22
  { 0, 4, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 4, 0 }, // 23
  { 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0 }, // 24
  { 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0 }, // 25
  { 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0 }, // 26
  { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, // 27
  { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, // 28
  { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 }, // 29
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 30
}};

bool Board::isWalkableForPacMan(Position point, double d, Direction direction) {
  return isWalkable(point, d, direction, true);
}

bool Board::isWalkableForGhost(Position point, double d, Direction direction) {
  return isWalkable(point, d, direction, false);
}

bool Board::isWalkable(Position point) {
  return board[int(point.y)][int(point.x)] != int(Cell::wall);
}

bool Board::isWalkableForGost(Position point, Position origin, bool isEyes) {
  return isWalkable(point) && (isEyes || (isInPen(origin) || !isInPen(point)));
}

bool Board::isInPen(Position point) {
  return board[int(point.y)][int(point.x)] == int(Cell::pen);
}

bool Board::isWalkable(Position point, double position_delta, Direction direction, bool pacman) {
  if (point.x <= 0 || point.x >= COLUMNS - 1)
    return true;

  auto cellAtPosition = [&](Position point, double position_delta, Direction direction) {
    switch (direction) {
      case Direction::LEFT:
        return board[int(point.y)][int(point.x - position_delta)];
      case Direction::RIGHT:
        return board[int(point.y)][int(point.x) + 1];
      case Direction::UP:
        return board[int(point.y - position_delta)][int(point.x)];
      case Direction::DOWN:
        return board[int(point.y) + 1][int(point.x)];
      case Direction::NONE:
      default:
        return int(Cell::wall);
    }
  };
  Cell cell = Cell(cellAtPosition(point, position_delta, direction));
  return pacman ? cell != Cell::wall : cell != Cell::wall && cell != Cell::pen;
}

std::vector<PositionInt> Board::initialPelletPositions() {
  std::vector<PositionInt> positions;
  for (int row = 0; row < ROWS; row++) {
    for (int column = 0; column < COLUMNS; column++) {
      if (board[row][column] == int(Cell::pellet))
        positions.push_back({ column, row });
    }
  }
  return positions;
}

std::vector<PositionInt> Board::initialSuperPelletPositions() {
  std::vector<PositionInt> positions;
  for (int row = 0; row < ROWS; row++) {
    for (int column = 0; column < COLUMNS; column++) {
      if (board[row][column] == int(Cell::power_pellet))
        positions.push_back({ column, row });
    }
  }
  return positions;
}
