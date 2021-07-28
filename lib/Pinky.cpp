#include "Pinky.hpp"

namespace pacman {

Pinky::Pinky()
  : Ghost(Atlas::Ghost::speedy, pacman::initialSpeedyPosition()) {
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
    return startingPosition;

  if (isInPen())
    return pacman::penDoorPosition();

  return speedyScatterTarget();
}

}