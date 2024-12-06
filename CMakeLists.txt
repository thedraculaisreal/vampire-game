cmake_minimum_required(VERSION 3.31.1) # min required vers of cmake.
set(PROJECT_NAME black) # project name & executable name
set(SOURCE_FILES source/entity/entity.c source/core/main.c source/core/game.c source/core/rooms.c ) # defining source files
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

#finding and linking with packages.

include(FetchContent)
find_package(X11 REQUIRED)
set(RAYLIB_VERSION 5.5)

# this whole section is for checking to see if raylib exists, if it doesnt it downloads and builds it.

FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS ${RAYLIB_VERSION} EXACT
)
set (BUILD_EXAMPLES OFF CASHE INTERNAL "")
FetchContent_MakeAvailable(raylib)
target_link_libraries(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} ${X11_LIBRARIES})
