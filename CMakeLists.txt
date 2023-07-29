cmake_minimum_required(VERSION 3.21)  

project(watchdog) 

set(CMAKE_CXX_FLAGS "\
    -O2\
    -Wall\
    -Wextra\
    -Wunused\
    -Wno-error=maybe-uninitialized\
    -Wcast-align\
    -Winvalid-pch\
    -Wmissing-include-dirs\
")  

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 14)  
set(CMAKE_CXX_STANDARD_REQUIRED ON)          

set(HEADER_FILES
    include/watchdog.h
    include/component.h
    include/deathManager.h
    include/lifeMonitor.h
)

set(SOURCE_FILES
    src/main.cpp
    src/watchdog.cpp
    src/component.cpp
    src/deathManager.cpp
    src/lifeMonitor.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/deploy)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC include)
