![CMake](https://github.com/turtlesec-no/modern_cpp_exercises/workflows/CMake/badge.svg)
# Mod(C++) - Pac-Man Exercise

## Ghosts
This will probably become relevant https://en.wikipedia.org/wiki/Ghosts_(Pac-Man)
This as well https://youtu.be/ataGotQ7ir8
https://gameinternals.com/understanding-pac-man-ghost-behavior
https://www.gamasutra.com/view/feature/3938/the_pacman_dossier.php?print=1

## Windows Toolchain

Visual Studio Community 2019 - latest (MSVC 19.28.29334.0)

## Get Clion

https://www.jetbrains.com/clion/download/download-thanks.html

## Get Python 3

https://docs.python.org/3/using/windows.html#the-full-installer

## Get Conan

pip3 install conan --upgrade

## Conan on Linux

Set this environment variable and Conan will tell you which packages you need to
intall on Linux.
CONAN_SYSREQUIRES_MODE=verify

In case of link errors around sndio, try to uninstall this package and rebuild the conan cache:
~~~
sudo apt remove libsndio-dev*
~~~
https://bugzilla.libsdl.org/show_bug.cgi?id=5105

## Currently does not work on windows - Get Clang

Clang 10 works seamlessly with Conan (version 1.31.4) - with 11 you have to update your 
<userhome>/.conan/settings.yml file, add "11" to the list at "clang: version:"

https://releases.llvm.org/download.html
https://www.jetbrains.com/help/clion/quick-tutorial-on-configuring-clion-on-windows.html#clang-cl
