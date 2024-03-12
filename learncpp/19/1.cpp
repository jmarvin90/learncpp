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
    ptr = nullptr;
    /*
        Have to set to nullptr manually - or, let it go out of scope?
    */
}

void nothrow() {
    /* 
        std::nothrow defaults the ptr to a nullptr in the case that the new
        keyword fails.
    */
    int* ptr {new (std::nothrow) int{16}};      
    delete ptr;
    ptr = nullptr;
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

void assignment_memory_leak() {
    /*
        The address for the memory allocated by new is lost when the pointer
        is re-assigned. There's then no way to de-allocate that memory: 
        a memory leak.
    */
    int* my_ptr{new int{5}};
    int my_int{5};
    my_ptr = &my_int;
}

void assignment_avoid_memory_leak() {
    /*
        Using delete before re-assignment allows the pointer to be re-assigned
        following de-allocation of the memory assigned to the original 
        variable, avoiding a memory leak.
    */
   int* my_ptr{new int{5}};
   int my_int{5};

   delete my_ptr;
   my_ptr = &my_int;
}

std::size_t get_length() {
    std::size_t length {};
    std::cout << "Please enter the required array length: ";
    std::cin >> length;
    return length;
}

void dynamically_allocated_arrays() {
    /* 
        The size_t type may need to be used when specifying the size of a 
        dynamically sized array whose length not known at compile-time
    */
    std::size_t length {get_length()};
    int* array{ new int[length]{}};         // Zero initialised 
    std::cout << "Initialised an array of length: " << length << "\n";
    delete[] array;
}

int main() {
    new_and_delete();
    nothrow();
    null_ptr_deletion();
    memory_leak();
    avoid_memory_leak();
    assignment_memory_leak();
    assignment_avoid_memory_leak();
    dynamically_allocated_arrays();
}