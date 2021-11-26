[< Back](../README.md)

# Exercise: Add Clyde as a Ghost

## Background: Clyde

We have three ghosts within the project. Blinky, Inky and Pinky. But Clyde is missing. Implement Clyde and their
behavior.

Clyde chases PacMan so you need to know where PacMan is currently located. But Clyde gets scared and runs back to its scatter target when PacMan gets too close (less than 8 the size of a cell).
Clyde also has the scatter and eyes behaviors as the other ghosts.

## Exercise

1. Clyde should inherit from Ghost
2. Make simple implementations of the functions to make it compile
3. Clyde should start at Position { x = 15.5, y = 14 }
4. Clydes sprite is the orange one. Where are the graphics for Clyde in the assets file and how can we make sure the ghost will be correctly rendered?
5. Modify `Canvas` to  make sure Clyde is rendered. Otherwise it will not appear on screen.
6. Clydes scatter target is { x = 0, y = 30 }
7. Clyde always targets its scatter target, unless PacMan is further than 8 tiles away
