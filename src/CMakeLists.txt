set(SRC
    "jac/device/uploader.cpp"
    "jac/device/controller.cpp"
    "jac/device/logger.cpp"
    "jac/device/util/sha1.c"
)

set(DCORE_VERSION "0.0.16")

if(ESP_PLATFORM)
    idf_component_register(
        SRCS ${SRC}
        INCLUDE_DIRS .
        REQUIRES jac-machine jac-link
                pthread mbedtls
    )

    target_compile_definitions(${COMPONENT_LIB} PUBLIC -DJAC_DCORE_USE_MBEDTLS=1 -DJAC_DCORE_VERSION="${DCORE_VERSION}")

else()
    Include(FetchContent)

    FetchContent_Declare(
        Jaculus-machine
        URL https://github.com/cubicap/Jaculus-machine/archive/refs/tags/v0.0.9.tar.gz
    )
    FetchContent_MakeAvailable(Jaculus-machine)

    FetchContent_Declare(
        Jaculus-link
        URL https://github.com/cubicap/Jaculus-link/archive/refs/tags/v0.0.3.tar.gz
    )
    FetchContent_MakeAvailable(Jaculus-link)


    add_library(jac-dcore STATIC ${SRC})
    target_include_directories(jac-dcore PUBLIC .)
    set_target_properties(jac-dcore PROPERTIES LINKER_LANGUAGE CXX)
    target_link_libraries(jac-dcore PUBLIC jac-machine jac-link)

    target_compile_definitions(quickjs PUBLIC -DJAC_DCORE_VERSION="${DCORE_VERSION}")

endif()
