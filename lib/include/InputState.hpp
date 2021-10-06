#pragma once

namespace pacman {

class InputState {
public:
  bool close = false;
  bool up = false;
  bool down = false;
  bool left = false;
  bool right = false;
  bool enableAI = false;

  Direction direction() const {
    if (left)
      return Direction::LEFT;
    if (right)
      return Direction::RIGHT;
    if (up)
      return Direction::UP;
    if (down)
      return Direction::DOWN;
    return Direction::NONE;
  }
};

} // namespace pacman
