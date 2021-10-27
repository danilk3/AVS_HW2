# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(task LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
    # Headers

        # Sources
        main.cpp
        movie.h fiction.h fiction.cpp rnd.h cartoon.h cartoon.cpp documentary.h documentary.cpp container.h container.cpp)

add_executable(task ${SOURCE_FILES})
