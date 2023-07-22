cmake_minimum_required(VERSION 3.23)  

set(This ExampleTests)


set(Sourses
    ExampleTests.cpp
)


add_executable(${This} ${Sourses})
target_link_libraries(${This} PUBLIC
    gtest_main
    Example
)

add_test(
    NAME ${This}
    COMMAND ${This}
)