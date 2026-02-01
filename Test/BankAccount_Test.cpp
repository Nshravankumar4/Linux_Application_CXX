#include <gtest/gtest.h>          // Google Test framework
#include "BankAccount.h"          // Class under test

// Test case → Initial state validation
TEST(BankAccountTest, InitialBalanceIsZero) {
    BankAccount acc;              // Object creation → constructor called
    EXPECT_DOUBLE_EQ(acc.getBalance(), 0.0);
}

// Test case → Add operation
TEST(BankAccountTest, AddAmount) {
    BankAccount acc;
    acc.add(100);                 // Function call
    EXPECT_DOUBLE_EQ(acc.getBalance(), 100.0);
}

// Test case → Successful withdrawal
TEST(BankAccountTest, WithdrawSuccess) {
    BankAccount acc;
    acc.add(100);
    bool result = acc.sub(40);    // Function returns bool

    EXPECT_TRUE(result);          // Check return value
    EXPECT_DOUBLE_EQ(acc.getBalance(), 60.0);
}

// Test case → Insufficient funds
TEST(BankAccountTest, WithdrawFailure) {
    BankAccount acc;
    acc.add(30);
    bool result = acc.sub(50);

    EXPECT_FALSE(result);         // Withdrawal should fail
    EXPECT_DOUBLE_EQ(acc.getBalance(), 30.0);
}
