#pragma once

#include "Blinky.hpp"
#include "Clyde.hpp"
#include "Ghost.hpp"
#include "Inky.hpp"
#include "PacMan.hpp"
#include "Pellets.hpp"
#include "Pinky.hpp"
#include "Score.hpp"
#include "SuperPellets.hpp"
#include "InputState.hpp"

namespace pacman {

struct GameState {
  void step(std::chrono::milliseconds delta);

  Blinky blinky;
  Pinky pinky;
  Inky inky;
  Clyde clyde;

  PacMan pacMan;
  InputState inputState;
  Pellets pellets;
  SuperPellets superPellets;

  Score score;
  std::chrono::milliseconds timeSinceDeath{};

  void checkCollision(Ghost & ghost);
  void handleDeathAnimation(std::chrono::milliseconds delta);
  void eatPellets();
  void killPacMan();
  bool isPacManDying() const;
};

} // namespace pacman
