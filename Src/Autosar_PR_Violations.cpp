#include <iostream>
using namespace std;                 // ❌ autosar-cpp14-7-3-4

// ❌ Global variable (AUTOSAR discourages globals)
int globalCounter = 0;               // ❌ autosar-cpp14-8-4-1

class Account
{
public:
    Account() {}

    // ❌ Should be const
    int getBalance() const                 // ❌ readability-make-member-function-const
    {
        return balance;
    }

    void setBalance(int b)
    {
        balance = b;
    }

private:
    int balance;
};

void pointerArithmeticViolation()
{
    int values[3] = {1, 2, 3};
    int* p = values;

    p++;                             // ❌ cppcoreguidelines-pro-bounds-pointer-arithmetic
}

void castViolation()
{
    double d = 10.5;
    int x = (int)d;                  // ❌ autosar-cpp14-5-2-3 (C-style cast)
}

void nullptrViolation()
{
    int* p = nullptr;                   // ❌ modernize-use-nullptr
}

void memoryViolation()
{
    int* p = new int(42);            // ❌ cppcoreguidelines-owning-memory
    cout << *p << "\n";
    // ❌ no delete → leak
}

int main()
{
    Account acc;
    acc.setBalance(100);

    cout << acc.getBalance() << "\n";

//    pointerArithmeticViolation();
    castViolation();
    nullptrViolation();
    memoryViolation();

    return 0;
}
