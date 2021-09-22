#include "Inky.hpp"
#include "GameState.hpp"

namespace pacman {

Inky::Inky()
  : Ghost(Atlas::Ghost::inky) {
  pos = initialPosition();
}

double Inky::speed(const GameState &) const {
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

  if (state == State::Scatter)
    return scatterTarget();

  // Inky first selects a position 2 cell away from pacman in his direction.
  GridPosition targetPosition = gameState.pacMan.positionInGrid();
  switch (gameState.pacMan.currentDirection()) {
    case Direction::LEFT:
      targetPosition.x -= 2;
      break;
    case Direction::RIGHT:
      targetPosition.x += 2;
      break;
    case Direction::UP:
      targetPosition.y -= 2;
      targetPosition.x -= 2;
      break;
    case Direction::DOWN:
      targetPosition.y += 2;
      break;
    case Direction::NONE:
      assert(false && "Pacman should be moving");
      break;
  }

  // Then it calculates the distance between Blinky and this position
  const auto & blinkyPosition = gameState.blinky.positionInGrid();
  const double distanceBetweenBlinkyAndTarget = std::hypot(blinkyPosition.x - targetPosition.x, blinkyPosition.y - targetPosition.y);

  // And selects a point on the line crossing blinky and this position that is at twice that distance
  // away from blinky
  targetPosition.x += std::size_t((double(targetPosition.x) - double(blinkyPosition.x)) / distanceBetweenBlinkyAndTarget) * 2;
  targetPosition.y += std::size_t((double(targetPosition.y) - double(blinkyPosition.y)) / distanceBetweenBlinkyAndTarget) * 2;

  return gridPositionToPosition(targetPosition);
}

Position Inky::initialPosition() const {
  return { 13.5, 14 };
}

Position Inky::scatterTarget() const {
  return { 27, 30 };
}

} // namespace pacman
