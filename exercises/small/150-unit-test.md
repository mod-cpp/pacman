# 150. Unit tests

1. Add a new unit test `TEST_CASE` for `isWall`. To test `isWall` we need to add it the `Board.hpp` file because it should
   be accessible within the `testBoard.cpp` file. Check for a couple of cases, similarly to the `isWalkableForPacMan`
   test. Remember since the unit tests are not inside of the `pacman` namespace, we need to append `pacman::` to the
   function calls.

2. Compile the project and run the unit tests. They should all be passing and if they are not then check which unit test
   is failing and figure out what was causing the issue. If all goes well you can run the game.
