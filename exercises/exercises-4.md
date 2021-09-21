## Exercises

# Exercise: PacMan Bot

PacMan can be controlled with the keyboard, but those inputs can be automated. The only thing that needs to change is the value within the InputState class.

Start by giving InputState random values on each update and then program in a fixed set of movement. For example "Go Right for 3 seconds, then down, right, up, right". This should pickup the first super pellet.

In this exercise, the input code in processEvents is not needed.

# Exercise: PacMan AI

The exercise above is fixed based on the layout of the board and is hard to make generic.

Let's implement a naive AI for PacMan. At each intersection, check if there is a ghost directly inline with that path. If the path is free of ghosts, you are allowed to turn there. And if PacMan is moving in a direction, and a ghost enters his path, then pacman will reverse.

For example if pacman is at an intersection and can go either right or up, and there is a ghost in the path going right, then pacman will go up. Then while pacman is going up, a ghost enters that path, pacman will go back.

You only need to worry about the grid itself and any ghosts on the North/South/East/West axis of PacMan.

# Exercise: ?

Extra