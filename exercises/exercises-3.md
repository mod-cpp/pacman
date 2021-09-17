## Exercises

# Exercise: Increased Ghost Speed

Currently the ghosts move at a fixed rate. But in the original game, the ghosts would move slightly faster and faster as the game went on.

Implement a way to incrementally increase the ghost speed over time. The speed function takes in the current game state so that can be used. The speed should not slowly increase for each update, so something like adding onto the speed value over time is not correct behavior.

You could increase the speed after each time the ghost is eaten for example, or increment the speed by a certain amount after N seconds.

Also ask yourself, how would you test this?

# Exercise: Add Blinky as a Ghost

We have three ghosts within the project. Clyde, Inky and Pinky. But Blinky is missing. Implement Blinky and their behavior.

Blinky always chases PacMan so the only thing you should need is where PacMan is currently located. But Blinky also has the scatter behavior as the other ghosts.

# Exercise: ?

Extra

# TODO Changes
Pinky as main exercise and Clyde as Extra.