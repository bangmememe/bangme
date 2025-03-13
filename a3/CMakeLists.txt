cmake_minimum_required(VERSION 3.10)
project(a3)

set(CMAKE_C_COMPILER "/usr/bin/gcc")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB EXCUTABLES "a3/*.c")

foreach(EXCUTABLE ${EXCUTANLES})
    get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)
    add_executable(${EXE_NAME} ${EXCUTANLE})
endforeach()