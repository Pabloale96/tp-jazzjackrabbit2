# SDL2pp tutorial
#
# Written in 2015 by Dmitry Marakasiv <amdmi3@amdmi3.ru>
#
# To the extent possible under law, the author(s) have dedicated all copyright
# and related and neighboring rights to this software to the public domain
# worldwide. This software is distributed without any warranty.
#
# You should have received a copy of the CC0 Public Domain Dedication along with
# this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.

cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(SDL2pp-tutorial LANGUAGES CXX)
project(qt5-demo)

# Find the QtWidgets library
find_package(Qt5Widgets)

# set up SDL2pp library
set(SDL2PP_WITH_IMAGE YES)
set(SDL2PP_WITH_TTF YES)
add_subdirectory(SDL2pp)

# add compilation flags
set(CMAKE_CXX_STANDARD 17)
add_definitions(-DIMG_PATH="${PROJECT_SOURCE_DIR}/img")
include_directories(${SDL2PP_INCLUDE_DIRS})

message("[INFO] La raiz del proyecto es ${PROJECT_SOURCE_DIR}")

# Agrego ej3/include a la lista de directorios de includes
include_directories(${PROJECT_SOURCE_DIR}/include)

# Esta macro toma cada uno los parámetros y ejecuta *uic* sobre ellos
# La aplicacion uic genera headers con la definición de los widgets
# a partir de un archivo .ui
# Los nombres de los headers generados se guardan en la variable pasada
# como primer parámetro.
# No, no los genera con la carpeta como prefijo.
qt5_wrap_ui(UIS_HEADERS
        ui/Greeter.ui
)

# Agrego la carpeta con los headers autogenerados a los includes
message("Agregando '${PROJECT_BINARY_DIR}' como directorio de includes")
include_directories(${PROJECT_BINARY_DIR})

message("Headers generados: ${UIS_HEADERS}")

add_executable(gui
  src/greeter.cpp
  src/gui.cpp
  src/main.cpp
  src/elements/animaciones.cpp
  src/elements/escenario.cpp
  src/elements/personaje.cpp
  src/elements/enemigos.cpp
  src/elements/frame.cpp
  ${UIS_HEADERS})

# Use the Widgets module from Qt 5.
target_link_libraries(gui PUBLIC Qt5::Widgets SDL2pp)
