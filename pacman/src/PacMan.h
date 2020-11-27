#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H

#include "Board.h"
#include "Direction.h"
#include "InputState.h"
#include "Position.h"

#include <SDL2/SDL_rect.h>
#include <chrono>

class PacMan {
public:
  PacMan();
  [[nodiscard]] SDL_Rect currentSprite() const;
  [[nodiscard]] Position currentPosition() const;

  void update(std::chrono::milliseconds time_delta, InputState state, const Board & board);

private:

  Direction direction = Direction::NONE;
  Position pos = {14, 23};
  const SDL_Rect right_wide   = {0*32, 0, 32, 32};
  const SDL_Rect right_narrow = {1*32, 0, 32, 32};
  const SDL_Rect closed       = {2*32, 0, 32, 32};
  const SDL_Rect left_narrow  = {3*32, 0, 32, 32};
  const SDL_Rect left_wide    = {4*32, 0, 32, 32};
  const SDL_Rect up_wide      = {5*32, 0, 32, 32};
  const SDL_Rect up_narrow    = {6*32, 0, 32, 32};
  const SDL_Rect down_wide    = {7*32, 0, 32, 32};
  const SDL_Rect down_narrow  = {8*32, 0, 32, 32};
  const SDL_Rect right_animation[4];
  const SDL_Rect left_animation[4];
  const SDL_Rect up_animation[4];
  const SDL_Rect down_animation[4];
  uint8_t animation_position = 0;
  float_t animation_position_delta = 0.0;

  void setDirection(const InputState & state);
  void updateAnimationPosition(std::chrono::milliseconds time_delta);
  void updateMazePosition(std::chrono::milliseconds time_delta, const Board & board);
};

#endif //PACMAN_PACMAN_H
