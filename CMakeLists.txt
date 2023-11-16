cmake_minimum_required(VERSION 3.26.4)
project(Final-Project-OOP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(SrcFile
        src/include
        src/main.cpp
        src/GameObject/GameObject.cpp
        src/GameObject/GameObject.h
        src/GameObject/Entity/Entity.cpp
        src/GameObject/Entity/Entity.h
        src/GameObject/Entity/Character/Character.cpp
        src/GameObject/Entity/Character/Character.h
        src/GameObject/Items/Items.cpp
        src/GameObject/Items/Items.h
        src/AreaObject.cpp
        src/AreaObject.h
        src/Game.cpp
        src/Game.h
)
add_executable(Final-Project-OOP ${SrcFile})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "app")