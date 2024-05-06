#include <gtest/gtest.h>

#include "day1/test.hpp"
#include "day2/test.hpp"
#include "day3/test.hpp"

int main (int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
