#include <iostream>

int main() {
    int your_number {};

    std::cout << "Please provide a number: ";
    std::cin >> your_number;

    std::cout   << "Your number squared is: " 
                << your_number * your_number 
                << "\n";
}