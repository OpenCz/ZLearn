#include <catch2/catch_test_macros.hpp>
#include <zlearn/zlearn.hpp>

TEST_CASE("version string is non-empty", "[core]") {
    REQUIRE_FALSE(zlearn::version().empty());
}
