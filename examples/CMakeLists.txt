#TODO DE-COMMENT
#cmake_minimum_required(VERSION 3.17)
#project(ZIAPI_Examples CXX)
#
#set(CMAKE_CXX_STANDARD 17)
#
#set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
#
#find_package(ziapi)

add_subdirectory(HttpListenerExample)
add_subdirectory(AuthorizationModuleExample)
add_subdirectory(HttpPacketParserExample)
add_subdirectory(HttpPipelineManagerExample)
add_subdirectory(HttpReplySenderExample)
