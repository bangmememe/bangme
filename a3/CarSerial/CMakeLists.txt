cmake_minimum_required(VERSION 3.10)
project(CarSeiral)

# include_directories((${CMAKE_CURRENT_LIST_DIR}/include)) # 필요한 폴더가 있을때 쓰는것
set(SOURCES 
    main.c 
    serial.c
    )

add_executable(CarSeiral ${SOURCES})