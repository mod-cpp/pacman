# Mod(C++) - Pac-Man Exercise


## Setup VCPKG

git submodule init
git submodule update
On windows, run `.\vcpkg\bootstrap-vcpkg.bat`.
On other platforms, run `./vcpkg/bootstrap-vcpkg.sh`

Dependencies will be automatically when running CMake.

## Keep PacMan Score

* Implement score by implementing eating of pellets by Pac-Man
* Use the existing test.cpp file for TDD scoring
* Pellets are worth 10 points - SuperPellets 50 points
* Implement support for the pellets to be eaten
* Implement support for counting pellets eaten by PacMan
* (Extra: Display score - if you have a LOT of time)

## Make a ghost

* Use the PacMan class as inspiration
* Pic a sprite from [sprites32.png](assets/sprites32.png) for the ghost
* Make an algorithm for movement (simple is fine)
* For fancy algorithm see next section

### Ghosts characters and algorithms
These will probably become relevant
* https://en.wikipedia.org/wiki/Ghosts_(Pac-Man)
* https://youtu.be/ataGotQ7ir8
* https://gameinternals.com/understanding-pac-man-ghost-behavior
* https://www.gamasutra.com/view/feature/3938/the_pacman_dossier.php?print=1
* https://www.slideshare.net/grimlockt/pac-man-6561257