cmake_minimum_required(VERSION 3.0)

Include(FetchContent)
include(CTest)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.2.0
)

FetchContent_MakeAvailable(Catch2)

file(COPY test_files DESTINATION "./")


file(GLOB_RECURSE test_files_files test_files/*)
set(tgz_name test_files.tar.gz)

# generate tar file
add_custom_command(
    OUTPUT ${tgz_name}
    DEPENDS ${test_files_files}
    COMMAND tar -czf ${tgz_name} -C ${CMAKE_CURRENT_SOURCE_DIR} test_files
)

# copy resources into resources.cpp
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/resources.cpp
    DEPENDS ${tgz_name} resources.cpp.in resources.cmake
    COMMAND "${CMAKE_COMMAND}"
        -D "resources_dir=${CMAKE_CURRENT_BINARY_DIR}"
        -D "src_in=${CMAKE_CURRENT_SOURCE_DIR}/resources.cpp.in"
        -D "src_out=${CMAKE_CURRENT_BINARY_DIR}/resources.cpp"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/resources.cmake"
)

add_library(resources STATIC ${CMAKE_CURRENT_BINARY_DIR}/resources.cpp)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC jac-dcore resources)

add_executable(resources_test resources_test.cpp)
target_link_libraries(resources_test PUBLIC jac-dcore resources Catch2::Catch2WithMain)
add_test(NAME resources_test COMMAND ${EXECUTABLE_OUTPUT_PATH}/resources_test)
