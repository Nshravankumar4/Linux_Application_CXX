#include <iostream>          // ✅ REQUIRED
#include "Class_Object.h"
#include <string>

using namespace std;         // OR use std::cout, std::endl

// Member function definition outside the class
void MyClass::FindEvenOrOdd(int a) {
    // Print message to indicate the operation being performed
    cout << "Checking the given number is Odd or Even:" << endl;

    // Condition to check if the number is divisible by 2
    if (a % 2 == 0) {
        // If remainder is 0, the number is Even
        cout << a << " is Even Number" << endl;
    } else {
        // If remainder is not 0, the number is Odd
        cout << a << " is Odd Number" << endl;
    }
}

// ------------------- Member Function Definition -------------------

// Define the member function outside the class using scope resolution (::)
string MyClass::FindStrEvenOrOdd(int a) {

    // Check if the number is divisible by 2
    // If remainder is 0, the number is even
    if (a % 2 == 0) {
        return "Even";     // Return string "Even" for even numbers
    } 
    // If remainder is not 0, the number is odd
    else {
        return "Odd";      // Return string "Odd" for odd numbers
    }
}

/*

string MyClass::FindStrEvenOrOdd(int a) {
    return (a % 2 == 0) ? "Even" : "Odd";
}

*/
