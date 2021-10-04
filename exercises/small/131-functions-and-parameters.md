# Functions and Parameter Passing

In this exercise we will write some helper functions for the game board.

The game board is defined in the `Board.cpp` file and the exported functions are described in `Board.hpp`

## Board.cpp/hpp

The structure of these files is as follows. The `cpp` file starts with including the `Board.hpp` file and all of its contents. Then we open a namespace and define how many rows and columns the board will have. We also create an enum that defines what each cell value means on the board itself.

Then we have the actual board. A two dimensional array of integers. This will be the layout of the game board. We use integers and not the Cell enum we defined above so we can use the numbers directly, the `enum class` is strongly typed, you can see this when we check for values.

Below the board are the helper functions. Some of them are static (only visible within this file) and some are not, those that are not should have a similar function description in the `Board.hpp` file. For example:

```cpp
// Board.hpp
bool isWalkableForPacMan(GridPosition point);

// Board.cpp
bool isWalkableForPacMan(GridPosition point) {
  return cellAtPosition(point) != Cell::wall && cellAtPosition(point) != Cell::pen;
}
```

## Board Unit Tests

The game board is covered by unit tests. They are located in the `testBoard.cpp` file within the `test` directory. They don't check every single tile on the board but they do assume that the board shape is not changed significantly. If you change the board layout you might have to change some of the unit tests to match.

Unit tests are broken down into test cases, in this file it is focused on a test case per function. A `TEST_CASE` takes two arguments, a test name and a tag. The test name needs to be unique and for the tag we use the section of the game we are testing. Think of them like functions that are called when testing.

## Exercise

Lets add a simple helper function.

You might notice that `isWalkableForPacMan` and `isWalkableForGhost` both call `cellAtPosition` with a `GridPosition` variable and check if it is a wall.

1. Create a function called `isWall` below `cellAtPosition` that returns true if the `GridPosition` variable sent in is a wall. Remember to also create the same function signature in the `Board.hpp` file so this helper function can be used elsewhere in the project if needed.

2. Replace the checks within `isWalkableForPacMan` and `isWalkableForGhost` with your new function.

3. Add a new unit test `TEST_CASE` for your function. Since you already added `isWall` to the `Board.hpp` file it should be accessible within the `testBoard.cpp` file. Check for a couple of cases, similarly to the `isWalkableForPacMan` test. Remember since the unit tests are not inside of the `pacman` namespace, we need to append `pacman::` to the function calls.

4. Compile the project and run the unit tests. They should all be passing and if they are not then check which unit test is failing and figure out what was causing the issue. If all goes well you can run the game.