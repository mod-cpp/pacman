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

Implement an AI for pacman, trying to leverage standard algorithms. There are many
ways to make PacMan move. Try to maximize the score of your AI, and the time it stays
alive!

<details>
   <summary>Hint: Getting started</summary>

The function [PacManAI::choseNewDirectionForPacMan](../../lib/PacManAI.cpp) returns
the direction PacMan should take at an intersection. This may be a good place to
implement our AI.

</details>

<details>
   <summary>Possible approach: Make PacMan move randomly</summary>

The function `randomInt` in `PacManAI.cpp` returns a random integer between its two
parameters. You can use this function to introduce some randomness.

You can use this function to pick a direction at random. But not all directions are
valid, make sure PacMan does not try to go in a wall or another inaccessible position.

</details>

<details>
   <summary>Possible approach: Make PacMan avoid the ghosts</summary>

Try to make PacMan flee the ghosts. The AI does not know the positions of the ghosts,
you will have to expose this information.

   <details>
      <summary>Hint: Exposing the ghost's position</summary>

You will need to create a `std::vector<GhostPosition>`
in `GameState.cpp` and pass it as parameter to
`PacManAI::update()` then `PacManAI::choseNewDirectionForPacMan`.
   </details>

<details>
      <summary>Hint: Finding the ghosts</summary>

Create a function that, for each of the possible directions, walks through each cell,
starting from PacMan's position outwards, and return true if a ghost is found. Use
that function to filter out the directions where PacMan will encounter a ghost, by
modifying the random solution

</details>

</details>

<details>
<summary>Possible approach: let PacMan go towards the closest pellet</summary>

</details>

<details>
   <summary>Solution: Make PacMan move randomly</summary>

```cpp
Direction PacManAI::choseNewDirectionForPacMan(const PacMan & pacMan) {
  const GridPosition currentPosition = pacMan.positionInGrid();
  const auto [x, y] = currentPosition;

  // Construct an array of the 4 moves
  std::array<Move, 4> possibleMoves = {
    Move{ Direction::UP, { x, y - 1 } },
    Move{ Direction::LEFT, { x - 1, y } },
    Move{ Direction::DOWN, { x, y + 1 } },
    Move{ Direction::RIGHT, { x + 1, y } }
  };

  // Filter out invalid moves
  auto end = std::remove_if(possibleMoves.begin(), possibleMoves.end(), [this](const Move & m) {
    return !isValidMove(m);
  });

  // The index of the choosen move is a random integer between 0 and the last valid move.
  auto index = randomInt(std::size_t(0),
                         std::size_t(std::distance(possibleMoves.begin(), end) - 1));

  return possibleMoves[index].direction;
}
```

</details>

<details>
   <summary>Solution: Make PacMan avoid the ghosts</summary>

<ul>
<li>
Create a vector of position in `GameState::step()`:

```cpp
void GameState::step(std::chrono::milliseconds delta) {

  std::vector<GridPosition> ghostPositions = {
    blinky.positionInGrid(),
    inky.positionInGrid(),
    pinky.positionInGrid(),
    clyde.positionInGrid()
  };

  pacManAI.update(pacMan, pellets, ghostPositions);
  pacMan.update(delta,
                inputState.enableAI ? pacManAI.suggestedDirection() : inputState.direction());

  if (isPacManDying()) {
    handleDeathAnimation(delta);
    return;
  }
  // [...]
}
```

</li>

<li>
Modify the signatures of `PacManAI::update` and `PacManAI::choseNewDirectionForPacMan`

```cpp
Direction choseNewDirectionForPacMan(const PacMan & pacMan,
                                     const std::vector<GridPosition> & ghostPositions);
```

```cpp
void update(const PacMan & pacMan, const Pellets & pellets, const
            std::vector<GridPosition> & ghostPositions);
 ```

Adjust  `PacManAI::update` to pass `ghostPositions`
to `PacManAI::choseNewDirectionForPacMan`.

