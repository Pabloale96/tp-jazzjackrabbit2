# cmake_minimum_required(VERSION 3.10)
# project(protocol_server_test)

# # Locate GTest
# find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIRS})

# # Locate GMock
# find_package(GMock REQUIRED)
# include_directories(${GMOCK_INCLUDE_DIRS})

# add_executable(protocol_server_test
#     tests/protocol_server_test.cpp
#     ../src/server_src/server_protocol.cpp
#     ../src/common_src/catedra/sockets.cpp
#     ../src/common_src/catedra/resolver.cpp
#     ../src/common_src/catedra/resolvererror.cpp
#     ../src/common_src/catedra/liberror.cpp
# )

# # Link GTest and GMock to the test executable
# target_link_libraries(protocol_server_test
#     ${GTEST_LIBRARIES}
#     ${GMOCK_LIBRARIES}
#     pthread
# )

# target_link_libraries(test_consola_cliente 
#     ${GTEST_LIBRARIES} 
#     ${GMOCK_LIBRARIES} 
#     pthread
#     SDL2pp::SDL2pp
# )

# # # Add the test executable
# # add_executable(protocol_server_test 
# #     protocol_server_test.cpp 
# #     ../src/server_src/server_protocol.cpp 
# #     ../src/common_src/catedra/sockets.cpp
# # )

# # add_executable(test_consola_cliente 
# #     test_consola_client.cpp 
# #     ../src/client_src/client_protocol.cpp 
# #     ../src/common_src/catedra/sockets.cpp
# # )


