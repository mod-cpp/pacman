#include "Pinky.hpp"

namespace pacman {

Pinky::Pinky()
  : Ghost(Atlas::Ghost::pinky) {
}

double Pinky::speed(const GameState & gameState) const {
  if (state == State::Eyes)
    return 2;
  if (state == State::Frightened)
    return 0.5;
  return 0.75;
}

Position Pinky::target(const GameState & gameState) const {
  if (state == State::Eyes)
    return initialPosition();

  if (isInPen())
    return penDoorPosition();

  return scatterTarget();
}

Position Pinky::initialPosition() const {
  return { 11.5, 14 };
}

Position Pinky::scatterTarget() const {
  return { 3, -2 };
}

}
