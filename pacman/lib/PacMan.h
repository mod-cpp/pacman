#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H

#include "Board.h"
#include "Direction.h"
#include "InputState.h"
#include "Position.h"
#include "PacManAnimation.hpp"

#include <SDL2/SDL_rect.h>
#include <chrono>

class PacMan {
public:
  [[nodiscard]] SDL_Rect currentSprite() const;

  [[nodiscard]] Position currentPosition() const;

  void update(std::chrono::milliseconds time_delta, InputState state, const Board & board);

private:

  Direction direction = Direction::NONE;
  Direction desired_direction = Direction::NONE;
  Position pos = {14, 23};
  PacManAnimation pacManAnimation;

  void setDirection(const InputState & state);

  void updateAnimationPosition(std::chrono::milliseconds time_delta);

  void updateMazePosition(std::chrono::milliseconds time_delta, const Board & board);
};

#endif //PACMAN_PACMAN_H
