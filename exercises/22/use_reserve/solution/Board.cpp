std::vector<GridPosition> initialPelletPositions() {
  std::vector<GridPosition> positions;

  positions.reserve((ROWS * COLUMNS) / 3);

  for (std::size_t row = 0; row < ROWS; row++) {
    for (std::size_t column = 0; column < COLUMNS; column++) {
      if (board[row][column] == int(Cell::pellet))
        positions.emplace_back(column, row);
    }
  }
  return positions;
}
