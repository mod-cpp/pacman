#pragma once

#include <SFML/Graphics.hpp>

namespace pacman {

struct Position {
  double x;
  double y;
};

struct GridPosition {
  size_t x;
  size_t y;
  constexpr GridPosition(size_t x, size_t y) : x(x), y(y) {}
};

using Rect = sf::Rect<int>;

using Sprite = sf::Sprite;

inline GridPosition positionToGridPosition(Position pos) {
  return { size_t(std::round(pos.x)), size_t(std::round(pos.y)) };
}

constexpr bool operator==(const GridPosition & a, const GridPosition & b) {
  return a.x == b.x && a.y == b.y;
}

constexpr bool operator==(const GridPosition & a, const Position & b) {
  return a.x == b.x && a.y == b.y;
}

constexpr bool operator==(const Position & a, const Position & b) {
  return a.x == b.x && a.y == b.y;
}

constexpr bool operator!=(const Position & a, const Position & b) {
  return !(a == b);
}

constexpr bool operator!=(const GridPosition & a, const GridPosition & b) {
  return !(a == b);
}

} // namespace pacman
