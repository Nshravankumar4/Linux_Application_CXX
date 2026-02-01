#ifndef BANKACCOUNT_H              // Header guard → prevents multiple inclusion
#define BANKACCOUNT_H

// Class declaration → OOP: Class (blueprint)
class BankAccount {

private:
    double balance;               // Encapsulation: private data (data hiding)

public:
    // Constructor declaration → initializes object state
    BankAccount();

    // Public methods → Abstraction (what object can do)
    void add(double amount);      // Deposit money
    bool sub(double amount);      // Withdraw money (returns success/failure)
    double getBalance() const;    // Getter → read-only access to balance
};

#endif // BANKACCOUNT_H
