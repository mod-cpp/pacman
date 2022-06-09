#!/bin/bash
set -e

#  bash <(curl -s https://raw.githubusercontent.com/mod-cpp/pacman/main/dev/ubuntu.sh)

sudo apt update
sudo apt upgrade

# install VSCode according to https://code.visualstudio.com/docs/setup/linux
sudo apt-get install wget gpg
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
sudo install -o root -g root -m 644 packages.microsoft.gpg /etc/apt/trusted.gpg.d/
sudo sh -c 'echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/trusted.gpg.d/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" > /etc/apt/sources.list.d/vscode.list'
rm -f packages.microsoft.gpg

sudo apt install apt-transport-https
sudo apt update
sudo apt install code

# dev
sudo apt install git ninja-build pkg-config curl zip unzip tar cmake build-essential libx11-dev libxrandr-dev libxi-dev libudev-dev libgl1-mesa-dev clang-12 g++-10
