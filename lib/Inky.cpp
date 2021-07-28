#include "Inky.hpp"

namespace pacman {

Inky::Inky()
  : Ghost(Atlas::Ghost::inky, pacman::initialInkyPosition()) {
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
    return startingPosition;

  if (isInPen())
    return pacman::penDoorPosition();

  return inkyScatterTarget();
}

}