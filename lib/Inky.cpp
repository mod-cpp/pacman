#include "Inky.hpp"

namespace pacman {

Inky::Inky()
  : Ghost(Atlas::Ghost::inky) {
}

double Inky::speed(const GameState & gameState) const {
  if (state == State::Eyes)
    return 2;
  if (state == State::Frightened)
    return 0.5;
  return 0.75;
}

Position Inky::target(const GameState & gameState) const {
  if (state == State::Eyes)
    return initialInkyPosition();

  if (isInPen())
    return penDoorPosition();

  return inkyScatterTarget();
}

Position Inky::initialPosition() const {
    return initialInkyPosition();
}


}
