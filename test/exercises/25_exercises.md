[< Back](README.md)

# 25. Algorithmic Thinking

* [Exercise 250](#exercise-250)
* [Exercise 251](#exercise-251)
* [Exercise 252](#exercise-252)

## Exercise 250

### PacMan AI

We've implemented a naive AI for PacMan, but maybe we can improve it?

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

For people who want to create a fancier AI, if you want to introduce some randomness,
you can look at this SFML
function https://www.sfml-dev.org/tutorials/1.6/system-random.php - you will need to
include `#include <SFML/Randomizer.hpp>`

## Exercise 251

### PacMan Bot

#### Background: Keyboard Input

PacMan can be controlled with the keyboard, but those inputs can be automated. The
only thing that needs to change is the value within the InputState class.

#### Exercise

Start by giving InputState random values on each update and then program in a fixed
set of movement. For example "Go Right for 3 seconds, then down, right, up, right".
This should pickup the first super pellet.

In this exercise, the input code in processEvents is not needed.

## [Exercise 252][1]

### Description

<details>
   <summary>Solution</summary>

```cpp

```

</details>

[1]: 25_exercises.cpp
