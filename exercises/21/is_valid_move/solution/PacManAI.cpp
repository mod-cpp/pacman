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
