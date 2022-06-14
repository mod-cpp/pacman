[< Back](README.md)

# 11. Introduction

* [Exercise 110](#exercise-110)
* [Exercise 111](#exercise-111)
* [Exercise 112](#exercise-112)

## Exercise 110

### Set up development environment

* [Quick install](#quick-install)
* [Manual install](#manual-install)
* [Build](#build)
* [Troubleshoot](#troubleshoot)

### Quick install

<details>
   <summary>Windows: <b>Chocolatey</b></summary>

PowerShell run as Admin

```bash
iex ((New-Object System.Net.WebClient).DownloadString('https://raw.githubusercontent.com/mod-cpp/pacman/main/dev/windows.ps1'))
```

</details>
<details>
   <summary>Windows: <b>WinGet</b></summary>

PowerShell run as Admin, Ninja has to be installed seperately

```bash
iex ((New-Object System.Net.WebClient).DownloadString('https://raw.githubusercontent.com/mod-cpp/pacman/main/dev/windows_winget.ps1'))
```

</details>
<details>
   <summary>Ubuntu: <b>apt</b></summary>

```bash
bash <(curl -s https://raw.githubusercontent.com/mod-cpp/pacman/main/dev/ubuntu.sh)
```

</details>

### Manual install

<details>
   <summary>Windows</summary>

* Follow the instructions to install cmake (3.22) from https://cmake.org/download/
* Install Visual Studio 2022 https://visualstudio.microsoft.com/
* Click "Modify" in the Visual Studio Installer and select "Desktop development with
  C++"
* Reboot your computer once that's done.
* Install VS Code: https://code.visualstudio.com/#alt-downloads

</details>

<details>
   <summary>MacOS</summary>

* Install clang by typing `xcode-select --install` in a terminal and following the
  instructions
* Install the build tools

```bash
brew install cmake ninja
```

* Follow the instructions for [Launching VSCode from the command line][4]

</details>

<details>
   <summary>Ubuntu 20.04 or newer</summary>

```bash
sudo apt install build-essential clang-12 cmake curl g++-10 git libgl1-mesa-dev libudev-dev libx11-dev libxi-dev libxrandr-dev ninja-build pkg-config tar unzip zip      
```

* Install VS Code: https://code.visualstudio.com/#alt-downloads
* https://code.visualstudio.com/docs/setup/linux#_debian-and-ubuntu-based-distributions

</details>

<details>
   <summary>Fedora 33 or newer</summary>

```bash
sudo dnf install ninja-build SFML-devel libXi-devel libX11-devel libXrandr-devel mesa-libGL-devel systemd-devel
```

* Install VS Code: https://code.visualstudio.com/#alt-downloads
* https://code.visualstudio.com/docs/setup/linux#_rhel-fedora-and-centos-based-distributions

</details>

<details>
   <summary>FreeBSD 12 or newer</summary>

```bash
sudo pkg install catch cmake libfmt ninja sfml
```

Install VS Code

```bash
sudo pkg install vscode
```

</details>

### Build

<details>
   <summary>VS Code</summary>

```bash
git clone https://github.com/mod-cpp/pacman.git
cd pacman
code .
```

* You will get a popup in the lower right hand corner asking "Do you want to install
  the recommended extensions for C++?" - click Install

</details>

<details>
   <summary>Commandline</summary>

```bash
git clone https://github.com/mod-cpp/pacman.git
cd pacman
cmake -B build
cmake --build build
ctest --test-dir build -C Debug
```

</details>

<details>
   <summary>CLion</summary>

* When opening the project in CLion use the CMake preset for your platform - see popup
  in the lower right-hand corner
* Unselect the "Debug" profile
* Select for example the preset profile called "windows-build" if you are on Windows
* Enable it by checking the checkbox "Enable profile"
* Click "Apply" and "OK"
* (If CLion created a `cmake-build-debug` folder you can safely delete it, we will be
  using the `build` directory)

</details>

### Troubleshoot

<details>
   <summary>All</summary>

After installing the build tools, you may have to reboot your IDE and/or your Linux
session if you encounter any errors such as Ninja not being found by VSCode.

</details>

<details>
   <summary>Arch Linux</summary>

If there are opengl driver errors, try running in software mode

</details>

<details>
   <summary>Windows</summary>

If you have issues with using VSCode, start it from the "Developer Command Prompt for
VS 2022"

</details>

## [Exercise 111][1]

### Enable a test and make it green

* Catch2 : [Special Tags][3]

<details>
   <summary>Solution</summary>

```cpp
TEST_CASE("Exercise 111 : Enable a test and make it green", "[11]") {
  REQUIRE(true == true);
}
```

</details>

## [Exercise 112][1]

### Make both asserts run (distinguish between REQUIRE and CHECK in Catch2)

* Catch2 : [Assertion Macros][2]

<details>
   <summary>Solution</summary>

```cpp
TEST_CASE("Exercise 112 : Make both asserts run (distinguish between REQUIRE and CHECK in Catch2)", "[11]") {
  CHECK(true == true);
  CHECK(true == true);
}
```

</details>

[1]: 11_exercises.cpp
[2]: https://github.com/catchorg/Catch2/blob/v2.x/docs/assertions.md
[3]: https://github.com/catchorg/Catch2/blob/v2.x/docs/test-cases-and-sections.md#special-tags
[4]: https://code.visualstudio.com/docs/setup/mac#_launching-from-the-command-line
