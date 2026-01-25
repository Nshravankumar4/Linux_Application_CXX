#ifndef BANK_ACCOUNT_H       // Include guard: prevents multiple inclusion of this header
#define BANK_ACCOUNT_H

// Class Declaration: BankAccount
class BankAccount {
private:                      // Private members: accessible only inside this class
    double balance;           // Data member to store account balance

public:                       // Public members: accessible from outside the class
    BankAccount(double initBalance); // Constructor: initialize balance
    void deposit(double amount);     // Function to add money to balance
    void withdraw(double amount);    // Function to withdraw money from balance
    double getBalance();             // Function to get current balance
};

#endif
