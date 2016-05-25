cmake_minimum_required(VERSION 2.8)
project(Cellmate)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/cellmate.cxx
        src/World.cxx
        src/WorldRenderer.cxx
        src/angelscript/scriptbuilder/scriptbuilder.cpp
        src/angelscript/scriptstdstring/scriptstdstring.cpp)

link_directories(${CMAKE_SOURCE_DIR}/deps)

add_executable(Cellmate ${SOURCE_FILES})

target_link_libraries(
        Cellmate
        sfml-graphics
        sfml-window
        sfml-system
        angelscript
)