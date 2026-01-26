#ifndef BANK_ACCOUNT_H       // Include guard: prevents multiple inclusion of this header file
#define BANK_ACCOUNT_H

// -----------------------------
// Class Declaration: BankAccount
// -----------------------------
class BankAccount {
private: 
    // Private data member: accessible only within this class
    double balance;           // Stores the current balance of the bank account

public: 
    // -----------------------------
    // Constructor
    // -----------------------------
    // Initialize the bank account with a starting balance
    BankAccount(double initBalance);

    // -----------------------------
    // Deposit function
    // -----------------------------
    // Adds the given amount to the current balance
    void deposit(double amount);

    // -----------------------------
    // Withdraw function
    // -----------------------------
    // Deducts the given amount from balance unconditionally
    // Balance can go negative if amount > current balance
    void withdraw(double amount);

    // -----------------------------
    // Getter function
    // -----------------------------
    // Returns the current balance of the account
    double getBalance();

    // -----------------------------
    // Safe withdrawal function
    // -----------------------------
    // Checks if there is enough balance before withdrawal
    // If balance is sufficient, withdraws the amount
    // Otherwise, prints "Insufficient balance!" and does not change balance
    void checkBalanceBeforewithdraw(double amount);
};

#endif // BANK_ACCOUNT_H
