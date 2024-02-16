cmake_minimum_required(VERSION 3.26)
project(tests)

set(CMAKE_CXX_STANDARD 17)
set(LIBS
        monitor
        monitor_proto
)

add_executable(test_monitor monitor_test.cpp)
target_link_libraries(test_monitor ${LIBS})