add_library(
    HttpPipelineManager
        include/HttpPipelineManager.hpp
        src/HttpPipelineManager.cpp
)

target_include_directories(
    HttpPipelineManager
        PUBLIC
        include/
)

target_link_libraries(
    HttpPipelineManager
        PUBLIC
        ziapi
        HttpListener
        HttpPacketParser
        HttpReplySender
)
