## Exercises

# Exercise: Game Over

In this exercise you will add a game over state to the game. After PacMan has lost all of his lives the game will be over. PacMan should not respawn and the ghosts should stop.

The GameState class has the number of lives and they are already drawn on screen so that information can be used to indicate the game over state itself.

If the game is over, the text "Game Over" should be drawn over the game board. You do not need to implement a new game, for this exercise restarting the application is enough.

# Exercise: New Level

In this exercise you will need to reset the game board but keep score and lives the same. This should happen when PacMan eats the last pellet or super pellet.

The ghosts and pacman should go back to their original position and all of the pellets should respawn. This can go on forever, but you can look at the next exercise for more information.

# Exercise: Victory

As a continuation of the Game Over and New Level exercises. If PacMan beats 3 levels, the game has been beaten and a victory screen should be shown.

A count of how many levels have been beaten needs to be stored and this should be checked when transitioning between levels.

This should function similarly to the Game Over state but used to indicate that the player won the game.