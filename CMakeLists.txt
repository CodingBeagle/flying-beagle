cmake_minimum_required(VERSION 3.15)

# Project declaration
project(
    flying_beagle
    VERSION 0.1.0
    LANGUAGES CXX
)

# Include custom compiler options module
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CompilerOptions.cmake)

# Fetch dependencies
include(FetchContent)

# GLFW - Windowing and input library
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)

FetchContent_MakeAvailable(glfw)

# Set output directories for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Add source subdirectory
add_subdirectory(src)
