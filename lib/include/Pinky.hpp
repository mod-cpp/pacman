#pragma once

#include <chrono>

#include "Ghost.hpp"

namespace pacman {

class Pinky {
public:
  explicit Pinky();

  [[nodiscard]] GridPosition currentSprite() const;

  [[nodiscard]] Position position() const;

  [[nodiscard]] Direction currentDirection() const {
    return direction;
  }

  void update(std::chrono::milliseconds time_delta, GridPosition pacman_position, Direction pacman_direction);
  void frighten();
  void die();
  [[nodiscard]] bool isFrightened() const;
  [[nodiscard]] bool isEyes() const;
  void reset();
  [[nodiscard]] Position target(GridPosition pacman_position, Direction pacman_direction) const;

private:
  [[nodiscard]] double speed() const;
  void updatePosition(std::chrono::milliseconds time_delta, GridPosition pacman_position, Direction pacman_direction);
  void updateDirection();

protected:
  Direction direction = Direction::NONE;
  GhostState state = GhostState::Chase;
  std::chrono::milliseconds timeFrighten = {};
  std::chrono::milliseconds timeChase{};
  Position pos;
  GhostAnimation animation = Atlas::Ghost::pinky;
  GridPosition last_grid_position = { 0, 0 };
};

} // namespace pacman
