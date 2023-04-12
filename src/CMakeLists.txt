set(SRC
    "jac/device/uploader.cpp"
    "jac/device/controller.cpp"
    "jac/device/logger.cpp"
)


if(ESP_PLATFORM)
    idf_component_register(
        SRCS ${SRC}
        INCLUDE_DIRS .
        REQUIRES jac-machine jac-link
                pthread
    )

else()
    Include(FetchContent)

    FetchContent_Declare(
        Jaculus-machine
        GIT_REPOSITORY https://github.com/cubicap/Jaculus-machine.git
        GIT_TAG        f9ac60ec53f5d832508648cebdf42d42d2f8fe07
    )
    FetchContent_MakeAvailable(Jaculus-machine)

    FetchContent_Declare(
        Jaculus-link
        GIT_REPOSITORY https://github.com/cubicap/Jaculus-link.git
        GIT_TAG        d58d118d2fed7ce6c1b36c505ccbd98801830745
    )
    FetchContent_MakeAvailable(Jaculus-link)


    add_library(jac-device STATIC ${SRC})
    target_include_directories(jac-device PUBLIC .)
    set_target_properties(jac-device PROPERTIES LINKER_LANGUAGE CXX)
    target_link_libraries(jac-device PUBLIC jac-machine jac-link)

endif()
