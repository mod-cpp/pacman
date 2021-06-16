#include "Pellets.hpp"
#include <algorithm>

Pellets::Pellets(const Board & board)
  : positions(board.initialPelletPositions()) {}

bool Pellets::eatPelletAtPosition(Position p) {
  auto it = std::find(positions.begin(), positions.end(), p);
  if (it == positions.end())
    return false;
  positions.erase(it);
  return true;
}
