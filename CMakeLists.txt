cmake_minimum_required(VERSION 3.15)

project(Persistence)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(googletest)

# Include Sources
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/source)

enable_testing()

add_subdirectory(source/pointer_machine)

add_executable(persistence
  source/main.cpp
  source/pointer_machine/directed_graph.hpp
  source/persistence/partial_directed_graph.hpp
  )
