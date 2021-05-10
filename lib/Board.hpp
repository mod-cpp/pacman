#ifndef PACMAN_BOARD_H
#define PACMAN_BOARD_H

#include "Direction.hpp"
#include "Position.hpp"

#include <SDL2/SDL_rect.h>
#include <cstdint>
#include <vector>

const uint8_t ROWS = 31;
const uint8_t COLUMNS = 28;

class Board {
public:
  Board();

  [[nodiscard]] bool isWalkable(Position point, float_t d, Direction direction) const;

  [[nodiscard]] std::vector<SDL_Point> initialPelletPositions() const;

  [[nodiscard]] std::vector<SDL_Point> initialSuperPelletPositions() const;

  static Position initialPacManPosition() { return {14, 23}; }

private:
  uint8_t board_state[ROWS][COLUMNS]{};
};

#endif //PACMAN_BOARD_H
