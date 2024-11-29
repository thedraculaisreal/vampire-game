cmake_minimum_required(VERSION 3.31.1)
project(first_proj C)
file(GLOB MAIN "main.c")
add_executable(executable ${MAIN})
