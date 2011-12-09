# Project name
project(GravityVillage)

# Minimum version required
cmake_minimum_required(VERSION 2.8)

SET(CMAKE_BUILD_TYPE Debug)

SET(COMMON_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
SET(COMMON_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/libs")

add_subdirectory(src)
add_subdirectory(src/include)

# -------------------------
