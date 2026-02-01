#include <iostream>           // Include I/O library for cout
#include "EncapsulationBankAccount.h"      // Include the header file of the class
using namespace std;          // Allows using cout without std::

/* Constructor definition */
BankAccount::BankAccount(double initBalance) {
    balance = initBalance;     // Initialize the private balance with the given value
}

/* Deposit function definition */
void BankAccount::deposit(double amount) {
    balance += amount;         // Add the given amount to the current balance
}

/* Withdraw function definition */
void BankAccount::withdraw(double amount) {
    if (amount <= balance) {   // Check if withdrawal is possible
        balance -= amount;     // Deduct amount from balance
    } else {
        cout << "Insufficient balance!" << endl; // Print error if not enough balance
    }
}

/* Getter function definition */
double BankAccount::getBalance() {
    return balance;            // Return the current balance
}

