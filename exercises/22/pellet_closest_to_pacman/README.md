[< Back](../README.md)

### 221. Exercise - `PacManAI::pelletClosestToPacman`

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
<details>
   <summary>Hint 2</summary>

Use the [std::sort](https://en.cppreference.com/w/cpp/algorithm/sort) function to sort the vector.

</details>

</details>
<details>
   <summary>Hint 3</summary>

[std::sort](https://en.cppreference.com/w/cpp/algorithm/sort) third parameter should be a lambda taking 2 `GridPosition` as parameter,
and return true if the first parameter is closer from PacMan than the second.

</details>
