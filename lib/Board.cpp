#include "Board.hpp"

// Legend
// 0 - wall
// 1 - pellet
// 2 - nothing
// 3 - door
// 4 - superpower
// 5 - pen doors

static const uint8_t board[ROWS][COLUMNS] = {
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
};

Board::Board() {
  for (uint8_t row = 0; row < ROWS; row++)
    for (uint8_t column = 0; column < COLUMNS; column++)
      board_state[row][column] = board[row][column];
}

bool Board::isWalkableForPacMan(Position point, float d, Direction direction) const {
  return isWalkable(point, d, direction, true);
}

bool Board::isWalkableForGhost(Position point, float d, Direction direction) const {
  return isWalkable(point, d, direction, false);
}

bool Board::isWalkable(Position point) const {
     return board_state[int(point.y)][int(point.x)] != uint8_t(Cell::wall);
}

bool Board::isWalkableForGost(Position point, Position origin) const
{
    return isWalkable(point) && (isInPen(origin) || !isInPen(point));
}

bool Board::isInPen(Position point) const {
    return board_state[int(point.y)][int(point.x)] == uint8_t(Cell::pen);
}

bool Board::isWalkable(Position point, float position_delta, Direction direction, bool pacman) const {
  if (point.x <= 0 || point.x >= COLUMNS - 1)
    return true;

  auto cellAtPosition = [&](Position point, float position_delta, Direction direction) {
    switch (direction) {
      case Direction::LEFT:
        return board_state[int(point.y)][int(point.x - position_delta)];
      case Direction::RIGHT:
        return board_state[int(point.y)][int(point.x) + 1];
      case Direction::UP:
        return board_state[int(point.y - position_delta)][int(point.x)];
      case Direction::DOWN:
        return board_state[int(point.y) + 1][int(point.x)];
      case Direction::NONE:
      default:
        return uint8_t(Cell::wall);
    }
  };
  Cell cell = Cell(cellAtPosition(point, position_delta, direction));
  return pacman ? cell != Cell::wall : cell != Cell::wall && cell != Cell::pen;
}

std::vector<PositionInt> Board::initialPelletPositions() const {
  std::vector<PositionInt> positions;
  for (uint8_t row = 0; row < ROWS; row++) {
    for (uint8_t column = 0; column < COLUMNS; column++) {
      if (board_state[row][column] == uint8_t(Cell::pellet))
        positions.push_back({ column, row });
    }
  }
  return positions;
}

std::vector<PositionInt> Board::initialSuperPelletPositions() const {
  std::vector<PositionInt> positions;
  for (uint8_t row = 0; row < ROWS; row++) {
    for (uint8_t column = 0; column < COLUMNS; column++) {
      if (board_state[row][column] == uint8_t(Cell::power_pellet))
        positions.push_back({ column, row });
    }
  }
  return positions;
}
