[< Back](../README.md)

# Exercise: Create an isWall function

In this exercise we will write some helper functions for the game board.

The file [`Board.cpp`](../../../lib/Board.cpp) defines functions to manipulate the game Board, for example finding where
the walls and the portals are.

## Background: Board.cpp

The Board itself is represented in memory as a 2 dimensional array. A cell in this grid can be for example walkable, a
wall, a pellet, a super pellet or a portal.

`Cell` is an enum representing the different types of cells.

`isWalkableForGhost` and `isWalkableForPacMan` are two functions which need to check whether a cell is a wall.

```cpp
bool isWalkableForPacMan(GridPosition point) {
 return cellAtPosition(point) != Cell::wall && cellAtPosition(point) != Cell::pen;
}

bool isWalkableForGhost(GridPosition point, GridPosition origin, bool isEyes) {
 const Cell cell = cellAtPosition(point);
 if (cell == Cell::wall)
   return false;
 return isEyes || isInPen(origin) || !isInPen(point);
}
```

## Exercise

Let's add a simple helper function.

You might notice that `isWalkableForPacMan` and `isWalkableForGhost` both call `cellAtPosition` with a `GridPosition`
variable and check if it is a wall. Maybe we can lift that check into a separate function (call it `isWall`) to avoid
repeating ourselves?

1. Create a function called `isWall` between `cellAtPosition` and `isWalkableForPacMan` that returns true if
   the `GridPosition` parameter is a wall. A function needs to be defined before it is called, so the order of functions
   is important. Try to define `isWall` after ``isWalkableForPacMan` or before `cellAtPosition`. It does not compile

2. Replace the checks within `isWalkableForPacMan` and `isWalkableForGhost` with your new function.

3. Check to see that the game still works as expected.
