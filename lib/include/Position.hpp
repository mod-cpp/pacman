#pragma once

#include <SFML/Graphics.hpp>

namespace pacman {

struct Position {
  double x;
  double y;
};

struct GridPosition {
  int x;
  int y;
};

using Rect = sf::Rect<int>;

using Sprite = sf::Sprite;

inline bool operator==(const GridPosition & a, const GridPosition & b) {
  return a.x == b.x && a.y == b.y;
}

inline bool operator==(const GridPosition & a, const Position & b) {
  return a.x == b.x && a.y == b.y;
}

inline bool operator==(const Position & a, const Position & b) {
  return a.x == b.x && a.y == b.y;
}

inline bool operator!=(const Position & a, const Position & b) {
  return !(a == b);
}

} // namespace pacman
