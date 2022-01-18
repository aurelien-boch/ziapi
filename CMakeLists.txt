cmake_minimum_required(VERSION 3.17)
project(ZIAPI CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(ziapi INTERFACE)

target_sources(
    ziapi
        INTERFACE
        Placeholder.hpp
)

target_include_directories(
    ziapi
        INTERFACE
        include/
)
