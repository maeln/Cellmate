cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME Cellmate)
set(BINARY_NAME cellmate)

project(${PROJECT_NAME})

set (${PROJECT_NAME}_VERSION_MAJOR 1)
set (${PROJECT_NAME}_VERSION_MINOR 0)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

add_executable(../${BINARY_NAME} src/cellmate.cxx)

target_link_libraries(
  ../${BINARY_NAME}
  sfml-graphics
  sfml-window
  sfml-system
)
