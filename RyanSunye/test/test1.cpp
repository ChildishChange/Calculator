//
// Created by HP on 2020/3/1.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../Calculator.h"

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    auto* calc = new Calculator();
    string ret = calc->Solve("11+22");
    REQUIRE(ret=="11+22=33");
}
