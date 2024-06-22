cmake_minimum_required(VERSION 3.10)
project(protocol_server_test)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Locate GMock
find_package(GMock REQUIRED)
include_directories(${GMOCK_INCLUDE_DIRS})

# Add the test executable
add_executable(protocol_server_test protocol_server_test.cpp mock_socket.h)

# Link GTest and GMock to the test executable
target_link_libraries(protocol_server_test ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} pthread)

# Add the main project source files
add_executable(server_protocol ../include/server_src/server_protocol.cpp ../include/common_src/catedra/sockets.cpp)
