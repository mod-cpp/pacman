#include "Pellets.hpp"
#include <algorithm>

namespace pacman {

Pellets::Pellets()
  : positions(initialPelletPositions()) {}

bool Pellets::eatPelletAtPosition(GridPosition p) {
  return std::erase(positions, p) > 0;
}

} // namespace pacman
