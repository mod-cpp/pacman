#include "Clyde.hpp"
#include "GameState.hpp"

namespace pacman {

Clyde::Clyde()
  : Ghost(Atlas::Ghost::clyde) {
  pos = initialPosition();
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
    return initialPosition();

  if (isInPen())
    return penDoorPosition();

  // Clyde always target its scatter target, unless pacman is further than 8 tiles away
  auto targetPosition = scatterTarget();
  if (state == State::Scatter)
    return targetPosition;

  const auto pacManPosition = gameState.pacMan.positionInGrid();
  auto distanceFomPacMan = std::hypot(pos.x - pacManPosition.x, pos.y - pacManPosition.y);
  if (distanceFomPacMan > 8)
    targetPosition = gridPositionToPosition(pacManPosition);

  return targetPosition;
}

Position Clyde::initialPosition() const {
  return { 15.5, 14 };
}

Position Clyde::scatterTarget() const {
  return { 0, 30 };
}

}
