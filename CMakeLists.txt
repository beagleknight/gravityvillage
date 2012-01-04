# Project name
project(GravityVillage)

# Minimum version required
cmake_minimum_required(VERSION 2.8)

set(CMAKE_BUILD_TYPE Debug)

set(COMMON_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
set(COMMON_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")

include_directories("include")

add_library(timer SHARED src/Timer.cpp)
add_library(texture SHARED src/Texture.cpp)
add_library(sprite SHARED src/Sprite.cpp)
add_library(tile_map SHARED src/TileMap.cpp)
add_library(player SHARED src/Player.cpp)
add_library(item SHARED src/Item.cpp)
add_library(enemy SHARED src/Enemy.cpp)
add_library(game SHARED src/Game.cpp)
add_executable(main src/main.cpp)

target_link_libraries(main timer)
target_link_libraries(main texture)
target_link_libraries(main sprite)
target_link_libraries(main tile_map)
target_link_libraries(main player)
target_link_libraries(main item)
target_link_libraries(main enemy)
target_link_libraries(main game)
target_link_libraries(main glut)
target_link_libraries(main GLU)
target_link_libraries(main corona)
