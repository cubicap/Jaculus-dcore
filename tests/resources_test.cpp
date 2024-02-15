#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include <string>

#include "resources.h"


TEST_CASE("Resources") {
    SECTION(".content") {
        std::string_view content(
            reinterpret_cast<const char*>(resources::testFilesContent.data()),
            resources::testFilesContent.size()
        );

        REQUIRE(content == "Hello world!\n");
    }
}
