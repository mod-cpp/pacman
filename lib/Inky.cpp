#include "Inky.hpp"
#include "Atlas.hpp"

namespace pacman {

Inky::Inky() {
  reset();
}

void Inky::frighten() {
  if (state > GhostState::Scatter)
    return;
  direction = oppositeDirection(direction);
  state = GhostState::Frightened;
  timeFrighten = {};
}

bool Inky::isFrightened() const {
  return state == GhostState::Frightened;
}

bool Inky::isEyes() const {
  return state == GhostState::Eyes;
}

void Inky::die() {
  if (state == GhostState::Eyes)
    return;
  direction = oppositeDirection(direction);
  state = GhostState::Eyes;
  timeFrighten = {};
}

void Inky::reset() {
  pos = initialInkyPosition();
}

[[nodiscard]] GridPosition Inky::currentSprite() const {
  return animation.currentSprite(state, direction, timeFrighten);
}

Position Inky::position() const {
  return pos;
}

void Inky::update(std::chrono::milliseconds time_delta) {
  if (state == GhostState::Eyes && ghostIsInPen(*this))
    state = GhostState::Scatter;

  if (state == GhostState::Frightened) {
    timeFrighten += time_delta;
    if (timeFrighten.count() > 6000)
      state = GhostState::Scatter;
  }

  animation.updateAnimation(time_delta);
  updatePosition(time_delta);
}

void Inky::updatePosition(std::chrono::milliseconds time_delta) {
  const auto position_in_grid = positionToGridPosition(position());
  if (position_in_grid != last_grid_position) {
    direction = calculateNewGhostDirection(*this, target());
    last_grid_position = position_in_grid;
  }

  double position_delta = (0.004 * time_delta.count()) * speed();
  pos = calculateGhostMovement(*this, direction, position_delta);
}

double Inky::speed() const {
  if (state == GhostState::Eyes)
    return 2;
  if (state == GhostState::Frightened)
    return 0.5;
  return 0.75;
}

Position Inky::target() const {
    return ghostTargetPosition(*this, initialInkyPosition(), inkyScatterTarget());
}

} // namespace pacman
