GridPosition PacManAI::pelletClosestToPacman(GridPosition pacmanGridPosition,
                                             std::vector<GridPosition> & pellets) {
  GridPosition closestPellet = { 0, 0 };
  double closestDistance = std::numeric_limits<double>::infinity();

  for (const auto & pellet : pellets) {
    const double distance = positionDistance(pacmanGridPosition, pellet);
    if (distance < closestDistance) {
      closestDistance = distance;
      closestPellet = pellet;
    }
  }

  return closestPellet;
}

