[< Back](../README.md)

### 210. Exercise - isValidMove

As a warmup exercise, implement [PacManAI::isValidMove](../../../lib/PacManAI.cpp) and test your implementation with the test
in [testPacmanAI.cpp](../../../test/testPacmanAI.cpp) called _"Is valid move"_

Note: The test is disabled, to enable the test remove the [.] from the tags on the test

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
