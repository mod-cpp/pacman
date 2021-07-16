#include "Blinky.hpp"
#include "Atlas.hpp"

namespace pacman {

Blinky::Blinky() {
  reset();
}

void Blinky::frighten() {
  if (state > GhostState::Scatter)
    return;
  direction = oppositeDirection(direction);
  state = GhostState::Frightened;
  timeFrighten = 0;
}

bool Blinky::isFrightened() const {
  return state == GhostState::Frightened;
}

bool Blinky::isEyes() const {
  return state == GhostState::Eyes;
}

void Blinky::die() {
  if (state == GhostState::Eyes)
    return;
  direction = oppositeDirection(direction);
  state = GhostState::Eyes;
  timeFrighten = 0;
}

void Blinky::reset() {
  pos = initialBlinkyPosition();
}

[[nodiscard]] GridPosition Blinky::currentSprite() const {
  return animation.currentSprite(state, direction, timeFrighten);
}

Position Blinky::position() const {
  return pos;
}

void Blinky::update(std::chrono::milliseconds time_delta) {
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

void Blinky::updatePosition(std::chrono::milliseconds time_delta) {
  const auto position_in_grid = positionToGridPosition(position());
  if (position_in_grid != last_grid_position) {
    direction = calculateNewGhostDirection(*this);
    last_grid_position = position_in_grid;
  }

  double position_delta = (0.004 * time_delta.count()) * speed();
  pos = calculateGhostMovement(*this, direction, position_delta);
}

double Blinky::speed() const {
  if (state == GhostState::Eyes)
    return 2;
  if (state == GhostState::Frightened)
    return 0.5;
  return 0.75;
}

Position Blinky::target() const {
  if (state == GhostState::Eyes)
    return initialBlinkyPosition();

  if (pacman::isInPen(positionToGridPosition(position())))
    return pacman::penDoorPosition();

  return blinkyScatterTarget();
}

} // namespace pacman
