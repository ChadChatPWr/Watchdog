cmake_minimum_required(VERSION 3.23)  

set(This watchdog)

project(${This} C CXX)   

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)            

enable_testing()

add_subdirectory(googletest)

set(Headers
    watchdog.h
)

set(Sourses
    main.cpp
    watchdog.cpp
)


add_library(${This} ${Sourses} ${Headers})

add_subdirectory(test)