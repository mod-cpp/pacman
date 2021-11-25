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
