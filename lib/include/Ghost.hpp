#pragma once

#include <chrono>

#include "Atlas.hpp"
#include "Board.hpp"
#include "Position.hpp"

namespace pacman {

class GameState;

class Ghost {
public:
  enum class State {
    Chase,
    Scatter,
    Frightened,
    Eyes,
  };

  explicit Ghost(Atlas::Ghost spritesSet);
  virtual ~Ghost() = default;

  [[nodiscard]] GridPosition currentSprite() const;

  [[nodiscard]] Position position() const;

  [[nodiscard]] GridPosition positionInGrid() const;

  void update(std::chrono::milliseconds time_delta, const GameState & gameState);
  void frighten();
  void die();
  [[nodiscard]] bool isFrightened() const;
  [[nodiscard]] bool isEyes() const;
  void reset();

private:
  void updateAnimation(std::chrono::milliseconds time_delta);
  void updatePosition(std::chrono::milliseconds time_delta, const GameState & gameState);
  void updateDirection(const GameState & gameState);

protected:

  virtual double speed(const GameState & gameState) const = 0;
  virtual Position target(const GameState & gameState) const = 0;
  virtual Position initialPosition() const = 0;


  Atlas::Ghost spritesSet;
  Direction direction = Direction::NONE;
  double timeForAnimation = 0;
  int animationIndex = 0;
  State state = State::Chase;
  int timeFrighten = 0;
  int timeChase = 0;
  Position pos;
  GridPosition last_grid_position = { 0, 0 };
  [[nodiscard]] bool isInPen() const;
};

} // namespace pacman
