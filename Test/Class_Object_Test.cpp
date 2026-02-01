#include <gtest/gtest.h>
#include "Class_Object.h"

// ------------------- Google Test Cases -------------------

// TEST is a Google Test macro used to define a test case
// MyClassTest  -> Test suite name
// EvenOrOddCheck -> Test case name
TEST(MyClassTest, EvenOrOddCheck) {

    // Create an object of MyClass
    MyClass obj;

    // EXPECT_EQ checks whether the expected value
    // is equal to the actual value returned by the function

    // Check if 10 is even
    EXPECT_EQ(obj.FindStrEvenOrOdd(10), "Even");

    // Check if 3 is odd
    EXPECT_EQ(obj.FindStrEvenOrOdd(3), "Odd");

    // Check if 0 is even
    EXPECT_EQ(obj.FindStrEvenOrOdd(0), "Even");
}
