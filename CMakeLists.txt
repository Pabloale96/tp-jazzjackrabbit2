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

# Agrego la carpeta con los headers autogenerados a los includes
message("Agregando '${PROJECT_BINARY_DIR}' como directorio de includes")
include_directories(${PROJECT_BINARY_DIR}/include)

message("Headers generados: ${UIS_HEADERS}")

add_executable(client
  src/client_src/client.cpp
  src/client_src/game_respuesta.cpp
  src/client_src/gui.cpp
  src/client_src/main.cpp
  src/client_src/client_protocol.cpp
  src/client_src/client_receiver.cpp
  src/client_src/client_sender.cpp
  src/common_src/liberror.cpp
  src/common_src/resolver.cpp
  src/common_src/resolvererror.cpp
  src/common_src/sockets.cpp
  src/elements/animaciones.cpp
  src/elements/escenario.cpp
  src/elements/spaz.cpp
  src/elements/lori.cpp
  src/elements/jazz.cpp
  src/elements/enemigos.cpp
  src/elements/frame.cpp
  src/elements/platform.cpp
  ${UIS_HEADERS})

add_executable(server
  src/server_src/cliente_aceptado.cpp
  src/server_src/server_aceptador.cpp
  src/server_src/server.cpp
  src/server_src/game_arma.cpp
  src/server_src/game_class.cpp
  src/server_src/game_comandos.cpp
  src/server_src/game_enemigo.cpp
  src/server_src/game_personaje.cpp
  src/server_src/game_posicion.cpp
  src/server_src/game_state_monitor.cpp
  src/server_src/game_state.cpp
  src/server_src/gameloop_class.cpp
  src/server_src/gameloop_monitor.cpp
  src/server_src/server_protocol.cpp
  src/server_src/server_receiver.cpp
  src/server_src/server_sender.cpp
  src/common_src/liberror.cpp
  src/common_src/resolver.cpp
  src/common_src/resolvererror.cpp
  src/common_src/sockets.cpp
  src/server_src/main.cpp
  ${UIS_HEADERS})

# Use the Widgets module from Qt 5.
target_link_libraries(client PUBLIC Qt5::Widgets SDL2pp)
#target_link_libraries(server PUBLIC Qt5::Widgets SDL2pp)
