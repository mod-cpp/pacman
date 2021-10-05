# Functions and Parameter Passing

In Board.cpp we have functions to detect the state of the game board. Let's add a few helper functions and create unit
tests for them.

Add a function that will check if a cell on the board is a wall. Then use that function in "isWalkableForPacMan" and "
isWalkableForGhost". Remember you will need to add the function into the Board.hpp header file to be able to use it in
the unit tests.

# Game - Foundation

?

# Compilation, Linking and Assets

One of the PacMan ghosts is missing and we will implement this ghost later. But for now, let's add the cpp and hpp files
and run CMake to see the file added to our project. Then let's create an empty class called Blinky that looks like the
other Ghost classes but it can be empty at this time. Where are the graphics for Blinky in the assets file and how can
we make sure the ghost will be correctly rendered?

# Memory and RAII

(corentin: maybe something about } that destroys things)
We are going to play with using std::unique_ptr as we discussed in the slides. Since we will be reverting these changes
back, do take a copy of the GameState files before we start. We will change PacMan within GameState into a std::
unique_ptr<PacMan>, once this has been done the code will not compile, because there are further changes needed within
the GameState class. Go through and figure out what needs to be updated. Can we change one of the ghosts into a std::
unique_ptr? Are there any current design problems we will run into? What do these design issues say about ownership of
data?

# Classes and Structs

Within the GameState class, we often call all of the ghost functionality at the same time. So lets create a class that
will contain all the ghosts. It can be called GhostState and the only member variables will be the ghosts. This class
then needs to be contained within GameState instead of the ghosts. Then you need to write the functions for this
GhostState class that are called within the GameState class.

# std::array and ranged for

waage: Maybe the "isIntersection" for the AI. Create an array of GridPosition and array of bool and loop through to
check "isWalkableForPacMan" and then return the different kinds of intersections (top/right, right/bottom, bottom/left,
left/top)

# std::vector

?

# Iterators and algorithms

Use algorithms in Pellet and SuperPellet

# Lambdas and Function Templates

?

# Algorithmic Thinking

?