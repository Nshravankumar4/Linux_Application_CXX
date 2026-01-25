#include <iostream>
#include "math_utils.h"

using namespace std;

int main() {
    cout << "Hello from WSL + CMake!" << endl;
    cout << "add(5, 3) = " << add(5, 3) << endl;
    cout << "sub(5, 3) = " << sub(5, 3) << endl;
    cout << "divide(4, 2) = " << divide(4, 2) << endl;
    cout << "mul(6, 3) = " << mul(6, 2) << endl;
    return 0;
}
