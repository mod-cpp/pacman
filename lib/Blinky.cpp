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
  timeFrighten = {};
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
  timeFrighten = {};
}

void Blinky::reset() {
  pos = initialBlinkyPosition();
  timeChase = {};
}

[[nodiscard]] GridPosition Blinky::currentSprite() const {
  return animation.currentSprite(state, direction, timeFrighten);
}

Position Blinky::position() const {
  return pos;
}

void Blinky::update(std::chrono::milliseconds time_delta, GridPosition pacman_position) {
  if (state == GhostState::Eyes && ghostIsInPen(*this))
    state = defaultStateAtDuration(std::chrono::duration_cast<std::chrono::seconds>(timeChase));

  if (state == GhostState::Frightened) {
    timeFrighten += time_delta;
    if (timeFrighten.count() > 6000)
      state = GhostState::Scatter;
  }

  if(state == GhostState::Scatter || state == GhostState::Chase) {
      timeChase += time_delta;
      auto newState = defaultStateAtDuration(std::chrono::duration_cast<std::chrono::seconds>(timeChase));
      if(newState != state) {
          direction = oppositeDirection(direction);
          state = newState;
      }
  }

  animation.updateAnimation(time_delta);
  updatePosition(time_delta, pacman_position);
}

void Blinky::updatePosition(std::chrono::milliseconds time_delta, GridPosition pacman_position) {
  const auto position_in_grid = positionToGridPosition(position());
  if (position_in_grid != last_grid_position) {
    direction = calculateNewGhostDirection(*this, target(pacman_position));
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

Position Blinky::target(GridPosition pacman_position) const {
  return ghostTargetPosition(*this, initialBlinkyPosition(),
                             state == GhostState::Chase ?
                                 gridPositionToPosition(pacman_position) : blinkyScatterTarget());
}

} // namespace pacman
