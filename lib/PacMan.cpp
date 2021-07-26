#include "PacMan.hpp"
#include <cmath>

namespace pacman {

GridPosition PacMan::currentSprite() const {
  return dead ? pacManAnimation.deathAnimationFrame() : pacManAnimation.animationFrame(direction);
}

Position PacMan::position() const {
  return pos;
}

GridPosition PacMan::positionInGrid() const {
  return positionToGridPosition(pos);
}

void PacMan::die() {
  if (dead)
    return;
  dead = true;
}

void PacMan::reset() {
  dead = false;
  direction = Direction::NONE;
  desired_direction = Direction::NONE;
  pos = initialPacManPosition();
}

void PacMan::update(std::chrono::milliseconds time_delta, Direction input_direction) {
  if (dead) {
    updateAnimationPosition(time_delta, false);
    return;
  }
  if (input_direction != Direction::NONE)
    desired_direction = input_direction;
  const auto old = pos;
  updateMazePosition(time_delta);
  const bool paused = pos == old;
  updateAnimationPosition(time_delta, paused);
}

void PacMan::updateAnimationPosition(std::chrono::milliseconds time_delta, bool paused) {
  if (paused) {
    pacManAnimation.pause();
  } else {
    pacManAnimation.updateAnimationPosition(time_delta, dead);
  }
}

void PacMan::updateMazePosition(std::chrono::milliseconds time_delta) {

  if (isPortal(positionInGrid(), direction)) {
    pos = gridPositionToPosition(teleport(positionInGrid()));
    return;
  }

  const double position_delta = 0.004 * time_delta.count();
  const auto pacman_size = 1;

  auto moveToPosition = [&](Position point, Direction move_direction) {
    switch (move_direction) {
      case Direction::LEFT:
        return GridPosition{ std::size_t(point.x - position_delta), std::size_t(point.y) };
      case Direction::RIGHT:
        return GridPosition{ std::size_t(point.x + pacman_size), std::size_t(point.y) };
      case Direction::UP:
        return GridPosition{ std::size_t(point.x), std::size_t(point.y - position_delta) };
      case Direction::DOWN:
        return GridPosition{ std::size_t(point.x), std::size_t(point.y + pacman_size) };
      case Direction::NONE:
      default:
        return positionToGridPosition(point);
    }
  };

  auto canGo = [&](Direction move_direction) {
    return isWalkableForPacMan(moveToPosition(pos, move_direction));
  };

  if (canGo(desired_direction)) {
    direction = desired_direction;
  }

  if (canGo(direction)) {
    switch (direction) {
      case Direction::NONE:
        break;
      case Direction::LEFT:
        pos.x -= position_delta;
        pos.y = std::floor(pos.y);
        break;
      case Direction::RIGHT:
        pos.x += position_delta;
        pos.y = std::floor(pos.y);
        break;
      case Direction::UP:
        pos.x = std::floor(pos.x);
        pos.y -= position_delta;
        break;
      case Direction::DOWN:
        pos.x = std::floor(pos.x);
        pos.y += position_delta;
        break;
    }
  }
}

} // namespace pacman
