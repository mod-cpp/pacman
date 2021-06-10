#include "PacMan.hpp"

PacMan::PacMan(const Board & board) :
    pos(board.initialPacManPosition()) {}

SDL_Rect PacMan::currentSprite() const {
  return pacManAnimation.animationFrame(direction);
}

Position PacMan::position() const {
  return pos;
}

void PacMan::update(std::chrono::milliseconds time_delta, InputState state, const Board & board) {
  setDirection(state);
  updateAnimationPosition(time_delta);
  updateMazePosition(time_delta, board);
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

void PacMan::updateAnimationPosition(std::chrono::milliseconds time_delta) {
  pacManAnimation.updateAnimationPosition(time_delta);
}

void PacMan::updateMazePosition(std::chrono::milliseconds time_delta, const Board & board) {
  float position_delta = (time_delta.count() / 128.0);

  if (board.isWalkable(pos, position_delta, desired_direction)) {
    direction = desired_direction;
  }

  if (board.isWalkable(pos, position_delta, direction)) {
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
