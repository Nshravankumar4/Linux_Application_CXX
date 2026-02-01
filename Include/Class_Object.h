#ifndef CLASS_OBJECT_H
#define CLASS_OBJECT_H

using namespace std;

#include <string>     // ✅ REQUIRED for std::string

// ------------------- Class Definition -------------------

// Define a class named MyClass
class MyClass {

public:
    // Member function declaration
    // Takes one integer parameter 'a'
    // This function checks whether the number is even or odd
    void FindEvenOrOdd(int a);

    // Public member function declaration
    // Takes one integer parameter 'a'
    // Returns a string: "Even" if number is even, "Odd" if number is odd
    string FindStrEvenOrOdd(int a);
};

#endif //CLASS_OBJECT_H
