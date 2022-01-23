add_library(
    HttpListener
        include/HttpListener.hpp
        src/HttpListener.cpp
)

target_include_directories(
    HttpListener
        PUBLIC
        include/
)

target_link_libraries(
    HttpListener
        PUBLIC
        ziapi
)
