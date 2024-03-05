#include <iostream>

int main() {
    int x {15};

    if (x > 30) {           // The initial condition
        std::cout << "Our value is bigger than 30." << "\n";
    } else if (x > 20) {    // A separate/cascading condition
        std::cout << "Our value is bigger than 20." << "\n";
    } else if (x > 10) {    // Another cascading condition
        std::cout << "Our value is bigger than 10." << "\n";
    } else {                // Our final else catches all other conditions
        std::cout << "Our value must be smaller than 10." << "\n";
    }

    return 0;
}