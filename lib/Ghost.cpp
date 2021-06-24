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
