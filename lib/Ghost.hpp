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
    Frightened,
    Eyes,
  };

  explicit Ghost(Atlas::Ghost spritesSet, Position startingPosition, Position scatterTarget);

  [[nodiscard]] PositionInt currentSprite() const;

  [[nodiscard]] Position position() const;

  [[nodiscard]] Position positionInGrid() const;

  void update(std::chrono::milliseconds time_delta, const Board & board);
  void frighten();
  void eat();
  bool isFrightened() const;
  bool isEyes() const;
  void reset();

private:
  double speed() const;
  void updateAnimation(std::chrono::milliseconds time_delta);
  void updatePosition(std::chrono::milliseconds time_delta, const Board & board);
  void updateDirection(const Board & board);
  Position target(const Board & board) const;

protected:
  Atlas::Ghost spritesSet;
  Direction direction = Direction::NONE;
  double timeForAnimation = 0;
  int animationIndex = 0;
  State state = State::Chase;
  int timeFrighten = 0;
  int timeChase = 0;
  Position pos;
  Position startingPosition;
  Position scatterTarget;
  Position lastIntersection = { -1, -1 };
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
