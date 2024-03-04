#include <iostream>

int main() {

    // Numbers prefixed with a single leading zero are interpreted as octal
    int my_octal { 0123 };

    // Numbers prefixed with '0x' are interpreted as hexidecimal
    int my_hexidecimal { 0x123 };

    std::cout << my_octal << "\n"; // Should print 83
    std::cout << my_hexidecimal << "\n"; // Should print 291 

    return 0;

}