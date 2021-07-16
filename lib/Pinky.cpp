#include "Pinky.hpp"
#include "Atlas.hpp"

namespace pacman {

Pinky::Pinky() {
  reset();
}

void Pinky::frighten() {
  if (state > GhostState::Scatter)
    return;
  direction = oppositeDirection(direction);
  state = GhostState::Frightened;
  timeFrighten = 0;
}

bool Pinky::isFrightened() const {
  return state == GhostState::Frightened;
}

bool Pinky::isEyes() const {
  return state == GhostState::Eyes;
}

void Pinky::die() {
  if (state == GhostState::Eyes)
    return;
  direction = oppositeDirection(direction);
  state = GhostState::Eyes;
  timeFrighten = 0;
}

void Pinky::reset() {
  pos = initialPinkyPosition();
}

[[nodiscard]] GridPosition Pinky::currentSprite() const {
  return animation.currentSprite(state, direction, timeFrighten);
}

Position Pinky::position() const {
  return pos;
}

void Pinky::update(std::chrono::milliseconds time_delta) {
  if (state == GhostState::Eyes && ghostIsInPen(*this))
    state = GhostState::Scatter;

  if (state == GhostState::Frightened) {
    timeFrighten += time_delta.count();
    if (timeFrighten > 6000)
      state = GhostState::Scatter;
  }

  animation.updateAnimation(time_delta);
  updatePosition(time_delta);
}

void Pinky::updatePosition(std::chrono::milliseconds time_delta) {
  const auto position_in_grid = positionToGridPosition(position());
  if (position_in_grid != last_grid_position) {
    direction = calculateNewGhostDirection(*this);
    last_grid_position = position_in_grid;
  }

  double position_delta = (0.004 * time_delta.count()) * speed();
  pos = calculateGhostMovement(*this, direction, position_delta);
}

double Pinky::speed() const {
  if (state == GhostState::Eyes)
    return 2;
  if (state == GhostState::Frightened)
    return 0.5;
  return 0.75;
}

Position Pinky::target() const {
  if (state == GhostState::Eyes)
    return initialPinkyPosition();

  if (pacman::isInPen(positionToGridPosition(position())))
    return pacman::penDoorPosition();

  return pinkyScatterTarget();
}

} // namespace pacman
