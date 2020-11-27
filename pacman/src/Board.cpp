#include "Board.h"

// Legend
// 0 - wall
// 1 - pellet
// 2 - nothing
// 3 - door
// 4 - superpower

// 16 pixels per square
// Maze in pixels - width: 448 - height - 496

static const uint8_t board[ROWS][COLUMNS] = {
// 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 0
  {0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0}, // 1
  {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0}, // 2
  {0,4,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,4,0}, // 3
  {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0}, // 4
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, // 5
  {0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0}, // 6
  {0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0}, // 7
  {0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0}, // 8
  {0,0,0,0,0,0,1,0,0,0,0,0,2,0,0,2,0,0,0,0,0,1,0,0,0,0,0,0}, // 9
  {0,0,0,0,0,0,1,0,0,0,0,0,2,0,0,2,0,0,0,0,0,1,0,0,0,0,0,0}, // 10
  {0,0,0,0,0,0,1,0,0,2,2,2,2,2,2,2,2,2,2,0,0,1,0,0,0,0,0,0}, // 11
  {0,0,0,0,0,0,1,0,0,2,0,0,0,3,3,0,0,0,2,0,0,1,0,0,0,0,0,0}, // 12
  {0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0}, // 13
  {3,2,2,2,2,2,1,2,2,2,0,0,0,0,0,0,0,0,2,2,2,1,2,2,2,2,2,3}, // 14
  {0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0}, // 15
  {0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0}, // 16
  {0,0,0,0,0,0,1,0,0,2,2,2,2,2,2,2,2,2,2,0,0,1,0,0,0,0,0,0}, // 17
  {0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0}, // 18
  {0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0}, // 19
  {0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0}, // 20
  {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0}, // 21
  {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0}, // 22
  {0,4,1,1,0,0,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,0,0,1,1,4,0}, // 23
  {0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0}, // 24
  {0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0}, // 25
  {0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0}, // 26
  {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0}, // 27
  {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0}, // 28
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, // 29
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, // 30
};

Board::Board() {
  resetBoardState();
}

void Board::resetBoardState() {
  for (uint8_t row = 0; row < ROWS; row++)
    for (uint8_t column = 0; column < COLUMNS; column++)
      board_state[row][column] = board[row][column];
}

bool Board::isWalkable(Position point, float_t position_delta, Direction direction) const {

  switch (direction) {
    case Direction::LEFT:
      return board_state[int(point.y)][int(point.x - position_delta)] != 0;
    case Direction::RIGHT:
      return board_state[int(point.y)][int(point.x) + 1] != 0;
    case Direction::UP:
      return board_state[int(point.y - position_delta)][int(point.x)] != 0;
    case Direction::DOWN:
      return board_state[int(point.y) + 1][int(point.x)] != 0;
    case Direction::NONE:
    default: return true;
  }
}

SDL_Rect Board::pelletSprite() {
  return pellet;
}

SDL_Rect Board::superPelletSprite() {
  return super_pellet;
}

std::vector<SDL_Point> Board::pelletPositions() {
  std::vector<SDL_Point> positions;
  for (uint8_t row = 0; row < ROWS; row++) {
    for (uint8_t column = 0; column < COLUMNS; column++) {
      if (board_state[row][column] == 1)
        positions.push_back({column, row});
    }
  }
  return positions;
}

std::vector<SDL_Point> Board::superPelletPositions() {
  // Hard coded is probably better than this
  std::vector<SDL_Point> positions;
  for (uint8_t row = 0; row < ROWS; row++) {
    for (uint8_t column = 0; column < COLUMNS; column++) {
      if (board_state[row][column] == 4)
        positions.push_back({column, row});
    }
  }
  return positions;
}
