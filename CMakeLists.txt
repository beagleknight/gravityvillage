# Project name
project(GravityVillage)

# Minimum version required
cmake_minimum_required(VERSION 2.8)

SET(CMAKE_BUILD_TYPE Debug)

# A warning appeared because cmake must look for cppunit.
# The warning told me to add this :
if(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

SET(COMMON_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
SET(COMMON_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")

ADD_EXECUTABLE(main src/main.cpp)

TARGET_LINK_LIBRARIES(main glut)

#
#ADD_LIBRARY(Scene STATIC Scene.cpp)
#ADD_LIBRARY(SceneManager STATIC SceneManager.cpp)
#ADD_LIBRARY(Texture STATIC Texture.cpp)
#ADD_LIBRARY(TextureManager STATIC TextureManager.cpp)
#ADD_LIBRARY(Game STATIC Game.cpp)
#ADD_EXECUTABLE(main main.cpp)
#
#TARGET_LINK_LIBRARIES(main Game)
#TARGET_LINK_LIBRARIES(main SceneManager)
#TARGET_LINK_LIBRARIES(main TextureManager)
#TARGET_LINK_LIBRARIES(main Scene)
#TARGET_LINK_LIBRARIES(main Texture)
#TARGET_LINK_LIBRARIES(main GLU)
#TARGET_LINK_LIBRARIES(main corona)
#
#ADD_LIBRARY(GameTest STATIC test/GameTest.cpp)

#
#TARGET_LINK_LIBRARIES(test cppunit)
