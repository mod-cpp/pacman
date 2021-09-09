#pragma once

#include <cmath>

namespace pacman {

struct Position {
  double x = 0;
  double y = 0;
};

struct GridPosition {
  int64_t x;
  int64_t y;
  constexpr GridPosition(int64_t x, int64_t y) : x(x), y(y) {}
};

inline GridPosition positionToGridPosition(Position pos) {
  return { int64_t(std::round(pos.x)), int64_t(std::round(pos.y)) };
}

inline Position gridPositionToPosition(GridPosition pos) {
  return { double(pos.x), double(pos.y) };
}

constexpr bool operator==(const GridPosition & a, const GridPosition & b) {
  return a.x == b.x && a.y == b.y;
}

constexpr bool operator!=(const GridPosition & a, const GridPosition & b) {
  return !(a == b);
}

inline bool operator==(const Position & a, const Position & b) {
  // This is ok as a test unless x and y become very large.
  constexpr double epsilon = std::numeric_limits<double>::epsilon();
  return std::abs(a.x - b.x) <= epsilon && std::abs(a.y - b.y) <= epsilon;
}

inline bool operator!=(const Position & a, const Position & b) {
  return !(a == b);
}

} // namespace pacman
