#include <iostream>
#include <iostream>
#include "math_utils.h"
#include "Class_Object.h"   // 🔥 THIS WAS MISSING
#include "EncapsulationBankAccount.h"

using namespace std;

// Main Program Start Here
int main() {
    cout << "Hello from WSL + CMake!" << endl;
    cout << "add(5, 3) = " << add(5, 3) << endl;
    cout << "sub(5, 3) = " << sub(5, 3) << endl;
    cout << "divide(4, 2) = " << divide(4, 2) << endl;
    cout << "mul(6, 3) = " << mul(6, 2) << endl;

    // Print program description
    cout << "This Program is about Class and Object\n";

// Create an object 'obj' of class MyClass
    MyClass obj;

    // Call the member function using the object
    // Passing value 10 as input to check even or odd
    cout << "10 is " << obj.FindStrEvenOrOdd(10) << endl;

    // Call the member function using the object
    // Passing value 10 as input to check even or odd
    cout << "3 is " << obj.FindStrEvenOrOdd(3) << endl;
    // Use string-returning function for printing

    
// Create an object 'acc' of BankAccount class with initial balance 1000
    BankAccount acc(1000);

    // Deposit 500 into the account
    acc.deposit(500);

    // Withdraw 200 from the account
    acc.withdraw(200);

    // Print the current balance using getBalance()
    cout << "Current Balance: " << acc.getBalance() << endl;

    // Try withdrawing more than the balance to see the error message
    acc.withdraw(2000);

// ------------------- Main Function for Tests -------------------

// Google Test provides its own main function
// But if needed, we can define our own main like this:
//int main(int argc, char **argv) {
  //  ::testing::InitGoogleTest(&argc, argv);  // Initialize GTest
    //return RUN_ALL_TESTS();                  // Run all defined test cases
//}

    // Return 0 indicates successful program execution
    return 0;
}
