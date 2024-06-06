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
    
sudo apt install -y build-essential cmake git libasound2-dev libpulse-dev libaudio-dev \
                    libx11-dev libxext-dev libxrandr-dev libxcursor-dev libxi-dev \
                    libxinerama-dev libxxf86vm-dev libgl1-mesa-dev libdbus-1-dev \
                    libudev-dev libgles2-mesa-dev libwayland-dev wayland-protocols \
                    libxkbcommon-dev libdrm-dev libgbm-dev libjpeg-dev libpng-dev \
                    libtiff-dev libwebp-dev libfreetype6-dev libfluidsynth-dev \
                    libmodplug-dev libvorbis-dev libmpg123-dev libopusfile-dev

# Create a directory for the SDL2 source code
mkdir ~/sdl2-src
cd ~/sdl2-src

# Clone SDL2 repository
git clone https://github.com/libsdl-org/SDL.git
cd SDL
mkdir build
cd build
cmake ..
make -j$(nproc)
sudo make install

# Clone SDL2_mixer repository
cd ~/sdl2-src
git clone https://github.com/libsdl-org/SDL_mixer.git
cd SDL_mixer
mkdir build
cd build
cmake ..
make -j$(nproc)
sudo make install

# Clone SDL2_ttf repository
cd ~/sdl2-src
git clone https://github.com/libsdl-org/SDL_ttf.git
cd SDL_ttf
mkdir build
cd build
cmake ..
make -j$(nproc)
sudo make install

# Clone SDL2_image repository
cd ~/sdl2-src
git clone https://github.com/libsdl-org/SDL_image.git
cd SDL_image
mkdir build
cd build
cmake ..
make -j$(nproc)
sudo make install

# Clean up
cd ~
rm -rf ~/sdl2-src

# Update the dynamic linker run-time bindings
sudo ldconfig

# Configurando y compilando el proyecto jazzJackrabbit2
echo "Configurando y compilando jazzJackrabbit2..."
mkdir -p build
cd build
cmake ..
make

echo "Instalación completada