#include "PacManAI.hpp"

#include "Board.hpp"
#include <fmt/format.h>

namespace pacman {
Direction PacManAI::suggestedDirection() const {
  return direction;
}

void PacManAI::update(const PacMan & pacMan, const Pellets & pellets) {
  const GridPosition pacManGridPos = pacMan.positionInGrid();
  const GridPosition currentGridPos = positionToGridPosition(pos);
  if (currentGridPos == pacManGridPos) {
    return;
  }

  pos = gridPositionToPosition(pacManGridPos);

  if (!isIntersection(pacManGridPos)) {
    return;
  }

  auto pelletPositions = pellets.currentPositions();
  if (pelletPositions.empty()) {
    return;
  }
  auto pelletSort = [&pacManGridPos](GridPosition pelletA, GridPosition pelletB) {
    double distanceA = positionDistance(pacManGridPos, pelletA);
    double distanceB = positionDistance(pacManGridPos, pelletB);
    return distanceA < distanceB;
  };
  std::sort(pelletPositions.begin(), pelletPositions.end(), pelletSort);

  const auto & target = pelletPositions[0];
  const Position targetPos{ double(target.x), double(target.y) };

  struct Move {
    Direction direction = Direction::NONE;
    Position position;
    double distanceToTarget = std::numeric_limits<double>::infinity();
  };

  const Position currentPosition = { double(pacManGridPos.x), double(pacManGridPos.y) };
  const auto [x, y] = currentPosition;
  std::array<Move, 4> possibleMoves = {
    Move{ Direction::UP, { x, y - 1 } },
    Move{ Direction::LEFT, { x - 1, y } },
    Move{ Direction::DOWN, { x, y + 1 } },
    Move{ Direction::RIGHT, { x + 1, y } }
  };

  for (auto & move : possibleMoves) {
    const bool invalidPosition = (move.position.x < 0 || move.position.y < 0);
    if (invalidPosition) {
      continue;
    }

    const bool isOpposite = (move.direction == oppositeDirection(direction));
    if (isOpposite) {
      continue;
    }

    const GridPosition gridMove = { size_t(move.position.x), size_t(move.position.y) };
    const bool canWalk = isWalkableForPacMan(gridMove);
    if (!canWalk) {
      continue;
    }

    move.distanceToTarget = positionDistance(move.position, targetPos);
  }

  const auto optimalMove = std::min_element(possibleMoves.begin(), possibleMoves.end(), [](const auto & a, const auto & b) {
    return a.distanceToTarget < b.distanceToTarget;
  });

  const auto & move = *optimalMove;
  direction = move.direction;
}
} // namespace pacman