#include <iostream>

// Introducing the std::string type
std::string get_name_with_cin() {
    std::string name;
    std::cout << "Please enter your name again: ";
    // std::cin stops at whitespace
    std::cin >> name;
    return name;
}

std::string get_name_with_getline() {
    std::string name;
    std::cout << "Enter your name: : ";
    std::getline(std::cin, name);
    return name;
}

// Note that names input with spaces will be truncated - will check why!
int main() {
    std::string cin_name {get_name_with_getline()};
    std::string getline_name {get_name_with_cin()};
    std::cout << "Welcome, " << cin_name << "! \n";
    std::cout << "Or should I say, " << getline_name << "? \n";
    return 0;
}