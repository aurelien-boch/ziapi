add_library(
    HttpReplySender
        include/HttpReplySender.hpp
        src/HttpReplySender.cpp
)

target_include_directories(
    HttpReplySender
        PUBLIC
        include/
)

target_link_libraries(
    HttpReplySender
        PUBLIC
        ziapi
)
