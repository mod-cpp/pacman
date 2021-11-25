[< Back](../README.md)

### 221. Exercise - Implement `PacManAI::pelletClosestToPacman`

Implement [PacManAI::pelletClosestToPacman](../../../lib/PacManAI.cpp) and test your implementation with the test
in [testPacmanAI.cpp](../../../test/testPacmanAI.cpp) called _"Find pellet closest to PacMan"_

The function should return the position of the pellet that is "closest" to PacMan. One implementation could be to sort
the vector of pellets by the distance they have to PacMan, and then return the first one.

```cpp
GridPosition PacManAI::pelletClosestToPacman(GridPosition pacmanGridPosition,
                                             std::vector<GridPosition> & pellets) {
  return {0, 0};
}
```

<details>
   <summary>Hint 1</summary>

Use the `positionDistance` function to find the distance to PacMan.

</details>
