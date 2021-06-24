#pragma once

#include <chrono>

#include "Atlas.hpp"
#include "Board.hpp"
#include "Position.hpp"

class Ghost {
public:
  enum class State {
    Chase,
    Scatter,
    Freightened,
    Eyes,
  };

  explicit Ghost(Atlas::Ghost spritesSet, Position startingPosition, Position scatterTarget);

  [[nodiscard]] PositionInt currentSprite() const;

  [[nodiscard]] Position position() const;

  [[nodiscard]] Position positionInGrid() const;

  void update(std::chrono::milliseconds time_delta, const Board & board);

protected:
  Atlas::Ghost spritesSet;
  Direction direction = Direction::NONE;
  double time = 0;
  bool alternate_animation = false;
  State state = State::Chase;
  Position pos;
  Position startingPosition;
  Position scatterTarget;
};

class Blinky : public Ghost {
public:
  explicit Blinky(const Board & board);
};

class Speedy : public Ghost {
public:
  explicit Speedy(const Board & board);
};

class Inky : public Ghost {
public:
  explicit Inky(const Board & board);
};

class Clyde : public Ghost {
public:
  explicit Clyde(const Board & board);
};
