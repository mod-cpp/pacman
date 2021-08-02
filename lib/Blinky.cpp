#include "Blinky.hpp"
#include "GameState.hpp"

namespace pacman {

Blinky::Blinky()
  : Ghost(Atlas::Ghost::blinky) {
  pos = initialPosition();
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

  const auto pacManPosition = gridPositionToPosition(gameState.pacMan.positionInGrid());
  return state == State::Chase ? pacManPosition : scatterTarget();
}

Position Blinky::initialPosition() const {
  return { 13.5, 11 };
}

Position Blinky::scatterTarget() const {
  return { 25, -3 };
}

}
