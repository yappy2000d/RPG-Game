cmake_minimum_required(VERSION 3.26.4)
project(RPG-Game)

include_directories(SYSTEM src/include)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
include_directories(${PROJECT_SOURCE_DIR}/src/include)
file(GLOB_RECURSE SrcFile ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(RPG-Game ${SrcFile})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "app")
