#pragma once

#include "Blinky.hpp"
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
  struct Move {
    Direction direction = Direction::NONE;
    GridPosition position;
    double distanceToTarget = std::numeric_limits<double>::infinity();
  };

  void update(const PacMan & pacMan, const Pellets & pellets);
  Direction suggestedDirection() const;
  GridPosition pelletClosestToPacman(GridPosition pacmanGridPosition,
                                     std::vector<GridPosition> & pellets);
  bool isValidMove(const Move & move);
  Direction optimalDirection(const std::array<Move, 4> & moves);
  void reset();

private:
  Position pos = initialPacManPosition();
  Direction direction = Direction::RIGHT;
};

} // namespace pacman
