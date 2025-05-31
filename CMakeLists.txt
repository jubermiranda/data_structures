cmake_minimum_required(VERSION 3.14)
project(my_ds)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_PROJECT "Build the main project" OFF)
option(BUILD_TESTS "Build project tests (with gtest)" ON)

enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/list)
include_directories(${CMAKE_SOURCE_DIR}/include/vector)
include_directories(${CMAKE_SOURCE_DIR}/include/list_iter)
include_directories(${CMAKE_SOURCE_DIR}/include/stack)

if(BUILD_PROJECT)
    add_executable(
        my_ds
        src/template.cxx
    )
endif(BUILD_PROJECT)


if(BUILD_TESTS)
    add_subdirectory(tests)
    add_test(NAME test_my_ds COMMAND test_my_ds)
endif(BUILD_TESTS)
