#include "PacManAI.hpp"

#include "Board.hpp"
#include <random>

namespace pacman {

[[maybe_unused]] std::size_t randomInt(std::size_t min, std::size_t max) {
  // construct a random device
  thread_local std::random_device device;
  //construct a mersenne twister pseudo generator engine, seeded with the device
  thread_local std::mt19937 generator(device());
  // create a distribution
  std::uniform_int_distribution<std::size_t> distribution(min, max);
  return distribution(generator);
}

void PacManAI::reset() {
  pos = {};
  direction = Direction::RIGHT;
}

Direction PacManAI::suggestedDirection() const {
  return direction;
}

// This function is not yet implemented.
// You will implement it as part of module 24.
GridPosition PacManAI::pelletClosestToPacman(GridPosition pacmanGridPosition  [[maybe_unused]],
                                             std::vector<GridPosition> & pellets [[maybe_unused]]) {
  return {0, 0};
}

// This function is not yet implemented.
// You will implement it as part of module 21.
bool PacManAI::isValidMove(const Move & move [[maybe_unused]]) {
  return false;
}

// This function is not yet implemented.
// You will implement it as part of module 21. and 24.
Direction PacManAI::optimalDirection(const std::array<Move, 4> & moves [[maybe_unused]]) {
  return Direction::NONE;
}

// This function is not yet implemented.
// You will implement it as part of module 25.
Direction PacManAI::choseNewDirectionForPacMan(const PacMan & pacMan [[maybe_unused]],
                                               const Pellets & pellets [[maybe_unused]]) {
  return Direction::RIGHT;
}

void PacManAI::update(const PacMan & pacMan, const Pellets & pellets [[maybe_unused]]) {

  const GridPosition pacManGridPos = pacMan.positionInGrid();
  const GridPosition currentGridPos = positionToGridPosition(pos);

  if (!isIntersection(pacManGridPos) || currentGridPos == pacManGridPos) {
    return;
  }

  direction = choseNewDirectionForPacMan(pacMan, pellets);
  pos = pacMan.position();
}
} // namespace pacman
