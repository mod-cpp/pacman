#include "PacManAnimation.hpp"

GridPosition PacManAnimation::animationFrame(Direction direction) const {
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
      return Atlas::pacman_closed;
  }
}

[[nodiscard]] GridPosition PacManAnimation::deathAnimationFrame(Direction direction) const {
  return GridPosition{ animation_position, 1 };
}

void PacManAnimation::updateAnimationPosition(std::chrono::milliseconds time_delta, bool dead) {
  if (dead && animation_position >= 11)
    return;

  animation_position_delta += (0.02) * double(time_delta.count());
  animation_position = int(animation_position + animation_position_delta);

  if (!dead)
    animation_position = animation_position % 4;

  animation_position_delta = (animation_position_delta < 1) ? animation_position_delta : (animation_position_delta - 1);
}

void PacManAnimation::pause() {
  animation_position = 0;
  animation_position_delta = 0;
}
