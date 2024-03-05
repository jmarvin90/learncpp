#include <iostream>

int get_user_input() {
    int input{};
    int max{};

    do {
        std::cout << "Please enter a number (-1 to stop): ";
        std::cin >> input;

        if (input > max) {
            max = input;
        }
    } while (input != -1);
    return max;
}

int main() {
    int number {get_user_input()};
    std::cout << "The biggest number you entered was: " << number << "\n";
    return 0;
}