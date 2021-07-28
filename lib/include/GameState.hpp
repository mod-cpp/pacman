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
