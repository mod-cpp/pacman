#include "PacManAnimation.hpp"

PositionInt PacManAnimation::animationFrame(Direction direction) const {
  switch (direction) {
    case Direction::LEFT:
      return left_animation[animation_position];
    case Direction::RIGHT:
      return right_animation[animation_position];
    case Direction::UP:
      return up_animation[animation_position];
    case Direction::DOWN:
      return down_animation[animation_position];
    case Direction::NONE:
    default:
      return closed;
  }
}

void PacManAnimation::updateAnimationPosition(std::chrono::milliseconds time_delta) {
  animation_position_delta += (time_delta.count() / 100.0);
  animation_position = int(animation_position + animation_position_delta) % 4;
  animation_position_delta = (animation_position_delta < 1) ? animation_position_delta : (animation_position_delta - 1);
}
