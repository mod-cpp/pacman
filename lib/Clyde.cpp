#include "Clyde.hpp"

namespace pacman {

Clyde::Clyde()
  : Ghost(Atlas::Ghost::clyde) {
}

double Clyde::speed(const GameState & gameState) const {
  if (state == State::Eyes)
    return 2;
  if (state == State::Frightened)
    return 0.5;
  return 0.75;
}

Position Clyde::target(const GameState & gameState) const {
  if (state == State::Eyes)
    return initialClydePosition();

  if (isInPen())
    return penDoorPosition();

  return clydeScatterTarget();
}

Position Clyde::initialPosition() const {
    return initialClydePosition();
}


}
