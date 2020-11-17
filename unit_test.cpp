#include "gtest/gtest.h"
#include "strategy_test.hpp"
#include "container.hpp"
#include "sort.hpp"
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
