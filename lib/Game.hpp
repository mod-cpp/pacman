#pragma once

#include "Board.hpp"
#include "Canvas.hpp"
#include "PacMan.hpp"
#include "Pellets.hpp"
#include "SuperPellets.hpp"

class InputState;

class Game {
public:
  Game();

  void run();

private:
  Canvas canvas;
  Board board;
  PacMan pacMan;
  Pellets pellets;
  SuperPellets superPellets;

  void eatPellets();

  void processEvents(InputState & inputState);

  [[nodiscard]] static auto now();
};
