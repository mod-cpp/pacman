#include "Ghost.hpp"
#include <cmath>

Ghost::Ghost(Atlas::Ghost spritesSet, Position startingPosition, Position scatterTarget)
  : spritesSet(spritesSet),
    pos(startingPosition),
    startingPosition(startingPosition),
    scatterTarget(scatterTarget) {
}

[[nodiscard]] PositionInt Ghost::currentSprite() const {
  return Atlas::ghostSprite(spritesSet, direction, alternate_animation);
}

Position Ghost::position() const {
  return pos;
}

Position Ghost::positionInGrid() const {
    return { std::round(pos.x), std::round(pos.y) };
}

void Ghost::update(std::chrono::milliseconds time_delta, const Board & board) {
    updateAnimation(time_delta);
    updatePosition(time_delta, board);
}

void Ghost::updatePosition(std::chrono::milliseconds time_delta, const Board & board) {
    updateDirection(board);

    float position_delta = (0.004 * time_delta.count()) * 0.75;

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

void Ghost::updateDirection(const Board & board) {
    auto cell  = positionInGrid();
    if(cell == lastIntersection)
        return;

    struct NewDirection {
        Direction direction;
        Position position;
        double distance;
    };

    auto [x , y] = cell;
    std::array directions = {
        NewDirection{Direction::UP,    {x, y-1}, 0},
        NewDirection{Direction::LEFT,  {x-1, y}, 0},
        NewDirection{Direction::DOWN,  {x, y+1}, 0},
        NewDirection{Direction::RIGHT, {x+1, y}, 0}
    };
    const Position target = this->target(board);

    for(auto && d : directions) {
        d.distance = (d.direction != oppositeDirection(direction) && board.isWalkableForGost(d.position, cell)) ?
                   std::hypot(d.position.x - target.x, d.position.y - target.y)
                 : std::numeric_limits<double>::infinity();
    }

    auto it = std::min_element(directions.begin(), directions.end(), [](const auto & a, const auto &b) {
        return a.distance < b.distance;
    });

    lastIntersection = cell;
    direction = it->direction;
}

Position Ghost::target(const Board & board) const {
    if(board.isInPen(positionInGrid()))
        return board.penDoorPosition();

    return scatterTarget;
}

void Ghost::updateAnimation(std::chrono::milliseconds time_delta)
{
    time += time_delta.count();
    if (time >= 250) {
      time = 0;
      alternate_animation = !alternate_animation;
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
