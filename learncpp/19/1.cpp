#include <iostream>

void new_and_delete() {
    /*
        The 'new' keyword returns a memory address; we initialise a new int
        pointer with that address
    */
    int* ptr { new int{16} };       

    std::cout << *ptr << "\n";      // Should show 16 assuming no exceptions

    /*
        The delete keyword takes a pointer as an operand and releases the memory
        at that address. Pointer variable survives but is now dangling
    */
    delete ptr;
    ptr = nullptr;                  // Have to set to nullptr manually
}

void nothrow() {
    /* 
        std::nothrow defaults the ptr to a nullptr in the case that the new
        keyword fails.
    */
    int* ptr {new (std::nothrow) int{16}};      
    delete ptr;
    ptr = nullptr;
    std::cout << *ptr << "\n";
}

void null_ptr_deletion() {
    int* ptr {nullptr};

    /*
    if (ptr) {
        delete ptr;                 // We can delete a pointer if it's not null
    }
    */

   /* 
        A delete operation has the same outcome (nullptr) regardless of whether
        the pointer operand was null or not beforehand
    */
    delete ptr;
}

void memory_leak() {
    /*
        The memory allocated using new is never de-allocated, but the pointer
        holding the address goes out of scope at the end of the function.

        We're left with no way to de-allocate the memory, leading to a memory
        leak.
    */
    int* my_ptr{new int{5}};
}

void avoid_memory_leak() {
    /*
        Memory leak can be avoided by de-allocating the memory using delete;
        this allows the pointer variable my_ptr to go safely out of scope
    */
    int* my_ptr{new int{5}};
    delete my_ptr;
}

int main() {
    new_and_delete();
    nothrow();
}