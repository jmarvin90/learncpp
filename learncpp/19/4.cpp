#include <iostream>

void pointer_to_pointer() {
    int x{5};
    int* y{&x};                         // Pointer to an int
    int** z{&y};                        // Pointer to a pointer

    std::cout << **z << "\n";           // Should show 5
}

std::size_t get_length() {
    std::size_t length;
    std::cout << "Please enter the desired length: ";
    std::cin >> length;
    return length;
}

void test_pointer_to_array() {
    std::size_t length{get_length()};
    int* my_array {new int[length]{}};
    std::cout << my_array << "\n";          // Should show a memory address
    delete[] my_array;
    my_array = nullptr;
}

void two_d_dynamically_allocated_array() {
    /*
        Create a one dimensional array whose elements are all pointers to other
        one dimensional arrays - thereby making the array effectively two
        dimensional
    */
    int** two_d_array {new int*[10]};

    /*
        For each item (pointer) in the initial one-dimensional array, we create
        a new dynamically allocated array whose length corresponds to the
        position of the 'child' in the 'parent'
    */
    for(int i=0; i<10; i++) {
        two_d_array[i] = new int[i+1];
    }

    for (int i=0; i<10; i++) {
        /*
            Return all the dynamically allocated memory for each 'row' back to
            the heap
        */
        delete[] two_d_array[i];
    }

    /*
        Return the memory for the 'outer' array back to the heap
    */
    delete[] two_d_array;
}

void test_two_d_array_repeat() {
    std::size_t length{get_length()};

    /*
        An array of pointers whose dereferenced values are also pointers
    */
    int** my_array{ new int*[length]{}};

    for (int i=0; i<length; i++) {
        /*
            The value of each pointer in the outer array will be set to the
            result of the 'new' operation (a pointer), which will itself
            create an array of int of the specified (i+1) length
        */
        my_array[i] = new int[i+1];
    }

    for (int i=0; i<length; i++) {
        delete[] my_array[i];
    }

    delete[] my_array;
    my_array = nullptr;
}

int main() {
    pointer_to_pointer();
    test_pointer_to_array();
}