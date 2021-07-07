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
  explicit PacMan(const Board & board);

  [[nodiscard]] GridPosition currentSprite() const;

  [[nodiscard]] Position position() const;

  [[nodiscard]] GridPosition positionInGrid() const;

  void update(std::chrono::milliseconds time_delta, InputState state, const Board & board);

  void eat();
  void reset(const Board & b);
  [[nodiscard]] bool onTheMove() const {
    return direction != Direction::NONE;
  }

private:
  Direction direction = Direction::NONE;
  Direction desired_direction = Direction::NONE;
  Position pos;
  PacManAnimation pacManAnimation;
  bool eaten = false;

  void setDirection(const InputState & state);

  void updateAnimationPosition(std::chrono::milliseconds time_delta, bool paused);
  void updateMazePosition(std::chrono::milliseconds time_delta, const Board & board);
};

} // namespace pacman
