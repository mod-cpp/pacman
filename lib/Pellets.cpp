#include "Pellets.hpp"
#include <algorithm>

namespace pacman {

Pellets::Pellets(const Board & board)
  : positions(pacman::Board::initialPelletPositions()) {}

bool Pellets::eatPelletAtPosition(GridPosition p) {
  auto it = std::find(positions.begin(), positions.end(), p);
  if (it == positions.end())
    return false;
  positions.erase(it);
  return true;
}

} // namespace pacman
