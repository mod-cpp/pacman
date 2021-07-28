#include "Blinky.hpp"

namespace pacman {

Blinky::Blinky()
  : Ghost(Atlas::Ghost::blinky) {
}

double Blinky::speed(const GameState & gameState) const {
  if (state == State::Eyes)
    return 2;
  if (state == State::Frightened)
    return 0.5;
  return 0.75;
}

Position Blinky::target(const GameState & gameState) const {
  if (state == State::Eyes)
    return initialBlinkyPosition();

  if (isInPen())
    return penDoorPosition();

  return blinkyScatterTarget();
}

Position Blinky::initialPosition() const {
    return initialBlinkyPosition();
}

}
