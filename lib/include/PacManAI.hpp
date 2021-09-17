#pragma once

#include "Blinky.hpp"
#include "Clyde.hpp"
#include "Direction.hpp"
#include "Inky.hpp"
#include "PacMan.hpp"
#include "Pellets.hpp"
#include "Pinky.hpp"
#include "Position.hpp"
#include "SuperPellets.hpp"

namespace pacman {

class PacManAI {
public:
  void update(const PacMan pacMan, const Pellets & pellets, const SuperPellets & superPellets, const Blinky & blinky, const Clyde & clyde, const Inky & inky, const Pinky & pinky);
  Direction suggestedDirection() const;

private:
  Position pos;
  Direction direction = Direction::RIGHT;
};

} // namespace pacman
