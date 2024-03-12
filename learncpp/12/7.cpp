#include <iostream>

/*
    NOTE: An un-initialised pointer ('wild' pointer) will point to a 'garbage'
    address; dereferencing a wild point may lead to U/B. 
    
    ALWAYS INITIALISE POINTERS
*/

void dereference_operator() {
    int x{5};                       // Straightforward
    std::cout << &x << "\n";        // Should show the memory address of x
    std::cout << *(&x) << "\n";     /* 'Dereferences' the address (returns value at
                                       the memory address) */
}

void pointer_example() {
    int x{30};                      // Straightforward
    int* y{&x};                     // The memory address of x, stored as y

    std::cout << y << "\n";         // Should show the memory address of x
    std::cout << *y << "\n";        // Dereferences the address; should show x
}

void pointer_type_mismatch() {
    int x {99};                     // Straightforward
    // float* y{&x};                // Type mistmatch - won't compile!
}

void pointer_reassignment() {
    int x{222};                     // Straightforward
    int z{333};                     // Straightforward
    int* y{&x};                     // Initially, 'point' to x

    std::cout << *y << "\n";        // Should show x's value

    y = &z;                         // Reassign the pointer using z's address
    std::cout << *y << "\n";        // Should show z's value
}

void pointer_update_value() {
    int x{202};                     // Straightforward
    int* y{&x};                     // Point to x

    std::cout << *y << "\n";        /* Dereference to show the value 'pointed'
                                       at - should show 202 */

    *y = 303;                       /* Dereference to CHANGE the value 'pointed'
                                       at */

    std::cout << x << "\n";         // Show the 'updated' value (303)
}

void null_pointers() {
    int* p {};                      // Value-initialised is a null pointer
    int* q {nullptr};               // Specifically initialised as a null pointer

    std::cout << "It's " << std::boolalpha << (q == nullptr) << " to say that q is a nullptr.\n";
    // std::cout << *q << "\n";     // U/B - could crash!
}

void pointers_to_const() {
    int control {1};

    const int x{999};               // Straightforward              
    const int* y{&x};               // A non-const pointer to a const value
    // *y = 9999;                   // Not allowed; val pointed to is const
    y=&control;                     // Can re-assign a non-const pointer

    int z{1000};                    // Straightforward
    int* const a{&z};               // A const pointer to a non-const value
    *a = 1111;                      // Allowed; val pointed to is not const
    // a = &control;                // Not allowed; can't re-assign const pointer

    const int d{2020};              // Straightforward
    const int* const e{&d};         // Const pointer to const value
    // *e = 2021;                   // Not allowed; val pointed to is const
    // e = &control;                // Not allowed; can't re-assign const pointer
}

void receive_by_address(const int* ptr) { // Accepts a pointer as a param
    std::cout << "Your number was: " << *ptr << ".\n";
}

void pass_by_address() {
    int x{1999};
    receive_by_address(&x);          // Pass pointer using address-of operator              
}

void receive_by_address_by_reference(int*& ptr) {   // Accepts a reference to a pointer
    ptr = nullptr;
}

void pass_by_address_by_reference() {
    int x {15};                     // Straightforward
    int* y{&x};                     // Point toward x

    std::cout   << "It's "   
                << std::boolalpha << (!y ? true:false) 
                << " to say that y is null.\n";

    receive_by_address_by_reference(y);
    // Pointer should be nulled as it's passed by reference

    std::cout   << "It's "   
                << std::boolalpha << (!y ? true:false) 
                << " to say that y is null.\n";
}

const int& pass_by_return_by_reference(
    const int& number_1, const int& number_2
) {
    return (number_1>number_2) ? number_1 : number_2;
}

void pass_by_return_by_reference() {
    const int number_1{10};
    const int number_2{20};
    std::cout   << "The biggest number was: "  
                << pass_by_return_by_reference(number_1, number_2)
                << "\n";
}

int main() {
    dereference_operator();
    pointer_example();
    pointer_reassignment();
    pointer_update_value();
    null_pointers();                // <---- Could crash the program!
    pointers_to_const();
    pass_by_address();
    pass_by_address_by_reference();
    pass_by_return_by_reference();
    return 0;
}