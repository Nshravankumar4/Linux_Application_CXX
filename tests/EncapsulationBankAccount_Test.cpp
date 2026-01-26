#include <gtest/gtest.h>        // Include Google Test framework
#include "EncapsulationBankAccount.h"        // Include the header file of the class we want to test

// ------------------- Google Test Cases -------------------

// TEST is a macro to define a test case
// Syntax: TEST(TestSuiteName, TestName)
TEST(BankAccountTest, DepositTest) {
    BankAccount acc(1000);      // Create BankAccount object with 1000 balance

    acc.deposit(500);           // Deposit 500
    EXPECT_EQ(acc.getBalance(), 1500);  // Expect balance to be 1500
}

TEST(BankAccountTest, WithdrawTest) {
    BankAccount acc(1000);      // Create BankAccount object with 1000 balance

    acc.withdraw(200);          // Withdraw 200
    EXPECT_EQ(acc.getBalance(), 800);   // Expect balance to be 800
}

TEST(BankAccountTest, WithdrawOverBalanceTest) {
    BankAccount acc(500);       // Create BankAccount object with 500 balance

    acc.withdraw(1000);         // Try withdrawing more than balance
    EXPECT_EQ(acc.getBalance(), 500);   // Balance should remain 500 (no change)
}

TEST(BankAccountTest, MultipleOperationsTest) {
    BankAccount acc(1000);      // Create BankAccount object

    acc.deposit(200);           // Deposit 200 → balance 1200
    acc.withdraw(300);          // Withdraw 300 → balance 900
    acc.deposit(100);           // Deposit 100 → balance 1000

    EXPECT_EQ(acc.getBalance(), 1000);  // Final balance should be 1000
}
