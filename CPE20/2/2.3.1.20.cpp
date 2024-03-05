#include <iostream>

int main() {
    // Will print 1-16, skipping 14
    for (int i = 0; i <= 16; i++) {
        if (i == 14) {
            continue;
        }
        std::cout << i << " ";
    }
    std ::cout << "\n";

    // Will print 1-16, breaking before 17
    for (int i = 0; i <= 1000; i++) {
        if (i == 17) {
            break;
        }
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}