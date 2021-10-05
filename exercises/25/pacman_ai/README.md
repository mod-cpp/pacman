[< Back](../README.md)

# Exercise: PacMan AI

The exercise above is fixed based on the layout of the board and is hard to make generic.

Let's implement a naive AI for PacMan. At each intersection, check if there is a ghost directly inline with that path.
If the path is free of ghosts, you are allowed to turn there. And if PacMan is moving in a direction, and a ghost enters
his path, then pacman will reverse.

For example if pacman is at an intersection and can go either right or up, and there is a ghost in the path going right,
then pacman will go up. Then while pacman is going up, a ghost enters that path, pacman will go back.

You only need to worry about the grid itself and any ghosts on the North/South/East/West axis of PacMan.
