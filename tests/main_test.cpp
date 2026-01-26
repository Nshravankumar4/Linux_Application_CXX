// Include Google Test framework
// This gives access to TEST(), EXPECT_*, RUN_ALL_TESTS(), etc.
#include <gtest/gtest.h>

/*
 * Custom main() function for Google Test
 *
 * Normally, Google Test provides its own main()
 * using the gtest_main library.
 *
 * In this project:
 * - We wrote our OWN main() function
 * - So we link only with gtest (NOT gtest_main)
 * - This gives us full control over test execution
 */

int main(int argc, char **argv)
{
    // Initialize Google Test framework
    // This reads command-line arguments like:
    // --gtest_filter, --gtest_repeat, etc.
    ::testing::InitGoogleTest(&argc, argv);

    // Run all test cases defined using TEST()
    // Returns:
    // 0  -> all tests passed
    // >0 -> at least one test failed
    return RUN_ALL_TESTS();
}
