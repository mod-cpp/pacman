#ifndef PACMAN_PELLETS_HPP
#define PACMAN_PELLETS_HPP

#include "Position.hpp"
#include "Board.hpp"

#include <SDL2/SDL_rect.h>

class Pellets {
public:
  explicit Pellets(const Board & board);

  [[nodiscard]] SDL_Rect currentSprite() const {
    return sprite;
  };

  [[nodiscard]] std::vector<SDL_Point> currentPositions() const {
    return positions;
  }

private:
  const SDL_Rect sprite = {1 * 32, 9 * 32, 32, 32};
  std::vector<SDL_Point> positions;
};

#endif //PACMAN_PELLETS_HPP
