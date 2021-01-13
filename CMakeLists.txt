PROJECT(polynomial)
cmake_minimum_required(VERSION 3.2)

include(GNUInstallDirs)

set(CMAKE_CXX_FLAGS "-g -O0 -Wall -Wextra -Werror -Wreturn-type -std=c++14 -pthread -fprofile-arcs -ftest-coverage")

set(LIBRARY_NAME ${PROJECT_NAME})
add_library(${LIBRARY_NAME} INTERFACE)
target_include_directories(${LIBRARY_NAME} INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

if(BUILD_TESTS)
    find_package(GTest REQUIRED)
    enable_testing()
    add_subdirectory(test)
endif()
