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
