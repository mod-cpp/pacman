#include "PacManAI.hpp"

#include "Board.hpp"
#include <fmt/format.h>

namespace pacman {

void PacManAI::reset() {
  pos = {};
  direction = Direction::RIGHT;
}

Direction PacManAI::suggestedDirection() const {
  return direction;
}

GridPosition PacManAI::pelletClosestToPacman(GridPosition pacmanGridPosition,
                                             std::vector<GridPosition> & pellets) {

  auto pelletSort = [&pacmanGridPosition](GridPosition pelletA, GridPosition pelletB) {
    double distanceA = positionDistance(pacmanGridPosition, pelletA);
    double distanceB = positionDistance(pacmanGridPosition, pelletB);
    return distanceA < distanceB;
  };
  std::sort(pellets.begin(), pellets.end(), pelletSort);
  return pellets[0];
}

bool PacManAI::isValidMove(const Move & move) {
  const bool isOpposite = (move.direction == oppositeDirection(direction));
  if (isOpposite) {
    return false;
  }

  const bool canWalk = isWalkableForPacMan(move.position);
  if (!canWalk) {
    return false;
  }
  return true;
}

Direction PacManAI::optimalDirection(const std::array<Move, 4> & moves) {
  const auto optimalMove = std::min_element(moves.begin(), moves.end(), [](const auto & a, const auto & b) {
    return a.distanceToTarget < b.distanceToTarget;
  });

  const auto & move = *optimalMove;
  return move.direction;
}

void PacManAI::update(const PacMan & pacMan, const Pellets & pellets) {
  const GridPosition pacManGridPos = pacMan.positionInGrid();
  const GridPosition currentGridPos = positionToGridPosition(pos);

  if (!isIntersection(pacManGridPos) || currentGridPos == pacManGridPos) {
    return;
  }

  auto pelletPositions = pellets.allPellets();
  if (pelletPositions.empty()) {
    return;
  }

  const GridPosition targetPos = pelletClosestToPacman(pacManGridPos, pelletPositions);

  const GridPosition currentPosition = pacMan.positionInGrid();
  const auto [x, y] = currentPosition;
  std::array<Move, 4> possibleMoves = {
    Move{ Direction::UP, { x, y - 1 } },
    Move{ Direction::LEFT, { x - 1, y } },
    Move{ Direction::DOWN, { x, y + 1 } },
    Move{ Direction::RIGHT, { x + 1, y } }
  };

  for (auto & move : possibleMoves) {
    if (!isValidMove(move))
      continue;
    move.distanceToTarget = positionDistance(move.position, targetPos);
  }
  direction = optimalDirection(possibleMoves);
}
} // namespace pacman
