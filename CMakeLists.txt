cmake_minimum_required(VERSION 3.0.0)
project(task1 LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

# Source files list
set(SOURCE_FILES
    # Headers
    src/procedural.h
    src/object_oriented.h
    src/functional.h
    src/language.h
    src/container.h

    # Sources
    src/procedural.cpp
    src/object_oriented.cpp
    src/functional.cpp
    src/language.cpp
    src/container.cpp
    main.cpp
)

add_executable(task1 ${SOURCE_FILES})

