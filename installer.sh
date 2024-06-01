#!/bin/bash

echo "Corriendo instalador..."

# Actualizando índice de paquetes
echo "Instalando dependencias..."
sudo apt-get update

# Instalando dependencias necesarias
sudo apt-get install -y git cmake build-essential libasound2-dev libpulse-dev libaudio-dev \
    libx11-dev libxext-dev libxrandr-dev libxcursor-dev libxi-dev libxinerama-dev \
    libxxf86vm-dev libxss-dev libgl1-mesa-dev libesd0-dev libdbus-1-dev fcitx-libs-dev \
    libudev-dev libgles2-mesa-dev libegl1-mesa-dev libibus-1.0-dev qt5-default \
    libsdl2-image-dev libsdl2-mixer-dev libyaml-cpp-dev

# Clonando y compilando SDL
echo "Clonando SDL..."
git clone https://github.com/libsdl-org/SDL.git --branch release-2.26.5
cd SDL
mkdir build
cd build
cmake ..
make
sudo make install
cd ../..

git clone --branch release-2.6.3 https://github.com/libsdl-org/SDL_image.git
cd SDL_image
git checkout SDL2
mkdir build
cd build
cmake ..
make
sudo make install
cd ../..

git clone --branch release-2.6.3 https://github.com/libsdl-org/SDL_mixer.git
cd SDL_mixer
git checkout SDL2
mkdir build
cd build
make
sudo make install
cd ../..


git clone --branch release-2.20.2 https://github.com/libsdl-org/SDL_ttf.git
cd SDL_ttf
git checkout SDL2
mkdir build
cd build
make
sudo make install
cd ../..


git clone https://github.com/libSDL2pp/libSDL2pp.git --branch 0.18.1
cd libSDL2pp
mkdir build
cd build
make
sudo make install
cd ../..

# Configurando y compilando el proyecto jazzJackrabbit2
echo "Configurando y compilando jazzJackrabbit2..."
mkdir -p build
cd build
cmake ..
make

echo "Instalación completada
