cmake_minimum_required(VERSION 3.26)
project(LightMonitor)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        cpu_load_monitor.cpp
        cpu_softirq_monitor.cpp
        cpu_stat_monitor.cpp
        mem_monitor.cpp
        net_monitor.cpp
        utils.cpp
)

add_library(monitor SHARED ${SOURCES})
