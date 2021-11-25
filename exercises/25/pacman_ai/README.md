[< Back](../README.md)

# Exercise: PacMan AI

Let's implement a naive AI for PacMan.

## Background: PacMan Moves

At each intersection, check if there is a ghost directly inline with that path. If the path is free of ghosts, you are
allowed to turn there. And if PacMan is moving in a direction, and a ghost enters his path, then PacMan will reverse.

For example if PacMan is at an intersection and can go either right or up, and there is a ghost in the path going right,
then PacMan will go up. Then while PacMan is going up, a ghost enters that path, PacMan will go back.

You only need to worry about the grid itself and any ghosts on the North/South/East/West axis of PacMan.

## Exercise

### 221. Exercise - pelletClosestToPacman

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

### 240. Exercise - Algorithm for optimalDirection

Rewrite optimalDirection to use algorithms.

### 241. Exercise - Use Lambdas and Algorithms for pelletClosestToPacman

Rewrite pelletClosestToPacman using lambdas and algorithms

## Advanced

For people who want to create a fancier AI, if you want to introduce some randomness, you can look at this SFML function https://www.sfml-dev.org/tutorials/1.6/system-random.php - you will need to include #include <SFML/Randomizer.hpp>
