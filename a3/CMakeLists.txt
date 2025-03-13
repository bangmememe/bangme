cmake_minimum_required(VERSION 3.10)
project(a3)

file(GLOB EXCUTABLES "/home/bangme/bangme/a3/*.c")

foreach(EXECUTABLE ${EXCUTABLES})
    get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)
    add_executable(${EXE_NAME} ${EXECUTABLE})
endforeach()