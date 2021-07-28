#pragma once

#include <SFML/Graphics.hpp>

#include "Direction.hpp"
#include "Position.hpp"
#include <array>
#include <cstdint>
#include <vector>

namespace pacman {

  [[nodiscard]] bool isWalkableForPacMan(GridPosition point);
  [[nodiscard]] bool isWalkableForGhost(GridPosition point, GridPosition origin, bool isEyes);
  [[nodiscard]] bool isInPen(GridPosition point);
  [[nodiscard]] bool isPortal(GridPosition point, Direction direction);
  [[nodiscard]] GridPosition teleport(GridPosition point);

  [[nodiscard]] std::vector<GridPosition> initialPelletPositions();

  [[nodiscard]] std::vector<GridPosition> initialSuperPelletPositions();

  inline Position penDoorPosition() { return { 13, 11 }; }
  inline Position initialPacManPosition() { return { 13.5, 23 }; }

  } // namespace pacman
