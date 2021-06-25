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

    using P = std::tuple<Direction, Position, double>;

    auto [x , y] = cell;
    std::array<P, 4> positions = {{
        P{Direction::UP,    {x, y-1}, 0},
        P{Direction::LEFT,  {x-1, y}, 0},
        P{Direction::DOWN,  {x, y+1}, 0},
        P{Direction::RIGHT, {x+1, y}, 0}
    }};
    const Position target = this->target(board);

    std::for_each(positions.begin(), positions.end(), [&](P & p) {
        get<2>(p) = (get<0>(p) != oppositeDirection(direction) && board.isWalkableForGost(get<1>(p), cell)) ?
                   std::hypot(get<1>(p).x - target.x, get<1>(p).y - target.y)
                 : std::numeric_limits<double>::infinity();
    });

    auto it = std::min_element(positions.begin(), positions.end(), [](const auto & a, const auto &b)
    {
        return get<2>(a) < get<2>(b);
    });

    lastIntersection = cell;
    direction = std::get<0>(*it);
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
