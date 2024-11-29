cmake_minimum_required(VERSION 3.31.1)
set(PROJECT_NAME black)
project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} source/main.c source/entity.c)
include(FetchContent)
set(RAYLIB_VERSION 5.5)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS ${RAYLIB_VERSION} EXACT
)
set (BUILD_EXAMPLES OFF CASHE INTERNAL "")
FetchContent_MakeAvailable(raylib)
target_link_libraries(${PROJECT_NAME} raylib)
