#include "PacMan.hpp"
#include <cmath>

PacMan::PacMan(const Board & board)
  : pos(Board::initialPacManPosition()) {}

PositionInt PacMan::currentSprite() const {
  return eaten ? pacManAnimation.deathAnimationFrame(direction) : pacManAnimation.animationFrame(direction);
}

Position PacMan::position() const {
  return pos;
}

Position PacMan::positionInGrid() const {
  return { std::round(pos.x), std::round(pos.y) };
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
  float position_delta = 0.004 * time_delta.count();

  // Handle teleport
  if (pos.x >= COLUMNS - 1 && direction == Direction::RIGHT) {
    pos.x = -1;
  } else if (pos.x <= 0 && direction == Direction::LEFT) {
    pos.x = COLUMNS;
  }

  else if (board.isWalkableForPacMan(pos, position_delta, desired_direction)) {
    direction = desired_direction;
  }

  if (board.isWalkableForPacMan(pos, position_delta, direction)) {
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
