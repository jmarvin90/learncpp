#include <iostream>

int foo() {
    return 5;
}

int main() {
    int x {5}; // r-value;
    int y {x}; // l-value;

    std::cout << &x << "\n";            // The address of x; should compile file
    // std::cout << &5 << "\n";         // The address of 5; WON'T COMPILE

    // std::cout << &foo() << "\n";     // Return values are r-values
    std::cout << &foo << "\n";          // Possible to return a reference to a function - weird!

    /*
        The result of l-value expressions will have an address, and the 
        corresponding reference can be printed.
        
        r-values don't, so attempting to print references for r-values will
        result in compilation errors.
    */
    
}