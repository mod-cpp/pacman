#pragma once

#include <SFML/Graphics.hpp>

struct Position {
  float x;
  float y;
};

struct PositionInt {
  int x;
  int y;
};

using Rect = sf::Rect<int>;

using Sprite = sf::Sprite;

inline bool operator==(const PositionInt & b, const Position & a) {
  return a.x == b.x && a.y == b.y;
}
