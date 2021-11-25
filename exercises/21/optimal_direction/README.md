[< Back](../README.md)

## Background: PacMan Moves

At each intersection, check if there is a ghost directly inline with that path. If the path is free of ghosts, you are
allowed to turn there. And if PacMan is moving in a direction, and a ghost enters his path, then PacMan will reverse.

For example if PacMan is at an intersection and can go either right or up, and there is a ghost in the path going right,
then PacMan will go up. Then while PacMan is going up, a ghost enters that path, PacMan will go back.

You only need to worry about the grid itself and any ghosts on the North/South/East/West axis of PacMan.

### 211. Exercise - Implement `PacManAI::optimalDirection`

Implement [PacManAI::optimalDirection](../../../lib/PacManAI.cpp) and test your implementation with the test
in [testPacmanAI.cpp](../../../test/testPacmanAI.cpp) called _"Is optimal direction"_

```cpp
Direction PacManAI::optimalDirection(const std::array<Move, 4> & moves) {
  return Direction::NONE;
}
```
