cmake_minimum_required(VERSION 3.10)
project(date)

set(SOURCES 
    main.c 
    date.c
    )

add_executable(date ${SOURCES})