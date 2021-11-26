Direction PacManAI::optimalDirection(const std::array<Move, 4> & moves) {
  double closestDistance = std::numeric_limits<double>::infinity();
  Direction dir = Direction::LEFT;

  for (const auto & move : moves) {
    if (move.distanceToTarget < closestDistance) {
      closestDistance = move.distanceToTarget;
      dir = move.direction;
    }
  }
  return dir;
}
