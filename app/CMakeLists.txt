﻿# CMakeList.txt : CMake project for ConsooleGame, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)


include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
 SFML
 GIT_REPOSITORY https://github.com/SFML/SFML.git
)
FetchContent_MakeAvailable(SFML)

# Add source to this project's executable.
add_executable (${PROJECT_NAME})

target_sources(
    ${PROJECT_NAME}
    PUBLIC
    src/main.cpp
    src/scene/player.h
    src/scene/player.cpp
    src/scene/scene.h
    src/scene/scene.cpp
    src/scene/item/iitem.h
    src/scene/item/point.h
    src/scene/item/bitcoin.h
    src/scene/item/bitcoin.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    sfml-graphics
    sfml-system
    sfml-window
)