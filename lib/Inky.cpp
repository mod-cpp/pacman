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
    return initialPosition();

  if (isInPen())
    return penDoorPosition();

  return scatterTarget();
}

Position Inky::initialPosition() const {
  return { 13.5, 14 };
}

Position Inky::scatterTarget() const {
  return { 27, 30 };
}

}
