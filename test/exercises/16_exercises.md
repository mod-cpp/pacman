[< Back](README.md)

# 16. Classes and Structs

* [Exercise 160](#exercise-160)
* [Exercise 161](#exercise-161)
* [Exercise 162](#exercise-161)

## Exercise 160

### Simple class

1. Create an empty class named `Clyde` within the `.hpp` file.
2. Look at other ghost `.hpp` files and see how they define the class. It does not
   need to inherit from the `Ghost` base class and it does not need any functions.

<details>
   <summary>Solution</summary>

Clyde.hpp

```cpp
#pragma once

#include "Ghost.hpp"

namespace pacman {

class Clyde {

};

} // namespace pacman

```

Clyde.cpp

```cpp
#include "Clyde.hpp"

namespace pacman {

} // namespace pacman
```

</details>

## Exercise 161

### Add Clyde as a Ghost

#### Background: Clyde

We have three ghosts within the project. Blinky, Inky and Pinky. But Clyde is missing.
Implement Clyde and their behavior.

Clyde chases PacMan so you need to know where PacMan is currently located. But Clyde
gets scared and runs back to its scatter target when PacMan gets too close (less than
8 the size of a cell). Clyde also has the scatter and eyes behaviors as the other
ghosts.

#### Exercise

1. Clyde should inherit from Ghost
2. Make simple implementations of the functions to make it compile
3. Clyde should start at Position { x = 15.5, y = 14 }
4. Clydes sprite is the orange one. Where are the graphics for Clyde in the assets
   file and how can we make sure the ghost will be correctly rendered?
5. Modify `Canvas` to make sure Clyde is rendered. Otherwise it will not appear on
   screen.
6. Clydes scatter target is { x = 0, y = 30 }
7. Clyde always targets its scatter target, unless PacMan is further than 8 tiles away

<details>
   <summary>Solution</summary>

Clyde.hpp

```cpp
#pragma once

#include "Ghost.hpp"

namespace pacman {

class Clyde final : public Ghost {
public:
  explicit Clyde();
  void setTarget(Position pacManPos);

protected:
  double speed() const override;
  Position initialPosition() const override;

private:
  Position scatterTarget() const;
};

} // namespace pacman
```

Clyde.cpp

```cpp
#include "Clyde.hpp"

namespace pacman {

Clyde::Clyde()
  : Ghost(Atlas::Ghost::clyde) {
  pos = initialPosition();
}

double Clyde::speed() const {
  if (state == State::Eyes)
    return 2;
  if (state == State::Frightened)
    return 0.5;
  return 0.75;
}

void Clyde::setTarget(Position pacManPos) {
  if (state == State::Eyes) {
    target = initialPosition();
    return;
  }

  if (isInPen()) {
    target = penDoorPosition();
    return;
  }

  // Clyde always target its scatter target, unless pacman is further than 8 tiles away
  target = scatterTarget();
  if (state == State::Scatter) {
    return;
  }

  const auto distanceFomPacMan = std::hypot(pos.x - pacManPos.x, pos.y - pacManPos.y);
  if (distanceFomPacMan > 8) {
    target = pacManPos;
  }
}

Position Clyde::initialPosition() const {
  return { 15.5, 14 };
}

Position Clyde::scatterTarget() const {
  return { 0, 30 };
}

} // namespace pacman
```

</details>

## [Exercise 162][1]

### Description

<details>
   <summary>Solution</summary>

```cpp

```

</details>

[1]: 16_exercises.cpp
