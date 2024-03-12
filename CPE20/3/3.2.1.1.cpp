#include <iostream>

void pointer_to_reference() {
    int my_number{15};
    int* my_pointer(&my_number);
}

void pointer_array_first_element() {
    int my_array[5] {0, 2, 4, 6, 8};

    /*
        'Pointing' directly to an array (and not a reference to an array) is
        equivalent to pointing to the first element in the array.
    */
    int* pointer_to_my_array{my_array};
    int* second_pointer_to_my_array{my_array};

    std::cout   << *pointer_to_my_array << " - "          // Should show 0
                << "Pointers are the same: " 
                << std::boolalpha 
                << (pointer_to_my_array == second_pointer_to_my_array)
                << "\n";

    /*
        Adding a value to a pointer is equivalent to adding size_of(type) to a
        the pointer; for example; adding one to a pointer 'pointing' to an array
        of int will add the size of an int to the memory address of the pointer.

        The net effect when using arrays is to point to the next element in the
        array.
    */

    second_pointer_to_my_array++;
    std::cout   << *second_pointer_to_my_array << " - "      // Should show 2
                << "Pointers are the same: " 
                << std::boolalpha 
                << (pointer_to_my_array == second_pointer_to_my_array)
                << "\n";
}

void pointer_array_non_int() {
    std::string my_strings[5] {
        "you're ok", "I'm ok", "they're ok", "we're ok", "who's ok"
    };

    std::string* ptr_1 {my_strings};            // equivalent to ptr_1 {&my_strings[0]}
    std::string* ptr_2 {&my_strings[3]};        // three places up
    std::cout << *ptr_1 << "\n";
    std::cout << ptr_2 - ptr_1 << "\n";         // Should show difference in index pos (3)
}



int main() {
    pointer_to_reference();
    pointer_array_first_element();
    pointer_array_non_int();
    return 0;
}