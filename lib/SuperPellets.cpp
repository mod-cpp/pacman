#include "SuperPellets.hpp"

SuperPellets::SuperPellets(const Board & board)
  : positions(board.initialSuperPelletPositions()) {}

bool SuperPellets::eatPelletAtPosition(Position p) {
  auto it = std::find(positions.begin(), positions.end(), p);
  if (it == positions.end())
    return false;
  positions.erase(it);
  return true;
}
