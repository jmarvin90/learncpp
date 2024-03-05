#include <iostream>

int get_user_input() {
    int input{};
    while (input == 0) {
        std::cout << "Please enter a number: ";
        std::cin >> input;
    }
    return input;
}

int main() {
    int user_input{get_user_input()};
    switch (user_input) {
        // Remember to use 'break'!
        case 1:     std::cout   << "You entered 1. " << "\n"; break;
        case 2:     std::cout   << "You entered 2. " << "\n"; break;
        default:    std::cout   << "You entered some number other than 1 or 2." 
                                << "\n"; break;
    }

    return 0;
}