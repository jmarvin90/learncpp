#include <iostream>

long set_long() {
    /*
        The L suffix makes it explicit that the value should be long
    */
    long my_long {1L};
    return my_long;  
}

void c_style_casting() {
    float my_float{1.0};
    std::cout << (int)my_float << "\n";         // Cast to int
}

void functional_notation_casting() {
    float my_float{2.0};
    std::cout << int(my_float) << "\n";                 // Cast to int
}

void static_casting() {
    float my_float{3.0};
    std::cout << static_cast<int>(my_float) << "\n";
}

int main() {
    set_long();
    c_style_casting();
    functional_notation_casting();
    static_casting();
}