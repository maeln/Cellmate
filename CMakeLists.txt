cmake_minimum_required(VERSION 3.5)
project(Cellmate)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/cellmate.cxx
    src/world.cxx
    src/world.hxx)

add_executable(Cellmate ${SOURCE_FILES})

target_link_libraries(
        Cellmate
        sfml-graphics
        sfml-window
        sfml-system
)