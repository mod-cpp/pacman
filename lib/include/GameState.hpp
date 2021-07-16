#pragma once

#include "Ghost.hpp"
#include "PacMan.hpp"
#include "Pellets.hpp"
#include "Score.hpp"
#include "SuperPellets.hpp"

namespace pacman {

struct GameState {
  Blinky blinky;
  Pinky pinky;
  Inky inky;
  Clyde clyde;
  PacMan pacMan;
  Pellets pellets;
  SuperPellets superPellets;
};

} // namespace pacman
