#ifndef PACMAN_BOARD_H
#define PACMAN_BOARD_H

#include "Direction.h"
#include "Position.h"
#include <SDL2/SDL_rect.h>
#include <cstdint>
#include <vector>

const uint8_t ROWS = 31;
const uint8_t COLUMNS = 28;

class Board {
public:
  Board();

  [[nodiscard]] bool isWalkable(Position point, float_t d, Direction direction) const;

  SDL_Rect pelletSprite();

  SDL_Rect superPelletSprite();

  std::vector<SDL_Point> pelletPositions();

  std::vector<SDL_Point> superPelletPositions();

private:
  uint8_t board_state[ROWS][COLUMNS];
  const SDL_Rect super_pellet = {0*32, 9*32, 32, 32};
  const SDL_Rect pellet       = {1*32, 9*32, 32, 32};

  void resetBoardState();
};

#endif //PACMAN_BOARD_H
