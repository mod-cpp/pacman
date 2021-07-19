#pragma once

#include <chrono>

#include "Ghost.hpp"

namespace pacman {

class Inky {
public:
  explicit Inky();

  [[nodiscard]] GridPosition currentSprite() const;

  [[nodiscard]] Position position() const;

  [[nodiscard]] Direction currentDirection() const {
    return direction;
  }

  void update(std::chrono::milliseconds time_delta);
  void frighten();
  void die();
  [[nodiscard]] bool isFrightened() const;
  [[nodiscard]] bool isEyes() const;
  void reset();
  [[nodiscard]] Position target() const;

private:
  [[nodiscard]] double speed() const;
  void updatePosition(std::chrono::milliseconds time_delta);
  void updateDirection();

protected:
  Direction direction = Direction::NONE;
  GhostState state = GhostState::Chase;
  std::chrono::milliseconds timeFrighten = {};
  Position pos;
  GhostAnimation animation = Atlas::Ghost::inky;
  GridPosition last_grid_position = { 0, 0 };
};

} // namespace pacman
