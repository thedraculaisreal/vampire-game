cmake_minimum_required(VERSION 3.31.1)
project(black C)
include_directories(~/projects/libs/raylib/src/)
add_executable(executable source/main.c source/entity.c)
