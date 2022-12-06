#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "compile_time_map.h"

TEST_CASE("my test", "[compute]") {
    REQUIRE(CTMap::compute() == 0);
}