#ifndef PACMAN_PACMAN_ANIMATION_HPP
#define PACMAN_PACMAN_ANIMATION_HPP

#include "Board.hpp"
#include "Direction.hpp"
#include "InputState.hpp"
#include "Position.hpp"

#include <SDL2/SDL_rect.h>
#include <chrono>

class PacManAnimation {
public:

  [[nodiscard]] SDL_Rect animationFrame(Direction direction) const;

  void updateAnimationPosition(std::chrono::milliseconds time_delta);

private:
  uint8_t animation_position = 0;
  float animation_position_delta = 0.0;
  const SDL_Rect right_wide   = {0 * 32, 0 * 32, 32, 32};
  const SDL_Rect right_narrow = {1 * 32, 0 * 32, 32, 32};
  const SDL_Rect closed       = {2 * 32, 0 * 32, 32, 32};
  const SDL_Rect left_narrow  = {3 * 32, 0 * 32, 32, 32};
  const SDL_Rect left_wide    = {4 * 32, 0 * 32, 32, 32};
  const SDL_Rect up_wide      = {5 * 32, 0 * 32, 32, 32};
  const SDL_Rect up_narrow    = {6 * 32, 0 * 32, 32, 32};
  const SDL_Rect down_wide    = {7 * 32, 0 * 32, 32, 32};
  const SDL_Rect down_narrow  = {8 * 32, 0 * 32, 32, 32};
  const SDL_Rect down_animation[4]{down_wide, down_narrow, closed, down_narrow};
  const SDL_Rect left_animation[4]{left_wide, left_narrow, closed, left_narrow};
  const SDL_Rect right_animation[4]{right_wide, right_narrow, closed, right_narrow};
  const SDL_Rect up_animation[4]{up_wide, up_narrow, closed, up_narrow};
};

#endif //PACMAN_PACMAN_ANIMATION_HPP
