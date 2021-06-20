#pragma once

#include "Direction.hpp"
#include "PacManAnimation.hpp"
#include "Position.hpp"

#include <chrono>

class Board;
class InputState;

class PacMan {
public:
  explicit PacMan(const Board & board);

  [[nodiscard]] PositionInt currentSprite() const;

  [[nodiscard]] Position position() const;

  [[nodiscard]] Position positionInGrid() const;

  void update(std::chrono::milliseconds time_delta, InputState state, const Board & board);

private:
  Direction direction = Direction::NONE;
  Direction desired_direction = Direction::NONE;
  Position pos;
  PacManAnimation pacManAnimation;

  void setDirection(const InputState & state);

  void updateAnimationPosition(std::chrono::milliseconds time_delta);

  void updateMazePosition(std::chrono::milliseconds time_delta, const Board & board);
};
