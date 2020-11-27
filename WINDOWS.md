[< Back](README.md)
# Mod(C++) Windows Instructions

## Windows Toolchain

Visual Studio Community 2019 - latest (MSVC 19.28.29334.0)

## Get Clion

https://www.jetbrains.com/clion/download/download-thanks.html

## Get Python 3

https://docs.python.org/3/using/windows.html#the-full-installer

## Get Conan

pip3 install conan --upgrade

## Currently does not work on windows - Get Clang

Clang 10 works seamlessly with Conan (version 1.31.4) - with 11 you have to update your 
<userhome>/.conan/settings.yml file, add "11" to the list at "clang: version:"

https://releases.llvm.org/download.html
https://www.jetbrains.com/help/clion/quick-tutorial-on-configuring-clion-on-windows.html#clang-cl
