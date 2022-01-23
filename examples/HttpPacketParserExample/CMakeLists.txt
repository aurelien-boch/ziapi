add_library(
    HttpPacketParser
        include/HttpPacketParser.hpp
        src/HttpPacketParser.cpp
)

target_include_directories(
    HttpPacketParser
        PUBLIC
        include/
)

target_link_libraries(
    HttpPacketParser
        PUBLIC
        ziapi
)
