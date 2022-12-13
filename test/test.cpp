#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch2/catch.hpp"
#include "compile_time_map.h"
#include <map>
#include <random>
enum Key : int {
    a = 0,
    b,
    c,
    d,
    e,
}

std::list<std::pair<Key, int>> data{
        {a, 100},
        {b, 200},
        {c, 300},
        {d, 400},
        {e, 500}
    };

int test_std_map(int key) {
    static const auto map = std::map<Key, int>(begin(data), end(data));
    return map[key];
}
 
int test_CT_map(int key) {
    static constexpr auto map = CTMap<Key, int, 5>{{data}};
    return map.at(key);
}

TEST_CASE("my test", "[compute]") {
    REQUIRE(CTMap::compute() == 0);
    // Seed with a real random value, if available
    std::random_device r;
 
    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 5);
    int key = Key(uniform_dist(e1));
    BENCHMARK("std map") {
        return test_std_map(key);
    }
    BENCHMARK("CT map") {
        return test_CT_map(key);
    }
}