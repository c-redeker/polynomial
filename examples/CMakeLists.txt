set(EXEC_NAME path_generation)
add_executable(${EXEC_NAME} path_generation.cpp)
target_link_libraries(${EXEC_NAME} polynomial)
