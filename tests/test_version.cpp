#include <catch2/catch_test_macros.hpp>

#include "ferrex/version.hpp"

TEST_CASE("build_info names the project and version", "[version]") {
    const auto info = ferrex::build_info();
    REQUIRE(info.starts_with("ferrex 0.1."));
}

TEST_CASE("build_info reports the build flavour", "[version]") {
    const auto info = ferrex::build_info();
#if defined(NDEBUG)
    REQUIRE(info.ends_with("optimized)"));
#else
    REQUIRE(info.ends_with("debug)"));
#endif
}
