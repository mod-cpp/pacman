[< Back](../README.md)

## Background: PacMan Moves

At each intersection, check if there is a ghost directly inline with that path. If the path is free of ghosts, you are
allowed to turn there. And if PacMan is moving in a direction, and a ghost enters his path, then PacMan will reverse.

For example if PacMan is at an intersection and can go either right or up, and there is a ghost in the path going right,
then PacMan will go up. Then while PacMan is going up, a ghost enters that path, PacMan will go back.

You only need to worry about the grid itself and any ghosts on the North/South/East/West axis of PacMan.

### 210. Exercise - Implement `PacManAI::isValidMove`

As a warmup exercise, implement [PacManAI::isValidMove](../../../lib/PacManAI.cpp) and test your implementation with the test
in [testPacmanAI.cpp](../../../test/testPacmanAI.cpp) called _"Is valid move"_

Note: `isValidMove` will be called 4 times in a loop. If the target cell is not walkable the distance is set to infinity.

Note: Going backwards is not allowed, otherwise you'll go back and forwards between 2 pellets while playing the game.

Note: The test is disabled, to enable the test remove the [!shouldfail] from the tags on the test

```cpp
bool PacManAI::isValidMove(const Move & move) {
  return false;
}
```

<details>
   <summary>Hint 1</summary>

Use [isWalkableForPacMan](../../../lib/Board.cpp) to make sure PacMan is not walking in ways that are not legal

</details>

<details>
   <summary>Hint 2</summary>

Use [oppositeDirection](../../../lib/include/Direction.hpp) to make sure PacMan doesn't get stuck toggeling back and forth

</details>
