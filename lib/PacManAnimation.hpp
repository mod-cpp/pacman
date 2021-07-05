#pragma once

#include "Atlas.hpp"
#include "Board.hpp"
#include "Direction.hpp"
#include "InputState.hpp"
#include "Position.hpp"

#include <chrono>

class PacManAnimation {
public:
  [[nodiscard]] PositionInt animationFrame(Direction direction) const;
  [[nodiscard]] PositionInt deathAnimationFrame(Direction direction) const;

  void updateAnimationPosition(std::chrono::milliseconds time_delta, bool dead);
  void pause();

private:
  uint8_t animation_position = 0;
  double animation_position_delta = 0.0;
  const PositionInt down_animation[4]{ Atlas::pacman_down_wide, Atlas::pacman_down_narrow, Atlas::pacman_closed, Atlas::pacman_down_narrow };
  const PositionInt left_animation[4]{ Atlas::pacman_left_wide, Atlas::pacman_left_narrow, Atlas::pacman_closed, Atlas::pacman_left_narrow };
  const PositionInt right_animation[4]{ Atlas::pacman_right_wide, Atlas::pacman_right_narrow, Atlas::pacman_closed, Atlas::pacman_right_narrow };
  const PositionInt up_animation[4]{ Atlas::pacman_up_wide, Atlas::pacman_up_narrow, Atlas::pacman_closed, Atlas::pacman_up_narrow };
};
