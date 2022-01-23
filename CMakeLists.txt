cmake_minimum_required(VERSION 3.17)
project(ZIAPI CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(ziapi INTERFACE)

target_sources(
    ziapi
        INTERFACE
        include/types/HttpReply.hpp
        include/types/HttpRequest.hpp
        include/types/PipelineConfig.hpp
        include/IClient.hpp
        include/IListener.hpp
        include/IModule.hpp
        include/IPacketParser.hpp
        include/IPipelineManager.hpp
        include/IReplySender.hpp
)

target_include_directories(
    ziapi
        INTERFACE
        include/
)

if (UNIX)
    set(COMPILE_FLAGS -Wall -Wextra -Weffc++)
else()
    set(COMPILE_FLAGS /W4)
endif()

target_compile_options(
    ziapi
        INTERFACE
        ${COMPILE_FLAGS}
)
