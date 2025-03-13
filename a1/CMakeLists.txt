cmake_minimum_required(VERSION 3.10)
project(a1)

#set(EXECUTABLES
#    bangme/a1/infinit.c
#    bangme/a1/limit.c
#    bangme/a1/celsius2fahr.c
#    bangme/a1/fahr2celsius.c
#    bangme/a1/charNumber.c
#    bangme/a1/triangle.c
#    bangme/a1/arithmetics.c
#    bangme/a1/literal.c
#    bangme/a1/genderRatio.c
#    bangme/a1/compare.c
#    bangme/a1/compare2.c
#    bangme/a1/sizeof.c
#    bangme/a1/oddeven.c
#    bangme/a1/fourBit.c
#    bangme/a1/fourBit2.c
#    )
file(GLOB EXCUTABLES "/home/bangme/bangme/a1/*.c")

foreach(EXECUTABLE ${EXCUTABLES})
    get_filename_component(EXE_NAME ${EXECUTABLE} NAME_WE)
    add_executable(${EXE_NAME} ${EXECUTABLE})