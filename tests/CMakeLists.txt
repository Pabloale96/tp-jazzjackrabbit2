# CMakeLists.txt en el directorio tests
add_executable(protocol_server_test
  protocol_server_test.cpp)

# Link libraries to the test executable
target_link_libraries(protocol_server_test PUBLIC gtest gmock pthread)
