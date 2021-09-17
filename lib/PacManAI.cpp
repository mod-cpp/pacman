#include "PacManAI.hpp"

#include "Board.hpp"
#include <fmt/format.h>

namespace pacman {
Direction PacManAI::suggestedDirection() const {
  return direction;
}

void PacManAI::update(const PacMan pacMan, const Pellets & pellets, const SuperPellets & superPellets, const Blinky & blinky, const Clyde & clyde, const Inky & inky, const Pinky & pinky) {
  const GridPosition pacManGridPos = pacMan.positionInGrid();
  const GridPosition currentGridPos = positionToGridPosition(pos);
  if (currentGridPos == pacManGridPos) {
    return;
  }

  pos = gridPositionToPosition(pacManGridPos);

  if (!isIntersection(pacManGridPos)) {
    return;
  }

  struct GridMove {
    Direction direction = Direction::NONE;
    GridPosition position;
    bool hasGhost = false;
    size_t pelletCount = 0;
  };

  std::array<GridMove, 4> possibleMoves = {
    GridMove{ Direction::UP, { pacManGridPos.x, pacManGridPos.y - 1 } },
    GridMove{ Direction::LEFT, { pacManGridPos.x - 1, pacManGridPos.y } },
    GridMove{ Direction::DOWN, { pacManGridPos.x, pacManGridPos.y + 1 } },
    GridMove{ Direction::RIGHT, { pacManGridPos.x + 1, pacManGridPos.y } }
  };

  auto isGhostDangerous = [](const auto ghost, GridPosition pos) {
    return !ghost.isFrightened() && ghost.positionInGrid() == pos;
  };

  for (auto & move : possibleMoves) {
    if (!isWalkableForPacMan(move.position)) {
      move.direction = Direction::NONE;
      continue;
    }

    GridPosition posTest = move.position;
    while (isWalkableForPacMan(posTest)) {
      if (pellets.isPellet(posTest) || superPellets.isPellet(posTest)) {
        move.pelletCount++;
      }

      if (isGhostDangerous(blinky, posTest) || isGhostDangerous(clyde, posTest) || isGhostDangerous(inky, posTest) || isGhostDangerous(pinky, posTest)) {
        move.hasGhost = true;
      }

      const GridPosition oldPosTest = posTest;
      posTest = iterateGridPosition(posTest, move.direction);
      if (posTest == oldPosTest) {
        break;
      }
    }
  }

  auto sortCondition = [&pacMan](const GridMove & moveA, const GridMove & moveB) {
    if (moveA.pelletCount == moveB.pelletCount) {
      return (moveA.direction == pacMan.currentDirection() ? true : false);
    }
    return moveA.pelletCount > moveB.pelletCount;
  };

  std::sort(possibleMoves.begin(), possibleMoves.end(), sortCondition);

  for (const auto & move : possibleMoves) {
    fmt::print("{}, {}, {}\n", move.pelletCount, move.hasGhost, move.direction);
  }
  fmt::print("\n");

  for (const auto & move : possibleMoves) {
    if (move.direction != Direction::NONE && !move.hasGhost) {
      direction = move.direction;
      break;
    }
  }

  // Then out of all of the movable directions, pick one and exit the loop
  /* for (const auto & move : possibleMoves) {
    if (move.direction == Direction::NONE || move.hasGhost) {
      continue;
    }
    if (pellets.isPellet(move.position) || superPellets.isPellet(move.position)) {
      direction = move.direction;
      break;
    }
  }*/
}
} // namespace pacman