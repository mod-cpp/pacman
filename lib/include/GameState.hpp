#pragma once

#include "Ghost.hpp"
#include "PacMan.hpp"
#include "Pellets.hpp"
#include "Score.hpp"
#include "SuperPellets.hpp"

namespace pacman {

struct GameState {
  std::tuple<Blinky, Speedy, Inky, Clyde> ghosts;
  PacMan pacMan;
  Pellets pellets;
  SuperPellets superPellets;
};

} // namespace pacman
