#pragma once

#include "Board.hpp"
#include "Direction.hpp"
#include "InputState.hpp"
#include "Position.hpp"

#include <SDL2/SDL_rect.h>
#include <chrono>

class PacManAnimation {
public:
  [[nodiscard]] SDL_Point animationFrame(Direction direction) const;

  void updateAnimationPosition(std::chrono::milliseconds time_delta);

private:
  uint8_t animation_position = 0;
  float animation_position_delta = 0.0;
  const SDL_Point right_wide = { 0, 0 };
  const SDL_Point right_narrow = { 1, 0 };
  const SDL_Point closed = { 2, 0 };
  const SDL_Point left_narrow = { 3, 0 };
  const SDL_Point left_wide = { 4, 0 };
  const SDL_Point up_wide = { 5, 0 };
  const SDL_Point up_narrow = { 6, 0 };
  const SDL_Point down_wide = { 7, 0 };
  const SDL_Point down_narrow = { 8, 0 };
  const SDL_Point down_animation[4]{ down_wide, down_narrow, closed, down_narrow };
  const SDL_Point left_animation[4]{ left_wide, left_narrow, closed, left_narrow };
  const SDL_Point right_animation[4]{ right_wide, right_narrow, closed, right_narrow };
  const SDL_Point up_animation[4]{ up_wide, up_narrow, closed, up_narrow };
};
