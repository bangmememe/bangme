cmake_minimum_required(VERSION 3.10)
project(a1)

# file(GLOB EXECUTABLES "/home/bangme/bangme/a1/*.c")
file(GLOB EXECUTABLES "${CMAKE_CURRENT_LIST_DIR}/*.c")

foreach(EXECUTABLE ${EXECUTABLES})
    get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)
    add_executable(${EXE_NAME} ${EXECUTABLE})
endforeach()