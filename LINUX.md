[< Back](README.md)
# Mod(C++) Linux (Ubuntu) Instructions

## Get Clion

https://www.jetbrains.com/clion/download/download-thanks.html

## Get Python 3

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
