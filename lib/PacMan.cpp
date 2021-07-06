#include "PacMan.hpp"
#include <cmath>

namespace pacman {

PacMan::PacMan(const Board & board)
  : pos(Board::initialPacManPosition()) {}

GridPosition PacMan::currentSprite() const {
  return eaten ? pacManAnimation.deathAnimationFrame(direction) : pacManAnimation.animationFrame(direction);
}

Position PacMan::position() const {
  return pos;
}

GridPosition PacMan::positionInGrid() const {
  return positionToGridPosition(pos);
}

void PacMan::eat() {
  if (eaten)
    return;
  eaten = true;
  direction = Direction::NONE;
}

void PacMan::reset(const Board & b) {
  eaten = false;
  direction = Direction::NONE;
  pos = b.initialPacManPosition();
}

void PacMan::update(std::chrono::milliseconds time_delta, InputState state, const Board & board) {
  if (eaten) {
    updateAnimationPosition(time_delta, false);
    return;
  }
  const auto old = pos;
  setDirection(state);
  updateMazePosition(time_delta, board);
  const bool paused = pos == old;
  updateAnimationPosition(time_delta, paused);
}

void PacMan::setDirection(const InputState & state) {
  if (state.left)
    desired_direction = Direction::LEFT;
  else if (state.right)
    desired_direction = Direction::RIGHT;
  else if (state.up)
    desired_direction = Direction::UP;
  else if (state.down)
    desired_direction = Direction::DOWN;
}

void PacMan::updateAnimationPosition(std::chrono::milliseconds time_delta, bool paused) {
  if (paused) {
    pacManAnimation.pause();
  } else {
    pacManAnimation.updateAnimationPosition(time_delta, eaten);
  }
}

void PacMan::updateMazePosition(std::chrono::milliseconds time_delta, const Board & board) {
  const double position_delta = 0.004 * time_delta.count();

  auto moveToPosition = [&](Position point, double position_delta, Direction direction) {
    switch (direction) {
      case Direction::LEFT:
        return Position{ std::floor(point.x - position_delta), std::floor(point.y) };
      case Direction::RIGHT:
        return Position{ std::floor(point.x + 1), std::floor(point.y) };
      case Direction::UP:
        return Position{ std::floor(point.x), std::floor(point.y - position_delta) };
      case Direction::DOWN:
        return Position{ std::floor(point.x), std::floor(point.y + 1) };
      case Direction::NONE:
      default:
        return point;
    }
  };

  auto canGo = [&](Direction desired_direction) {
    return board.isWalkableForPacMan(positionToGridPosition(moveToPosition(pos, position_delta, desired_direction)));
  };

  // Handle teleport
  if (pos.x >= COLUMNS - 1 && direction == Direction::RIGHT) {
    pos.x = -1;
  } else if (pos.x <= 0 && direction == Direction::LEFT) {
    pos.x = COLUMNS;
  } else if (canGo(desired_direction)) {
    direction = desired_direction;
  }

  if (canGo(direction)) {
    switch (direction) {
      case Direction::NONE:
        break;
      case Direction::LEFT:
        pos.x -= position_delta;
        pos.y = floor(pos.y);
        break;
      case Direction::RIGHT:
        pos.x += position_delta;
        pos.y = floor(pos.y);
        break;
      case Direction::UP:
        pos.x = floor(pos.x);
        pos.y -= position_delta;
        break;
      case Direction::DOWN:
        pos.x = floor(pos.x);
        pos.y += position_delta;
        break;
    }
  }
}

} // namespace pacman
