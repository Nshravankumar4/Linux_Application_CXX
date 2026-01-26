#include "BankAccount.h"          // Include own header
#include <iostream>               // For cout (I/O)
using namespace std;

// Constructor definition
BankAccount::BankAccount() {
    balance = 0.0;                // Initialization of private member
}

// Add amount to balance
void BankAccount::add(double amount) {
    balance += amount;            // Modify encapsulated data
}

// Withdraw amount from balance
bool BankAccount::sub(double amount) {

    // Control flow: if-else
    if (amount > balance) {
        return false;             // Withdrawal failed
    }

    balance -= amount;            // Update balance
    return true;                  // Withdrawal successful
}

// Getter function
double BankAccount::getBalance() const {
    return balance;               // Read-only access (const correctness)
}
