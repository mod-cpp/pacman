[< Back](../README.md)

# 250. Exercise - Smarter PacMan AI

We've implemented a naive AI for PacMan, but maybe we can improve it?

## Background: PacMan Moves

At each intersection, check if there is a ghost directly inline with that path. If the
path is free of ghosts, you are allowed to turn there. And if PacMan is moving in a
direction, and a ghost enters his path, then PacMan will reverse.

For example if PacMan is at an intersection and can go either right or up, and there
is a ghost in the path going right, then PacMan will go up. Then while PacMan is going
up, a ghost enters that path, PacMan will go back.

You only need to worry about the grid itself and any ghosts on the
North/South/East/West axis of PacMan.

## Exercise

For people who want to create a fancier AI, if you want to introduce some randomness,
you can look at this SFML
function https://www.sfml-dev.org/tutorials/1.6/system-random.php - you will need to
include `#include <SFML/Randomizer.hpp>`
