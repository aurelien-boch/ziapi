if (NOT ziapi_found)
    include("FetchContent")

    FetchContent_Declare(ziapi GIT_REPOSITORY https://https://github.com/aurelien-boch/ziapi.git)
    FetchContent_MakeAvailable(ziapi)
    set(ziapi_found)
endif()
