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
    return initialPosition();

  if (isInPen())
    return penDoorPosition();

  return scatterTarget();
}

Position Blinky::initialPosition() const {
  return { 13.5, 11 };
}

Position Blinky::scatterTarget() const {
  return { 25, -3 };
}

}
