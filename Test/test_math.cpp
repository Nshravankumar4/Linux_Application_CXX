#include <gtest/gtest.h>
#include "math_utils.h"

TEST(MathTest, AddTest) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(-1, 1), 0);
}

TEST(MathTest, SubTest) {
    EXPECT_EQ(sub(5, 3), 2);
    EXPECT_EQ(sub(0, 5), -5);
}

TEST(MathTest, DivideTest) {
    EXPECT_EQ(divide(6, 3), 2);
    EXPECT_EQ(divide(12, 4), 3);
}

TEST(MathTest, MulTest) {
    EXPECT_EQ(mul(7, 3), 21);
    EXPECT_EQ(mul(8, 4), 32);
}

