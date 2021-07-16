#pragma once

#include <chrono>

#include "Atlas.hpp"
#include "Board.hpp"
#include "Position.hpp"

namespace pacman {

class Ghost {
public:
  enum class State {
    Chase,
    Scatter,
    Frightened,
    Eyes,
  };

  explicit Ghost(Atlas::Ghost spritesSet, Position startingPosition, Position scatterTarget);

  [[nodiscard]] GridPosition currentSprite() const;

  [[nodiscard]] Position position() const;

  [[nodiscard]] GridPosition positionInGrid() const;

  void update(std::chrono::milliseconds time_delta);
  void frighten();
  void die();
  [[nodiscard]] bool isFrightened() const;
  [[nodiscard]] bool isEyes() const;
  void reset();

private:
  [[nodiscard]] double speed() const;
  void updateAnimation(std::chrono::milliseconds time_delta);
  void updatePosition(std::chrono::milliseconds time_delta);
  void updateDirection();
  [[nodiscard]] Position target() const;

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
  GridPosition last_grid_position = { 0, 0 };
  [[nodiscard]] bool isInPen() const;
};

class Blinky : public Ghost {
public:
  explicit Blinky();
};

class Pinky : public Ghost {
public:
  explicit Pinky();
};

class Inky : public Ghost {
public:
  explicit Inky();
};

class Clyde : public Ghost {
public:
  explicit Clyde();
};

} // namespace pacman
