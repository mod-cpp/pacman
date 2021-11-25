[< Back](../README.md)

## 220. Exercise - use reserve in `initialPelletPositions` (`Board.cpp`)

To avoid having to resize the vector too many times, we can preemptively reserve space for elements.
At a glance, we can estimate that there are pellets on a third of the grid.
This is not accurate, so we might either reserve too much or too little memory,
but this will still be faster than not calling reserve at all.
This will be very noticeable on both very large vectors (tens of thousands of elements),
Or small vectors in functions called very frequently.

```cpp
std::vector<GridPosition> initialPelletPositions() {
  std::vector<GridPosition> positions;

  for (std::size_t row = 0; row < ROWS; row++) {
    for (std::size_t column = 0; column < COLUMNS; column++) {
      if (board[row][column] == int(Cell::pellet))
        positions.emplace_back(column, row);
    }
  }
  return positions;
}
```
