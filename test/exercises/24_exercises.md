[< Back](README.md)

# 24. Lambdas and Function Templates

* [Exercise 240](#exercise-240)
* [Exercise 241](#exercise-241)
* [Exercise 242](#exercise-242)

## Exercise 240
### Use Algorithms for `PacManAI::optimalDirection`

Rewrite optimalDirection to use algorithms.

```cpp
Direction PacManAI::optimalDirection(const std::array<Move, 4> & moves) {
  return Direction::NONE;
}
```

<details>
   <summary>Hint 1</summary>

You can use [std::min_element](https://en.cppreference.com/w/cpp/algorithm/min_element) to find the closest pellet

</details>

<details>
   <summary>Solution</summary>

```cpp
Direction PacManAI::optimalDirection(const std::array<Move, 4> & moves) {
  const auto optimalMove = std::min_element(moves.begin(), moves.end(), [](const auto & a, const auto & b) {
    return a.distanceToTarget < b.distanceToTarget;
  });

  return optimalMove->direction;
}
```
</details>

## Exercise 241
### Use Lambdas and Algorithms for `PacManAI::pelletClosestToPacman`

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

<details>
   <summary>Solution</summary>

```cpp
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
```
</details>

## [Exercise 242][1]
### Description

<details>
   <summary>Solution</summary>

```cpp

```
</details>

[1]: 24_exercises.cpp