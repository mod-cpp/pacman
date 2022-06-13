[< Back](README.md)

# 21. std::array and ranged for

* [Exercise 210](#exercise-210)
* [Exercise 211](#exercise-211)
* [Exercise 212](#exercise-212)

## Exercise 210
### Implement PacManAI::isValidMove

#### Background: PacMan Moves

At each intersection, check if there is a ghost directly inline with that path. If the
path is free of ghosts, you are allowed to turn there. And if PacMan is moving in a
direction, and a ghost enters his path, then PacMan will reverse.

For example if PacMan is at an intersection and can go either right or up, and there
is a ghost in the path going right, then PacMan will go up. Then while PacMan is going
up, a ghost enters that path, PacMan will go back.

You only need to worry about the grid itself and any ghosts on the
North/South/East/West axis of PacMan.

#### Exercise

As a warmup exercise, implement [PacManAI::isValidMove][2] and test your
implementation with the test in [testPacmanAI.cpp][3] called _"Is valid move"_

Note: `isValidMove` will be called 4 times in a loop. If the target cell is not
walkable the distance is set to infinity.

Note: Going backwards is not allowed, otherwise you'll go back and forwards between 2
pellets while playing the game.

Note: The test is disabled, to enable the test remove the [!shouldfail] from the tags
on the test

```cpp
bool PacManAI::isValidMove(const Move & move) {
  return false;
}
```

<details>
   <summary>Hint 1</summary>

Use [isWalkableForPacMan][4] to make sure PacMan is not walking in ways that are not
legal

</details>

<details>
   <summary>Hint 2</summary>

Use [oppositeDirection][5] to make sure PacMan doesn't get stuck toggeling back and
forth

</details>

<details>
   <summary>Solution</summary>

```cpp
bool PacManAI::isValidMove(const Move & move) {
  const bool isOpposite = (move.direction == oppositeDirection(direction));
  if (isOpposite) {
    return false;
  }

  const bool canWalk = isWalkableForPacMan(move.position);
  if (!canWalk) {
    return false;
  }
  return true;
}
```
</details>

## Exercise 211
### Implement PacManAI::optimalDirection

#### Background: PacMan Moves

At each intersection, check if there is a ghost directly inline with that path. If the
path is free of ghosts, you are allowed to turn there. And if PacMan is moving in a
direction, and a ghost enters his path, then PacMan will reverse.

For example if PacMan is at an intersection and can go either right or up, and there
is a ghost in the path going right, then PacMan will go up. Then while PacMan is going
up, a ghost enters that path, PacMan will go back.

You only need to worry about the grid itself and any ghosts on the
North/South/East/West axis of PacMan.

#### Exercise

Implement [PacManAI::optimalDirection][2] and test your implementation with the test
in [testPacmanAI.cpp][3] called _"Is optimal direction"_

```cpp
Direction PacManAI::optimalDirection(const std::array<Move, 4> & moves) {
  return Direction::NONE;
}
```

<details>
   <summary>Solution</summary>

```cpp
Direction PacManAI::optimalDirection(const std::array<Move, 4> & moves) {
  double closestDistance = std::numeric_limits<double>::infinity();
  Direction dir = Direction::LEFT;

  for (const auto & move : moves) {
    if (move.distanceToTarget < closestDistance) {
      closestDistance = move.distanceToTarget;
      dir = move.direction;
    }
  }
  return dir;
}

```
</details>

## [Exercise 212][1]
### Description

<details>
   <summary>Solution</summary>

```cpp

```
</details>

[1]: 21_exercises.cpp
[2]: ../../lib/PacManAI.cpp
[3]: ../../test/unit_tests/testPacmanAI.cpp
[4]: ../../lib/Board.cpp
[5]: ../../lib/include/Direction.hpp
