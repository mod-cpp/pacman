#include "Clyde.hpp"

namespace pacman {

Clyde::Clyde()
  : Ghost(Atlas::Ghost::clyde) {
  pos = initialPosition();
}

double Clyde::speed() const {
  if (state == State::Eyes)
    return 2;
  if (state == State::Frightened)
    return 0.5;
  return 0.75;
}

void Clyde::setTarget(Position pacManPos) {
  if (state == State::Eyes) {
    target = initialPosition();
    return;
  }

  if (isInPen()) {
    target = penDoorPosition();
    return;
  }

  // Clyde always target its scatter target, unless pacman is further than 8 tiles away
  target = scatterTarget();
  if (state == State::Scatter) {
    return;
  }

  const auto distanceFomPacMan = std::hypot(pos.x - pacManPos.x, pos.y - pacManPos.y);
  if (distanceFomPacMan > 8) {
    target = pacManPos;
  }
}

Position Clyde::initialPosition() const {
  return { 15.5, 14 };
}

Position Clyde::scatterTarget() const {
  return { 0, 30 };
}

} // namespace pacman
