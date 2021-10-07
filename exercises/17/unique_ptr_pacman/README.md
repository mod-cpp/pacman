[< Back](../README.md)

# Exercise: std::unique_ptr<PacMan>

## Background:

(corentin: maybe something about } that destroys things)
We are going to play with using std::unique_ptr as we discussed in the slides. Since we will be reverting these changes
back, do take a copy of the GameState files before we start. We will change PacMan within GameState into a std::
unique_ptr<PacMan>, once this has been done the code will not compile, because there are further changes needed within
the GameState class. Go through and figure out what needs to be updated. Can we change one of the ghosts into a std::
unique_ptr? Are there any current design problems we will run into? What do these design issues say about ownership of
data?

## Exercise

1.
