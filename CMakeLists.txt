cmake_minimum_required(VERSION 3.23)  

project(watchdog)   

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
