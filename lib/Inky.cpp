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
  timeChase = {};
}

[[nodiscard]] GridPosition Inky::currentSprite() const {
  return animation.currentSprite(state, direction, timeFrighten);
}

Position Inky::position() const {
  return pos;
}

void Inky::update(std::chrono::milliseconds time_delta, GridPosition pacman_position,
                  Direction pacman_direction, GridPosition blinky_position) {
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
  updatePosition(time_delta, pacman_position, pacman_direction, blinky_position);
}

void Inky::updatePosition(std::chrono::milliseconds time_delta, GridPosition pacman_position,
                          Direction pacman_direction, GridPosition blinky_position) {
  const auto position_in_grid = positionToGridPosition(position());
  if (position_in_grid != last_grid_position) {
    direction = calculateNewGhostDirection(*this, target(pacman_position, pacman_direction, blinky_position));
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

Position Inky::target(GridPosition pacman_position, Direction pacman_direction, GridPosition blinky_position) const {

    // Inky first selects a position 2 cell away from pacman in his direction.
    GridPosition targetPosition = pacman_position;
    switch(pacman_direction) {
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
           assert("Pacman should be moving!");
        break;
    }
    // Then it calculates the distance between Blinky and this position
    auto distanceBetweenBlinkyAndTarget
            = std::hypot(blinky_position.x - targetPosition.x, blinky_position.y - targetPosition.y);

    // And selects a point on the line crossing blinky and this position that is at twice that distance
    // away from blinky
    targetPosition.x += ((targetPosition.x - blinky_position.x) / distanceBetweenBlinkyAndTarget) * 2;
    targetPosition.y += ((targetPosition.y - blinky_position.y) / distanceBetweenBlinkyAndTarget) * 2;


    return ghostTargetPosition(*this, initialInkyPosition(), state == GhostState::Chase ?
                                   gridPositionToPosition(targetPosition) : inkyScatterTarget());
}

} // namespace pacman
