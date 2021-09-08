#include "SuperPellets.hpp"
#include <algorithm>

namespace pacman {

SuperPellets::SuperPellets()
  : positions(initialSuperPelletPositions()) {}

bool SuperPellets::eatPelletAtPosition(GridPosition p) {
  return std::erase(positions, p) > 0;
}

} // namespace pacman
