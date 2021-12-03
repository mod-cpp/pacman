bool Pellets::isPellet(GridPosition p) const {
  auto match = [&p](GridPosition pellet) {
    return p.x == pellet.x && p.y == pellet.y;
  };
  return std::any_of(positions.begin(), positions.end(), match);
}
