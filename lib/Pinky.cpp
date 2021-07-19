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
  timeFrighten = {};
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
  timeFrighten = {};
}

void Pinky::reset() {
  pos = initialPinkyPosition();
  timeChase = {};
}

[[nodiscard]] GridPosition Pinky::currentSprite() const {
  return animation.currentSprite(state, direction, timeFrighten);
}

Position Pinky::position() const {
  return pos;
}

void Pinky::update(std::chrono::milliseconds time_delta, GridPosition pacman_position, Direction pacman_direction) {
  if (state == GhostState::Eyes && ghostIsInPen(*this))
    state = GhostState::Scatter;

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
  updatePosition(time_delta, pacman_position, pacman_direction);
}

void Pinky::updatePosition(std::chrono::milliseconds time_delta, GridPosition pacman_position, Direction pacman_direction) {
  const auto position_in_grid = positionToGridPosition(position());
  if (position_in_grid != last_grid_position) {
    direction = calculateNewGhostDirection(*this, target(pacman_position, pacman_direction));
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

/*
 * Pinky targets a position 4 cells away from pacman in the direction of pacman.
 * When pacman goes up, pinky choses a target 4 cells above and 4 cells to the left
 * of pacman
 */
Position Pinky::target(GridPosition pacman_position, Direction pacman_direction) const {
    switch(pacman_direction) {
        case Direction::LEFT:
             pacman_position.x -= 4;
             break;
        case Direction::RIGHT:
             pacman_position.x += 4;
             break;
        case Direction::UP:
             pacman_position.y -= 4;
             pacman_position.x -= 4;
             break;
        case Direction::DOWN:
             pacman_position.y += 4;
             break;
        case Direction::NONE:
           assert("Pacman should be moving!");
        break;
    }

    return ghostTargetPosition(*this, initialPinkyPosition(), state == GhostState::Chase ?
                                   gridPositionToPosition(pacman_position) : pinkyScatterTarget());
}

} // namespace pacman