</li>

<li>
Create a function to check if a direction contains a ghost.
This scans all positions outwards from a posible move's position until we encounter a wall.

```cpp
bool hasGhost(GridPosition p, Direction d,
             const std::vector<GridPosition> & ghostPositions)  {
  int xd = 0;
  int yd = 0;
  switch(d) {
    case Direction::UP:    yd  = -1; break;
    case Direction::DOWN:  yd  = 1; break;
    case Direction::LEFT:  xd  = -1; break;
    case Direction::RIGHT: xd = 1; break;
    default:
      return false;
  }
  while(isWalkableForPacMan(p)) {
    auto it = std::find(ghostPositions.begin(), ghostPositions.end(), p);
    if(it != std::end(ghostPositions))
      return true;
    p.x = static_cast<std::size_t>(static_cast<int64_t>(p.x) + xd);
    p.y = static_cast<std::size_t>(static_cast<int64_t>(p.y) + yd);
  }
  return false;
}
```

</li>

<li>

Modify `PacManAI::choseNewDirectionForPacMan` to filter out direction that cross the
path of a ghost. There is a small pitfall: what happen if Pacman is circled by ghosts?

```cpp
Direction PacManAI::choseNewDirectionForPacMan(const PacMan & pacMan,
                                               const std::vector<GridPosition> & ghostPositions) {
  const GridPosition currentPosition = pacMan.positionInGrid();
  const auto [x, y] = currentPosition;

  // Construct an array of the 4 moves
  std::array<Move, 4> possibleMoves = {
    Move{ Direction::UP, { x, y - 1 } },
    Move{ Direction::LEFT, { x - 1, y } },
    Move{ Direction::DOWN, { x, y + 1 } },
    Move{ Direction::RIGHT, { x + 1, y } }
  };

  // Filter out invalid moves
  auto end = std::remove_if(possibleMoves.begin(), possibleMoves.end(), [this](const Move & m) {
    return !isValidMove(m);
  });

  // Filter out invalid moves
  auto lasWithoutGhost = std::remove_if(possibleMoves.begin(), end,
    [this, &ghostPositions](const Move & m) {
      return hasGhost(m.position, m.direction, ghostPositions);
  });

  // We need to handle the case where PacMan is circled by ghosts
  if(lasWithoutGhost != possibleMoves.begin())
    end = lasWithoutGhost;

  // The index of the choosen move is a random integer between 0 and the last valid move.
  auto index = randomInt(std::size_t(0),
                         std::size_t(std::distance(possibleMoves.begin(), end) - 1));

  return possibleMoves[index].direction;
}
```

</li>
</ul>
</details>

<details>
<summary>Solution: Make PacMan go towards the closest Pellet</summary>

Use `pelletClosestToPacman` to calculate a target for PacMan, then find then
use `optimalMove` to decide a direction.

```cpp
Direction PacManAI::choseNewDirectionForPacMan(const PacMan & pacMan,
                                               const Pellets & pellets) {

  const GridPosition pacManGridPos = pacMan.positionInGrid();
  auto pelletPositions = pellets.allPellets();
  if (pelletPositions.empty()) {
    return Direction::NONE;
  }

  const GridPosition targetPos = pelletClosestToPacman(pacManGridPos, pelletPositions);

  const GridPosition currentPosition = pacMan.positionInGrid();
  const auto [x, y] = currentPosition;
  std::array<Move, 4> possibleMoves = {
    Move{ Direction::UP, { x, y - 1 } },
    Move{ Direction::LEFT, { x - 1, y } },
    Move{ Direction::DOWN, { x, y + 1 } },
    Move{ Direction::RIGHT, { x + 1, y } }
  };

  for (auto & move : possibleMoves) {
    if (!isValidMove(move))
      continue;
    move.distanceToTarget = positionDistance(move.position, targetPos);
  }
  return optimalDirection(possibleMoves);
}
```

</details>

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
