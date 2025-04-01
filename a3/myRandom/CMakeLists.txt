cmake_minimum_required(VERSION 3.10)
project(myRandom)

set(SOURCES 
    main.c 
    myRandom.c
    )

add_executable(myRandom ${SOURCES})