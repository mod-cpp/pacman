#include "Ghost.hpp"
#include <array>
#include <cmath>

namespace pacman {

Ghost::Ghost(Atlas::Ghost spritesSet, Position startingPosition, Position scatterTarget)
  : spritesSet(spritesSet),
    pos(startingPosition),
    startingPosition(startingPosition),
    scatterTarget(scatterTarget) {
}

void Ghost::frighten() {
  if (state > State::Scatter)
    return;
  direction = oppositeDirection(direction);
  state = State::Frightened;
  timeFrighten = 0;
}

bool Ghost::isFrightened() const {
  return state == State::Frightened;
}

bool Ghost::isEyes() const {
  return state == State::Eyes;
}

void Ghost::eat() {
  if (state == State::Eyes)
    return;
  direction = oppositeDirection(direction);
  state = State::Eyes;
  timeFrighten = 0;
  timeChase = 0;
}

void Ghost::reset() {
  pos = startingPosition;
}

[[nodiscard]] GridPosition Ghost::currentSprite() const {
  switch (state) {
    default:
      return Atlas::ghostSprite(spritesSet, direction, (animationIndex % 2) == 0);
    case State::Eyes:
      return Atlas::eyeSprite(direction);
    case State::Frightened:
      if (timeFrighten < 3500)
        return Atlas::initialFrightened(animationIndex);
      else
        return Atlas::endingFrightened(animationIndex);
  }
}

Position Ghost::position() const {
  return pos;
}

GridPosition Ghost::positionInGrid() const {
  return positionToGridPosition(pos);
}

void Ghost::update(std::chrono::milliseconds time_delta, const Board & board) {
  if (state == State::Eyes && isInPen(board))
    state = State::Scatter;

  if (state == State::Frightened) {
    timeFrighten += time_delta.count();
    if (timeFrighten > 6000)
      state = State::Scatter;
  }

  updateAnimation(time_delta);
  updatePosition(time_delta, board);
}

bool Ghost::isInPen(const Board & board) const {
  return board.isInPen(positionInGrid());
}

void Ghost::updatePosition(std::chrono::milliseconds time_delta, const Board & board) {
  updateDirection(board);

  double position_delta = (0.004 * time_delta.count()) * speed();

  switch (direction) {
    case Direction::NONE:
      break;
    case Direction::LEFT:
      pos.x -= position_delta;
      pos.y = round(pos.y);
      break;
    case Direction::RIGHT:
      pos.x += position_delta;
      pos.y = round(pos.y);
      break;
    case Direction::UP:
      pos.x = round(pos.x);
      pos.y -= position_delta;
      break;
    case Direction::DOWN:
      pos.x = round(pos.x);
      pos.y += position_delta;
      break;
  }
}

double Ghost::speed() const {
  if (state == State::Eyes)
    return 2;
  if (state == State::Frightened)
    return 0.5;
  return 0.75;
}

void Ghost::updateDirection(const Board & board) {
  const auto current_grid_position = positionInGrid();
  if (current_grid_position == last_grid_position)
    return;

  struct Move {
    Direction direction;
    Position position;
    double distance = std::numeric_limits<double>::infinity();
  };

  const Position current_position = { double(current_grid_position.x), double(current_grid_position.y) };
  const auto [x, y] = current_position;
  std::array<Move, 4> possible_moves = { { Move{ Direction::UP, { x, y - 1 } },
                                           Move{ Direction::LEFT, { x - 1, y } },
                                           Move{ Direction::DOWN, { x, y + 1 } },
                                           Move{ Direction::RIGHT, { x + 1, y } } } };

  const Position target_position = target(board);

  for (auto & move : possible_moves) {
    const bool invalid_position = (move.position.x < 0 || move.position.y < 0);
    if (invalid_position)
      continue;

    const bool opposite_direction = (move.direction == oppositeDirection(direction));
    if (opposite_direction)
      continue;

    const GridPosition grid_position = {size_t(move.position.x), size_t(move.position.y)};
    const bool can_walk = board.isWalkableForGost(grid_position, current_grid_position, isEyes());
    if (!can_walk)
      continue;

    move.distance = std::hypot(move.position.x - target_position.x, move.position.y - target_position.y);
  }

  const auto optimal_move = std::min_element(possible_moves.begin(), possible_moves.end(), [](const auto & a, const auto & b) {
    return a.distance < b.distance;
  });

  auto move = *optimal_move;
  direction = move.direction;
  last_grid_position = current_grid_position;
}

Position Ghost::target(const Board & board) const {
  if (state == State::Eyes)
    return startingPosition;

  if (board.isInPen(positionInGrid()))
    return board.penDoorPosition();

  return scatterTarget;
}

void Ghost::updateAnimation(std::chrono::milliseconds time_delta) {
  timeForAnimation += time_delta.count();
  if (timeForAnimation >= 250) {
    timeForAnimation = 0;
    animationIndex = (animationIndex + 1) % 4;
  }
}

Blinky::Blinky(const Board & board)
  : Ghost(Atlas::Ghost::blinky, board.initialBlinkyPosition(), board.blinkyScatterTarget()) {
}

Speedy::Speedy(const Board & board)
  : Ghost(Atlas::Ghost::speedy, board.initialSpeedyPosition(), board.speedyScatterTarget()) {
}

Inky::Inky(const Board & board)
  : Ghost(Atlas::Ghost::inky, board.initialInkyPosition(), board.inkyScatterTarget()) {
}

Clyde::Clyde(const Board & board)
  : Ghost(Atlas::Ghost::clyde, board.initialClydePosition(), board.clydeScatterTarget()) {
}

} // namespace pacman
