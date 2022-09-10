# CMakeList.txt : CMake project for ConsooleGame, include source and define
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

cmake_policy(SET CMP0076 NEW)

# Add source to this project's executable.
add_executable (${PROJECT_NAME})

target_sources(
    ${PROJECT_NAME}
    PUBLIC
    src/main.cpp
    src/model/items/player.h
    src/model/items/player.cpp
    src/model/items/iitem.h
    src/model/point.h
    src/mainwindow.h
    src/mainwindow.cpp
    src/scene/items/player.h
    src/scene/items/player.cpp
    src/scene/items/item.h
    src/scene/items/item.cpp
    src/scene/controller/controller.h
    src/scene/controller/controller.cpp
    src/model/controller/controller.h
    src/model/controller/controller.cpp
    src/utils/utils.h
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    src/
)

target_link_libraries(
    ${PROJECT_NAME}
    sfml-graphics
    sfml-system
    sfml-window
)
