#include "Ghost.hpp"
#include <array>
#include <cmath>

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

Position Ghost::positionInGrid() const {
  return { std::round(pos.x), std::round(pos.y) };
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
  auto cell = positionInGrid();
  if (cell == lastIntersection)
    return;

  struct NewDirection {
    Direction direction;
    Position position;
    double distance;
  };

  auto [x, y] = cell;
  std::array<NewDirection, 4> directions = { { NewDirection{ Direction::UP, { x, y - 1 }, 0 },
                                               NewDirection{ Direction::LEFT, { x - 1, y }, 0 },
                                               NewDirection{ Direction::DOWN, { x, y + 1 }, 0 },
                                               NewDirection{ Direction::RIGHT, { x + 1, y }, 0 } } };
  const Position target = this->target(board);

  for (auto && d : directions) {
    d.distance = (d.direction != oppositeDirection(direction) && board.isWalkableForGost(d.position, cell, state == State::Eyes)) ? std::hypot(d.position.x - target.x, d.position.y - target.y)
                                                                                                                                  : std::numeric_limits<double>::infinity();
  }

  auto it = std::min_element(directions.begin(), directions.end(), [](const auto & a, const auto & b) {
    return a.distance < b.distance;
  });

  lastIntersection = cell;
  direction = it->direction;
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
