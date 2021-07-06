#pragma once

#include "Board.hpp"
#include "Canvas.hpp"
#include "Ghost.hpp"
#include "PacMan.hpp"
#include "Pellets.hpp"
#include "Score.hpp"
#include "SuperPellets.hpp"

namespace pacman {

class InputState;

class Game {
public:
  Game();
  void run();

private:
  friend class Canvas;

  Canvas canvas;
  Board board;
  PacMan pacMan;
  Pellets pellets;
  SuperPellets superPellets;
  std::tuple<Blinky, Speedy, Inky, Clyde> ghosts;
  Score score;
  std::chrono::milliseconds timeSinceDeath{};

  void step(std::chrono::milliseconds delta, InputState inputState);
  void eatPellets();
  void processEvents(InputState & inputState);
  void checkCollision(Ghost & g);

  [[nodiscard]] static auto now();
};

} // namespace pacman