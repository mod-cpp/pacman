[< Back](../README.md)

### 241. Exercise - Use Lambdas and Algorithms for `PacManAI::pelletClosestToPacman`

Rewrite pelletClosestToPacman using lambdas and algorithms. One implementation could be to sort
the vector of pellets by the distance they have to PacMan, and then return the first one.

```cpp
GridPosition PacManAI::pelletClosestToPacman(GridPosition pacmanGridPosition,
                                             std::vector<GridPosition> & pellets) {
  return {0, 0};
}
```

<details>
   <summary>Hint 1</summary>

Use the [std::sort](https://en.cppreference.com/w/cpp/algorithm/sort) function to sort the vector.

</details>

<details>
   <summary>Hint 2</summary>

[std::sort](https://en.cppreference.com/w/cpp/algorithm/sort) third parameter should be a lambda taking 2 `GridPosition` as parameter,
and return true if the first parameter is closer from PacMan than the second.

</details>
