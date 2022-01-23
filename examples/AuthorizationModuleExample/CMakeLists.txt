add_library(
    AuthorizationModule
        include/AuthorizationModule.hpp
        src/AuthorizationModule.cpp
)

target_include_directories(
        AuthorizationModule
        PUBLIC
        include/
)

target_link_libraries(
        AuthorizationModule
        PUBLIC
        ziapi
)
