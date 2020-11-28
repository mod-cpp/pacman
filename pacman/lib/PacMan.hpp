#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H

#include "Direction.hpp"
#include "Position.hpp"
#include "PacManAnimation.hpp"

#include <SDL2/SDL_rect.h>
#include <chrono>

class Board;
class InputState;

class PacMan {
public:
  explicit PacMan(const Board & board);

  [[nodiscard]] SDL_Rect currentSprite() const;

  [[nodiscard]] Position currentPosition() const;

  void update(std::chrono::milliseconds time_delta, InputState state, const Board & board);

private:

  Direction direction = Direction::NONE;
  Direction desired_direction = Direction::NONE;
  Position pos;
  PacManAnimation pacManAnimation;

  void setDirection(const InputState & state);

  void updateAnimationPosition(std::chrono::milliseconds time_delta);

  void updateMazePosition(std::chrono::milliseconds time_delta, const Board & board);
};

#endif //PACMAN_PACMAN_H
