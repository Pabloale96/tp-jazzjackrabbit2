cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(jazzJackrabbit2)

# Find the yaml-cpp library
find_package(yaml-cpp REQUIRED)

# Set up SDL2pp library
set(SDL2PP_WITH_IMAGE YES)
set(SDL2PP_WITH_TTF YES)
add_subdirectory(SDL2pp)

# Add compilation flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -pedantic-errors -O0 -ggdb -DDEBUG -fno-inline -D _POSIX_C_SOURCE=200809L")

add_definitions(-DIMG_PATH="${PROJECT_SOURCE_DIR}/img")
include_directories(${SDL2PP_INCLUDE_DIRS})

message("[INFO] La raiz del proyecto es ${PROJECT_SOURCE_DIR}")

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/client_src/gui)
include_directories(${PROJECT_SOURCE_DIR}/include/server_src/game)
include_directories(${PROJECT_SOURCE_DIR}/include/common_src/catedra)
include_directories(${PROJECT_SOURCE_DIR}/include/common_src)
include_directories(${PROJECT_SOURCE_DIR}/include/client_src)
include_directories(${PROJECT_SOURCE_DIR}/include/server_src)
include_directories(${PROJECT_BINARY_DIR}/include)

# Add executable for the client
add_executable(client
  src/client_src/client.cpp
  src/client_src/game_state_client.cpp
  src/client_src/gui/gui.cpp
  src/client_src/main.cpp
  src/common_src/vector_monitor.cpp
  src/client_src/client_protocol.cpp
  src/client_src/client_receiver.cpp
  src/client_src/client_sender.cpp
  src/common_src/catedra/liberror.cpp
  src/common_src/catedra/resolver.cpp
  src/common_src/catedra/resolvererror.cpp
  src/common_src/catedra/sockets.cpp
  src/client_src/gui/gui_animaciones.cpp
  src/client_src/gui/gui_keyhandler.cpp
  src/client_src/gui/gui_escenario.cpp
  src/client_src/gui/gui_personaje.cpp
  src/client_src/gui/gui_balas.cpp
  src/client_src/gui/gui_vida.cpp
  src/client_src/gui/gui_coleccionables.cpp
  src/client_src/gui/gui_clase_texturas.cpp
  src/client_src/gui/gui_enemigos.cpp
  src/client_src/gui/gui_frame.cpp
  src/client_src/gui/gui_platform.cpp
  ${UIS_HEADERS})

# Add executable for the server
add_executable(server
  src/server_src/lobby.cpp
  src/server_src/cliente_aceptado.cpp
  src/server_src/server_aceptador.cpp
  src/server_src/server.cpp
  src/server_src/yaml_config.cpp
  src/server_src/game/game_arma.cpp
  src/server_src/game/game_class.cpp
  src/server_src/game/game_comandos.cpp
  src/server_src/game/game_enemigo.cpp
  src/server_src/game/game_escenario.cpp
  src/server_src/game/game_personaje.cpp
  src/server_src/game/game_velocidad.cpp
  src/server_src/game/game_municion.cpp
  src/server_src/game/game_posicion.cpp
  src/server_src/game/game_platform.cpp
  src/server_src/game/game_state_monitor.cpp
  src/server_src/game/game_state.cpp
  src/server_src/game/gameloop_class.cpp
  src/server_src/game/gameloop_monitor.cpp
  src/server_src/server_protocol.cpp
  src/server_src/server_receiver.cpp
  src/server_src/server_sender.cpp
  src/common_src/catedra/liberror.cpp
  src/common_src/catedra/resolver.cpp
  src/common_src/catedra/resolvererror.cpp
  src/common_src/catedra/sockets.cpp
  src/common_src/vector_monitor.cpp
  src/server_src/main.cpp
  ${UIS_HEADERS})

# Add Google Test and Google Mock
# Clonar Google Test y Google Mock si no están ya clonados
if(NOT EXISTS ${CMAKE_BINARY_DIR}/googletest)
  message(STATUS "Cloning GoogleTest and GoogleMock...")
  execute_process(COMMAND git clone https://github.com/google/googletest.git googletest
                  WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

# Construir Google Test
add_subdirectory(${CMAKE_BINARY_DIR}/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add executable for tests
add_executable(protocol_server_test
  tests/protocol_server_test.cpp
  src/server_src/lobby.cpp
  src/server_src/cliente_aceptado.cpp
  src/server_src/server_aceptador.cpp
  src/server_src/server.cpp
  src/server_src/yaml_config.cpp
  src/server_src/game/game_arma.cpp
  src/server_src/game/game_class.cpp
  src/server_src/game/game_comandos.cpp
  src/server_src/game/game_enemigo.cpp
  src/server_src/game/game_escenario.cpp
  src/server_src/game/game_personaje.cpp
  src/server_src/game/game_velocidad.cpp
  src/server_src/game/game_municion.cpp
  src/server_src/game/game_posicion.cpp
  src/server_src/game/game_platform.cpp
  src/server_src/game/game_state_monitor.cpp
  src/server_src/game/game_state.cpp
  src/server_src/game/gameloop_class.cpp
  src/server_src/game/gameloop_monitor.cpp
  src/server_src/server_protocol.cpp
  src/server_src/server_receiver.cpp
  src/server_src/server_sender.cpp
  src/common_src/catedra/liberror.cpp
  src/common_src/catedra/resolver.cpp
  src/common_src/catedra/resolvererror.cpp
  src/common_src/catedra/sockets.cpp
  src/common_src/vector_monitor.cpp
  ${UIS_HEADERS})

add_executable(test_consola_cliente
  tests/test_consola_cliente.cpp
  src/client_src/client.cpp
  src/client_src/game_state_client.cpp
  src/client_src/gui/gui.cpp
  src/common_src/vector_monitor.cpp
  src/client_src/client_protocol.cpp
  src/client_src/client_receiver.cpp
  src/client_src/client_sender.cpp
  src/common_src/catedra/liberror.cpp
  src/common_src/catedra/resolver.cpp
  src/common_src/catedra/resolvererror.cpp
  src/common_src/catedra/sockets.cpp
  src/client_src/gui/gui_animaciones.cpp
  src/client_src/gui/gui_keyhandler.cpp
  src/client_src/gui/gui_escenario.cpp
  src/client_src/gui/gui_personaje.cpp
  src/client_src/gui/gui_balas.cpp
  src/client_src/gui/gui_vida.cpp
  src/client_src/gui/gui_coleccionables.cpp
  src/client_src/gui/gui_clase_texturas.cpp
  src/client_src/gui/gui_enemigos.cpp
  src/client_src/gui/gui_frame.cpp
  src/client_src/gui/gui_platform.cpp
  ${UIS_HEADERS})

# Link libraries to executables
target_link_libraries(client PUBLIC SDL2pp)
target_link_libraries(server PUBLIC yaml-cpp::yaml-cpp)
target_link_libraries(protocol_server_test PUBLIC yaml-cpp::yaml-cpp gtest pthread)
target_link_libraries(test_consola_cliente PUBLIC gtest pthread SDL2pp)

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
install(TARGETS client server protocol_server_test test_consola_cliente
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/img DESTINATION share/${CPACK_PACKAGE_NAME})
install(FILES ${PROJECT_SOURCE_DIR}/config/config.yaml DESTINATION etc/${CPACK_PACKAGE_NAME})
