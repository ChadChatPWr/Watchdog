cmake_minimum_required(VERSION 3.23)  
project(watchdog_utest)

set ( CMAKE_VERBOSE_MAKEFILE ON)

set ( CMAKE_CXX_STANDARD 20)
set ( CMAKE_CXX_STANDARD_REQUIRED TRUE)


include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

get_filename_component(PARENT_DIR ${CAMKE_CURRENT_LIST_DIR} DIRECTORY)

set(HEADER_FILES
    ${PARENT_DIR}/include/watchdog.h
    ${PARENT_DIR}/include/component.h
    ${PARENT_DIR}/include/deathManager.h
    ${PARENT_DIR}/include/lifeMonitor.h
)

set(SOURCE_FILES
    ${PARENT_DIR}/src/main.cpp
    ${PARENT_DIR}/src/watchdog.cpp
    ${PARENT_DIR}/src/component.cpp
    ${PARENT_DIR}/src/deathManager.cpp
    ${PARENT_DIR}/src/lifeMonitor.cpp
)

set(MOCK_FILES

)

set(TEST_FILES
    utest/main.cpp
    utest/test.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/deploy)

enable_testing()

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES} ${MOCK_FILES} ${TEST_FILES}) 

target_link_libraries(${PROJECT_NAME} gmonk gtest)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})