#include <iostream>

void basic_references() {
    int x{5};
    int& y{x};                  // Create a reference to x named y

    y = 10;                     // Assign a new value via the reference

    std::cout << x << "\n";     // Should now say 10
}

void references_to_const() {
    const int x{5};             // Value is const...can't be referenced?
    // int& y{x};               // Should error
    const int& y{x};            // If value is const, reference must be

    int a{15};                  // Non-const
    const int& b{a};            /* Makes the referenced object immutable when
                                   accessed via the reference */

    std::cout << y << "\n";     // Should say 5
    std::cout << b << "\n";     // Should say 15
}

/*
    Will return a reference to an object which no longer exists!
    This should generate a compiler error
*/
// int& dangling_reference_helper() {
//     int x{5};
//     return x;
// }

/*
    Will attempt to create a reference to an object which no longer exists
*/
// void dangling_reference() {
//     int& my_dangling_reference{dangling_reference_helper()};
//     std::cout << my_dangling_reference << "\n";
// }

void reference_to_rvalue() {
    const int& ref{999};            // Create a const reference to an rvalue
    // int& ref{4};                 // Non-const reference to rvalue will error

    /*
        Const reference to an rvalue will create an object which exists in the
        local scope
    */

    std::cout << ref << "\n";       // Should show 999;
}

int main() {
    basic_references();
    references_to_const();
    // dangling_reference();        // Commented out as it'll cause an error!
    reference_to_rvalue();
    return 0;
}