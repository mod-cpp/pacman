[< Back](../README.md)

# Exercise: Create and run a unit test

## Background: Board Unit Tests

The game board is covered by unit tests. They are located in the `testBoard.cpp` file within the `test` directory. They
don't check every single tile on the board, but they do assume that the board shape is not changed significantly. If you
change the board layout you might have to change some unit tests to match.

Unit tests are broken down into test cases, in this file it is focused on a test case per function. A `TEST_CASE` takes
two arguments, a test name and a tag. The test name needs to be unique and for the tag we use the section of the game we
are testing. Think of them like functions that are called when testing.

## Exercise

1. Add a new unit test `TEST_CASE` for `isWall`. To test `isWall` we need to add it the `Board.hpp` file because it
   should be accessible within the `testBoard.cpp` file. Check for a couple of cases, similarly to the 
   `isWalkableForPacMan` test. Remember since the unit tests are not inside of the `pacman` namespace, we need to append
   `pacman::` to the function calls.

2. Compile the project and run the unit tests. They should all be passing and if they are not then check which unit test
   is failing and figure out what was causing the issue. If all goes well you can run the game.
