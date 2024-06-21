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

# Clonar y compilar yaml-cpp
git clone https://github.com/jbeder/yaml-cpp.git
cd ~/yaml-cpp
mkdir build
cd build
cmake ..
make -j$(nproc)
sudo make install

# Crear directorio para el código fuente de SDL2
mkdir ~/sdl2-src
cd ~/sdl2-src

# Clonar y compilar SDL2
git clone https://github.com/libsdl-org/SDL.git --branch release-2.30.4
cd SDL
mkdir build
cd build
cmake ..
make -j$(nproc)
sudo make install

# Clonar y compilar SDL2_mixer
cd ~/sdl2-src
git clone https://github.com/libsdl-org/SDL_mixer.git --branch release-2.8.0
cd SDL_mixer
mkdir build
cd build
cmake ..
make -j$(nproc)
sudo make install

# Clonar y compilar SDL2_ttf
cd ~/sdl2-src
git clone https://github.com/libsdl-org/SDL_ttf.git --branch release-2.22.0
cd SDL_ttf
mkdir build
cd build
cmake ..
make -j$(nproc)
sudo make install

# Clonar y compilar SDL2_image
cd ~/sdl2-src
git clone https://github.com/libsdl-org/SDL_image.git --branch release-2.8.2
cd SDL_image
mkdir build
cd build
cmake ..
make -j$(nproc)
sudo make install

# Limpiar
cd ~
rm -rf ~/sdl2-src
rm -rf ~/yaml-cpp

# Actualizar las vinculaciones de tiempo de ejecución del enlazador dinámico
sudo ldconfig

# Instalar Google Test y Google Mock
echo "Instalando Google Test y Google Mock..."
sudo apt-get install -y libgtest-dev libgmock-dev
cd /usr/src/gtest
sudo cmake .
sudo make
sudo cp *.a /usr/lib

cd /usr/src/gmock
sudo cmake .
sudo make
sudo cp *.a /usr/lib

# Configurar y compilar el proyecto jazzJackrabbit2
echo "Configurando y compilando jazzJackrabbit2..."
cd ~/tp-jazzjackrabbit2  # Cambia este directorio al correcto

mkdir -p build
cd build
cmake ..
make

# Compilar y ejecutar pruebas
echo "Compilando y ejecutando pruebas unitarias..."
cd ~/tp-jazzjackrabbit2/test/gtest.cpp
mkdir -p build
cd build
cmake ..
make
./protocol_server_test  # Ejecuta las pruebas unitarias

echo "Instalación completa"
