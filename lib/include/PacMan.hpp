#pragma once

#include "Direction.hpp"
#include "PacManAnimation.hpp"
#include "Position.hpp"

#include <chrono>

namespace pacman {

class Board;
class InputState;

class PacMan {
public:
  explicit PacMan();

  [[nodiscard]] GridPosition currentSprite() const;

  [[nodiscard]] Position position() const;

  [[nodiscard]] GridPosition positionInGrid() const;

  void update(std::chrono::milliseconds time_delta, Direction input_direction);

  void eat();
  void reset();
  [[nodiscard]] bool hasDirection() const {
    return direction != Direction::NONE;
  }

private:
  Direction direction = Direction::NONE;
  Direction desired_direction = Direction::NONE;
  Position pos;
  PacManAnimation pacManAnimation;
  bool eaten = false;

  void updateAnimationPosition(std::chrono::milliseconds time_delta, bool paused);
  void updateMazePosition(std::chrono::milliseconds time_delta);
};

} // namespace pacman
