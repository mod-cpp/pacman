[< Back](../README.md)

# Exercise: Set up development environment

## Install tools

### All Platforms

* Follow the instructions to install VSCode from https://code.visualstudio.com/
* If you already have it installed, make sure it is up to date

### Ubuntu 20.04 or newer

* Install the build tools
```bash
sudo apt-get install ninja-build pkg-config curl zip unzip tar cmake build-essential libx11-dev libxrandr-dev libxi-dev libudev-dev libgl1-mesa-dev
```

### Fedora 33 or newer

* Install the build tools
```bash
sudo dnf install ninja-build SFML-devel libXi-devel libX11-devel libXrandr-devel mesa-libGL-devel systemd-devel
```

### FreeBSD 12 or newer

* Install the build tools
```bash
sudo pkg install catch cmake libfmt ninja sfml
```

### Windows:

* Follow the instructions to install cmake (3.22) from https://cmake.org/download/
* Install Visual Studio 2022 https://visualstudio.microsoft.com/
* Reboot your computer once that's done.
* If you have issues with using VSCode, start it from the "Developer Command Prompt for VS 2022"

### Mac

* Install clang by typing `xcode-select --install` in a terminal and following the instructions
* Install the build tools
```bash
brew install cmake ninja
```
* Follow the instructions for [Launching VSCode from the command line](https://code.visualstudio.com/docs/setup/mac#_launching-from-the-command-line)

## Configure and build project

### All Platforms, using VS Code

```bash
git clone https://github.com/mod-cpp/pacman.git
cd pacman
code .
```

* You will get a popup in the lower right hand corner asking "Do you want to install the recommended extensions for C++?" - click Install

### Commandline based build (Not used in this training)

```bash
git clone https://github.com/mod-cpp/pacman.git
cd pacman
cmake -B build
cmake --build build
ctest --test-dir build -C Debug
```

### Using CLion

* When opening the project in CLion use the CMake preset for your platform - see popup in the lower right hand corner
* Unselect the "Debug" profile
* Select for example the preset profile called "windows-build" if you are on Windows
* Enable it by checking the checkbox "Enable profile"
* Click "Apply" and "OK"
* (If CLion created a `cmake-build-debug` folder you can safely delete it, we will be using the `build` directory)
