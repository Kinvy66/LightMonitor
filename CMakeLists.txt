cmake_minimum_required(VERSION 3.26)
project(LightMonitor)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(monitor)
add_subdirectory(proto)
add_subdirectory(tests)

add_executable(LightMonitor main.cpp)
