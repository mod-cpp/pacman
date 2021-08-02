#pragma once

namespace pacman {

class InputState {
public:
  bool close = false;
  bool up = false;
  bool down = false;
  bool left = false;
  bool right = false;

  Direction direction() const {
    if (left)
      return Direction::LEFT;
    else if (right)
      return Direction::RIGHT;
    else if (up)
      return Direction::UP;
    else if (down)
      return Direction::DOWN;
    else
      return Direction::NONE;
  }
};

} // namespace pacman
