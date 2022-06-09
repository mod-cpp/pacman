#!/bin/bash
set -e

#  bash <(curl -s https://raw.githubusercontent.com/mod-cpp/pacman/main/dev/ubuntu.sh)

# install VSCode according to https://code.visualstudio.com/docs/setup/linux
sudo apt-get install -y wget gpg
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
sudo install -o root -g root -m 644 packages.microsoft.gpg /etc/apt/trusted.gpg.d/
sudo sh -c 'echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/trusted.gpg.d/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" > /etc/apt/sources.list.d/vscode.list'
rm -f packages.microsoft.gpg

sudo apt install -y apt-transport-https
sudo apt update
sudo apt install -y code

# PacMan deps
sudo apt install -y \
build-essential \
clang-12 \
cmake \
g++-10 \
git \
libgl1-mesa-dev \
libudev-dev \
libx11-dev \
libxi-dev \
libxrandr-dev \
ninja-build \
pkg-config \
tar \
unzip \
zip
