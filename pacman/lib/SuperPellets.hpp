#ifndef PACMAN_SUPERPELLETS_HPP
#define PACMAN_SUPERPELLETS_HPP

#include "Position.hpp"
#include "Board.hpp"

#include <SDL2/SDL_rect.h>

class SuperPellets {
public:
  explicit SuperPellets(const Board & board);

  [[nodiscard]] SDL_Rect currentSprite() const {
    return super_pellet;
  }

  [[nodiscard]] std::vector<SDL_Point> currentPositions() const {
    return positions;
  }

private:
  const SDL_Rect super_pellet = {0 * 32, 9 * 32, 32, 32};
  std::vector<SDL_Point> positions;
};

#endif //PACMAN_SUPERPELLETS_HPP
