#pragma once

#include "Direction.hpp"
#include "Position.hpp"
#include "assert.h"

#include <array>

namespace Atlas {

  enum class Ghost {
    blinky = 2,
    speedy = 3,
    inky = 4,
    clyde = 5,
  };

  constexpr PositionInt pacman_right_wide = { 0, 0 };
  constexpr PositionInt pacman_right_narrow = { 1, 0 };
  constexpr PositionInt pacman_closed = { 2, 0 };
  constexpr PositionInt pacman_left_narrow = { 3, 0 };
  constexpr PositionInt pacman_left_wide = { 4, 0 };
  constexpr PositionInt pacman_up_wide = { 5, 0 };
  constexpr PositionInt pacman_up_narrow = { 6, 0 };
  constexpr PositionInt pacman_down_wide = { 7, 0 };
  constexpr PositionInt pacman_down_narrow = { 8, 0 };

  constexpr PositionInt ghost_blue_frightened = { 0, 7 };
  constexpr PositionInt ghost_blue_frightened2 = { 1, 7 };
  constexpr PositionInt ghost_white_frightened = { 2, 7 };
  constexpr PositionInt ghost_white_frightened2 = { 3, 7 };

  constexpr PositionInt eyeSprite(Direction direction) {
    int x = 0;
    switch (direction) {
      case Direction::RIGHT:
        x = 0;
        break;
      case Direction::DOWN:
        x = 2;
        break;
      case Direction::LEFT:
        x = 4;
        break;
      case Direction::UP:
        x = 6;
        break;
      default:
        x = 0;
        break;
    }
    return { x, 6 };
  }

  constexpr PositionInt ghostSprite(Ghost ghost, Direction direction, bool alternative) {
    assert(ghost >= Ghost::blinky && ghost <= Ghost::clyde && "Invalid Ghost");
    int y = static_cast<int>(ghost);
    int x = 0;
    switch (direction) {
      case Direction::RIGHT:
        x = 0;
        break;
      case Direction::DOWN:
        x = 2;
        break;
      case Direction::LEFT:
        x = 4;
        break;
      case Direction::UP:
        x = 6;
        break;
      default:
        x = 0;
        break;
    }
    if (alternative)
      x++;
    return { x, y };
  }

  constexpr PositionInt initialFrightened(int animationIndex) {
    return (animationIndex % 2) == 0 ? Atlas::ghost_blue_frightened2 : Atlas::ghost_blue_frightened;
  }

  constexpr PositionInt endingFrightened(int animationIndex) {
    std::array<PositionInt, 4> positions = { Atlas::ghost_blue_frightened,
                                             Atlas::ghost_blue_frightened2,
                                             Atlas::ghost_white_frightened,
                                             Atlas::ghost_white_frightened2 };
    return positions[animationIndex];
  }
}
