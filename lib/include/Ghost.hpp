#pragma once

#include <chrono>

#include "Atlas.hpp"
#include "Board.hpp"
#include "Position.hpp"

namespace pacman {

enum class GhostState {
  Chase,
  Scatter,
  Frightened,
  Eyes,
};

/*
 *  Each time a ghost finds itself at an intersection,
 *  it picks a target position - the specific target depends on the state
 *  of the ghost and the specific ghost.
 *
 *  For each 4 cells around the current ghost position the straight-line distance
 *  to the target is calculated (this ignores all obstacles, including walls)
 *
 *  The ghost then selects among these 4 cells the one with the shortest euclidean distance to the target.
 *  If a cell is a wall or would cause a ghost to move in the opposite direction, the distance to the target
 *  from that cell is considered infinite (due to the shape of the maze, there is always one direction
 *  a ghost can take).
 *
 *  In the scatter state, each ghost tries to reach an unreachable position outside of the map.
 *  This makes ghosts run in circle around the island at each of the 4 map corner.
 */
template<typename Ghost>
[[nodiscard]] Direction calculateNewGhostDirection(const Ghost & ghost) {
  const auto current_grid_position = positionToGridPosition(ghost.position());

  struct Move {
    Direction direction;
    Position position;
    double distance = std::numeric_limits<double>::infinity();
  };

  const Position current_position = { double(current_grid_position.x), double(current_grid_position.y) };
  const auto [x, y] = current_position;
  std::array<Move, 4> possible_moves = { { Move{ Direction::UP, { x, y - 1 } },
                                           Move{ Direction::LEFT, { x - 1, y } },
                                           Move{ Direction::DOWN, { x, y + 1 } },
                                           Move{ Direction::RIGHT, { x + 1, y } } } };

  const Position target_position = ghost.target();

  for (auto & move : possible_moves) {
    const bool invalid_position = (move.position.x < 0 || move.position.y < 0);
    if (invalid_position)
      continue;

    const bool opposite_direction = (move.direction == oppositeDirection(ghost.currentDirection()));
    if (opposite_direction)
      continue;

    const GridPosition grid_position = { size_t(move.position.x), size_t(move.position.y) };
    const bool can_walk = pacman::isWalkableForGhost(grid_position, current_grid_position, ghost.isEyes());
    if (!can_walk)
      continue;

    move.distance = std::hypot(move.position.x - target_position.x, move.position.y - target_position.y);
  }

  const auto optimal_move = std::min_element(possible_moves.begin(), possible_moves.end(), [](const auto & a, const auto & b) {
    return a.distance < b.distance;
  });

  auto move = *optimal_move;
  return move.direction;
}

template<typename Ghost>
[[nodiscard]] Position calculateGhostMovement(const Ghost & ghost, Direction direction, double position_delta) {
  Position pos = ghost.position();
  switch (direction) {
    case Direction::NONE:
      break;
    case Direction::LEFT:
      pos.x -= position_delta;
      pos.y = round(pos.y);
      break;
    case Direction::RIGHT:
      pos.x += position_delta;
      pos.y = round(pos.y);
      break;
    case Direction::UP:
      pos.x = round(pos.x);
      pos.y -= position_delta;
      break;
    case Direction::DOWN:
      pos.x = round(pos.x);
      pos.y += position_delta;
      break;
  }
  return pos;
}

template<typename Ghost>
bool ghostIsInPen(const Ghost & ghost) {
  return isInPen(positionToGridPosition(ghost.position()));
}

class GhostAnimation {
public:
  GhostAnimation(Atlas::Ghost spriteSet);
  GridPosition currentSprite(GhostState state, Direction direction, int timeFrighten) const;
  void updateAnimation(std::chrono::milliseconds time_delta);

private:
  Atlas::Ghost spriteSet;
  double timeForAnimation = 0;
  int animationIndex = 0;
};

} // namespace pacman
