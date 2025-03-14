cmake_minimum_required(VERSION 3.10)
project(MainProject)

# 내부 CMakeLists.txt 포함
# include(sqlQurry/CMakeLists.txt)
# include(a3/CMakeLists.txt)
# include(a1/CMakeLists.txt)

add_subdirectory(sqlQurry)
add_subdirectory(a1)
add_subdirectory(a2)
add_subdirectory(a3)