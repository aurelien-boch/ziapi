if (NOT ziapi_found)
    include(FetchContent)

    message(STATUS "Cloning ziapi")
    FetchContent_Declare(ziapi GIT_REPOSITORY https://github.com/aurelien-boch/ziapi.git)
    FetchContent_MakeAvailable(ziapi)
    set(ziapi_found)
endif()
