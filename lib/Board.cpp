#include "Board.hpp"

namespace pacman {

const std::size_t ROWS = 31;
const std::size_t COLUMNS = 28;

enum class Cell {
  wall = 0,
  pellet = 1,
  // nothing = 2,
  // missing 3,
  power_pellet = 4,
  pen = 5,
  left_portal = 6,
  right_portal = 7
};

// clang-format off
constexpr std::array<std::array<int, COLUMNS>, ROWS> board = {{
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
  { 6, 2, 2, 2, 2, 2, 1, 2, 2, 2, 0, 5, 5, 5, 5, 5, 5, 0, 2, 2, 2, 1, 2, 2, 2, 2, 2, 7 }, // 14
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
// clang-format on

static Cell cellAtPosition(GridPosition point) {
  if (point.x >= COLUMNS || point.y >= ROWS)
    return Cell::wall;
  return Cell(board[point.y][point.x]);
}

bool isWalkableForPacMan(GridPosition point) {
  return cellAtPosition(point) != Cell::wall;
}

bool isWalkableForGhost(GridPosition point, GridPosition origin, bool isEyes) {
  const Cell cell = cellAtPosition(point);
  if (cell == Cell::wall)
    return false;
  return isEyes || isInPen(origin) || !isInPen(point);
}

bool isInPen(GridPosition point) {
  return cellAtPosition(point) == Cell::pen;
}

bool isPortal(GridPosition point, Direction direction) {
  return (cellAtPosition(point) == Cell::left_portal && direction == Direction::LEFT) ||
         (cellAtPosition(point) == Cell::right_portal && direction == Direction::RIGHT);
}

GridPosition teleport(GridPosition point) {
  size_t right = COLUMNS - 1;
  size_t left = 0;
  if (point.x == left)
    point.x = right;
  else if (point.x == right)
    point.x = left;
  return point;
}

std::vector<GridPosition> initialPelletPositions() {
  std::vector<GridPosition> positions;
  positions.reserve(4); // Reserve space for 4 supper pellets

  for (std::size_t row = 0; row < ROWS; row++) {
    for (std::size_t column = 0; column < COLUMNS; column++) {
      if (board[row][column] == int(Cell::pellet))
        positions.emplace_back(column, row);
    }
  }
  return positions;
}

std::vector<GridPosition> initialSuperPelletPositions() {
  std::vector<GridPosition> positions;

  // To avoid having to resize the vector too many times, we can
  // presemptively reserve space for elements.
  // At a glance, we can estimate that there are pellets on a third of the grid.
  // This is not accurate so we might either reserve too much or too little memory,
  // but this is will still be faster than not calling reserve at all!
  // This will be very noticeable on both very large vectors (10 thousands of elements),
  // Or small vectors in functions called very frequently.

  positions.reserve((ROWS * COLUMNS) / 3);

  for (std::size_t row = 0; row < ROWS; row++) {
    for (std::size_t column = 0; column < COLUMNS; column++) {
      if (board[row][column] == int(Cell::power_pellet))
        positions.emplace_back(column, row);
    }
  }
  return positions;
}

// AI

bool isIntersection(GridPosition point) {
  if (!isWalkableForPacMan(point) || cellAtPosition(point) == Cell::left_portal || cellAtPosition(point) == Cell::right_portal) {
    return false;
  }

  const GridPosition right{ point.x + 1, point.y };
  const bool rightWalkable = isWalkableForPacMan(right);

  const GridPosition left{ point.x - 1, point.y };
  const bool leftWalkable = isWalkableForPacMan(left);

  const GridPosition top{ point.x, point.y - 1 };
  const bool topWalkable = isWalkableForPacMan(top);

  const GridPosition bottom{ point.x, point.y + 1 };
  const bool bottomWalkable = isWalkableForPacMan(bottom);

  return (topWalkable && rightWalkable) || (rightWalkable && bottomWalkable) || (bottomWalkable && leftWalkable) || (leftWalkable && topWalkable);
}

bool isWalkableStraightLine(GridPosition pointA, GridPosition pointB) {
  // Points with no shared x,y have no straight line between them
  if (pointA.x != pointB.x && pointA.y != pointB.y) {
    return false;
  }

  // this is std::all_of
  if (pointA.x == pointB.x) {
    const size_t startY = (pointA.y > pointB.y ? pointB.y : pointA.y);
    const size_t endY = (pointA.y > pointB.y ? pointA.y : pointB.y);
    for (size_t y = startY; y <= endY; y++) {
      const GridPosition test{ pointA.x, y };
      if (!isWalkableForPacMan(test)) {
        return false;
      }
    }
    return true;
  }

  if (pointA.y == pointB.y) {
    const size_t startX = (pointA.x > pointB.x ? pointB.x : pointA.x);
    const size_t endX = (pointA.x > pointB.x ? pointA.x : pointB.x);
    for (size_t x = startX; x <= endX; x++) {
      const GridPosition test{ x, pointA.y };
      if (!isWalkableForPacMan(test)) {
        return false;
      }
    }
    return true;
  }

  return false;
}

} // namespace pacman
