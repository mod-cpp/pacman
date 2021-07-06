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

  // Handle teleport
  const size_t right = COLUMNS - 1;
  const size_t left = 0;

  if (std::round(pos.x) == right && direction == Direction::RIGHT) {
    pos.x = left;
    return;
  } else if (std::round(pos.x) == left && direction == Direction::LEFT) {
    pos.x = right;
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
    return pacman::Board::isWalkableForPacMan(moveToPosition(pos, move_direction));
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
