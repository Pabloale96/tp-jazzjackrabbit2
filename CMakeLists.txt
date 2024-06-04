cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(jazzJackrabbit2)

# Find the SDL2pp library
#find_package(SDL2 REQUIRED)
#find_package(SDL2_image REQUIRED)
#find_package(SDL2_mixer REQUIRED)

# Find the yaml-cpp library
#find_package(yaml-cpp REQUIRED)

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

# Agregar subcarpetas a la lista de directorios de includes
include_directories(${PROJECT_SOURCE_DIR}/include/client_src/gui)
include_directories(${PROJECT_SOURCE_DIR}/include/server_src/game)
include_directories(${PROJECT_SOURCE_DIR}/include/common_src)
include_directories(${PROJECT_SOURCE_DIR}/include/client_src)
include_directories(${PROJECT_SOURCE_DIR}/include/server_src)

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
  src/server_src/game/game_personaje.cpp
  src/server_src/game/game_enemigo.cpp
  src/server_src/game/game_arma.cpp
  src/server_src/game/game_posicion.cpp
  src/server_src/game/game_state.cpp
  src/client_src/gui/gui.cpp
  src/client_src/main.cpp
  src/client_src/client_protocol.cpp
  src/client_src/client_receiver.cpp
  src/client_src/client_sender.cpp
  src/common_src/liberror.cpp
  src/common_src/resolver.cpp
  src/common_src/resolvererror.cpp
  src/common_src/sockets.cpp
  src/client_src/gui/gui_animaciones.cpp
  src/client_src/gui/gui_escenario.cpp
  src/client_src/gui/gui_personaje.cpp
  src/client_src/gui/gui_clase_texturas.cpp
  src/client_src/gui/gui_enemigos.cpp
  src/client_src/gui/gui_frame.cpp
  src/client_src/gui/gui_platform.cpp
  ${UIS_HEADERS})

add_executable(server
  src/server_src/cliente_aceptado.cpp
  src/server_src/server_aceptador.cpp
  src/server_src/server.cpp
  src/server_src/game/game_arma.cpp
  src/server_src/game/game_class.cpp
  src/server_src/game/game_comandos.cpp
  src/server_src/game/game_enemigo.cpp
  src/server_src/game/game_personaje.cpp
  src/server_src/game/game_posicion.cpp
  src/server_src/game/game_platform.cpp
  src/server_src/game/game_state_monitor.cpp
  src/server_src/game/game_state.cpp
  src/server_src/game/gameloop_class.cpp
  src/server_src/game/gameloop_monitor.cpp
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
target_link_libraries(client PUBLIC SDL2pp)
#target_link_libraries(server PUBLIC Qt5::Widgets SDL2pp)

# CPack setup
include(CPack)

# Set package properties
set(CPACK_PACKAGE_NAME "JazzJackrabbit2")
set(CPACK_PACKAGE_VENDOR "FIUBA")
set(CPACK_PACKAGE_CONTACT "csebellin@fi.uba.ar")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Jazz Jackrabbit 2 Game")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

# Specify which generator to use
if(WIN32)
    set(CPACK_GENERATOR "NSIS")
elseif(APPLE)
    set(CPACK_GENERATOR "DragNDrop")
elseif(UNIX)
    set(CPACK_GENERATOR "DEB;RPM")
endif()

# Additional settings for NSIS (Windows)
if(CPACK_GENERATOR STREQUAL "NSIS")
    set(CPACK_NSIS_DISPLAY_NAME "${CPACK_PACKAGE_NAME} ${CPACK_PACKAGE_VERSION}")
    set(CPACK_NSIS_PACKAGE_NAME "${CPACK_PACKAGE_NAME}")
    set(CPACK_NSIS_MUI_ICON "${CMAKE_CURRENT_SOURCE_DIR}/icon.ico")
    set(CPACK_NSIS_MUI_UNIICON "${CMAKE_CURRENT_SOURCE_DIR}/icon.ico")
endif()

# Additional settings for DEB (Debian-based Linux)
if(CPACK_GENERATOR STREQUAL "DEB")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name") # required
    set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.27), libgcc1 (>= 1:4.2.1), libstdc++6 (>= 4.2.1)")
endif()

# Additional settings for RPM (RedHat-based Linux)
if(CPACK_GENERATOR STREQUAL "RPM")
    set(CPACK_RPM_PACKAGE_REQUIRES "libc.so.6, libgcc_s.so.1, libstdc++.so.6")
endif()

# Include the install targets
install(TARGETS client server
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/img DESTINATION share/${CPACK_PACKAGE_NAME})
install(FILES ${PROJECT_SOURCE_DIR}/config/config.yaml DESTINATION etc/${CPACK_PACKAGE_NAME})