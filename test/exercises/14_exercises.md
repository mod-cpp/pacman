[< Back](README.md)

# 14. Functions and Parameter Passing

* [Exercise 140](#exercise-140)
* [Exercise 141](#exercise-141)

## Exercise 140

### Play with parameter passing

In this exercise we will look together at what happens when we change a reference
parameter to a value or a const reference.

Let's look at this function in [`Game.cpp`][1]

```cpp
void Game::processEvents(InputState & inputState) {


 auto event = canvas.pollEvent();
 if (event && event.value().type == sf::Event::Closed) {
   inputState.close = true;
   return;
 }


 inputState.down  = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
 inputState.up    = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
 inputState.left  = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
 inputState.right = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}
```

### Exercise

You can follow along locally:

1. Make `inputState` a value. What happens when you compile the code? Can you explain
   why?

2. Now make it a `const` reference. What happens? Can you explain why?

3. Revert it back to a non-const reference an make sure the code compile.

## Exercise 141

### Create an isWall function

In this exercise we will write some helper functions for the game board.

The file [`Board.cpp`][2] defines functions to manipulate the game Board, for example
finding where the walls and the portals are.

#### Background: Board.cpp

The Board itself is represented in memory as a 2 dimensional array. A cell in this
grid can be for example walkable, a wall, a pellet, a super pellet or a portal.

`Cell` is an enum representing the different types of cells.

`isWalkableForGhost` and `isWalkableForPacMan` are two functions which need to check
whether a cell is a wall.

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

### Exercise

Let's add a simple helper function.

You might notice that `isWalkableForPacMan` and `isWalkableForGhost` both
call `cellAtPosition` with a `GridPosition`
variable and check if it is a wall. Maybe we can lift that check into a separate
function (call it `isWall`) to avoid repeating ourselves?

1. Create a function called `isWall` between `cellAtPosition`
   and `isWalkableForPacMan` that returns true if the `GridPosition` parameter is a
   wall. A function needs to be defined before it is called, so the order of functions
   is important. Try to define `isWall` after ``isWalkableForPacMan` or before `
   cellAtPosition`. It does not compile

2. Replace the checks within `isWalkableForPacMan` and `isWalkableForGhost` with your
   new function.

3. Check to see that the game still works as expected.

<details>
   <summary>Solution</summary>

```cpp
bool isWall(GridPosition point) {
   return cellAtPosition(point) == Cell::wall;
}

bool isWalkableForPacMan(GridPosition point) {
  return !isWall(point) && cellAtPosition(point) != Cell::pen;
}

bool isWalkableForGhost(GridPosition target_position,
                        GridPosition current_position, bool isEyes) {
  if (isWall(target_position))
    return false;
  return isEyes || isInPen(current_position) || !isInPen(target_position);
}
```
</details>

[1]: ../../lib/Game.cpp
[2]: ../../lib/Board.cpp
