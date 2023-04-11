cmake_minimum_required(VERSION 3.0)

Include(FetchContent)
include(CTest)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.2.0
)

FetchContent_MakeAvailable(Catch2)


add_executable(main main.cpp)
target_link_libraries(main PUBLIC jac-device)
