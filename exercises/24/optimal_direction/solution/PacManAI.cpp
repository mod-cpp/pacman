Direction PacManAI::optimalDirection(const std::array<Move, 4> & moves) {
  const auto optimalMove = std::min_element(moves.begin(), moves.end(), [](const auto & a, const auto & b) {
    return a.distanceToTarget < b.distanceToTarget;
  });

  return optimalMove->direction;
}
