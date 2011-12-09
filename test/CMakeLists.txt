include_directories(${CMAKE_SOURCE_DIR}/src/include include)

ADD_LIBRARY(game_test SHARED GameTest.cpp)
SET_TARGET_PROPERTIES(game_test PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${COMMON_LIBRARY_OUTPUT_DIRECTORY}")

install_targets(/lib game_test)

add_executable(test test.cpp)
SET_TARGET_PROPERTIES(test PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${COMMON_RUNTIME_OUTPUT_DIRECTORY}")

ADD_CUSTOM_COMMAND(TARGET test POST_BUILD COMMAND "${COMMON_RUNTIME_OUTPUT_DIRECTORY}/test")
ADD_CUSTOM_TARGET(tests "${COMMON_RUNTIME_OUTPUT_DIRECTORY}/test" DEPENDS test COMMENT "Running CPPUNIT tests...")

target_link_libraries(test game_test) 
TARGET_LINK_LIBRARIES(test scene)
TARGET_LINK_LIBRARIES(test game)
TARGET_LINK_LIBRARIES(test scene_manager)
TARGET_LINK_LIBRARIES(test texture_manager)
TARGET_LINK_LIBRARIES(test texture)
TARGET_LINK_LIBRARIES(test glut)
TARGET_LINK_LIBRARIES(test GLU)
TARGET_LINK_LIBRARIES(test corona)
target_link_libraries(test cppunit) 

install_programs(/bin FILES test)
